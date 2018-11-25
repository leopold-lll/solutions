//Problem: 599
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=540
using namespace std;

#include <iostream>
#include <string>

int main(){
    int test;
    cin >> test;
    char c;
    cin>>c;
    for(int t=0; t<test; t++){
        int V[26] = {};
        int node=0, edge=0, acorn=0, tree=0;
        while(c!='*'){
            edge++;
            cin>>c;
            V[c-'A']++;
            cin>>c; cin>>c;
            V[c-'A']++;
            cin>>c; cin>>c;
        }
        string str;
        getline(cin, str);
        cin>>c;
        while('A'<=c && c<='Z'){
            node++;
            if(V[c-'A']==0){
                acorn++;   
            }
            c='.';
            if(cin>>c){
                if(c==','){
                    cin>>c;
                }// else if(c=='('){}
            }            
        }
        tree = node-edge-acorn;
        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
    }    
return(0);
}