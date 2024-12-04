#include <bits/stdc++.h>
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
	//vertical
	for(int i{0};i<length-3;i++){
		for(int j{0};j<width;j++){
			if((input[i][j]=='X' && input[i+1][j]=='M' && input[i+2][j]=='A' && input[i+3][j]=='S') || (input[i][j]=='S' && input[i+1][j] == 'A' && input[i+2][j] == 'M' && input[i+3][j] == 'X')){
				count++;
			}
		}
	}
	//forward diagonal
	for(int i{0};i<length-3;i++){
		for(int j{0};j<width-3;j++){
			if((input[i][j]=='X' && input[i+1][j+1]=='M' && input[i+2][j+2]=='A' && input[i+3][j+3]=='S') || (input[i][j]=='S' && input[i+1][j+1] == 'A' && input[i+2][j+2] == 'M' && input[i+3][j+3] == 'X')){
				count++;
			}
		}
	}
	//horizontal
	for(int i{0};i<length;i++){
		for(int j{0};j<width-3;j++){
			if((input[i][j]=='X' && input[i][j+1]=='M' && input[i][j+2]=='A' && input[i][j+3]=='S') || (input[i][j]=='S' && input[i][j+1] == 'A' && input[i][j+2] == 'M' && input[i][j+3] == 'X')){
				count++;
			}
		}
	}
	//backslant diagonal
	for(int i{0};i<length-3;i++){
		for(int j{3};j<width;j++){
			if((input[i][j]=='X' && input[i+1][j-1]=='M' && input[i+2][j-2]=='A' && input[i+3][j-3]=='S') || (input[i][j]=='S' && input[i+1][j-1] == 'A' && input[i+2][j-2] == 'M' && input[i+3][j-3] == 'X')){
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}



