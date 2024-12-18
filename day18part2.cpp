#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;
vector<vector<int>> adj4 = {{0,1},{-1,0},{0,-1},{1,0}};
//is this just simple dijkstras?
//guess this is as good a time as any to actually learn how to write dijkstras
//got to the computer at 10 past
//i wrote dijkstras!!
//p1 done at 7:15
//p2 done at 7:43
//
//nice! I feel like I actually did smart things there instead of just weird hacks and bruteforce
//learned better what dijkstras is and used binary search in the second part
//day   p1time    p1rank   p2time    p2rank
//18   02:14:41   7617     02:43:33   7683 
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
		if(u==end){
			break;
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
	int inputLength = 3450;
	//int inputLength = 1024;
	//int inputLength = 12;
	int gridsize = 70;
	string inputLine;
	vector<string> inputGrid;
	map<pair<int,int>,int> dist;
	vector<pair<int,int>> potentialFills(inputLength);
	for(int i{0};i<inputLength;i++){
		getline(cin,inputLine);
		vector<int> nums = splitNumLine(inputLine);
		potentialFills[i] = (make_pair(nums[0],nums[1]));
	}
	int l = 1024;
	int r = 4350;
	while(l<=r){
		int mid = (r + l)/2;
		//line input
	//	cout << nums[0] << " " << nums[1] << endl;
		set<pair<int,int>>lfilled;
		for(int i{0};i<=mid;i++){
			lfilled.insert(potentialFills[i]);
		}
		map<pair<int,int>,int> dists = dijkstra(invert(lfilled,gridsize),make_pair(0,0),make_pair(gridsize,gridsize));
		if(dists[make_pair(gridsize,gridsize)]==1e7){
			r = mid-1;
		}else{
			l = mid+1;
		}
		//grid input
		//getline(cin,inputLine);
		//inputGrid.push_back(inputLine);
//		cout << l << " " << r << endl;
	}
//	cout << l << " " << r << endl;

	cout << potentialFills[l].first << "," << potentialFills[l].second << endl;
		
	



	return 0;
}

