//Problem: 11933
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3084
using namespace std;

#include <iostream>

typedef long long ll;

int main(){
    int n, a, b;
    while(cin>>n){
        if(n==0){break;}
        a=0;
        b=0;
        while(n!=0){
            a += n & (-n);  //add last true bit to a
            n &= (n-1);     //remove last true bit from n
            if(n!=0){
                b += n & (-n);
                n &= (n-1);     
            }
        }
        cout << a << " " << b << endl;
    }
return(0);
}