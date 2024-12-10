#include <bits/stdc++.h>

//day  p1time   p1rank     p2time    p2rank
//4   11:03:23  53427      11:14:49  46466
using namespace std;

int main(){
	// I had a small thought of doing this with regex, to keep with the apparent
	// theme I have been doing? but I was up till 3 last night getting some results
	// so I think I'll just take the easy route :3
	const int width = 140;
	const int length = 140;
	int count = 0; 
	vector<string> input;
	string lines;
	for(int i{0};i<length;i++){
		getline(cin,lines);
		input.push_back(lines);
	}
	for(int i{1};i<length-1;i++){
		for(int j{1};j<length-1;j++){
			if((input[i][j]=='A') &&
			((input[i-1][j-1]=='M' && input[i+1][j+1]=='S' && input[i+1][j-1]=='S' && input[i-1][j+1]=='M')
			||  (input[i-1][j-1]=='M' && input[i+1][j+1]=='S' && input[i+1][j-1]=='M' && input[i-1][j+1]=='S')
			||  (input[i-1][j-1]=='S' && input[i+1][j+1]=='M' && input[i+1][j-1]=='M' && input[i-1][j+1]=='S')
			||  (input[i-1][j-1]=='S' && input[i+1][j+1]=='M' && input[i+1][j-1]=='S' && input[i-1][j+1]=='M') )){
				
				count++;

			}
		}
	}

	cout << count << endl;
	return 0;
}



