#include <bits/stdc++.h>
using namespace std;

//got to computer at 6:15
// day    p1time   p1rank   p2time    p2rank
// 15   02:42:33   8282    05:16:29   6677
//
// I had a small break after part 1 but still 1.5h for part 1 and another 1.5h for part 2 is *rough*, I don't think my ideas here are too bad, but my implementation could definitely
// be better and more concise
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
vector<vector<int>> moveup(int currboxx,int currboxy,map<int,unordered_set<int>> boxhmap, map<int,unordered_set<int>>boxvmap,map<int,unordered_set<int>>wallhmap,map<int,unordered_set<int>> wallvmap){
	vector<vector<int>> thingstomoveleft = {}, thingstomoveright= {}, thingstomove= {};
	if(wallhmap[currboxy-1].count(currboxx) || wallhmap[currboxy-1].count(currboxx+1)){
		return {{-1,-1}};
	}else{
		if(boxhmap[currboxy-1].count(currboxx-1)){
			thingstomoveleft = moveup(currboxx-1,currboxy-1,boxhmap,boxvmap,wallhmap,wallvmap);
		}
		if(boxhmap[currboxy-1].count(currboxx+1)){
			thingstomoveright = moveup(currboxx+1,currboxy-1,boxhmap,boxvmap,wallhmap,wallvmap);
		}
		if(boxhmap[currboxy-1].count(currboxx)){
			thingstomoveleft = moveup(currboxx,currboxy-1,boxhmap,boxvmap,wallhmap,wallvmap);
		}
		thingstomove = thingstomoveleft;
		for(int i{0};i<thingstomoveright.size();i++){
			thingstomove.push_back(thingstomoveright[i]);
		}
		thingstomove.push_back({currboxy,currboxx});
		return thingstomove;

	}
	
}
vector<vector<int>> movedown(int currboxx,int currboxy,map<int,unordered_set<int>> boxhmap, map<int,unordered_set<int>>boxvmap,map<int,unordered_set<int>>wallhmap,map<int,unordered_set<int>> wallvmap){
	vector<vector<int>> thingstomoveleft = {}, thingstomoveright= {}, thingstomove= {};
	if(wallhmap[currboxy+1].count(currboxx) || wallhmap[currboxy+1].count(currboxx+1)){
		return {{-1,-1}};
	}else{
		if(boxhmap[currboxy+1].count(currboxx-1)){
			thingstomoveleft = movedown(currboxx-1,currboxy+1,boxhmap,boxvmap,wallhmap,wallvmap);
		}
		if(boxhmap[currboxy+1].count(currboxx+1)){
			thingstomoveright = movedown(currboxx+1,currboxy+1,boxhmap,boxvmap,wallhmap,wallvmap);
		}
		if(boxhmap[currboxy+1].count(currboxx)){
			thingstomove = movedown(currboxx,currboxy+1,boxhmap,boxvmap,wallhmap,wallvmap);
		}
		for(int i{0};i<thingstomoveleft.size();i++){
			thingstomove.push_back(thingstomoveleft[i]);
		}
		for(int i{0};i<thingstomoveright.size();i++){
			thingstomove.push_back(thingstomoveright[i]);
		}
		thingstomove.push_back({currboxy,currboxx});
		return thingstomove;

	}
	
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
				wallhmap[i].insert(j*2);
				wallhmap[i].insert((j*2)+1);
				wallvmap[(j*2)].insert(i);
				wallvmap[(j*2)+1].insert(i);
			}else if(inputLine[j]=='O'){
				boxhmap[i].insert((j)*2);
				boxvmap[(j)*2].insert(i);
			}else if(inputLine[j] == '@'){
				posx = (j)*2;
				posy = i;
			}
		}
	}
	cout << endl;
			for(int h{0};h<inputLength;h++){
				for(int g{0};g<inputLength*2;g++){
					if(boxhmap[h].count(g)>0){
						cout << "[";
					}else if(wallhmap[h].count(g)>0){
						cout << "#";
					}else if(h==posy && g == posx){
						cout << '@';
					}else if(boxhmap[h].count(g-1)>0){
						cout << "]";
					}else{
						cout << '.';
					}

				}
				cout << "\n";
			}
	for(int b{0};b<20;b++){
		cin >> inputLine;
		for(int j{0};j<inputLine.size();j++){
			moves.push_back(inputLine[j]);
			if(inputLine[j] == '^'){
				if(boxhmap[posy-1].count(posx) || boxhmap[posy-1].count(posx-1)){
					vector<vector<int>> move1={}, move2={};
					if(boxhmap[posy-1].count(posx)){
						move1 = moveup(posx,posy-1,boxhmap,boxvmap,wallhmap,wallvmap);
					}
					if(boxhmap[posy-1].count(posx-1)){
						move2 = moveup(posx-1,posy-1,boxhmap,boxvmap,wallhmap,wallvmap);
					}
					vector<vector<int>> move = move1;
					for(int u{0};u<move2.size();u++){
						move.push_back(move2[u]);
					}
					if(move.size()>0){
						sort(move.begin(),move.end());
						if(move[0][0]!=-1){
							for(int i{0};i<move.size();i++){
								boxhmap[move[i][0]].erase(move[i][1]);
								boxhmap[move[i][0]-1].insert(move[i][1]);
								boxvmap[move[i][1]].erase(move[i][0]);
								boxvmap[move[i][1]].insert(move[i][0]-1);
							}
						
							posy--;
							boxhmap[posy].erase(posx);
							boxvmap[posx].erase(posy);
						}
					}

				}else if(wallhmap[posy-1].count(posx)==0){
					posy--;
				}
			}else if(inputLine[j] == '>'){
				if(boxvmap[posx+1].count(posy)){
					int z = posx+1;
					while(boxhmap[posy].count(z)){
						z+=2;
					}
					if(!wallhmap[posy].count(z)){
						for(int k{--(--z)};k>posx;k-=2){
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
				if(boxhmap[posy+1].count(posx) || boxhmap[posy+1].count(posx-1)){
					vector<vector<int>> move1={}, move2={};
					if(boxhmap[posy+1].count(posx)){
						move1 = movedown(posx,posy+1,boxhmap,boxvmap,wallhmap,wallvmap);
					}
					if(boxhmap[posy+1].count(posx-1)){
						move2 = movedown(posx-1,posy+1,boxhmap,boxvmap,wallhmap,wallvmap);
					}
					vector<vector<int>> move = move1;
					for(int u{0};u<move2.size();u++){
						move.push_back(move2[u]);
					}
					if(move.size()>0){
						sort(move.rbegin(),move.rend());
						if(move[move.size()-1][0]!=-1){
							for(int i{0};i<move.size();i++){
								boxhmap[move[i][0]].erase(move[i][1]);
								boxhmap[move[i][0]+1].insert(move[i][1]);
								boxvmap[move[i][1]].erase(move[i][0]);
								boxvmap[move[i][1]].insert(move[i][0]+1);
							}
						
						posy++;
						boxhmap[posy].erase(posx);
						boxvmap[posx].erase(posy);
						}
					}

				}else if(wallhmap[posy+1].count(posx)==0){
					posy++;
				}
			
			}else if(inputLine[j] == '<'){
				if(boxhmap[posy].count(posx-2)){
					int z = posx-2;
					while(boxhmap[posy].count(z)){
						z-=2;
					}
					if((!wallhmap[posy].count(z+1)) ){
						z+=2;
						for(int k{z};k<posx;k+=2){
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
			//cout << endl;
			int out = 0;
			if(out == 1 && b<20){
			for(int h{0};h<inputLength;h++){
				for(int g{0};g<inputLength*2;g++){
					if(boxhmap[h].count(g)>0){
						cout << "[";
					}else if(wallhmap[h].count(g)>0){
						cout << "#";
					}else if(h==posy && g == posx){
						cout << '@';
					}else if(boxhmap[h].count(g-1)>0){
						cout << "]";
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
			sum+=(*lineIt);
		}
	}
	//cout << endl;
	//		for(int h{0};h<inputLength;h++){
	//			for(int g{0};g<inputLength*2;g++){
	//				if(boxhmap[h].count(g)>0){
	//					cout << "[";
	//				}else if(wallhmap[h].count(g)>0){
	//					cout << "#";
	//				}else if(h==posy && g == posx){
	//					cout << '@';
	//				}else if(boxhmap[h].count(g-1)>0){
	//					cout << "]";
	//				}else{
	//					cout << '.';
	//				}
//
//				}
//				cout << "\n";
//			}
	cout << sum << endl;
	
	

//1158394

	return 0;
}

