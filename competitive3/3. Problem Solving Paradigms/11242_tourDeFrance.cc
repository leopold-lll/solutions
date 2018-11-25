//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2183
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>

typedef long long ll;

int front[10], rear[10];

int main(){
    int n_front, n_rear;
    while(cin>>n_front){
        if(n_front==0){break;}
        cin>>n_rear;
        for(int i=0; i<n_front; i++){
            cin>>front[i];
        }
        for(int i=0; i<n_rear; i++){
            cin>>rear[i];
        }
        vector<float> ratio;
        for(int i=0; i<n_front; i++){
            for(int j=0; j<n_rear; j++){
                ratio.push_back(rear[j]*1.0/front[i]);
            }
        }
        sort(ratio.begin(), ratio.end());
        float max=0.0, tmp;
        //cout << ratio[0];
        for(int i=1; i<ratio.size(); i++){
            //cout << " " << ratio[i];
            tmp = ratio[i]*1.0/ratio[i-1];
            max = ((tmp>max)?tmp:max);
        }
    cout << setprecision(2) << fixed << round(max*100)/100 << endl;
    }
return(0);
}