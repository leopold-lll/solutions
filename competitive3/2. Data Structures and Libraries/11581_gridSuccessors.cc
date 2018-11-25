//problem 11581
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2628

using namespace std;

#include <iostream>

int mat[3][3];
int support[5][5];

void print(){
    /*for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
}

int sum(){
    int res = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            res += mat[i][j];
        }
    }
    return(res);
}

void update(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            support[i+1][j+1] = mat[i][j];
        }
    }
    int ii, jj;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ii = i+1;
            jj = j+1;
            mat[i][j] = (support[ii+1][jj] + support[ii-1][jj] + support[ii][jj+1] + support[ii][jj-1]) % 2;
        }
    }
}

int main(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            support[i][j] = 0;
        }
    }

    bool find;
    int n;
    cin >> n;
    for(int q=0; q<n; q++){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                char c;
                cin >> c;
                mat[i][j] = c-'0';
            }
        }
        print();
        if(sum()==0){
            cout << "-1\n";
        } else{
            find = false;
            for(int x=0; x<512 && !find; x++){
                update();
                print();
                if(sum()==0){
                    cout << x << endl;
                    find = true;
                }
            }
            if(!find){
                cout << "-1\n";
            }
        }
    }
return(0);
}