//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=514

// la soluzione è così e non migliore perché stavo impazzendo...
using namespace std;

#include <iostream>
#include <cmath>

int main(){
    int h, u, d, f;
    double lvl, inc, dec, dd;
    while(cin>>h>>u>>d>>f){
        if(h==0){break;}
        lvl=0.0;
        dec=u*1.0*(f/100.0);
        inc= u*1.0;
        dd = d*1.0;
        //cout << "inc: " << inc << " dd: " << dd << endl;

        for(int i=1; ; i++){
            lvl = lvl + inc;
            //cout << "day: " << i << " dì: " << lvl;
            inc -= dec;
            if(inc<0.0){
                inc=0.0;
            }
            if(lvl>h*1.0){
                cout << "success on day " << i << endl;
                break;
            }
            lvl -= dd;
            //cout << " notte: " << lvl << endl;
            if(lvl<0.0){
                cout << "failure on day " << i << endl;
                break;
            }
        }
    }
return(0);
}