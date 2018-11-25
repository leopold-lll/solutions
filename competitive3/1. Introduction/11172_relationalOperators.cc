//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2113
using namespace std;

#include <iostream>

typedef long long ll;

int main(){
    ll t, a, b;
    cin >> t;
    for(int x=0; x<t; x++){
        cin >> a >> b;
        if(a==b){
            cout << "=\n";
        } else if(a<b){
            cout << "<\n";
        } else{
            cout << ">\n";
        }
    }
return(0);
}