//Problem: 10827
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1768
using namespace std;

#include <iostream>

typedef long long ll;

int mat[226][226];
int matSum[226][226];

int main(){
    int test, n, tmp;
    cin >> test;
    for(int t=0; t<test; t++){
        cin >> n;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0){
                    mat[i][j] = 0;
                } else{
                    cin >> tmp;
                    for(int x=0; x<3; x++){
                        for(int y=0; y<3; y++){
                            mat[i+x*n][j+y*n] = tmp;
                        }
                    }
                }
            }
        }

        for(int i=0; i<=n*3; i++){
            for(int j=0; j<=n*3; j++){
                if(i==0 || j==0){
                    matSum[i][j] = 0;
                } else{
                    matSum[i][j] = mat[i][j] + ( matSum[i-1][j] + matSum[i][j-1] - matSum[i-1][j-1] );
                }
            }
        }

        ll max_sum=0, sum;
        for(int i=1; i<=n*3; i++){
            for(int j=1; j<=n*3; j++){

                for(int x=i; x<=n*3 && x<i+n; x++){
                    for(int y=j; y<=n*3 && y<j+n; y++){
                        sum = matSum[x][y] - matSum[x][j-1] - matSum[i-1][y] + matSum[i-1][j-1];
                        max_sum = max(max_sum, sum);
                    }
                }
            }
        }
        cout << max_sum << endl;
    }
return(0);
}