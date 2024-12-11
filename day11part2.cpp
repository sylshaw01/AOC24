#include <bits/stdc++.h>
#include "BigInt.hpp"

using namespace std;

//Obviously my part1 code was not going to run to 75 within the lifetime of the universe
//
//
//what have I done
//what have I done
//what have I done
//
//is this a dynamic programming problem that I'm trying to do by hand? 
//
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
vector<BigInt> twoStep(BigInt item, map<BigInt, vector<BigInt>>& mem, map<BigInt,vector<BigInt>>& mem2){
	if(mem2.count(item)>0){
		return mem2[item];
	}else{
		vector<BigInt> stepOne = oneStep(item,mem);
		vector<BigInt> ret = oneStep(stepOne[0],mem);
		for(int i{1};i<stepOne.size();i++){
			vector<BigInt> add = oneStep(stepOne[i],mem);
			ret.insert(ret.end(),add.begin(),add.end());
		}
		mem2[item] = ret;
		return ret;
	}

}

vector<BigInt> fourStep(BigInt item, map<BigInt, vector<BigInt>>& mem, map<BigInt,vector<BigInt>>& mem2, map<BigInt,vector<BigInt>>& mem4){
	if(mem4.count(item)>0){
		return mem4[item];
	}else{
		vector<BigInt> stepTwo = twoStep(item,mem,mem2);
		vector<BigInt> ret = twoStep(stepTwo[0],mem,mem2);
		for(int i{1};i<stepTwo.size();i++){
			vector<BigInt> add = twoStep(stepTwo[i],mem,mem2);
			ret.insert(ret.end(),add.begin(),add.end());
		}
		mem4[item] = ret;
		return ret;
	}

}
vector<BigInt> eightStep(BigInt item, map<BigInt, vector<BigInt>>& mem, map<BigInt,vector<BigInt>>& mem2, map<BigInt,vector<BigInt>>& mem4,map<BigInt,vector<BigInt>>& mem8){
	if(mem8.count(item)>0){
		return mem8[item];
	}else{
		vector<BigInt> stepFour = fourStep(item,mem,mem2,mem4);
		vector<BigInt> ret = fourStep(stepFour[0],mem,mem2,mem4);
		for(int i{1};i<stepFour.size();i++){
			vector<BigInt> add = fourStep(stepFour[i],mem,mem2,mem4);
			ret.insert(ret.end(),add.begin(),add.end());
		}
		mem8[item] = ret;
		return ret;
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
	map<BigInt,vector<BigInt>> memory2;
	map<BigInt, vector<BigInt>> memory4;
	map<BigInt,vector<BigInt>> memory8;
	memory1[0] = {BigInt(1)};
	
	for(int blinks{0};blinks<75;blinks++){
		
		cout << "blinkno: " << blinks << "\n";
		cout << "size: " << puzzleInput.size() << "\n";
		cout << "mapsize: " << memory1.size() << "\n";
		cout << "mapsize2: " << memory2.size() << "\n";
		cout << "mapsize4: " << memory4.size() << "\n";
		cout << "mapsize8: " << memory8.size() << "\n";
		//cout << puzzleInput[0] << "\n";
		//cout << memory.count(puzzleInput[0]) << "\n";	
		long long fixsize = puzzleInput.size();
		//vector<BigInt> newarr;
		map<BigInt,long long> newmap;
		for(auto item:puzzleInput){
		//	cout << memory.count(puzzleInput[0]) << "count\n";
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
		fixsize = puzzleInput.size();
		cout << "\n";
		if(blinks<4){
		//for(int i{0};i<puzzleInput.size();i++){
		//	cout << puzzleInput[i] << " ";
		//}
		cout << "\n";
	}
	
	}
	long long fixsize = puzzleInput.size();
	vector<BigInt> endi;
	//for(long long j{0};j<fixsize;j++){
	//		vector<BigInt> add = twoStep(puzzleInput[j],memory1,memory2);
	//		endi.insert(endi.end(),add.begin(),add.end());
	//	}
	//fixsize = endi.size();
	//puzzleInput = endi;
	//endi = {};
	//for(long long j{0};j<fixsize;j++){
	//		vector<BigInt> add = oneStep(puzzleInput[j],memory1);
	//		endi.insert(endi.end(),add.begin(),add.end());
	//	}
	//map<BigInt,int> newmap;
	//	for(auto item:puzzleInput){
	//		vector<BigInt> add = twoStep(item.first,memory1,memory2);
	//		sort(add.begin(),add.end());
	//		for(int i{0};i<add.size();i++){
	//			if(i>0 && add[i]==add[i-1]){
	//			} else{
	//			if(newmap.count(add[i])>0){
	//				newmap[add[i]]+=(count(add.begin(),add.end(),add[i])*item.second);
	//			}else{
	//				newmap[add[i]] = count(add.begin(),add.end(),add[i])*item.second;
	//			}
	//			}
	//		}
//
//		}
//	puzzleInput = newmap;
//	map<BigInt,int> newnewmap;
//		for(auto item:puzzleInput){
//		//	cout << memory.count(puzzleInput[0]) << "count\n";
//			vector<BigInt> add = oneStep(item.first,memory1);
//			sort(add.begin(),add.end());
//			for(int i{0};i<add.size();i++){
//				if(i>0 && add[i]==add[i-1]){
//				} else{
//				if(newnewmap.count(add[i])>0){
//					newnewmap[add[i]]+=(count(add.begin(),add.end(),add[i])*item.second);
//				}else{
//					newnewmap[add[i]] = count(add.begin(),add.end(),add[i])*item.second;
//				}
//				}
//			}
//
//		}
//	puzzleInput = newnewmap;
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
