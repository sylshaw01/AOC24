#include <bits/stdc++.h>

//day  p1time   p1rank     p2time    p2rank
//2   01:56:24  20235      02:35:05  16123  
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
	int sum = 0;
	string line;
	ifstream infile("inp2.txt");
	while(getline(infile,line)){
		cout << line << endl;
		vector<int> level;
		vector<string> splitup = split(line,' ');
		for(int i{0};i<splitup.size();i++){
			level.push_back(stoi(splitup[i]));
		}
		int add=0;
		for(int l{0};l<level.size();l++){
			//awful time complexity but its faster to code this and its only run on a small dataset
			vector<int> tmp(level.size());
			copy(level.begin(),level.end(),tmp.begin());
			tmp.erase(tmp.begin()+l);
			if(tmp[1]<tmp[0]){
				int track = 0;
				for(int j{1};j<tmp.size();j++){
					if(tmp[j-1]-tmp[j]>=1 && tmp[j-1]-tmp[j]<=3){
						track++;
					}
				}
				if(track+1==tmp.size()){
					add=1;
				}
			}else if(tmp[0]<tmp[1]){
				int track = 0;
				for(int j{1};j<tmp.size();j++){
					if(tmp[j]-tmp[j-1]>=1 && tmp[j]-tmp[j-1]<=3){
						track++;
					}
				}
				if(track+1==tmp.size()){
					add=1;
				}

			}

		}
		sum+=add;
	}

	cout << sum << endl;



	return 0;
}
