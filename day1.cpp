#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int sum = 0;
	vector<int> n1, n2;
	int num1, num2 = 1;
	while(num2!=0){
		cin >> num1;
		n1.push_back(num1);
		cin >> num2;
		n2.push_back(num2);
	}
	sort(n1.begin(),n1.end());
	sort(n2.begin(),n2.end());
	for(int i{0};i<n1.size();i++){
		sum+=abs(n1[i]-n2[i]);
	}
	cout << sum << endl;


	return 0;
}
