//Problem: 12532
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3977
using namespace std;

// too corner case... (the code work but is terrible)

#include <vector>
#include <stdio.h>
#include <cmath>
#include <iostream>

typedef vector<int> vi;
typedef vector<float> vf;

class SegmentTree { // the segment tree is stored like a heap array
private: 
    vi A; // recall that vi is: typedef vector<int> vi;
    vf st;
    int n;
    
    int left (int p) { return p << 1; } // same as binary heap operations
    int right(int p) { return (p << 1) + 1; }
    
    void build(int p, int L, int R) { // O(n)
        if (L == R){ // as L == R, either one is fine
            st[p] = A[L]*1.0;
            /*if(A[L]=0)      {st[p]=2.0;}
            else if(A[L]<0) {st[p]=-1.0;}
            else            {st[p]=1.0;}*/
        } else { // recursively compute the values
            build(left(p) , L , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R );
            float p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1*p2;
        }
    }
    
    // Range Max query
    float rmq(int p, int L, int R, int i, int j) { // O(log n)
        if (i > R || j < L) return 0; // current segment outside query range
        if (L >= i && R <= j){
            //cout << "find: " << st[p] << endl;
            return st[p]; // inside query range
        } 

        // compute the min position in the left and right part of the interval
        float p1 = rmq(left(p) , L , (L+R) / 2, i, j);
        float p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);

        if (0 == (int)p1) return p2; // if we try to access segment outside query
        if (0 == (int)p2) return p1; // same as above
        return p1*p2; // as in build routine
    }

    float update(int p, int L, int R, int i, int v){
        if (L == i && R == i){
            float ret = v*1.0/A[i];
            /*if(i==2){
                cout << "v:" << v << " A[i]:" << A[i] << " ret:" << ret << endl;
            }*/
            A[i] = v;
            st[p] = v*1.0;
            return(ret);
        } else{
            float p2;
            if(i<=(L+R) / 2){
                p2 = update(left(p), L, (L+R) / 2, i, v);
            } else{
                p2 = update(right(p), (L+R) / 2 +1, R, i, v);
            }
            float ret = 1.0/st[p];
            st[p] = st[p]*p2;
            ret *= st[p];
            return(ret);
        }
    }

public:
    SegmentTree(const vi & _A) {
        A = _A; n = (int)A.size(); // copy content for local usage
        st.resize(4 * n);
        build(1, 0, n - 1); // recursive build
    }  
    float rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading
    void update(int i, int v){ update(1.0, 0, n - 1, i, v); }     // overloading
    void print(){
        //cout << "Print:\n";
        for(int i=1, k=1; i<st.size(); i++){
            //cout << i << ":" << st[i] << " \t";
            if(i==pow(2, k)-1){
                k++;
                cout << endl;
            }
        }
    }
};

void print(vector<int> & v){
    for(int i=0; i<v.size(); i++){
        cout << i << ":" << v[i] << endl;
    }
    cout << endl;
}

int main(){
    int n, k;
    while(cin>>n>>k){
        vector<int> A;
        int in;
        for(int i=0; i<n; i++){
            cin >> in;
            if(in==0){ A.push_back(2); } 
            else if(in<0){ A.push_back(-1); } 
            else{ A.push_back(1); }
        }
        SegmentTree st(A);
        //print(A);
        //st.print();
        char c;
        int a, b, v;
        for(int i=0; i<k; i++){
            cin >> c >> a >> b;
            if(c=='C'){ //change
                a--;
                int v;
                if(b==0){ v=2; } 
                else if(b<0){ v=-1; } 
                else{ v=1; }
                st.update(a, v);
                //st.print();
            } else{ //product
                a--; b--;
                float prod = st.rmq(a, b);
                //cout << "\n(" << a << ", " << b << ") result: -> " << prod << " -> ";
                if((int)prod==-1){
                    cout << "-";
                } else if((int)prod==1){
                    cout << "+";
                } else{
                    cout << "0";
                }
                //cout << endl;
            }
        }
        cout << endl;
    }
return(0);
}