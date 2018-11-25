//Problem: 10507
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1448
using namespace std;

// follows a very bad code...

#include <iostream>
#include <vector>

vector<vector<int> > graph;
int V[26];

int main(){
    int n, m;
    while(cin>>n){
        cin>>m;
        //check isolated nodes
        for(int i=0; i<26; i++){
            V[i]=-1;
            vector<int> vi;
            graph.push_back(vi);
        }

        char c;
        for(int i=0;i<3;i++){
            cin>>c;
            V[c-'A']=1;
        }

        char aa, bb;
        int a, b;
        for(int i=0; i<m; i++){
            cin>>aa>>bb;
            a = aa-'A'; b = bb-'A';
            if(V[a]==-1){V[a]=0;}
            if(V[b]==-1){V[b]=0;}
            graph[a].push_back((int)b);
            graph[b].push_back((int)a);
        }

        bool never = false;
        int wake=3, years=0;
        vector<int> waking;
        while(wake<n && !never){
            for(int i=0; i<26; i++){
                if(V[i]==0){
                    int count = 0;
                    for(int j=0; j<graph[i].size(); j++){
                        if(V[graph[i][j]]==1){
                            count++;
                        }
                    }
                    if(count >= 3){
                        waking.push_back(i);
                    }
                }
            }
            if(waking.size()==0){
                never = true;
            } else{
                wake+=waking.size();
                for(int i=0; i<waking.size(); i++){
                    V[waking[i]] = 1;
                }
                waking.resize(0);
                years++;
            }
        }
        graph.resize(0);

        if(never){
            cout << "THIS BRAIN NEVER WAKES UP\n";
        } else{
            cout << "WAKE UP IN, " << years << ", YEARS\n";
        }
    }  
return(0);
}