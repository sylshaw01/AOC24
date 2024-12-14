#include <bits/stdc++.h>

using namespace std;
//got to the computer at 8:40 ish
//
//I'm guessing part 2 will be 10^many seconds?
int main(){
	int noOfRobots = 500;
	//int noOfRobots = 12;
	long long width = 101;
	long long length = 103;
	//long long width = 11;
	//long long length = 7;
	vector<vector<int>> robotpositions;
	vector<long long> safety = {0,0,0,0};
	long long seconds = 100;;
	string inputLine;
	for(int i{0};i<noOfRobots;i++){
		getline(cin,inputLine);
		cout << endl;
		regex numbers("(-*[0-9]+)");
		auto beg = sregex_iterator(inputLine.begin(),inputLine.end(),numbers);
		auto end = sregex_iterator();
		long long rx, ry, vx, vy;
		vector<long long> nums;
		for(sregex_iterator i = beg; i!= end; ++i){
			smatch num = *i;
			string numStr = num.str();
			nums.push_back(stoll(numStr));
		}
		rx = nums[0];
		ry = nums[1];
		vx = nums[2];
		while(vx<0){
			vx +=width;
		}
		vy = nums[3];
		while(vy<0){
			vy+=length;
		}
		long long posx, posy;
		
		posx = (rx+(seconds * vx))%width;
		posy = (ry + (seconds*vy))%length;
		cout << posx << " " << posy << endl;
		if(posx<((width-1)/2) && posy<((length-1)/2)){
			safety[0]++;
		}else if(posx<((width-1)/2) && posy>((length-1)/2)){
			safety[1]++;
		}else if(posy<((length-1)/2) && posx>((width-1)/2)){
			safety[2]++;
		}else if(posx>((width-1)/2) && posy>((length-1)/2)){
			safety[3]++;
		}


		
	}
	cout << endl;
	cout << safety[0] << " " << safety[1] << " " << safety[2] << " " << safety[3] << endl;
	cout << safety[0]*safety[1]*safety[2]*safety[3] << endl;


	return 0;
}

