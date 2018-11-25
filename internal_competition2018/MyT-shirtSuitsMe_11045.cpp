//Problem: 11045 -> solved
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1986
using namespace std;

#include <cmath>
#include <vector>
#include <iostream>

typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 1000000000;

struct MaxFlow {
    int N;
    VVI cap, flow;
    VI dad, Q;

    MaxFlow(int N) :
        N(N), cap(N, VI(N)), flow(N, VI(N)), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap) {
        this->cap[from][to] += cap;
    }

    int BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), -1);
        dad[s] = -2;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < N; i++) {
                if (dad[i] == -1 && cap[x][i] - flow[x][i] > 0) {
                    dad[i] = x;
                    Q[tail++] = i;
                }
            }
        }

        if (dad[t] == -1) return 0;

        int totflow = 0;
        for (int i = 0; i < N; i++) {
            if (dad[i] == -1) continue;
            int amt = cap[i][t] - flow[i][t];
            for (int j = i; amt && j != s; j = dad[j])
                amt = min(amt, cap[dad[j]][j] - flow[dad[j]][j]);
            if (amt == 0) continue;
            flow[i][t] += amt;
            flow[t][i] -= amt;
            for (int j = i; j != s; j = dad[j]) {
                flow[dad[j]][j] += amt;
                flow[j][dad[j]] -= amt;
            }
            totflow += amt;
        }

        return totflow;
    }

    int GetMaxFlow(int source, int sink) {
        int totflow = 0;
        while (int flow = BlockingFlow(source, sink))
            totflow += flow;
        return totflow;
    }
};

int get_size();

int main() {

    int n_test;
    cin >> n_test;
    for(int x=0; x<n_test; x++){
        int n, m, t;
        cin >> n >> m;
        t = n/6;

        // 0=start 1=sink 2/7=t-shirt 8/8+m=person
        MaxFlow mf(2+6+m);  // take the number of node

        for(int i=0; i<6; i++){
            mf.AddEdge(i+2, 1, t);
        }

        for(int i=0; i<m; i++){
            mf.AddEdge(0, 8+i, 1);
            mf.AddEdge(8+i, 2+get_size(), 1);
            mf.AddEdge(8+i, 2+get_size(), 1);
        }
        int max_flow = mf.GetMaxFlow(0, 1);
        if(max_flow==m){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
return(0);
}

int get_size(){
    char tmp;
    cin >> tmp; 
    int size;
    switch(tmp){
        case 'S':  size=1; break;
        case 'M':  size=2; break;
        case 'L':  size=3; break;
        default: //case 'X': 
            cin >> tmp; 
            switch(tmp){
                case 'S':  size=0; break;
                case 'L':  size=4; break;
                default: //case 'X':  
                    size=5;
                    cin >> tmp;
                break;
            }
        break;
    }
    return(size);
}


/*
3
18 6
L XL
XL L
XXL XL
S XS
M S
M L
6 4
S XL
L S
L XL
L XL
6 1
L M

out:
YES
NO
YES
*/