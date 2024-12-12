#include <bits/stdc++.h>


//woke up at 6:15
//p1 completed at 7:05
//p2 completed at 9:12
//
//I definitely made this *way* too complicated, there is certainly a better solution but this still works :)
//day   p1time    p1rank     p2time   p2rank
//12   02:05:05   9736      04:12:32   7443  
//
//How I spent 2h on part 2 and still got my best ever ranking I have no idea
using namespace std;
int sizemap = 140;
int mapWidth = sizemap;
int mapLength = sizemap;

void search(int i, int j, unordered_set<int>& visited,vector<long long>& area, vector<long long>& perimeter, char head, vector<string>m, set<vector<int>>&sideSet, vector<long long>& sides){
	vector<vector<int>> dxy = {{0,-1},{-1,0},{0,1},{1,0}};
	area[area.size()-1]++;
	visited.insert((mapLength*j)+i);
	for(auto d : dxy){
		if((0<=(j+d[1]))&& ((j+d[1])<mapLength)&&(0<=(i+d[0])) &&((i+d[0]) <mapWidth)){
			if( visited.count((mapLength * (j+d[1])) + (i + d[0]))==0 && m[j+d[1]][i+d[0]]==head){	
				search(i+d[0],j+d[1],visited,area,perimeter,head,m,sideSet, sides);
			}else if(m[j+d[1]][i+d[0]]!=head){
				perimeter[perimeter.size()-1]++;				
			}
			if(m[j+d[1]][i+d[0]]!=head){
				if(d[1]==0 && sideSet.count({i,j,d[0],d[1]})==0){
					sides[sides.size()-1]++;
					int dummyj = j;
					while(dummyj>=0 && m[dummyj][i]==head && m[dummyj][i+d[0]]!=head){
						sideSet.insert({i,dummyj,d[0],d[1]});
						dummyj--;
					}
					dummyj=j+1;
					while(dummyj<mapLength && m[dummyj][i]==head && m[dummyj][i+d[0]]!=head){
						sideSet.insert({i,dummyj,d[0],d[1]});
						dummyj++;
					}
				}
				if(d[0]==0 &&sideSet.count({i,j,d[0],d[1]})==0){
					sides[sides.size()-1]++;
					int dummyi = i;
					while(dummyi>=0 && m[j][dummyi]==head && m[j+d[1]][dummyi]!=head){
						sideSet.insert({dummyi,j,d[0],d[1]});
						dummyi--;
					}
					dummyi=i+1;
					while(dummyi<mapLength && m[j][dummyi]==head && m[j+d[1]][dummyi]!=head){
						sideSet.insert({dummyi,j,d[0],d[1]});
						dummyi++;
					}
				}
			}
		}else{
			perimeter[perimeter.size()-1]++;	
			if(d[1]==0 && sideSet.count({i,j,d[0],d[1]})==0){
				sides[sides.size()-1]++;
				int dummyj = j;
				while(dummyj>=0 && m[dummyj][i]==head ){
					sideSet.insert({i,dummyj,d[0],d[1]});
					dummyj--;
				}
				dummyj=j+1;
				while(dummyj<mapLength && m[dummyj][i]==head ){
					sideSet.insert({i,dummyj,d[0],d[1]});
					dummyj++;
				}
			}
			if(d[0]==0 && sideSet.count({i,j,d[0],d[1]})==0){
				sides[sides.size()-1]++;
				int dummyi = i;
				while(dummyi>=0 && m[j][dummyi]==head ){
					sideSet.insert({dummyi,j,d[0],d[1]});
					dummyi--;
				}
				dummyi=i+1;
				while(dummyi<mapLength && m[j][dummyi]==head ){
					sideSet.insert({dummyi,j,d[0],d[1]});
					dummyi++;
				}
			}
		}
	}

	
}

int main(){
	vector<string> m;
	unordered_set<int> visited;
	vector<long long> area;
	vector<long long> perimeter;
	vector<long long> sides;
	for(int i{0};i<mapLength;i++){
		string line;
		cin >> line;
		m.push_back(line);
	}
	for(int j{0};j<mapLength;j++){
		for(int i{0};i<mapWidth;i++){
			if(visited.count((mapLength * j)+i)>0){
				continue;
			}else{
				area.push_back(0);
				perimeter.push_back(0);
				sides.push_back(0);
				set<vector<int>> sideSet;
				search(i,j,visited,area,perimeter,m[j][i],m,sideSet,sides);
			}
		}
	}
	long long sum1=0;
	long long sum2=0;
	for(int i{0};i<area.size();i++){
		sum1+=area[i] * perimeter[i];
		sum2+=area[i] * sides[i];
	}

	cout << sum1 << endl;
	cout << sum2 << endl;
	
	return 0;
}
