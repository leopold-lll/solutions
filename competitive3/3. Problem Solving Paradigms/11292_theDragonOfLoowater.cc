//Problem: 11292
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2267
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

vector<int> heads, heights;

int main(){
    ll sum;
    int n, m, tmp;
    while(cin >> n >> m){
        if(n==0 && m==0){break;}
        for(int i=0; i<n; i++){
            cin >> tmp;
            heads.push_back(tmp);
        }
        for(int i=0; i<m; i++){
            cin >> tmp;
            heights.push_back(tmp);
        }
        if(m<n){
            cout << "Loowater is doomed!\n";
        } else{
            sort(heads.begin(), heads.end());
            sort(heights.begin(), heights.end());

            sum=0;
            int j=0;
            bool end, doom = false;
            for(int i=0; i<n && !doom; i++){
                end=false;
                for(; j<m && !end; j++){
                    if(heights[j]>=heads[i]){
                        end=true;
                        sum += heights[j];
                    }
                }
                if(j==m && !end){
                    doom = true;
                }
            }
            if(doom){
                cout << "Loowater is doomed!\n";
            } else{
                cout << sum << endl;
            }
            heads.resize(0);
            heights.resize(0);
        }
    }

return(0);
}