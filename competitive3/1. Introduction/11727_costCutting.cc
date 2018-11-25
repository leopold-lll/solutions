//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2827
using namespace std;

#include <iostream>

typedef long long ll;

int main(){
    int t, a, b, c, max, min;
    cin>>t;
    for(int i=0; i<t; i++){
        cout << "Case " << i+1 << ": ";
        cin>>a>>b>>c;
        if(a>b){
            max=a;
            min=b;
        } else{
            max=b;
            min=a;
        }
        if(c>max){
            cout<<max<<endl;
        } else if(c<min){
            cout<<min<<endl;
        } else{
            cout<<c<<endl;
        }
    }
return(0);
}