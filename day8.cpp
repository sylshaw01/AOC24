#include <bits/stdc++.h>

using namespace std;

int main(){

	const int mapWidth = 50;
	const int mapLength = 50;
	string inputLine;
	map<char,vector<vector<int>>> antennaPoints;
	set<pair<int,int>> antinodePoints;
	for(int j{0};j<mapLength;j++){
		getline(cin,inputLine);
		for(int i{0};i<mapWidth;i++){
			if(inputLine[i]!='.'){
			if(antennaPoints.count(inputLine[i])){	
				antennaPoints[inputLine[i]].push_back({i,j});
			}else{
				antennaPoints.insert({inputLine[i],{{i,j}}});
			}
			}
		}
	}
	for(auto antennaType : antennaPoints){

		if(antennaType.second.size()>1){
			for(int a{0};a+1<antennaType.second.size();a++){
				for(int b{a+1};b<antennaType.second.size();b++){
					cout <<antennaType.first << " : " <<  "(" << antennaType.second[a][0] << "," << antennaType.second[a][1] << ") with (" << antennaType.second[b][0] << "," << antennaType.second[b][1] <<  ")\n";
					// Upper left quadrant
					if(antennaType.second[a][0]<=antennaType.second[b][0] && antennaType.second[a][1]<=antennaType.second[b][1]){
						int xdist = antennaType.second[b][0]-antennaType.second[a][0];
						int ydist = antennaType.second[b][1]-antennaType.second[a][1];
						if(antennaType.second[a][0]-xdist>=0 && antennaType.second[a][1]-ydist>=0){
							antinodePoints.insert(make_pair(antennaType.second[a][0]-xdist,antennaType.second[a][1]-ydist));
						}
						if(antennaType.second[b][0]+xdist<mapWidth && antennaType.second[b][1]+ydist<mapLength){
							antinodePoints.insert(make_pair(antennaType.second[b][0]+xdist,antennaType.second[b][1]+ydist));
						}
					} else if (antennaType.second[a][0]>antennaType.second[b][0] && antennaType.second[a][1]<=antennaType.second[b][1]){// upper Right quadrant
						int xdist = antennaType.second[a][0]-antennaType.second[b][0];
						int ydist = antennaType.second[b][1]-antennaType.second[a][1];
						if(antennaType.second[a][0]+xdist<mapWidth && antennaType.second[a][1]-ydist>=0){
							antinodePoints.insert(make_pair(antennaType.second[a][0]+xdist,antennaType.second[a][1]-ydist));
						}
						if(antennaType.second[b][0]-xdist>=0 && antennaType.second[b][1]+ydist<mapLength){
							antinodePoints.insert(make_pair(antennaType.second[b][0]-xdist,antennaType.second[b][1]+ydist));
						}


					} else if (antennaType.second[a][0]<=antennaType.second[b][0] && antennaType.second[a][1]>antennaType.second[b][1]){ // lower Left quadrant
						int xdist = antennaType.second[b][0]-antennaType.second[a][0];
						int ydist = antennaType.second[a][1]-antennaType.second[b][1];
						if(antennaType.second[a][0]-xdist>=0 && antennaType.second[a][1]+ydist<mapLength){
							antinodePoints.insert(make_pair(antennaType.second[a][0]-xdist,antennaType.second[a][1]+ydist));
						}
						if(antennaType.second[b][0]+xdist<mapWidth && antennaType.second[b][1]-ydist>=0){
							antinodePoints.insert(make_pair(antennaType.second[b][0]+xdist,antennaType.second[b][1]-ydist));
						}


					} else{// lower Right quadrant
						int xdist = antennaType.second[a][0]-antennaType.second[b][0];
						int ydist = antennaType.second[a][1]-antennaType.second[b][1];
						if(antennaType.second[a][0]+xdist<mapWidth && antennaType.second[a][1]+ydist<mapLength){
							antinodePoints.insert(make_pair(antennaType.second[a][0]+xdist,antennaType.second[a][1]+ydist));
						}
						if(antennaType.second[b][0]-xdist>=0 && antennaType.second[b][1]-ydist>=0){
							antinodePoints.insert(make_pair(antennaType.second[b][0]-xdist,antennaType.second[b][1]-ydist));
						}

					
					}
				}
			}
		}
	}
	//523
	cout << antinodePoints.size()<<endl;

	return 0;
}
