#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main(){
	
	long sum = 0 ;
	while(0==0){
	string input;
	getline(cin,input);
	regex dodont("do\\(\\).+?don't\\(\\)");
	auto dodontBegin = sregex_iterator(input.begin(),input.end(),dodont);
	auto dodontEnd = sregex_iterator();
	for(sregex_iterator k = dodontBegin;k!=dodontEnd;++k){
	regex mulMatch("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
		smatch dodontMatch = *k;
		string dodontString = dodontMatch.str();
	auto mulBegin = sregex_iterator(dodontString.begin(),dodontString.end(),mulMatch);
	auto mulEnd = sregex_iterator();

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
	}
	cout << endl << endl << sum << endl;
	}
	return 0;
}
