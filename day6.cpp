#include <bits/stdc++.h>
#include <iterator>
using namespace std;
int main(){

	map<int,vector<int>> hmap;
	map<int,vector<int>> vmap;
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
	cout << hmap.size() << " " << vmap.size() << "\n";
	cout << posx << " " << posy << "\n";
	cout << "test" << endl;
	set<pair<int,int>> visited;
	char dir = 'u';
	int sum = 0;
	while(posx!=-1){
		cout << "test2" << endl;
		cout << visited.size() << endl;
		cout << posx << " " << posy << endl;
		if(dir=='u'){
			int closest = 1e7;
			for(int i{0};i<vmap[posx].size();i++){
				if(vmap[posx][i]>posy && (vmap[posx][i]<closest)){
					closest = vmap[posx][i];
				}
			}
			if(closest>1000){
				for(int i{posy};i<130;i++){
					visited.insert(make_pair(posx,i));
				}
				posx=-1;
				posy=-1;
			} else{
				for(int i{posy};i<closest;i++){
					visited.insert(make_pair(posx,i));
				}
				posy = closest-1;
			}
			
			dir='r';
		} else if(dir=='r'){
			int closest = 1e7;
			for(int i{0};i<hmap[posy].size();i++){
				if(hmap[posy][i]>posx && (hmap[posy][i]<closest)){
					closest = hmap[posy][i];
				}
			}
			if(closest>1000){
				for(int i{posx};i<130;i++){
					visited.insert(make_pair(i,posy));
				}
				posx=-1;
				posy=-1;
			} else{
				for(int i{posx};i<closest;i++){
					visited.insert(make_pair(i,posy));
				}
				posx = closest-1;
			}
			dir='d';
		} else if(dir=='d'){
			int closest = -1e7;
			for(int i{0};i<vmap[posx].size();i++){
				if(vmap[posx][i]<posy && (vmap[posx][i]>closest)){
					closest = vmap[posx][i];
				}
			}
			if(closest<-1000){
				for(int i{0};i<=posy;i++){
					visited.insert(make_pair(posx,i));
				}
				posx=-1;
				posy=-1;
			} else{
				for(int i{closest+1};i<=posy;i++){
					visited.insert(make_pair(posx,i));
				}
				posy = closest+1;
			}
			dir='l';
		}else if(dir=='l'){
			int closest = -1e7;
			for(int i{0};i<hmap[posy].size();i++){
				if(hmap[posy][i]<posx && (hmap[posy][i]>closest)){
					closest = hmap[posy][i];
				}
			}
			if(closest<-1000){
				for(int i{0};i<=posx;i++){
					visited.insert(make_pair(i,posy));
				}
				posx=-1;
				posy=-1;
			} else{
				for(int i{closest+1};i<=posx;i++){
					visited.insert(make_pair(i,posy));
				}
				posx = closest+1;
			}
			dir='u';
		}
	}

	cout << visited.size() << "\n";
	return 0;

}

