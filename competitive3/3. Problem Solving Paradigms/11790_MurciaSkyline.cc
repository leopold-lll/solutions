//Problem: 11790
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2890
using namespace std;

#include <iostream>
#include <vector>

typedef long long ll;

vector<int> height;
vector<int> width;
vector<ll> ls;

int lis(){
    ls.resize(0);
    int mx = 0, n=height.size();
    for(int i=0; i<n; i++){
        ls.push_back(width[i]);
        for(int j=0; j<i; j++){
            if(height[j]<height[i] && ls[j]+width[i] > ls[i]){
                ls[i] = ls[j]+width[i];
            }
        }
        if(ls[i]>mx){
            mx=ls[i];
        }
    }
    return(mx);
}

int lds(){
    ls.resize(0);
    int mx = 0, n=height.size();
    for(int i=0; i<n; i++){
        ls.push_back(width[i]);
        for(int j=0; j<i; j++){
            if(height[j]>height[i] && ls[j]+width[i] > ls[i]){
                ls[i] = ls[j]+width[i];
            }
        }
        if(ls[i]>mx){
            mx=ls[i];
        }
    }
    return(mx);
}

int main(){
    int test, N;
    cin >> test;
    for(int t=0; t<test; t++){
        cin>>N;
        int c;
        for(int i=0; i<N; i++){
            cin >> c;
            height.push_back(c);   
        }
        for(int i=0; i<N; i++){
            cin >> c;
            width.push_back(c);   
        }

        ll max_lis = lis();
        ll max_lds = lds();

        if(max_lis>=max_lds){
            cout << "Case " << t+1 << ". Increasing (" << max_lis << "). Decreasing (" << max_lds << ").\n";
        } else{
            cout << "Case " << t+1 << ". Decreasing (" << max_lds << "). Increasing (" << max_lis << ").\n";
        }

        height.resize(0);
        width.resize(0);
    }

return(0);
}