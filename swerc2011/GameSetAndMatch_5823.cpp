//Problem: 5823 -> solved
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3834

using namespace std;

#include <iostream>
#include <cmath>
#include <iomanip>

int fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

int comb(int n, int k);
double prob_result(double p, double q, int x, int y);
double prob_equal(double p, double q, int x);

int main() {
    double p, q, k;
    while (cin >> p) {
    	if(p==-1){
    		break;
    	}
    	q = 1-p;
		k = 2*p*q;
		
		double game=0.0, tie=0.0, set=0.0, match=0.0;

		// game
		for(int i=0; i<3; i++){
			game += prob_result(p, q, 4, i);
		}
		game += prob_equal(p, q, 3) * (1.0/(1.0-k))*pow(p, 2);
		cout << fixed << setprecision(11) << game << " ";

		// tie-break
		for(int i=0; i<6; i++){
			tie += prob_result(p, q, 7, i);
		}
		tie += prob_equal(p, q, 6) * (1.0/(1.0-k))*pow(p, 2);
		//cout << fixed << setprecision(11) << tie << " ";

		// sets
		for(int i=0; i<5; i++){
			set += prob_result(game, 1-game, 6, i);
		}
		double prob5_5 = prob_equal(game, 1-game, 5);
		set += prob5_5 * pow(game, 2);	//7-5
		set += (prob5_5 * game * (1-game) * comb(2, 1)) * tie;	//8-6
		cout << fixed << setprecision(11) << set << " ";

		// match
		match += pow(set, 2);	//2-0
		match += prob_result(set, 1-set, 2, 1);
		cout << fixed << setprecision(11) << match << "\n";
    }
return(0);
}

int comb(int n, int k){
	if(n>12 || k>12){
		return(-1);
	}
	return(fact[n]/(fact[n-k]*fact[k]));
}

double prob_result(double p, double q, int x, int y){//p:prob victory, q=prob lose, x=result player X, y=result player Y
	double res = (pow(p, x-1) * pow(q, y) * comb(x+y-1, x-1)) * p;
	return(res);
}
double prob_equal(double p, double q, int x){//p:prob victory, q=prob lose, x=result player X and Y
	double res = pow(p, x) * pow(q, x) * comb(x+x, x);
	return(res);
}