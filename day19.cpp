#include <bits/stdc++.h>
using namespace std;
//okay got to desk at 6?21
//I commpletely misjudged the question and now I don't know what to do
//MIDJUDGED THE QUESTION AGAIN
//ah coming back after a few hours it seems i misjudged it again
//you cant just remove letters from the sequence
//okay so I wrote something super complicated, and now I just watched someone else do it and I realise I was overcomplicating things way too much, I'm just going to comment out
//the old stuff and then write in the new, so I remember it
//stuck for like 40 mins because I didn't think to have my "results" as lls instead of ints, very silly
//day  p1time    p1rank       p2time   p2rank
//19   07:29:07  15092       07:29:44  12576
vector<string> splitNumLine(string inputLine){
	regex numbers("([a-z]+)");
	auto beginning = sregex_iterator(inputLine.begin(),inputLine.end(),numbers);
	auto end = sregex_iterator();
	vector<string> matches;
	for(sregex_iterator it= beginning; it!= end; ++it){
		smatch num = *it;
		string numStr = num.str();
		matches.push_back(numStr);
	}
	return matches;

}
int search(string input, vector<string> towels){
	string myinput = input;
	if(input.size()==0){
		return 1;
	}
	
	for(int i{0};i<towels.size();i++){
			if(myinput.size()>=towels[i].size() && myinput.contains(towels[i])){
				int ind = myinput.find(towels[i]);
			//	cout << myinput << " " << towels[i] << " " << ind << endl;
				int l = search(myinput.substr(0,ind),towels);
				int r = search(myinput.substr(ind+towels[i].size(),(myinput.size())-(ind+towels[i].size())),towels);	
				if(l>0 && r>0){
			return 1;


			}
		}
			
	}
	return 0;

}

map<string,long long> memo;
long long betterSearch(string input, set<string> towels){
//	cout << input <<  "  " << memo.count(input) << "   " << input.size() <<endl;
	if(memo.count(input)==0){
	if(input.size()==0){
		return 1;
	}else{
		long long result = 0;
		for(auto towel : towels){
			if(input.substr(0,towel.size())==towel){
//					cout << input << " " << towel << "       " << input.substr(towel.size(),input.size()-towel.size()) <<  endl;
				result+=betterSearch(input.substr(towel.size(),input.size()-towel.size()),towels);
//					cout << result << endl;
			}
		}
		memo[input]= result;

	}
	}
	return memo[input];	
}



int main(){
	int inputLength = 400;
	string inputLine;
	//vector<string> inputGrid;
	getline(cin, inputLine);
	vector<string> towelsvec = splitNumLine(inputLine);
	set<string> towels;
	for(int i{0};i<towelsvec.size();i++){
		towels.insert(towelsvec[i]);
	}
	//sort(towels.begin(),towels.end(),[](string&a, string&b) {return a.length()<b.length();});
	//int k = towels.size();
	//cout << k << endl;
	//for(int i{1};i<k;i++){
	//	vector<string> smalltowels = {};
	//	for(int j{0};j<i;j++){
	//		smalltowels.push_back(towels[j]);
	//	}
	//	if(search(towels[i],smalltowels)>0){
	//		towels.erase(towels.begin()+i);
	//		k--;
	//	}
	//}
	//cout << towels.size() << endl;
	//sort(towels.begin(),towels.end(),[](string&a, string&b) {return a.length()>b.length();});
	//cout << towels[0] << "   " <<  towels[towels.size()-1] << endl;
	long long output = 0;
	for(int i{0};i<inputLength;i++){
		//line input
		cin >> inputLine;
		//cout << inputLine << endl;
		//cout << inputLine.substr(0,towels[0].size()) << " " << towels[0] << endl;
		//cout << inputLine.substr(towels[0].size(),inputLine.size()-towels[0].size()) << endl;
	//	output+=search(inputLine,towels);
		if(betterSearch(inputLine,towels)>0){
			output+= betterSearch(inputLine,towels);
		//	cout <<  betterSearch(inputLine,towels) << endl;
		//	cout << "YES" << endl;
		}else{
		//	cout << "NO" << endl;
		}
		//cout << endl;
		//	cout << output << endl;
		//vector<long long> nums = splitNumLine(inputLine);
		
		//grid input
		//getline(cin,inputLine);
		//inputGrid.push_back(inputLine);
	}

cout << output << endl;

	return 0;
}

