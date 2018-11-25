//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2493
using namespace std;

#include <iostream>

typedef long long ll;

int main(){
    int k;
    ll xx, yy, x, y;
    while(cin >> k){
        if(k==0){break;}
        cin >> xx >> yy;
        for(int i=0; i<k; i++){
            cin>>x>>y;
            if(x==xx || y==yy){
                cout << "divisa\n";
            } else{
                if(y>yy){
                    if(x<xx){cout<<"NO\n";}
                    else{cout<<"NE\n";}
                } else{
                    if(x<xx){cout<<"SO\n";}
                    else{cout<<"SE\n";}
                }
            }
        }
    }
return(0);
}