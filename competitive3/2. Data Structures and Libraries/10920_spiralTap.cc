// problem 10920
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1861

using namespace std;

#include <iostream>
#include <cmath>

typedef long long ll;

void print(ll a, ll b){
    cout << "Line = " << a << ", column = " << b << ".\n";
}

int main(){
    ll s, n;
    double sq;
    ll ring, pos, side, center, far, dist;
    while(cin >> s >> n){
        center = (s+1)/2;
        if(s==0 && n==0){
            break;
        } else if(n > pow(s,2)){
            cout << "error\n";
        } else if(n==1){
            print(center, center);
        } else{
            sq = sqrt(n);
            ring = (ll)ceil(sq);
            if(ring%2==0){
                ring++;
            }

            pos = n - pow(ring-2, 2);

            side = (pos-1) / (ring-1);
            pos = (pos-1) % (ring-1);
            far = (ring-1)/2;
            dist = far-1-pos;
            switch(side){
                case 0: print(center+far, center+dist); break;
                case 1: print(center+dist, center-far); break;
                case 2: print(center-far, center-dist); break;
                case 3: print(center-dist, center+far); break; 
                default:
                    cout << "Why? " << side << " " << pos << " " << far << " " << dist << endl;           
            }
        }
    }
return(0);
}