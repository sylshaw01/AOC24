#include <bits/stdc++.h>
using namespace std;

//got to computer at 6:15

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
	int inputLength = 50;
	string inputLine;
	vector<string> inputGrid;
	string moves;
	map<int, unordered_set<int>> boxhmap, boxvmap, wallhmap, wallvmap;
	int posx,posy;
	// INPUT
	for(int i{0};i<inputLength;i++){
		//line input
		//getline(cin,inputLine);
		//vector<long long> nums = splitNumLine(inputLine);
		
		//grid input
		getline(cin,inputLine);
		inputGrid.push_back(inputLine);
		for(int j{0};j<inputLine.size();j++){
			if(inputLine[j] == '#'){
				wallhmap[i].insert(j);
				wallvmap[j].insert(i);
			}else if(inputLine[j]=='O'){
				boxhmap[i].insert(j);
				boxvmap[j].insert(i);
			}else if(inputLine[j] == '@'){
				posx = j;
				posy = i;
			}
		}
	}
	for(int i{0};i<20;i++){
		cin >> inputLine;
		for(int j{0};j<inputLine.size();j++){
			moves.push_back(inputLine[j]);
			if(inputLine[j] == '^'){
				if(boxhmap[posy-1].count(posx)){
					int z = posy-1;
					while(boxvmap[posx].count(z)){
						z--;
					}
					if(!wallvmap[posx].count(z)){
						for(int k{++z};k<posy;k++){
							boxhmap[k].erase(posx);
							boxhmap[k-1].insert(posx);
							boxvmap[posx].erase(k);
							boxvmap[posx].insert(k-1);
						}
						posy--;
					}
				}else if(wallhmap[posy-1].count(posx)==0){
					posy--;
				}
			}else if(inputLine[j] == '>'){
				if(boxvmap[posx+1].count(posy)){
					int z = posx+1;
					while(boxhmap[posy].count(z)){
						z++;
					}
					if(!wallhmap[posy].count(z)){
						for(int k{--z};k>posx;k--){
							boxvmap[k].erase(posy);
							boxvmap[k+1].insert(posy);
							boxhmap[posy].erase(k);
							boxhmap[posy].insert(k+1);
						}
						posx++;
					}
				}else if(wallvmap[posx+1].count(posy)==0){
					posx++;
				}
				
			}else if(inputLine[j] == 'v'){
				if(boxhmap[posy+1].count(posx)){
					int z = posy+1;
					while(boxvmap[posx].count(z)){
						z++;
					}
					if(!wallvmap[posx].count(z)){
						for(int k{--z};k>posy;k--){
							boxhmap[k].erase(posx);
							boxhmap[k+1].insert(posx);
							boxvmap[posx].erase(k);
							boxvmap[posx].insert(k+1);
						}
						posy++;
					}
				}else if(wallhmap[posy+1].count(posx)==0){
					posy++;
				}
			
			}else if(inputLine[j] == '<'){
				if(boxhmap[posy].count(posx-1)){
					int z = posx-1;
					while(boxhmap[posy].count(z)){
						z--;
					}
					if(!wallhmap[posy].count(z)){
						for(int k{++z};k<posx;k++){
							boxvmap[k].erase(posy);
							boxvmap[k-1].insert(posy);
							boxhmap[posy].erase(k);
							boxhmap[posy].insert(k-1);
						}
						posx--;
					}
				}else if(wallvmap[posx-1].count(posy)==0){
					posx--;
				}
			
			}
			//OUTPUT
			cout << endl;
			int out = 0;
			if(out == 1){
			for(int h{0};h<inputLength;h++){
				for(int g{0};g<inputLength;g++){
					if(boxhmap[h].count(g)>0){
						cout << 'O';
					}else if(wallhmap[h].count(g)>0){
						cout << '#';
					}else if(h==posy && g == posx){
						cout << '@';
					}else{
						cout << '.';
					}

				}
				cout << "\n";
			}
			}
		}
	}
	long long sum = 0;
	for(auto lines : boxhmap){
		for(auto lineIt = lines.second.begin();lineIt!=lines.second.end();++lineIt){
			sum+=(100 * lines.first);
			sum+=*lineIt;
		}
	}
	cout << sum << endl;
	
	

//1158394

	return 0;
}

