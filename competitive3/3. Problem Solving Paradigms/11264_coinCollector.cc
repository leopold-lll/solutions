//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2231
using namespace std;

#include <iostream>

typedef long long ll;

int main(){
    int T;
    cin>>T;
    for(int t=0; t<T; t++){
        int n, c, last_c, sum, deleted=0;
        cin>>n;
        cin>>last_c;
        sum = last_c;
        for(int i=1; i<n; i++){
            cin>>c;
            if(sum>=c){;
                deleted++;
                sum = sum - last_c + c;
                //cout << "delete c:" << c << endl;
            }  else{
                sum += c;
            }
            last_c = c;
        }
        cout << n-deleted << endl;
    }
return(0);
}