//Problem: 11572
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2619
using namespace std;

#include <iostream>
#include <set>
#include <vector>

typedef long long ll;

int main(){
    set<ll> flakes;
    vector<ll> lasts;
    int test;
    cin >> test;
    for(int t=0; t<test; t++){
        int n, c;
        cin >> n;

        int mx = 0;
        for(int i=0; i<n; i++){
            cin >> c;
            if(flakes.count(c)){
                //cout << "reset thx to:" << c << " len now:" << flakes.size();
                mx = (mx>=flakes.size() ? mx : flakes.size());
                flakes.clear();
                //cout << " last len:" << lasts.size();
                for(int j=lasts.size()-1; j>=0 && lasts[j]!=c; j--){
                    flakes.insert(lasts[j]);
                }
                //cout << " after len:" << flakes.size() << endl;
            }
            lasts.push_back(c);
            flakes.insert(c);
        }
        mx = (mx>=flakes.size() ? mx : flakes.size());
        cout << mx << endl;

        flakes.erase(flakes.begin(), flakes.end()); // AKA flakes.clear()
        lasts.resize(0);
    }
return(0);
}