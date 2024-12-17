#include <bits/stdc++.h>
using namespace std;

//got to computer at 6:04

vector<long long> splitNumLine(string inputLine){
	regex numbers("(-*[0-9]+)");
	auto beginning = sregex_iterator(inputLine.begin(),inputLine.end(),numbers);
	auto end = sregex_iterator();
	vector<long long> matches;
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
	vector<long long> registers(registerLength);
	//register parse
	for(int i{0};i<registerLength;i++){
		//line input
		getline(cin,inputLine);
		vector<long long> nums = splitNumLine(inputLine);
		registers[i] = nums[0];	
		//grid input
		//getline(cin,inputLine);
		//inputGrid.push_back(inputLine);
	}
	//operation parse
	getline(cin,inputLine);
	getline(cin,inputLine);
	string program = inputLine.substr(9,inputLine.size()-9);
	vector<long long> ops  = splitNumLine(inputLine);
	//cout << ops[0] << " " << ops[1] << endl;
	//cout << registers[0] << " " << endl;
	for(int i{0};i<ops.size();i+=2){
		long long combo;
		if(ops[i+1] <4 ){
			combo = ops[i+1];
		}else{
			combo = registers[ops[i+1]-4];
		}
		if(ops[i] == 0){
			registers[0] = registers[0]/(2<<(combo-1));
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
			cout << combo%8 << ",";
		}else if(ops[i]==6){
			registers[1] = registers[0]/(2<<(combo-1));
		}else if(ops[i]==7){
			registers[2] = registers[0]/(2<<(combo-1));
		}
	}

	cout << endl;



	return 0;
}

