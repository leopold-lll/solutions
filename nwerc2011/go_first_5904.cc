using namespace std;
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=528&page=show_problem&problem=3915
// compile with: g++ go_first.cc -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

#include <fstream>
#include <iostream>

int extract_gain(int N, int * arr);

int main(){
	// input
	ifstream in("input");
	int IT; //iteration
	in >> IT;
	//cout << "IT: " << IT << endl;
	int * gains = new int [IT];

	int gain; 	//max_gain_from_queue
	int N;		//size of queue
	char c;		//character read
	int * arr;	//the queue
	for (int i = 0; i < IT; i++){
		in >> N;
		/*cout << "position:\t";
		for (int k = 0; k < N; k++){
			cout << k << "\t";
		}
		cout << "\nN: " << N << " -> \t";*/
		arr = new int [N];

		// transform characters to int
		for(int j=0; j<N; j++){
			in >> c;
			if('0'<=c and c<='9'){
				arr[j] = c-'0';
			} else if('a'<=c and c<='z'){
				arr[j] = (c-'a')+10;
			} else if('A'<=c and c<='Z'){
				arr[j] = (c-'A')+36;
			} else{
				cout << "\nbad input, read: " << c << endl;
			}
			//cout << arr[j] << "\t";
		}
		//cout << endl;

		// calculate the gain from the queue, core of algorithm
		gain = extract_gain(N, arr);

		// print results
		cout << "GAIN: " << gain << endl;
		gains[i] = gain;
		delete arr;
	}
	//cout << "\nEnd of Input\n";
	in.close();

	// output
	ofstream out("output");
	// report the results on output file
	for (int i = 0; i < IT; i++){
		out << gains[i] << endl;
	}
	out.close();
return 0;
}

int extract_gain(int N, int * arr){

	int gain = 0;	// the return value

	// groups contain: [0] position of last member, [1] cardinality of group, [2] flag if already in best position or not
	int groups[62][3];	// I have at most 62 group so I use a simple array
	int last_el[62];	// in invert order the list on the position of last element from the last to the first group
	int n_group = 0;	// number of effective group

	// initialize the arrays
	for(int i=0; i<62; i++){
		groups[i][0] = -1;
		groups[i][1] = -1;	
		groups[i][2] = 0;	
		last_el[i]	 = -1;	
	}

	int i_last = 0;	//counter on number of group
	// along the queue for each group save the position where is the last element and the cardinality
	for(int i=(N-1); i>=0; i--){

		// update cardinality
		if( groups[arr[i]][1] == -1 ){
			groups[arr[i]][1] = 1;
		} else{
			groups[arr[i]][1] += 1;
		}

		// update the last position for each group and in the list of position (last_el)
		if( i >= groups[arr[i]][0] ){
			if(groups[arr[i]][0] == -1){
				last_el[i_last] = arr[i];
				i_last += 1;
			}
			groups[arr[i]][0] = i;
		}
	}
	n_group = i_last;	//more significant name

	// output for debug
	/*cout << "groups: \n";
	for (int i = 0; i < 62; i++){
		if(groups[i][0]!=-1){
			cout << groups[i][0] << " " << groups[i][1] << " " << groups[i][2] << endl;
		}
	}

	cout << "last element: ";
	for (int i = 0; i < n_group; i++){
		cout << last_el[i] << " ";
	}
	cout << endl;*/

	// after collect some value calculate the effective gain
	int min_cardinality, el_with_min, group_gain;
	for(int last_position_start = N-1; last_position_start >= 0;){
		min_cardinality = 25001; // max size of N given by text

		// for each group from the end of the queue
		for (int j=0; j < n_group; j++){
			// not already consider and available
			if( groups[last_el[j]][2] == 0 and last_position_start <= groups[last_el[j]][0] ){
				// find the best group (the smallest)
				if( groups[last_el[j]][1] < min_cardinality ){
					min_cardinality = groups[last_el[j]][1];
					el_with_min = last_el[j];
				}
			}
		}

		groups[el_with_min][2] = 1;	//group consider from now

		group_gain = groups[el_with_min][1] * (groups[el_with_min][0] - last_position_start);
		gain += group_gain;

		// update for consider more group
		last_position_start -= groups[el_with_min][1];
	}

	//cout << "\n\n";
	return(5*gain);	// each point of gain have a value of 5 (given by text)
}