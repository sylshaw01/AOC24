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
					//cout <<antennaType.first << " : " <<  "(" << antennaType.second[a][0] << "," << antennaType.second[a][1] << ") with (" << antennaType.second[b][0] << "," << antennaType.second[b][1] <<  ")\n";
					// Upper left quadrant
					if(antennaType.second[a][0]<=antennaType.second[b][0] && antennaType.second[a][1]<=antennaType.second[b][1]){
						int xdist = antennaType.second[b][0]-antennaType.second[a][0];
						int ydist = antennaType.second[b][1]-antennaType.second[a][1];

						int n=0;
						while((antennaType.second[a][0]-(n*xdist)>=0 && antennaType.second[a][1]-(n*ydist)>=0)||(antennaType.second[b][0]+(n*xdist)<mapWidth && antennaType.second[b][1]+(n*ydist)<mapLength)){
							if(antennaType.second[a][0]-(n*xdist)>=0 && antennaType.second[a][1]-(n*ydist)>=0){
								antinodePoints.insert(make_pair(antennaType.second[a][0]-(n*xdist),antennaType.second[a][1]-(n*ydist)));
							//	cout <<"one " <<  antennaType.second[a][0]-(n*xdist) << " " << antennaType.second[a][1]-(n*ydist) << "\n";
							}
							if(antennaType.second[b][0]+(n*xdist)<mapWidth && antennaType.second[b][1]+(n*ydist)<mapLength){
								antinodePoints.insert(make_pair(antennaType.second[b][0]+(n*xdist),antennaType.second[b][1]+(n*ydist)));
							//	cout << "two " << antennaType.second[b][0]+xdist<<" " << antennaType.second[b][1]+(n*ydist) << "\n";
							}
							n++;
						}
					} else if (antennaType.second[a][0]>antennaType.second[b][0] && antennaType.second[a][1]<=antennaType.second[b][1]){// upper Right quadrant
						int xdist = antennaType.second[a][0]-antennaType.second[b][0];
						int ydist = antennaType.second[b][1]-antennaType.second[a][1];

						int n=0;
						while((antennaType.second[a][0]+(n*xdist)<mapWidth && antennaType.second[a][1]-(n*ydist)>=0)||(antennaType.second[b][0]-(n*xdist)>=0 && antennaType.second[b][1]+(n*ydist)<mapLength)){
							if(antennaType.second[a][0]+(n*xdist)<mapWidth && antennaType.second[a][1]-(n*ydist)>=0){
								antinodePoints.insert(make_pair(antennaType.second[a][0]+(n*xdist),antennaType.second[a][1]-(n*ydist)));
							//	cout << "three " << antennaType.second[a][0]+(n*xdist) << " " << antennaType.second[a][1]-(n*ydist) << "\n";
							}
							if(antennaType.second[b][0]-(n*xdist)>=0 && antennaType.second[b][1]+(n*ydist)<mapLength){
								antinodePoints.insert(make_pair(antennaType.second[b][0]-(n*xdist),antennaType.second[b][1]+(n*ydist)));
							//	cout << "four " << antennaType.second[b][0]-(n*xdist) << " " << antennaType.second[b][1]+(n*ydist) << "\n";
							}
								n++;
							}


					} else if (antennaType.second[a][0]<=antennaType.second[b][0] && antennaType.second[a][1]>antennaType.second[b][1]){ // lower Left quadrant
						int xdist = antennaType.second[b][0]-antennaType.second[a][0];
						int ydist = antennaType.second[a][1]-antennaType.second[b][1];
						int n=0;
						while((antennaType.second[a][0]-(n*xdist)>=0 && antennaType.second[a][1]+(n*ydist)<mapLength)||(antennaType.second[b][0]+(n*xdist)<mapWidth && antennaType.second[b][1]-(n*ydist)>=0)){
							if(antennaType.second[a][0]-(n*xdist)>=0 && antennaType.second[a][1]+(n*ydist)<mapLength){

								antinodePoints.insert(make_pair(antennaType.second[a][0]-(n*xdist),antennaType.second[a][1]+(n*ydist)));
							}
							if(antennaType.second[b][0]+(n*xdist)<mapWidth && antennaType.second[b][1]-(n*ydist)>=0){
								antinodePoints.insert(make_pair(antennaType.second[b][0]+(n*xdist),antennaType.second[b][1]-(n*ydist)));
							}
							n++;
						}


					} else{// lower Right quadrant
						int xdist = antennaType.second[a][0]-antennaType.second[b][0];
						int ydist = antennaType.second[a][1]-antennaType.second[b][1];
						int n=0;
						while((antennaType.second[a][0]+(n*xdist)<mapWidth && antennaType.second[a][1]+(n*ydist)<mapLength)||(antennaType.second[b][0]-(n*xdist)>=0 && antennaType.second[b][1]-(n*ydist)>=0)){
							if(antennaType.second[a][0]+(n*xdist)<mapWidth && antennaType.second[a][1]+(n*ydist)<mapLength){
								antinodePoints.insert(make_pair(antennaType.second[a][0]+(n*xdist),antennaType.second[a][1]+(n*ydist)));
							}
							if(antennaType.second[b][0]-(n*xdist)>=0 && antennaType.second[b][1]-(n*ydist)>=0){
								antinodePoints.insert(make_pair(antennaType.second[b][0]-(n*xdist),antennaType.second[b][1]-(n*ydist)));
							}
							n++;
						}
					
					}
				}
			}
		}
	}
	//523
	//1318
	set<int>::iterator itr;
	for(auto itr: antinodePoints){
	//	cout << itr.first << "," << itr.second << "\n";
	}
	cout << antinodePoints.size()<<endl;
	
	return 0;
}
