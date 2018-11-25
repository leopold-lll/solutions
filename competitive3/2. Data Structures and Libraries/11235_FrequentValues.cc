//Problem: 11235
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2176
using namespace std;

// follows a very bad code...

#include <vector>
#include <stdio.h>

typedef vector<int> vi;

class SegmentTree { // the segment tree is stored like a heap array
private: vi st, A; // recall that vi is: typedef vector<int> vi;
    int n;
    
    int left (int p) { return p << 1; } // same as binary heap operations
    int right(int p) { return (p << 1) + 1; }
    
    void build(int p, int L, int R) { // O(n)
        if (L == R) // as L == R, either one is fine
            st[p] = L; // store the index
        else { // recursively compute the values
            build(left(p) , L , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R );
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
        } 
    }
    
    int rmq(int p, int L, int R, int i, int j) { // O(log n)
        if (i > R || j < L) return -1; // current segment outside query range
        if (L >= i && R <= j) return st[p]; // inside query range

        // compute the min position in the left and right part of the interval
        int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
        int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);

        if (p1 == -1) return p2; // if we try to access segment outside query
        if (p2 == -1) return p1; // same as above

        return (A[p1] >= A[p2]) ? p1 : p2; // as in build routine
    }

public:
    SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size(); // copy content for local usage
    st.assign(4 * n, 0); // create large enough vector of zeroes
    build(1, 0, n - 1); // recursive build
    }   
    int rmq(int i, int j) { 
        if(i>j){return(0);}
        return rmq(1, 0, n - 1, i, j); 
    } // overloading
};

#include <iostream>

const int size = 1e5; //1e5

int main() {
    int n, q;
    vector<int> freq;
    vector<int> next;
    while(cin>>n){
        if(n==0){break;}
        cin>>q;

        freq.resize(size+1);
        next.resize(size);
        int c, last, seq;

        freq[0]=1;
        seq=1;
        cin>>last;
        for(int i=1; i<n; i++){
            cin>>c;
            if(c==last){
                seq++;
            } else{
                seq=1;
                last=c;
            }
            freq[i]=seq;
        }
        /*cout << "freq:\n";
        for(int i=0; i<freq.size(); i++){
            cout << i << ": " << freq[i] << endl;
        }
        cout << endl;*/

        int after = next.size();
        next[next.size()-1] = after;
        for(int i=next.size()-2; i>=0; i--){
            if(freq[i+1]==1){
                after = i+1;
            }
            next[i]=after;
        }
        /*cout << "next:\n";
        for(int i=0; i<next.size(); i++){
            cout << i << ": " << next[i] << endl;
        }
        cout << endl;*/

        SegmentTree st(freq);
        int a, b;
        for(int i=0; i<q; i++){
            cin>>a>>b;
            a--; b--;
            //cout << "(" << next[a] << ", " << b << "): " << st.rmq(next[a], b) <<  " -> " << freq[st.rmq(next[a], b)] << endl;
            int tmp = max( freq[st.rmq(next[a], b)], min(next[a], b+1)-a );
            cout << tmp << endl;
        }
        freq.resize(0);
        next.resize(0);
    }
    return(0);
}