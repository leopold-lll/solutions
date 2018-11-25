//Problem: 10550
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1491
using namespace std;

#include <iostream>

int diff(int a, int b){
    if(a>=b){
        return(a-b);
    } else{
        return(40+a-b);
    }
}

int main(){
    int init, a, b, c, step;
    while(cin>>init>>a>>b>>c){
        if(init==0 && a==0 && b==0 && c==0){break;}
        step = 0;
        step += 2*40 + diff(init, a);
        step += 40 + diff(b, a);
        step += diff(b, c);
        step *= 9;
        cout << step << endl;
    }
return(0);
}