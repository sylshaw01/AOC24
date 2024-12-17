#include <bits/stdc++.h>
using namespace std;

//got to computer at 6:04
//had like 2.5h break after part 1
//okay I have a feeling the dumb way isn't going to cut it this time, I think I need to work backwards?
// alright I think I'm mgetting there? I'm doing this very very shakily and arguably, against the core idea of AOC. I'm basically pattern matching the numbers it shows manually
// and using those patterns to inform the future brute-force, rince and repeat. Did this thrice over to get new values for the t loop
//
//day    p1time    p1rank     p2time    p2rank
// 17   01:40:46   6293      06:39:14   5395  

vector<unsigned long long> splitNumLine(string inputLine){
	regex numbers("(-*[0-9]+)");
	auto beginning = sregex_iterator(inputLine.begin(),inputLine.end(),numbers);
	auto end = sregex_iterator();
	vector<unsigned long long> matches;
	for(sregex_iterator it= beginning; it!= end; ++it){
		smatch num = *it;
		string numStr = num.str();
		matches.push_back(stoll(numStr));
	}
	return matches;

}



int main(){
	int registerLength = 3;
	string inputLine;
	vector<string> inputGrid;
	vector<unsigned long long> registers(registerLength);
	//register parse
	for(int i{0};i<registerLength;i++){
		//line input
		getline(cin,inputLine);
		vector<unsigned long long> nums = splitNumLine(inputLine);
		registers[i] = nums[0];	
		//grid input
		//getline(cin,inputLine);
		//inputGrid.push_back(inputLine);
	}
	//operation parse
	getline(cin,inputLine);
	getline(cin,inputLine);
	string program = inputLine.substr(9,inputLine.size()-9);
	vector<unsigned long long> ops  = splitNumLine(inputLine);
	//cout << ops[0] << " " << ops[1] << endl;
	//cout << registers[0] << " " << endl;
	int flag= 0;
	cout << "test" << endl;
	int tester=1;
	for(unsigned long long t{5158087066};t<((unsigned long long)2<<62);t+=8589934592){
		//cout << t << endl;
		registers[0] = t;
			string output;
		long long pointer = 0;
		for(unsigned long long i{0};i<ops.size();i+=2){
			long long combo;
			if(ops[i+1] <4 ){
				combo = ops[i+1];
			}else{
				combo = registers[ops[i+1]-4];
			}
			if(ops[i] == 0){
				registers[0] = floor(registers[0]/(1<<(combo)));
			}else if(ops[i]==1){
				registers[1] = registers[1]^ops[i+1];
			}else if(ops[i]==2){
				registers[1] = combo%8;
			}else if(ops[i]==3){
				if(registers[0]!=0){
					i=ops[i+1];
					i-=2;
					continue;
				}
			}else if(ops[i]==4){
				registers[1] = registers[2]^registers[1];
			}else if(ops[i]==5){
				//cout << combo%8 << ",";
				output.push_back(to_string(combo%8)[0]);
				output.push_back(',');
			//	cout << to_string(combo%8)[0];
			//	cout << " " << output << endl;
			//	cout << program << endl;
			//	cout << program[pointer+1] << endl;
				if(to_string(combo%8)[0]!=program[pointer]){
					break;
				}
				pointer+=2;
			}else if(ops[i]==6){
				registers[1] = (unsigned long long) registers[0]/(1<<(combo));
			}else if(ops[i]==7){
	//			cout << registers[0] << " " << combo << endl;
				registers[2] = (unsigned long long) registers[0]/(1<<(combo));
			}
			if(output.substr(0,output.size()-1) == program){
				flag = 1;
				break;
			}
		}
			if(output.size()>tester){
			cout << t << endl;
			cout << output << endl;
			tester+=2;
		}
			if(flag ==1){
			cout << t << endl;
			cout << output << endl;
			break;
			}
	}

	cout << registers[0] <<  endl;



	return 0;
}

