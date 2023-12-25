#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <map>
using namespace std;

/*
int main(){
	int total=0;
	regex match("\\d");
	fstream input("input.txt");
	string v;
	while (getline(input,v))
		smatch base;
		vector<string> result;
		while (regex_search(v,base,match)){
			result.push_back(base[0]);
			v=base.suffix().str();
		}
		string First=result[0];
		string Last=result[result.size()-1];
		string Combined=First+Last;
		int Num=stoi(Combined);
		total+=Num;
	}
	cout<<total;
	return 0;
}
*/

// Day 2
int main(){
	map<string,string> s={
		{"oneight","18"},
		{"twone","21"},
		{"threeight","38"},
		{"fiveight","58"},
		{"nineight","98"},
		{"eightwo","82"},
		{"eighthree","83"},
	};
	map<string,string> m={
		{"one","1"},
		{"two","2"},
		{"three","3"},
		{"four","4"},
		{"five","5"},
		{"six","6"},
		{"seven","7"},
		{"eight","8"},
		{"nine","9"},
	};
	int total=0;
	regex match("\\d");
	fstream input("input.txt");
	string v;
	while (getline(input,v))
		smatch base;
		vector<string> result;
		for (auto r:s){
			v=regex_replace(v,regex(r.first),r.second);
		}
		for (auto r:m){
			v=regex_replace(v,regex(r.first),r.second);
		}
		while (regex_search(v,base,match)){
			result.push_back(base[0]);
			v=base.suffix().str();
		}
		string First=result[0];
		string Last=result[result.size()-1];
		string Combined=First+Last;
		int Num=stoi(Combined);
		total+=Num;
	}
	cout<<total;
	return 0;
}