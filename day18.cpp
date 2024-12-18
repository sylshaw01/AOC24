#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;
vector<vector<int>> adj4 = {{0,1},{-1,0},{0,-1},{1,0}};
//is this just simple dijkstras?
//guess this is as good a time as any to actually learn how to write dijkstras
//got to the computer at 10 past
//i wrote dijkstras!!
//p1 done at 7:15
vector<int> splitNumLine(string inputLine){
	regex numbers("(-*[0-9]+)");
	auto beginning = sregex_iterator(inputLine.begin(),inputLine.end(),numbers);
	auto end = sregex_iterator();
	vector<int> matches;
	for(sregex_iterator it= beginning; it!= end; ++it){
		smatch num = *it;
		string numStr = num.str();
		matches.push_back(stoi(numStr));
	}
	return matches;

}

map<pair<int,int>,int> dijkstra(set<pair<int,int>>nodes, pair<int,int> beginning, pair<int,int> end){
	set<pair<int,int>> qnode;
	map<pair<int,int>,pair<int,int>> prev;
	map<pair<int,int>,int> dist;
	for(auto node : nodes){
		dist[make_pair(node.first,node.second)]=1e7;
		qnode.insert(node);	
	//	cout << node.first << " " << node.second << " 1e7 " << endl;
	}
	dist[make_pair(0,0)]=0;
	while(qnode.size()>0){
		pair<int,int> u = *qnode.begin();
		for(auto node : qnode){
			if(dist[node]<dist[u]){
				u = node;
			}
		}
		qnode.erase(u);
		for(auto adj : adj4){
			pair<int, int> potential = make_pair(u.first+adj[0],u.second+adj[1]);
			if(qnode.count(make_pair(u.first+adj[0],u.second+adj[1]))>0){
				int alt = dist[u] + 1;
				if(alt < dist[potential]){
					dist[potential] = alt;
					prev[potential] = u;

				}
			}
		}
	}
	return dist;


}
set<pair<int,int>> invert(set<pair<int,int>> filled, int gridsize){
	set<pair<int,int>> notfilled;
	for(int i{0};i<=gridsize;i++){
		for(int j{0};j<=gridsize;j++){
			if(filled.count(make_pair(j,i))==0){
				notfilled.insert(make_pair(j,i));
			//	cout << '.';
			}else{
			//	cout << '#';
			}
		}
		//cout << endl;
	}
	return notfilled;

}

int main(){
	//int inputLength = 3450;
	int inputLength = 1024;
	//int inputLength = 12;
	int gridsize = 70;
	string inputLine;
	set<pair<int,int>> filled;
	vector<string> inputGrid;
	map<pair<int,int>,int> dist;
	for(int i{0};i<inputLength;i++){
		//line input
		getline(cin,inputLine);
		vector<int> nums = splitNumLine(inputLine);
	//	cout << nums[0] << " " << nums[1] << endl;
		filled.insert(make_pair(nums[0], nums[1]));
			
		//grid input
		//getline(cin,inputLine);
		//inputGrid.push_back(inputLine);
	}
		
	map<pair<int,int>,int> dists = dijkstra(invert(filled,gridsize),make_pair(0,0),make_pair(gridsize,gridsize));
	cout << dists[make_pair(gridsize,gridsize)] << endl;
	



	return 0;
}

