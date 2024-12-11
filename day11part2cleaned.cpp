#include <bits/stdc++.h>
#include "BigInt.hpp"

using namespace std;

//day   p1time   p1rank        p2time   p2rank
//11   02:14:54  14608        04:57:49  14840 

vector<BigInt> oneStep(BigInt item, map<BigInt,vector<BigInt>>& mem){
	if(mem.count(item)>0){
		return mem[item];
	}else{
		if(item.to_string().size()%2==0){
			string pi = item.to_string();
			long long len = pi.size();
			mem[item] = {BigInt(pi.substr(0,len/2)),BigInt(pi.substr(len/2,len/2))};
			return mem[item];
		}else{
			mem[item] = {item*2024};
			return mem[item];
		}
	}
	

}
int main(){
	//this started out being a vector, but by blink number 50 it got so big that it crashed my terminal :/ so I realised that a lot of the numbers are repeated, so why can't I just use a map for counting the distinct elements
	
	//vector<BigInt> puzzleInput(8);
	map<BigInt,long long> puzzleInput;
	for(int i{0};i<8;i++){
		string tmp;
		cin >> tmp;
		puzzleInput[tmp] = 1;
	}
	map<BigInt,vector<BigInt>> memory1;
	memory1[0] = {BigInt(1)};
	
	for(int blinks{0};blinks<75;blinks++){
		
		map<BigInt,long long> newmap;
		for(auto item:puzzleInput){
			vector<BigInt> add = oneStep(item.first,memory1);
			sort(add.begin(),add.end());
			for(int i{0};i<add.size();i++){
				if(i>0 && add[i]==add[i-1]){
				} else{
				if(newmap.count(add[i])>0){
					newmap[add[i]]+=(count(add.begin(),add.end(),add[i])*item.second);
				}else{
					newmap[add[i]] = count(add.begin(),add.end(),add[i])*item.second;
				}
				}
			}

		}
		puzzleInput = newmap;
	}
	
	long long size = 0;
	for(auto item: puzzleInput){
		size+=(item.second);
	}
	cout << size << "\n";
//5107771263
//7985770355
	//5107771263
	return 0;
}

//okay wow that was a journey, lessons learned you really just need to put everything in a hashmap after all (I think c++ maps are balanced binary trees? not actual hashmaps but w/e)// I'm going to prune down this a LOT
