#include <bits/stdc++.h>

using namespace std;
//got to the computer at 8:40 ish
//
//I'm guessing part 2 will be 10^many seconds?
//
//okay to find the christmas tree I guess I look for a trunk? I'm going to look for a long vertical line
//yeah okay this is so rediculously slow I could cry but it works so :)
//day   p1time   p1rank	   p2time    p2rank
//14   04:52:42  14119     05:58:42  12171 
//
//so really it took me like 1h for part 1 and 1h for part 2, actually not too bad?
int main(){
	int noOfRobots = 500;
//	int noOfRobots = 12;
	long long width = 101;
	long long length = 103;
	//long long width = 11;
	//long long length = 7;
	
	vector<vector<long long>> robotpositions(500);
	vector<long long> safety = {0,0,0,0};
	long long seconds = 100;
	string inputLine;
	vector<long long> rx;
	vector<long long> ry;
	vector<long long> vx;
	vector<long long> vy;
	for(int i{0};i<noOfRobots;i++){
		getline(cin,inputLine);
		regex numbers("(-*[0-9]+)");
		auto beg = sregex_iterator(inputLine.begin(),inputLine.end(),numbers);
		auto end = sregex_iterator();
		long long vvx, vvy;
		vector<long long> nums;
		for(sregex_iterator i = beg; i!= end; ++i){
			smatch num = *i;
			string numStr = num.str();
			nums.push_back(stoll(numStr));
		}
		rx.push_back(nums[0]);
		ry.push_back(nums[1]);
		vvx = nums[2];
		vvy = nums[3];
		while(vvx<0){
			vvx +=width;
		}
		vx.push_back(vvx);
		while(vvy<0){
			vvy+=length;
		}
		vy.push_back(vvy);
		
	}
	int flag = 1;
	int stepno = 0;
	while(flag>0){
		string test;
		//cin >> test;
		set<pair<int,int>> pos;
		for(int i{0};i<noOfRobots;i++){
			rx[i]= (rx[i]+vx[i])%width;
			ry[i] = (ry[i]+vy[i])%length;
			pos.insert(make_pair((int)rx[i],(int)ry[i]));
		}
		for(int i{0};i<length;i++){
			for(int j{0};j<width;j++){
				//if(pos.count(make_pair(j,i))>0 ){
				//	cout << 1;
				//}else{
				//	cout << "*";
				//}
				flag = 0;
				for(int k{0};k<10;k++){
					if(pos.count(make_pair(j,(i+k)%length))==0){
						flag = 1;
					}
				}
				if(flag == 0){
					break;
				}
			}
			if(flag==0){
			break;	
		}
		//	cout << endl;
		}
		 ++stepno;
	}
	cout << stepno << endl;



	return 0;
}

