#include <bits/stdc++.h>
#include <chrono>
#include <iterator>
//day  p1time   p1rank    p2time  p2rank
//6   01:44:13  13536   03:09:08  10164

using namespace std;
using namespace chrono;
int main(){
	auto start = high_resolution_clock::now();
	unordered_map<int,vector<int>> hmap;
	unordered_map<int,vector<int>> vmap;
	int posx = 0, posy = 0;
	string line;

	int inlen = 130;
	for(int i{inlen-1};i>=0;i--){
		getline(cin,line);
		for(int j{0};j<line.size();j++){
			if(line[j] == '#'){
				if(hmap.count(i)){
					hmap[i].push_back(j);
				}else{
					hmap[i] = {j};
				}
				if(vmap.count(j)){
					vmap[j].push_back(i);
				} else{
					vmap[j] = {i};
				}
			} else if (line[j] == '^'){
				posx = j;
				posy = i;
			}
		}
		
	}
	set<pair<int,int>> visited;
	char dir = 'u';
	int sum = 0;
	int obsum = 0;
	int step = 0;
	const int startx = posx;
	const int starty = posy;
	unordered_map<int,vector<int>> newhmap(hmap);
	unordered_map<int,vector<int>> newvmap(vmap);
	for(int a{0};a<inlen;a++){
		for(int b{0};b<inlen;b++){
			step = 0;
			dir = 'u';
			newvmap = vmap;
			newhmap = hmap;
			if(newhmap.count(b)){
				newhmap[b].push_back(a);
			}else{
				newhmap[b]={a};
			}
			if(newvmap.count(a)){
				newvmap[a].push_back(b);
			}else{
				newvmap[a] = {b};
			}
			posx = startx;
			posy=starty;


			
	
	
	while(posx!=-1 && step<((2*inlen)+1)){
		if(dir=='u'){
			int closest = 1e7;
			for(int i{0};i<newvmap[posx].size();i++){
				if(newvmap[posx][i]>posy && (newvmap[posx][i]<closest)){
					closest = newvmap[posx][i];
				}
			}
			if(closest>1000){
				posx=-1;
				posy=-1;
			} else{
				posy = closest-1;
			}
			
			dir='r';
		} else if(dir=='r'){
			int closest = 1e7;
			for(int i{0};i<newhmap[posy].size();i++){
				if(newhmap[posy][i]>posx && (newhmap[posy][i]<closest)){
					closest = newhmap[posy][i];
				}
			}
			if(closest>1000){
				posx=-1;
				posy=-1;
			} else{
				posx = closest-1;
			}
			dir='d';
		} else if(dir=='d'){
			int closest = -1e7;
			for(int i{0};i<newvmap[posx].size();i++){
				if(newvmap[posx][i]<posy && (newvmap[posx][i]>closest)){
					closest = newvmap[posx][i];
				}
			}
			if(closest<-1000){
				posx=-1;
				posy=-1;
			} else{
				posy = closest+1;
			}
			dir='l';
		}else if(dir=='l'){
			int closest = -1e7;
			for(int i{0};i<newhmap[posy].size();i++){
				if(newhmap[posy][i]<posx && (newhmap[posy][i]>closest)){
					closest = newhmap[posy][i];
				}
			}
			if(closest<-1000){
				posx=-1;
				posy=-1;
			} else{
				posx = closest+1;
			}
			dir='u';
		}
				step++;
	} if(step>=((2*inlen)+1)){
				obsum++;
			}
		}}
	cout  << obsum << "\n"; 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start);
	//cout << (double)duration.count()/1000000 << "\n";
	//
	//
	//runs in 2.92674s
	return 0;

}

