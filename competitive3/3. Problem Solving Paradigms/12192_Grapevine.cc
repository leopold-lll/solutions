//Problem: 12192
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=3344&mosmsg=Submission+received+with+ID+22329500
using namespace std;

#include <iostream>

int n, m, q;
int mat[501][501];
int minimi[501], massimi[501];

int binary_search(int row, int x){
    int l=0, r=m, mid;
    while(r>l){
        mid = (r+l)/2;
        if( mat[row][mid] >= x ){
            r = mid;
        } else{
            if(r-l==1){
                return((r<m)?r:-1);
            } else{
                l = mid;
            }
        }
    }
    return(mid);
}

void iterative_search(int x){
    int c=0; //column
    for(; c<m && mat[0][c]<x; c++){}
    if(c==m){
        minimi[0]=-1;
        c--;
    } else{
        minimi[0]=c;
    }

    for(int r=1/*row*/; r<n; r++){
        while(c>=0 && mat[r][c]>=x){c--;}
        if(c==m-1){
            minimi[r]=-1;
        } else{
            c++;
            minimi[r]=c;
        }
    }
}

int main(){
    while(cin>>n>>m){
        if(n==0 && m==0){
            break;
        }
        for(int i=0; i<n; i++){
            minimi[i]=-1;
            for(int j=0; j<m; j++){
                cin >> mat[i][j];
            }
        }
        cin >> q;
        int mn, mx;
        for(int qq=0; qq<q; qq++){
            cin >> mn >> mx;
            iterative_search(mn);
            for(int row=0; row<n; row++){
                minimi[row] = binary_search(row, mn);
            }

            int i=0, size=0;
            while(i<n){
                if( minimi[i]!=-1 && i+size<n && minimi[i]+size < m){
                    if( mat[i+size][minimi[i]+size] <= mx ){
                        size++;
                    } else{
                        i++;
                    }
                } else{
                    i++;
                }
            }
            cout << size << endl;
        }
        cout << "-\n";
    }    
return(0);
}