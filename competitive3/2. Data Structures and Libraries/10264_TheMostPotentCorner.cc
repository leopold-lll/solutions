//Problem: 10264
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1205
using namespace std;

#include <iostream>
#include <cmath>

typedef long long ll;

int weight[32768];  // 2e15=32768
int potency[32768];


int main(){
    int n;
    while(cin>>n){
        ll corners = pow(2, n);
        for(int i=0; i<corners; i++){
            cin >> weight[i];
            potency[i]=0;
        }
        int el;
        for(int i=0; i<corners; i++){
            for(int j=0; j<n; j++){
                // change the bit j
                el = i ^ (1<<j); //xor(i, 1<<j)
                potency[i] += weight[el];
            }
            //cout << potency[i] << endl;
        }
        ll mx = 0, tmp;
        for(int i=0; i<corners; i++){
            for(int j=0; j<n; j++){
                // change the bit j
                el = i ^ (1<<j); //xor(i, 1<<j)
                tmp = potency[i]+potency[el];
                if(tmp>mx){
                    mx = tmp;
                }
            }
        }
        cout << mx << endl;
    }
return(0);
}