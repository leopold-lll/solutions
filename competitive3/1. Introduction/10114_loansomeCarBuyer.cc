//Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1055
using namespace std;

#include <iostream>

typedef long long ll;

int main(){
    int months, n_rate, m;
    double down, loan, rate, car, depr;
    bool end;
    while(cin>>months>>down>>loan>>n_rate){
        if(months<=0){break;}
        end=false;
        rate = loan/months; //rate of the loan

        // load the deprecations of the car
        int * r_mon = new int[n_rate+1];
        double * r_depr = new double[n_rate+1];
        for(int i=0; i<n_rate; i++){
            cin>>m>>depr;
            r_mon[i]=m;
            r_depr[i]=depr;
        }
        r_mon[n_rate]=months+1; //manage strange corner case

        car = (loan+down)*(1.0-r_depr[0]);
        //cout << loan << " " << car << endl;
        if(car>loan){   //impossible??? IDK
            cout<<"0 months\n";
            end=true;
        }

        for(int i=1, indx_depr=0; i<=months && !end; i++){
            //update deprectaion rate of car
            if(i==r_mon[indx_depr+1]){
                indx_depr++;
                //cout << "increase to: "<< r_mon[indx_depr] << endl;
            }

            //update value
            loan -= rate;
            car *= (1-r_depr[indx_depr]);
            //cout << "\t" << loan << " " << car << endl;
            if(car>loan){
                if(i==1){cout<<"1 month\n";}
                else{cout<<i<<" months\n";}
                end=true;
            }
        }
        if(!end){cout<<months<<"months\n";}//is it possible??? IDK
    }
return(0);
}