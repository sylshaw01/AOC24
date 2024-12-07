#include <bits/stdc++.h>



using namespace std;
template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

int main(){

	int t = 850;
	long long answer = 0;
	for(int i{0};i<t;i++){
		//cout << "line: " << i << "\n";
		//maybe I don't need all these structures if I only process input line by line
		// but it can't hurt for now
		// 
		long long target;



		string inputLine;
		getline(cin,inputLine);
		vector<string> inputs = split(inputLine,' ');
		
		//cout << inputs[0].substr(0,inputs[0].size()-1) << "\n";
		target = stoll(inputs[0].substr(0,inputs[0].size()-1));
		//cout << inputs.size() << "\n";
		//cout << inputLine << "\n";
		//cout << target << "\n";
		vector<long long> operands;
		for(int j{0};j<inputs.size()-1;j++){
			operands.push_back(stoll(inputs[j+1]));
		//	cout << " " << operands[j] << "\n";
		}
		//should I binary search through the potential outcomes? there are 2^9 potential outcomes, so yeah 9 is better than 2^ AH wait if I sort it I can make a monotonically increasing function
		// no I don't think this works, and I think its fast enough to just go through all possibilities?
		//might as well calculate a lower and upper bound?
		//long long lb = operands[0];
		//long long ub = operands[0];
		//for(int k{1};k<operands.size();k++){
		//	lb+=operands[k];
		//	ub*=operands[k];
		//}
		//if((target >=lb) && (target <= ub)){
			//cout << (1<<(operands.size())) << "\n";
		for(int b{0};b<(1<<(operands.size()-1));b++){

			long long trial = operands[0];
			for(int j{1};j<operands.size();j++){
				if((b>>(j-1))&1){
					trial+=operands[j];
				}else{
					trial*=operands[j];
				}
			}
				//cout << trial << "\n";
			if(trial==target){
				answer+=target;
				break;
			}
		}
			
		//}



	}
	cout << answer << "\n";


	return 0;
}


