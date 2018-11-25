//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2899
using namespace std;

#include <iostream>

typedef long long ll;

int main(){
    ll t, n, max, s;
    cin >> t;
    for(int q=0; q<t; q++){
        cin>>n;
        max=0;
        for(int x=0; x<n; x++){
            cin>>s;
            if(s>max){max=s;}
        }
        cout << "Case " << q+1 << ": " << max << endl;
    }
return(0);
}