#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main(){

	string input;
	getline(cin,input);
	regex mulMatch("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
	auto mulBegin = sregex_iterator(input.begin(),input.end(),mulMatch);
	auto mulEnd = sregex_iterator();

	long sum = 0 ;
	cout << distance(mulBegin,mulEnd) << endl;
	for(sregex_iterator i = mulBegin;i!=mulEnd;++i){
		smatch match = *i;
		string matchStr = match.str();
		cout << matchStr << endl;
		matchStr = matchStr.substr(4,match.str().size()-5);

		int commapos = 0;
		for(int j{0};j<matchStr.size();j++){
			if(matchStr[j]==','){commapos=j;}
		}
		//cout << matchStr.substr(0,commapos) << " " << matchStr.substr(commapos+1,matchStr.size()-(commapos+1)) << endl;
		sum+=stoi(matchStr.substr(0,commapos)) * stoi(matchStr.substr(commapos+1,matchStr.size()-(commapos+1)));

	}
	
	cout << endl << endl << sum << endl;

	return 0;
}
