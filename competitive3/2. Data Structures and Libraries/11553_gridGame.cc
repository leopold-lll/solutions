//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2548
#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

int m[9][9];

int main() {
    int T;
    cin>>T;
    for(int t=0;t<T;t++) {
        int N; cin>>N;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin>>m[i][j];
            }
        }
        vector<int> v;
        for(int i=0;i<N;i++)v.push_back(i);
        int res = 0;
        for(int i=0;i<N;i++) res+=m[i][v[i]];
        while(next_permutation(v.begin(), v.end())) {
            int s = 0;
            for(int i=0;i<N;i++) s+=m[i][v[i]];
            res = min(s, res);
        }
        cout<<res<<endl;
    }
    return 0;
}