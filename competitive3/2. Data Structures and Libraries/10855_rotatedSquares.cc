// problem 10855
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1796

//________________________________________________________________________________________________________________
//solve all the debug input but don't do the submission...
//________________________________________________________________________________________________________________

using namespace std;

#include <iostream>

typedef long long ll;
const ll match[26] = {101, 137, 157, 179, 197, 227, 241, 269, 283, 313, 347, 367, 389, 401, 421, 443, 467, 487, 503, 541, 571, 587, 601, 619, 653, 661};

ll countIN =0, countOUT=0;
int main(){
    ll N, n;
    while(cin >> N >> n){
        if(N==0 && n==0){
            break;
        }
        ll **mat_sum = new ll*[N];
        ll **MAT = new ll*[N];
        ll **mat = new ll*[n];
        // input big matrix
        char c;
        for(ll i=0; i<N; i++){
            MAT[i] = new ll[N];
            mat_sum[i] = new ll[N];
            for(ll j=0; j<N; j++){
                cin >> c;
                MAT[i][j] = match[c-'A'];
                if(i==0 && j==0){
                    mat_sum[i][j] = match[c-'A'];
                } else if(i==0){
                    mat_sum[i][j] = match[c-'A'] + mat_sum[i][j-1];
                } else if(j==0){
                    mat_sum[i][j] = match[c-'A'] + mat_sum[i-1][j];
                } else{
                    mat_sum[i][j] = match[c-'A'] + mat_sum[i-1][j] + mat_sum[i][j-1] - mat_sum[i-1][j-1];
                }
            }
        }

        // input little matrix
        ll sum = 0;
        for(ll i=0; i<n; i++){
            mat[i] = new ll[n];
            for(ll j=0; j<n; j++){
                cin >> c;
                mat[i][j] = match[c-'A'];
                sum += match[c-'A'];
            }
        }

        // look for possible matching
        ll find[4] = {0, 0, 0, 0};
        bool end;
        for(ll i=0; i<=(N-n); i++){
            for(ll j=0; j<=(N-n); j++){
                ll tmp_sum = mat_sum[i+n-1][j+n-1];
                if(i>0 && j>0){
                    tmp_sum += mat_sum[i-1][j-1] - mat_sum[i+n-1][j-1] - mat_sum[i-1][j+n-1];
                } else if(i>0){
                    tmp_sum -= mat_sum[i-1][j+n-1];
                } else if(j>0){
                    tmp_sum -= mat_sum[i+n-1][j-1];
                }
                countOUT++;
                if(sum == tmp_sum){
                    countIN++;
                    //check matrix
                    for(ll f=0; f<4; f++){
                        find[f]++;
                    }
                    // degree 0°
                    for(ll x1=0, end=false; x1<n && !end; x1++){
                        for(ll x2=0; x2<n && !end; x2++){
                            if(mat[x1][x2] != MAT[x1+i][x2+j]){
                                find[0]--;
                                end = true;
                            }   
                        }
                    }
                    // degree 90°
                    for(ll x1=0, end=false; x1<n && !end; x1++){
                        for(ll x2=0; x2<n && !end; x2++){
                            if(mat[n-1-x2][x1] != MAT[x1+i][x2+j]){
                                find[1]--;
                                end = true;
                            }         
                        }
                    }
                    // degree 180°
                    for(ll x1=0, end=false; x1<n && !end; x1++){
                        for(ll x2=0; x2<n && !end; x2++){
                            if(mat[n-1-x1][n-1-x2] != MAT[x1+i][x2+j]){
                                find[2]--;
                                end = true;
                            }                                     
                        }
                    }
                    // degree 270°
                    for(ll x1=0, end=false; x1<n && !end; x1++){
                        for(ll x2=0; x2<n && !end; x2++){
                            if(mat[x2][n-1-x1] != MAT[x1+i][x2+j]){
                                find[3]--;
                                end = true;
                            }         
                        }
                    }
                }
            }
        }
        // print output
        for(ll f=0; f<4; f++){
            cout << find[f] << " ";
        }
        cout << "\b\n";
    }
    //cout << endl << "IN/OUT: " << countIN*100.0/countOUT << endl;
return(0);
}