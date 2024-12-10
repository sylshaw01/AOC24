#include <bits/stdc++.h>

//day  p1time   p1rank   p2time    p2rank
//1   10:24:11  56292    14:41:18  73666 

using namespace std;

int main(){

	int num1, num2 = 1;
	map<int,int> n1 ;
	vector<int> n2;
	while(num2 != 0){
		cin >> num1;
		n1[num1]=0;
		
		cin >> num2;
		n2.push_back(num2);
	}
	for(int i{0};i<n2.size();i++){
		if(n1.count(n2[i])){
			n1[n2[i]]++;
		}
	}
	int sum=0;
	for(const auto& [key,value] : n1){
		sum+= key * value;
	}
	cout << sum << endl;
	return 0;
}
