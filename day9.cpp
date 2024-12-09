#include <bits/stdc++.h>

using namespace std;

int main(){
	//losing my mind, I've just wasted an hour becuase it was working on all the test cases, but it turns out c++ input can't be more than 4000 chars?
	//

	string input;
	string inputtmp;
	getline(cin,input);
	for(int i{0};i<9;i++){
		getline(cin,inputtmp);
		input = input + inputtmp;
	}
	cout << input.size() << "\n";
	vector<long long> fullVector;
	vector<long long> oddVector;
	long long whitespaceCount =0 ;
	for(long long i{0};i<input.size();i++){
		for(long long j{0};j<(input[i] - '0');j++){
			if(i%2==1){
				fullVector.push_back(-1);
				cout << ".";
				whitespaceCount++;
			}else{
				fullVector.push_back(i/2);
				cout << i/2;
				oddVector.push_back(i/2);
			}
		}
	}
	cout << "\n";
	long long checksum=0; 
	long long lastindex = oddVector.size()-1;
	//cout << fullVector.size()-whitespaceCount;
	for(long long i{0};i<(fullVector.size()-whitespaceCount);i++){
	//	cout << "testing\n";
		if(fullVector[i]==-1){
			cout << oddVector[lastindex];
			checksum+=i*oddVector[lastindex];
			lastindex--;
		}else{
			cout << fullVector[i];
			checksum+=i*fullVector[i];
		}
	}

	//108112247752
	//54056123876
	//54067123051
	//
	cout << "\n\n" << checksum << "\n";

	return 0;
}
