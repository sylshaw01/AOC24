#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;

using namespace std;
//day   p1time   p1rank	    p2time   p2rank
//10   04:05:42  17442     04:12:22  16651 
//
//
//Slept in today, so really p1 was about 40 mins, and p2 then about 50 mins, which might actually be my quickest time!



void search(int indi, int indj, vector<vector<int>> topmap, map<pair<int,int>,int>& tails, int mapWidth, int mapHeight){
	if(topmap[indi][indj] == 9 ){
		//cout << "found" << endl; 
		if(tails.count({indi,indj})==0){
			tails[{indi,indj}]=1;
		}else{
			tails[{indi,indj}]++;
		}
		return;
	}else{
		//cout << indi << " " << indj << "\n";
		if((indi+1)<mapWidth && topmap[indi+1][indj]==(topmap[indi][indj]+1)){
			search(indi+1,indj,topmap,tails, mapWidth, mapHeight);
		}
		if((indj+1)<mapHeight && topmap[indi][indj+1] == (topmap[indi][indj]+1)){
			search(indi,indj+1,topmap,tails,mapWidth,mapHeight);
		}
		if(indi>0 && topmap[indi-1][indj]==(topmap[indi][indj]+1)){
			search(indi-1,indj,topmap,tails,mapWidth,mapHeight);
		}
		if(indj>0 && topmap[indi][indj-1]==(topmap[indi][indj]+1)){
			search(indi,indj-1,topmap,tails,mapWidth,mapHeight);

		}
		return;
	}

}

int main(){

//	auto start=high_resolution_clock::now();
	int mapHeight = 50;
	int mapWidth = 50;
	vector<vector<int>> topmap(mapHeight,vector<int>(mapWidth));
	for(int i{0};i<mapHeight;i++){
		string singleLine;
		cin >> singleLine;
		for(int j{0};j<mapWidth;j++){
			topmap[i][j] = (singleLine[j]-'0');
		}
	}

	long long trailScore = 0;
	for(int i{0};i<mapHeight;i++){
		for(int j{0};j<mapWidth;j++){
			if(topmap[i][j]==0){
				map<pair<int,int>,int> trailTail;
				search(i,j,topmap,trailTail,mapWidth,mapHeight);
				int indivtrailscore = 0;
				for(auto t: trailTail){
					indivtrailscore+=t.second;
				}
				trailScore+=indivtrailscore;
				//cout << trailScore << "\n";
			}
		}
	}
	cout << trailScore << "\n";
//	auto stop = high_resolution_clock::now();
//	auto duration = duration_cast<microseconds>(stop-start);
//	cout << (double)duration.count()/1000000 << "\n";
	
}
