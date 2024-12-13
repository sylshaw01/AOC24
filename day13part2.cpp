#include <bits/stdc++.h>


using namespace std;
//starting at 6:03
//day    p1time   p1rank    p2time   p2rank
//13   02:53:55  11110     02:56:26   7347  
//
//
//I wonder what part 2 will be? combining them into one big prize machine?
//firstly it wont be possible if b1 and b2 are colinear, it will also not be possible if the prize lies outside the 
//hmm wait is this a dynamic programming problem? do I figure out all the possible locations I can go with my different buttons
//amount of steps to get to (x,y) = amount of steps to get to (x-b1x,y-b1y) + amount of steps to get to (x-b2x,y-b2y)
//does this work?? I haven't really done dynamic programing before
//then if the norm of x,y is greater than the norm of the prize, then it can't be possible
//
//just a quick check on memory, each step has norm about 70? then each prize has a norm at wost about 22000, so there would be at worst about 300k points at worst, thats manageable?u
//I wonder is part 2 going to let you go negative on steps? that seems like a nice generalisation
//I have no idea what I'm doing
//could I search over a bitmask? between a certain range
//
//okay I accidentally had a hint because I looked on the AoC reddit, the hint I got was `linear algebra' and so I think the solution goes as follows
//
//  ( b1x   b2x ) ( apresses) = (tx) 
//  ( b1y   b2y ) ( bpresses) = (ty)
//			so you just need to invert the matrix and if apresses and bpresses are integers, then you are done
//			I don't like this it feels like cheating :( I never would have thought to use linear algebra here, but I think at least I will in the future
//			always remember, x of one thing + y of other = target can be linear algebra!!
// I think also this solution is unique? unless the buttons are colinear AND line up with the puzzle or they are orthogonal, which in this case would mean they are only x and only y
// which I don't think they are
//

vector<int> dp(int b1x, int b1y, int b2x, int b2y, int targetX, int targetY){
	int aSteps,bSteps;
	double targetSlope = (double)targetY/targetX;


	
	vector<int> moreA = dp(b1x,b1y,b2x,b2y,targetX+b1x,targetY+b1y);
	vector<int> moreB = dp(b1x,b1y,b2x,b2y,targetX+b2x,targetY+b2y);
	
	return {aSteps,bSteps};
}

int main(){
	long long b1x, b1y, b2x, b2y, tx, ty, aprep, bprep;
	long long sum=0;
	int t = 320;
	string inp;
	for(int i{0};i<t;i++){
		//cout << "test" << endl;
		cin >> inp;
		cin >> inp;
		cin >> inp;
		//cout << inp.substr(2,2) << endl;
		
		//cout << inp << endl;
		b1x = stoll(inp.substr(2,2));
		cin >> inp;
		b1y = stoll(inp.substr(2,2));
		cin >> inp;
		cin >> inp;
		cin >> inp;
		//cout << inp.substr(2,2);
		//cout << inp << endl;
		b2x = stoll(inp.substr(2,2));
		cin >> inp;
		b2y = stoll(inp.substr(2,2));
		cin >> inp;
		cin >> inp;
		//cout << inp.substr(2,inp.size()-3);
		tx = stoll(inp.substr(2,inp.size()-3));
		tx+=10000000000000;
		//cout << tx << endl;
		cin >> inp;
		//cout << inp.substr(2,inp.size()-3);
		ty = stoll(inp.substr(2,inp.size()-2));
		ty+=10000000000000;
		//cout << ty << endl;
		long long det = (b1x * b2y) - (b2x * b1y);
		aprep = (b2y*tx) - (b2x * ty);
		bprep = (b1x*ty) - (b1y*tx);
		if((floor((double)aprep/det)<((double)aprep/det)) || (floor((double)bprep/det)<((double)bprep/det)) || bprep/det<0 || aprep/det<0){
			
		}else{

			sum+=(3*(aprep/det)) + (bprep/det);
		}
	}

//26689	
	cout << sum << endl;
	return 0;
}

//agh! I still feel bad for seeing the linear algebra spoiler because it just trivialises the entire problem. I got my best ranking ever on part 2 but I don't deserve it.
//also I NEED to work out a better way to do inputs because WHAT IS THIS
