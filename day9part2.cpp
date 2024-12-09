#include <bits/stdc++.h>

using namespace std;

int main(){
	//losing my mind, I've just wasted an hour becuase it was working on all the test cases, but it turns out c++ input can't be more than 4000 chars? maybe its a terminal thing? idk its good to know either way
	//
	//I think this solution is fairly straightforward, 

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
	long long rpoint = fullVector.size()-(input[input.size()-1]-'0');
	if(input.size()%2==0){
		rpoint -=input[input.size()-2]-'0';
	}
	cout << rpoint << "\n";
	for(long long i{static_cast<long long>(input.size())-(1+(static_cast<long long>(input.size()+1)%2))};i>0;i-=2){
		//check for each non-space block
		if((input[i]-'0')>0){
	//		cout << input[i] << endl;
			for(int j{0};j<=(rpoint-(input[i]-'0'));j++){
			//brute force each potential space
				int fits = 1;
				for(int k{j};k<(j+(input[i]-'0'));k++){
					if(fullVector[k]!=-1){
						fits=0;
					}
				}
				if(fits == 1){
					for(int k{j};k<(j+(input[i]-'0'));k++){
						fullVector[k] = i/2;
					}
					for(long long k{rpoint};k<(rpoint+(input[i]-'0'));k++){
						fullVector[k] = -1;
					}
					break;
				}
				
			}
		}
	//	cout << "rpoint: " << rpoint << "\n";
			rpoint-=(input[i-1]-'0')+(input[i-2]-'0');
	//for(int i{0};i<fullVector.size();i++){
	//	if(fullVector[i]==-1){
	//		cout << ".";
	//	}else{
	//		cout << fullVector[i];
	//	}
	//}
	//	cout << "\n";
	}
	cout << "\n";
	for(int i{0};i<fullVector.size();i++){
		if(fullVector[i]==-1){
			cout << ".";
		}else{
			cout << fullVector[i];
		}
	}
	cout << "\n";
	long long checksum=0; 
	//long long lastindex = oddVector.size()-1;
	//cout << fullVector.size()-whitespaceCount;
	//for(long long i{0};i<(fullVector.size()-whitespaceCount);i++){
	//	cout << "testing\n";
	//	if(fullVector[i]==-1){
	//		cout << oddVector[lastindex];
	//		checksum+=i*oddVector[lastindex];
	//		lastindex--;
	//	}else{
	//		cout << fullVector[i];
	//		checksum+=i*fullVector[i];
	//	}
	//}
	//
	//
	for(long long i{0};i<fullVector.size();i++){
		if(fullVector[i]!=-1){
			checksum+=i*fullVector[i];
		}
	}

	//108112247752
	//54056123876
	//54067123051
	//
	//
	//
	//6250606043917
	cout << "\n\n" << checksum << "\n";

	return 0;
}
