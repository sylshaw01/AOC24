#include <bits/stdc++.h>


//day  p1time   p1rank     p2time  p2rank
//5   04:36:53  28622     04:50:14  22106
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

	int ruleLength = 1176;
	int inpLength = 204;
	int sum = 0;
	map<int,vector<int>> backMap;
	map<int,vector<int>> forwardMap;

	for(int i{0};i<ruleLength;i++){
		string rule;
		getline(cin,rule);
		int left = stoi(rule.substr(0,2));
		int right = stoi(rule.substr(3,2));
		if(backMap.count(right)){
			backMap[right].push_back(left);
		}else{
			backMap[right] = {left};
		}
		if(forwardMap.count(left)){
			forwardMap[left].push_back(right);
		}else{
			forwardMap[left] = {right};
		}
	}

	for(int i{0};i<inpLength;i++){
		string input;
		int flag = 1;
		getline(cin,input);
		vector<string> inputVals= split(input,',');
		vector<int> intInputVals(inputVals.size());
		for(int j{0};j<inputVals.size();j++){
			intInputVals[j] = stoi(inputVals[j]);
		}
		//potentially the least efficient code to ever exist??
		for(int j{0};j<intInputVals.size();j++){
			for(int l{0};l<j;l++){
				if(forwardMap.count(intInputVals[j])){
					for(int z{0};z<forwardMap[intInputVals[j]].size();z++){
						if(intInputVals[l]==forwardMap[intInputVals[j]][z]){
							flag = 0;
						}
					}
				}
			}
			for(int r{j+1};r<intInputVals.size();r++){
				if(backMap.count(intInputVals[j])){
					for(int z{0};z<backMap[intInputVals[j]].size();z++){
						if(intInputVals[r]==backMap[intInputVals[j]][z]){
							flag = 0;
						}
					}
				}
			
			}
		}
		if(flag==0){
			while(flag==0){
				for(int j{0};j<intInputVals.size();j++){
					for(int l{0};l<j;l++){
						if(forwardMap.count(intInputVals[j])){
							for(int z{0};z<forwardMap[intInputVals[j]].size();z++){
								if(intInputVals[l]==forwardMap[intInputVals[j]][z]){
									int tmp = intInputVals[l];
									intInputVals[l] = intInputVals[j];
									intInputVals[j] = tmp;
								}
							}
						}
					}
					for(int r{j+1};r<intInputVals.size();r++){
						if(backMap.count(intInputVals[j])){
							for(int z{0};z<backMap[intInputVals[j]].size();z++){
								if(intInputVals[r]==backMap[intInputVals[j]][z]){
									int tmp = intInputVals[r];
									intInputVals[r] = intInputVals[j];
									intInputVals[j] = tmp;
								}
							}
						}
					
					}
				}
		flag=1;
		for(int j{0};j<intInputVals.size();j++){
			for(int l{0};l<j;l++){
				if(forwardMap.count(intInputVals[j])){
					for(int z{0};z<forwardMap[intInputVals[j]].size();z++){
						if(intInputVals[l]==forwardMap[intInputVals[j]][z]){
							flag = 0;
						}
					}
				}
			}
			for(int r{j+1};r<intInputVals.size();r++){
				if(backMap.count(intInputVals[j])){
					for(int z{0};z<backMap[intInputVals[j]].size();z++){
						if(intInputVals[r]==backMap[intInputVals[j]][z]){
							flag = 0;
						}
					}
				}
			
			}
			}
		}
			sum+=intInputVals[intInputVals.size()/2];
		}
		
	}
	cout << sum << endl;


	return 0;
}

