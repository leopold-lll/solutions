//Problem:11157
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2098
using namespace std;

#include <iostream>

typedef long long ll;

int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        int N, D, leap, d, d_prec, d_prec2;
        char stone, ignore;
        cin >> N >> D;
        if(N==0){
            cout << "Case " << t << ": " << D << endl;
        } else{
            leap = 0;
            d_prec = 0;
            d_prec2 = 0;
            for(int x=0; x<N; x++){
                cin >> stone >> ignore >> d;
                leap = max(leap, d-d_prec);
                //cout << "1 leap: " << leap << endl;
                d_prec2 = d_prec;
                d_prec = d;
                if(stone=='S'){
                    for(x=x+1; x<N && stone=='S'; x++){
                        cin >> stone >> ignore >> d;
                        leap = max(leap, d-d_prec2);
                        //cout << "2 leap: " << leap << endl;
                        if(stone=='S'){
                            d_prec2 = d_prec;
                        } else{
                            leap = max(leap, d-d_prec);
                            //cout << "3 leap: " << leap << endl;
                        }
                        d_prec = d;
                    }
                    if(x!=N){
                        x--;
                    }
                }
            }
            leap = max(leap, D-d);
            //cout << "4 leap: " << leap << endl;
            if(stone=='S'){
                leap = max(leap, D-d_prec2);
                //cout << "5 leap: " << leap << endl;
            }
            cout << "Case " << t << ": " << leap << endl;
        }
    }
return(0);
}