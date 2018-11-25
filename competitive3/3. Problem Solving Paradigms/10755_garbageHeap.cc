//Problem: 10755
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1696
using namespace std;

#include <iostream>

typedef long long ll;

ll mat[21][21][21];

int main(){
    int T, A, B, C;
    cin>>T;
    for(int t=0; t<T; t++){
        cin>>A>>B>>C;
        ll tmp;
        for(int i=0; i<=A; i++){
            for(int j=0; j<=B; j++){
                for(int k=0; k<=C; k++){
                    if(i==0||j==0||k==0){
                        mat[i][j][k] = 0;
                    } else{
                        cin >> tmp;
                        mat[i][j][k] = tmp + (mat[i-1][j][k] + mat[i][j-1][k] - mat[i-1][j-1][k]) + (mat[i][j][k-1] - mat[i-1][j][k-1] - mat[i][j-1][k-1] + mat[i-1][j-1][k-1]);
                    }
                    //cout << mat[i][j][k] << " ";
                }
                //cout << endl;
            }
            //cout << endl << endl;
        }

        ll max_value = mat[A][B][C];
        for(int i=1; i<=A; i++){
            for(int j=1; j<=B; j++){
                for(int k=1; k<=C; k++){

                    for(int ii=i; ii<=A; ii++){
                        for(int jj=j; jj<=B; jj++){
                            for(int kk=k; kk<=C; kk++){
                                tmp = (mat[ii][jj][kk] - mat[i-1][jj][kk] - mat[ii][j-1][kk] + mat[i-1][j-1][kk]) - (mat[ii][jj][k-1] - mat[i-1][jj][k-1] - mat[ii][j-1][k-1] + mat[i-1][j-1][k-1]);
                                max_value = max(max_value, tmp);
                            }
                        }
                    }

                }
            }
        }
        cout << max_value << endl;
        if(t<T-1){  // without this condition UVa gives presentation error
            cout << endl;
        }
    }
return(0);
}