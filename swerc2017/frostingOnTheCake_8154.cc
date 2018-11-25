//problem 8154
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=783&problem=6176&mosmsg=Submission+received+with+ID+2462938

using namespace std;

#include <iostream>

int main(){
    int n, x;
    long long unsigned int a [3];
    long long unsigned int b [3];
    long long unsigned int yellow, white, pink;
    while(cin >> n){
        // initialization
        for(int i=0; i<3; i++){
            a[i]=0;
            b[i]=0;
        }
        // load and compress input
        for(int i=0; i<n; i++){
            cin >> x;
            a[i%3]+=x;
        }
        for(int i=0; i<n; i++){
            cin >> x;
            b[i%3]+=x;
        }
        // compute output
        yellow = a[1]*b[0] + a[0]*b[1] + a[2]*b[2];
        pink   = a[2]*b[0] + a[1]*b[1] + a[0]*b[2];
        white  = a[0]*b[0] + a[2]*b[1] + a[1]*b[2];

        cout << yellow << " " << pink << " " << white << endl;
    }
return(0);
}

/*

input:
3
1 1 1
1 1 1
7
6 2 4 5 1 1 4
2 5 1 4 2 3 4

output:
3 3 3
155 131 197

*/