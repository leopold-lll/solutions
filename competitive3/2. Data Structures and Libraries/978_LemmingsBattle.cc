//Problem: 978
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=919
using namespace std;

#include <iostream>
#include <vector>
#include <queue>

int main(){
    int test;
    cin >> test;
    for(int t=0; t<test; t++){

        //initialization
        vector<short> newG, newB;
        priority_queue<short> green, blue;
        int field, ng, nb, c;
        cin >> field >> ng >> nb;

        //cout << "green team: ";
        for(int i=0; i<ng; i++){
            cin >> c;
            //cout << c << " ";
            green.push(c);   
        }
        //cout << "\nblue team: ";
        for(int i=0; i<nb; i++){
            cin >> c;
            //cout << c << " ";
            blue.push(c);   
        }
        //cout << endl << endl;

        // until the end
        while(green.size()!=0 && blue.size()!=0){
            short g, b;
            bool end = false;
            //for each battlefield
            for(int i=0; i<field && !end; i++){
                if(green.size()!=0 && blue.size()!=0){
                    g = green.top();
                    green.pop();
                    b = blue.top();
                    blue.pop();
                    //cout << "g:" << g << " b:" << b;
                    if(g>b){
                        newG.push_back(g-b);
                        //cout << " G-res:" << g-b << endl;
                    } else if(g<b){
                        newB.push_back(b-g);
                        //cout << " B-res:" << b-g << endl;
                    }
                } else{
                    end=true;
                }
            }
            //cout << endl;

            // update again race team
            //cout << "green push: ";
            for(int i=0; i<newG.size(); i++){
                //cout << newG[i] << " ";
                green.push(newG[i]);
            }
            newG.resize(0);
            //cout << "\nblue push: ";
            for(int i=0; i<newB.size(); i++){
                //cout << newB[i] << " ";
                blue.push(newB[i]);
            }
            newB.resize(0);
            //cout << endl;
        }

        // print output
        if(green.size()==0 && blue.size()==0){
            cout << "green and blue died\n";
        } else if(green.size()==0){
            cout << "blue wins\n";
            //for(int i=blue.size()-1; i>=0; i--){
            while(blue.size()!=0){
                cout << blue.top() << endl;
                blue.pop();
            }
        } else if(blue.size()==0){
            cout << "green wins\n";
            //for(int i=green.size()-1; i>=0; i--){
            while(green.size()!=0){
                cout << green.top() << endl;
                green.pop();
            }
        }
        if(t!=test-1){
            cout << endl;
        }
    }
return(0);
}