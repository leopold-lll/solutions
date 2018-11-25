//Problem: 11085
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2026
using namespace std;

#include <iostream>
#include <algorithm>

typedef long long ll;

int pos[8], rows[8];

int main(){
    int a, t=1;
    while(cin>>a){
        pos[0]=a-1;
        rows[0]=0;
        for(int i=1; i<8; i++){
            cin >> pos[i];
            pos[i]--;
            rows[i] = i;
        }
        ll ld, rd, m_ld, m_rd; //left/right diagonal
        bool broken;
        int dist, min_dist=100;
        do{
            //lf = col+row, rd = col-row+7
            ld = 0; //2e15-1
            rd = 0; //2e15-1
            broken = false;
            dist = 0;
            for(int i=0; i<8 && !broken; i++){

                // check with bitmask O(1)
                m_ld = i+rows[i];
                if( ld & (1<<m_ld) ){
                    broken = true;
                } else{
                   ld |= (1<<m_ld); 
                }
                
                m_rd = i-rows[i]+7;
                if( rd & (1<<m_rd) ){
                    broken = true;
                } else{
                   rd |= (1<<m_rd); 
                }//*/
                
                /*/ check with distance the other queens O(8)
                for(int j=0; j<i; j++){
                    if( abs(i-j) == abs(rows[i]-rows[j]) ){
                        broken = true;
                    }
                }//*/

                //I have a true queen position
                dist += ((abs(pos[i] - rows[i])>0) ? 1:0 );
            }
            if(!broken && dist<min_dist){
                min_dist = dist;
            }
        } while(next_permutation(rows, rows+8));
        cout << "Case " << t << ": " << min_dist << endl;
        t++;
    }    
return(0);
}