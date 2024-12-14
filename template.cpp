#include <bits/stdc++.h>
using namespace std;

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
	int inputLength;
	string inputLine;
	vector<string> inputGrid;
	for(int i{0};i<inputLength;i++){
		//line input
		//getline(cin,inputLine);
		//vector<long long> nums = splitNumLine(inputLine);
		
		//grid input
		//getline(cin,inputLine);
		//inputGrid.push_back(inputLine);
	}



	return 0;
}

