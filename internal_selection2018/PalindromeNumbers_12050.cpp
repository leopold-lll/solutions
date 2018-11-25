//Problem: 12050 -> solved
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3202
using namespace std;

#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

int main() {
    ofstream out ("output.txt");

    int n;
    while(cin >> n){
        if(n==0){
            break;
        } else if(n<10){
            cout << n << endl;
        } else{
            int digits=1, k=9;
            // calculate the number of digits
            while(n>=k){
                n-=k;
                digits++;
                if(n<k){
                    break;
                }
                n-=k;
                k*=10;
                digits++;
            }
            // digits_l the first digit up to the center of palindrome
            int digits_l = (digits+1)/2;
            //cout << endl << digits  << " " << digits_l << endl;

            // calculate the number
            int * num = new int[digits_l];
            for(int i=digits_l-1; i>=0; i--){
                num[i] = n%10;
                n/=10;
            }
            num[0]++;
            num[digits_l-1]--;

            // check particular case: 798 -> 7 0 -1 0 7 -> 7 9 9 9 7 
            
            if(num[digits_l-1]==-1){
                num[digits_l-1]=9;
                for(int i=digits_l-2; i>=0; i--){
                    if(num[i]>0){
                        if(i==0 && num[i]==1){
                            // questa è una pessima gestione di un caso che più particolare non si può, ossia: 198 - 1998 - 10998 e altri...
                            num[0]=9;
                            digits_l--;
                            cout << '9';
                            out << '9';
                        } else{
                            num[i]--;
                        }
                        break;
                    } else{
                        num[i]=9;
                    }
                }
            }


            // print the number
            for(int i=0; i<digits_l; i++){
                cout << num[i];
                out << num[i];
            }
            if(digits%2==1){
                digits_l--;
            }
            for(int i=digits_l-1; i>=0; i--){
                cout << num[i];
                out << num[i];
            }
            cout << endl;
            out << endl;
        }
    }
return(0);
}

/*
input:
1
12
24
798
888
117977708
0

output:
1
33
151
69996
78987
1797770990777971

caso pessimo:
10997
10998
10999
197
198
199
1997
1998
1999

sol caso pessimo:
9998999
9999999
10000001
9889
9999
10001
998899
999999
1000001
*/