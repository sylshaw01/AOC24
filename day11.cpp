#include <bits/stdc++.h>
#include "BigInt.hpp"

using namespace std;


int main(){

	vector<BigInt> puzzleInput(8);
	for(int i{0};i<8;i++){
		cin >> puzzleInput[i];
	}
	for(int blinks{0};blinks<25;blinks++){
		cout << "blinkno: " << blinks << "\n";
		for(int j{(int)puzzleInput.size()-1};j>=0;j--){
			if(puzzleInput[j]=="0"){
				puzzleInput[j]="1";
			}else if(puzzleInput[j].to_string().size()%2==0){
				string pi = puzzleInput[j].to_string();
				long long len = pi.size();
				//string a = pi.to_string().substr(0,len/2);
				puzzleInput.insert(puzzleInput.begin()+j,BigInt(pi.substr(0,len/2)));
				//string b = pi.to_string().substr(len/2,len/2);
				puzzleInput[j+1] = BigInt(pi.substr(len/2,len/2));
			}else{
				puzzleInput[j]*=2024;
			
			}
		}
		if(blinks<8){
		for(int i{0};i<puzzleInput.size();i++){
			cout << puzzleInput[i] << " ";
		}
		cout << "\n";
		}
	}

	cout << puzzleInput.size() << "\n";

	return 0;
}
