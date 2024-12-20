#include <bits/stdc++.h>
using namespace std;
//got to my computer at 6:17
//okay I have the idea to do dijkstras from the end to the beginning so then I store how long it takes to get to the end from every square?? then for each square on the path I can just check 8 squares and see how much they save
//i imagine part 2 will be that cheating is allowed a lot more??
//no way was it a long long issue again??? it just wasnt giving me the right answer to i changed all ints to long long nad now it works?
//part 2 what. I mean I was right but huh
//so I need a function which gives all the taxi cab distance values up until 50, and also gives where they go
//got it wrong so having a little break
//
//oh my goodness I misread the numbers and thought that the cheats could go for 50 spaces instead of 20
//THAT WAS IT aaaa
//could have gotten sub 4k if I realised that before I went on a break for like 20 mins
// day   p1time   p1rank       p2time    p2rank   
// 20   02:16:11   5693       03:05:37   4245
set<pair<pair<long long, long long>, long long>> adj(long long maxdist){
	set<pair<pair<long long, long long>, long long>> adjacencies; // is that how you spell it??
	//I'm not sure how to go about this so I'm just going to draw concentric circles in the taxi cab metric
	long long x, y;
	for(long long i{1};i<=maxdist;i++){
		x = i;
		y = 0;
		while(x!=0){
			adjacencies.insert(make_pair(make_pair(x,y),i));
			x--;
			y++;
		}
		while(y!=0){
			adjacencies.insert(make_pair(make_pair(x,y),i));
			y--;
			x--;
		}
		while(x!=0){
			adjacencies.insert(make_pair(make_pair(x,y),i));
			y--;
			x++;
		}
		while(y!=0){
			adjacencies.insert(make_pair(make_pair(x,y),i));
			x++;
			y++;
		}
	}
	return adjacencies;
}
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
//copying this dijkstra code from day18
vector<vector<long long>> adj4 = {{0,1},{-1,0},{0,-1},{1,0}};
map<pair<long long,long long>,long long> dijkstra(set<pair<long long,long long>>nodes, pair<long long,long long> beginning, pair<long long,long long> end){
	set<pair<long long,long long>> qnode;
	map<pair<long long,long long>,pair<long long,long long>> prev;
	map<pair<long long,long long>,long long> dist;
	for(auto node : nodes){
		dist[make_pair(node.first,node.second)]=1e7;
		qnode.insert(node);	
	//	cout << node.first << " " << node.second << " 1e7 " << endl;
	}
	dist[beginning]=0;
	while(qnode.size()>0){
		pair<long long,long long> u = *qnode.begin();
		for(auto node : qnode){
			if(dist[node]<dist[u]){
				u = node;
			}
		}
		qnode.erase(u);
		for(auto adj : adj4){
			pair<long long, long long> potential = make_pair(u.first+adj[0],u.second+adj[1]);
			if(qnode.count(make_pair(u.first+adj[0],u.second+adj[1]))>0){
				long long alt = dist[u] + 1;
				if(alt < dist[potential]){
					dist[potential] = alt;
					prev[potential] = u;

				}
			}
		}
	}
	return dist;
}


int main(){
	long long inputLength = 141;
//	long long inputLength = 15;
	string inputLine;
	vector<string> inputGrid(inputLength);
	set<pair<long long,long long>>notFilled;
	pair<long long,long long> start;
	pair<long long,long long> end;
	for(long long j{0};j<inputLength;j++){
		//line input
		//getline(cin,inputLine);
		//vector<long long> nums = splitNumLine(inputLine);
		
		//grid input
		getline(cin,inputLine);
		inputGrid.push_back(inputLine);
		for(long long i{0};i<inputLine.size();i++){
			if(inputLine[i] == '.'){
				notFilled.insert(make_pair(i,j));
			}else if(inputLine[i]=='S'){
				start = make_pair(i,j);
				notFilled.insert(start);
			}else if(inputLine[i]=='E'){
				end = make_pair(i,j);
				notFilled.insert(end);
			}
		}
	}
	map<pair<long long,long long>,long long>dist;
	for(auto square: notFilled){
	//	cout << square.first << "    " << square.second << endl;
	}
	dist = dijkstra(notFilled,end,start);
	vector<vector<long long>> adj8 = {{0,2},{1,1},{2,0},{1,-1},{0,-2},{-1,-1},{-2,0},{-1,1}};
	set<pair<pair<long long, long long>,long long>> adj50 = adj(20);
	for(auto adj: adj50){
//		cout << adj.first.first << "   " << adj.first.second << "    " << adj.second << endl;
	}
	map<pair<pair<long long,long long>,pair<long long,long long>>, long long> cheatCount;
	for(auto square : notFilled){
	//	cout << dist[square] << endl;
	//	cout << "working" << endl;	
		for(auto adj : adj50){
			if(notFilled.count(make_pair(square.first + adj.first.first,square.second+adj.first.second))>0){
		//		cout << "test" << endl;
				long long cheatAmount = (dist[make_pair(square.first+adj.first.first,square.second+adj.first.second)]-dist[square])-adj.second;
				if(cheatAmount>0){
					if(cheatCount.count(make_pair(square,make_pair(square.first+adj.first.first,square.second + adj.first.second)))>0){
						if(cheatAmount >= cheatCount[make_pair(square,make_pair(square.first+adj.first.first,square.second+adj.first.second))]){
							
							cheatCount[make_pair(square,make_pair(square.first+adj.first.first,square.second+adj.first.second))]=cheatAmount;
						}
					}else{
					cheatCount[make_pair(square,make_pair(square.first+adj.first.first,square.second+adj.first.second))]=cheatAmount;
					}
				}
			}

		}
	}
	long long ans = 0;
	//cout << dist[start] << endl;
	map<long long,long long> cheatLengthCount;
	
	for(auto cheats : cheatCount){
//		cout << cheats.second << endl;
		if(cheats.second>0){
			if(cheatLengthCount.count(cheats.second)>0){
				cheatLengthCount[cheats.second]++;
			}else{
				cheatLengthCount[cheats.second]=1;
			}
		}
	}
	for(auto ch : cheatLengthCount){
		cout << "There are " << ch.second << " cheats that save " << ch.first << " seconds." << endl;
		if(ch.first>=100){
			ans+=ch.second;	
		}
	}
	cout << ans << endl;


//831106
	//832806
	//1374
	//
	//
	//7830139
	

	return 0;
}

