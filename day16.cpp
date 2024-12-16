#include <bits/stdc++.h>
using namespace std;

//wow done in 2h!! one of my quickest solves, and I think its mainly down to getting better at implementing things, even if I'm implementing them poorly
//also sub 5k ranking!!!
//day	p1time    p1rank     p2time    p2rank
//16   02:12:47   6073      03:02:47   4553 
//got to my computer at 6:08
//is this a dfs?
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
vector<unordered_set<int>> bests;
 void dfs(vector<int>& paths, map<int,int>& visited, vector<string> inputGrid, int posx, int posy, vector<int> facing, int weight,unordered_set<int> personalVisited){
	if(weight>90000){
		return;
	}
	personalVisited.insert(posx+(256*posy));
	if(inputGrid[posy][posx] =='E'){
		visited[posx+(1000*posy)]=weight;
	//	cout << "PATH FOUND    " << weight << endl; 
		paths.push_back(weight);
		if(weight == 88468){
			bests.push_back(personalVisited);
		//	cout << personalVisited.size() << endl; 
		}
		return;
	}else{
		vector<vector<int>> adj = {{1,0},{0,1},{-1,0},{0,-1}};
		//no option to turn back, its always suboptimal
		//see whats available
		if(visited.count(posx+(1000*posy))){
			visited[posx+(1000*posy)] = min(visited[posx+(1000*posy)],weight);
		}else{
			visited[posx+(1000*posy)]=weight;
		}
		for(auto dxy : adj){
			//cout << dxy[0] << " " << dxy[1] << "    " << posx << " " << posy << endl;
			if(dxy[0]==-facing[0] && dxy[1]==-facing[1]){
				continue;
			}else if(inputGrid[posy+dxy[1]][posx+dxy[0]]!= '#'){
				if(visited.count((posx+dxy[0])+(1000*(posy+dxy[1])))){
					if(dxy[0]==facing[0] && dxy[1] == facing[1]){
							if(visited[(posx+dxy[0])+(1000*(posy+dxy[1]))]>=weight-1100){
								dfs(paths,visited,inputGrid,posx+dxy[0],posy+dxy[1],facing,weight+1,personalVisited);
							}
					}else{
						//no idea why -1000 works more than 0 here
						if(visited[(posx+dxy[0])+(1000*(posy+dxy[1]))]>=weight-1100){
							dfs(paths,visited,inputGrid,posx+dxy[0],posy+dxy[1],{dxy[0],dxy[1]},weight+1001,personalVisited);
						}
					}
				}else{
					if(dxy[0]==facing[0] && dxy[1] == facing[1]){
						dfs(paths,visited,inputGrid,posx+dxy[0],posy+dxy[1],facing,weight+1,personalVisited);	
					}else{
						dfs(paths,visited,inputGrid,posx+dxy[0],posy+dxy[1],{dxy[0],dxy[1]},weight+1001,personalVisited);
					}
				}
			}
		}
	}
}

int main(){
	int inputLength = 141;
	//int inputLength = 17;
	string inputLine;
	vector<string> inputGrid;
	vector<int> paths;
	map<int,int> visited;
	int posx, posy;
	vector<int> facing = {1,0};
	for(int i{0};i<inputLength;i++){
		//line input
		//getline(cin,inputLine);
		//vector<long long> nums = splitNumLine(inputLine);
		
		//grid input
		getline(cin,inputLine);
		inputGrid.push_back(inputLine);
	}
	posx = 1;
	posy = inputLength-2;
	unordered_set<int> personalVisited;
	dfs(paths,visited,inputGrid,posx,posy,facing,0,personalVisited );
	sort(paths.begin(),paths.end());
	cout << paths[0] << endl;
	personalVisited = bests[0];
	//cout << personalVisited.size() << endl;
	for(int i{1};i<bests.size();i++){
	//	cout << bests[i].size() << endl;
		for(auto item : bests[i]){
			personalVisited.insert(item);
		}
	}
	cout << personalVisited.size() << endl;
	



// 88472 too high
	return 0;
}

