//problem 146
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=82

using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    string str;
    while(cin>>str){
        if(str=="#"){break;}
        if(next_permutation(str.begin(), str.end())){
            cout << str << endl;
        } else{
            cout << "No Successor\n";
        }
    }
return(0);
}