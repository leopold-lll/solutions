//Problem:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4965
// written by giulia

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ll prime_n[1000000];

bool prime[10000001];

// int k=0;

// bool Miller(ll p,int iteration);

void SieveOfEratosthenes(ll n) { 
    // cout << "in sieve" << endl;
    memset(prime,1,sizeof(prime));
    for (int p=2; p*p<=n; p++) { 
        if (prime[p] == true) {
            // prime_n[k] = p;
            // k++;
            for (int i=p*2; i<=n; i += p) {
                prime[i] = false; 
            }
        } 
    }
}
/*
bool isPrime(long long n) {
    // cout << "check primality\n";
    long long lim = sqrt(n) + 1;
    for(long long i=prime_n[k++]; i < lim;) {
        if(n%i==0) {
            k = 0;
            return false;
        }
        if (i < 3137) {
            i = prime_n[k++];
        } else {
            i+=2;
        }
    }
    k = 0;
    return true; 
} 
*/
int main() {
    long long n,customers;
    SieveOfEratosthenes(10000001);
    cin >> n;
    while (n != 1) {
        // k=0;
        customers = 0;
        ll lim = sqrt(n)+1;
        for (int i=2; i < lim; i++) {
            // cout << i << endl;
            if (prime[i]) {
                while (n%i == 0) {
                    customers++;
                    n/=i;
                }
            }
        }
        if (n>1) customers++;
        cout << customers << endl;
        cin >> n;
    }
   return 0;
}