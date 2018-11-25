//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=676
using namespace std;

#include <iostream>

typedef long long ll;
const int len=43;
int v[len] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};

int main(){
    int n;
    while(cin>>n){
        if(n<=0){break;}
        int c=0, p=0;
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){
                for(int k=j; k<len; k++){
                    if(v[i]+v[j]+v[k]==n){
                        c++;
                        if(v[i]==v[j] && v[i]==v[k]){
                            p++;
                        } else if(v[i]==v[j] || v[i]==v[k] || v[k]==v[j]){
                            p+=3;
                        } else{
                            p+=6;
                        }
                    }
                }
            }
        }
        if(c==0){
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
        } else{
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << c << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << p << ".\n";
        }
        cout << "**********************************************************************\n";
    }
    cout << "END OF OUTPUT\n";
return(0);
}