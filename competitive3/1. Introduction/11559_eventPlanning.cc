//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2595
using namespace std;

#include <iostream>
#include <cmath>

typedef long long ll;

int main(){
    ll n, b, h, w;
    ll cost, price, beds;
    bool available;
    while(cin>>n>>b>>h>>w){
        cost=b+1;
        for(int i=0; i<h; i++){
            cin >> price;
            available = false;
            for(int j=0; j<w; j++){
                cin >> beds;
                if(beds>=n){
                    available=true;
                }
            }
            if(available){
                cost = min(cost, n*price);
            }
        }
        if(cost<=b){cout<<cost<<endl;}
        else{cout<<"stay home\n";}
    }
return(0);
}