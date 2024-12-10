#include <bits/stdc++.h>

//day  p1time   p1rank   p2time   p2rank
//7   02:18:59  12392    04:10:21  16012

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
		long long trial;
		for(int b{0};b<(1<<(operands.size()-1));b++){

			trial = operands[0];
			//simple little bitmask
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
			//	cout << "YES" << "\n";
				break;
			}
		}
		//bitmask again?
		for(int c{0};c<(1<<(operands.size()-1));c++){
			if(trial==target){
				break;
			}
			//cout << c << "\n";
			//vector<long long> smallerOperands(operands);
			//int index = 0;
			//for(int l{1};l<operands.size();l++){
			
				//cout << index << "\n";
			//	if((c>>(l-1))&1){
				//	cout << "yes\n"; 
			//		smallerOperands[index] = stoll(to_string(smallerOperands[index])+to_string(smallerOperands[index+1]));
			//		smallerOperands.erase(smallerOperands.begin()+index+1);
					
			//	}else{
				//	cout << "no\n";
			//		index++;

			//	}

			//}
			//for(int v{0};v<smallerOperands.size();v++){
			//	cout << " " << smallerOperands[v];
			//}
			//cout << "\n";
			for(int b{0};b<(1<<(operands.size()-1));b++){

				int index = 0;	
				//vector<long long> smallerOperands(operands);
				trial = operands[0];
				//simple little bitmask
				for(int j{1};j<operands.size();j++){
			//			cout <<"size "<< smallerOperands.size() << "\n";
			//			cout <<"index " << index << "\n";
					if(((b>>(j-1))&1) && (c>>(j-1)&1)){
						trial +=operands[j];
						//smallerOperands[index]=smallerOperands[index] + smallerOperands[index+1];
						//smallerOperands.erase(smallerOperands.begin()+index+1);
					}else if ((c>>(j-1)&1)){
						trial*=operands[j];
						//smallerOperands[index] = smallerOperands[index] * smallerOperands[index+1];
						//smallerOperands.erase(smallerOperands.begin()+index+1);
					}else{
						trial = stoll(to_string(trial)+to_string(operands[j]));
						//smallerOperands[index] = stoll(to_string(smallerOperands[index])+to_string(smallerOperands[index+1]));
						//smallerOperands.erase(smallerOperands.begin()+index+1);
					}
				
				}
				//cout << "test\n";
				//cout << smallerOperands[0];
				//cout << "test2\n";
				//string trialstring = to_string(smallerOperands[0]);
				//for(int g{1};g<smallerOperands.size();g++){
			//		cout << " " << smallerOperands[g];
				//	trialstring = trialstring + to_string(smallerOperands[g]);
				//}
			//	cout << "\n";
			//	cout << trialstring << "\n";



			//	cout << trial << "\n";
				if(trial==target){
				//	cout << "YES\n";
					answer+=target;
					break;
				}

				//im so SILLY of course its just evaluated left to right as always
		}

		}
		//3024776040947
		//3769823878002
		//317.....
		//
		//}
		// OKAY the lessons learned here. Read the question to make sure you are not overcomplicating things.
		// leaving all these comments in just so you can see all the effort I threw at this :3



	}
	cout << answer << "\n";


	return 0;
}


