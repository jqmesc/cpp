#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
using namespace std;

vector<long> seeds;
vector<vector<vector<long>>> locations;
int main(){
	fstream input("input.txt");
	string txt;
	smatch digit;
	// Input data
	getline(input,txt);
	cout<<txt<<endl;
	while (regex_search(txt,digit,regex("\\d+"))){
		seeds.push_back(stol(digit[0].str()));
		txt=digit.suffix().str();
	}
	vector<vector<long>> vec;
	while (getline(input,txt)){	
	cout<<txt<<endl;	
		if (regex_search(txt,digit,regex(":"))){
			vector<vector<long>> new_vec;
			vec=new_vec;
		}
		else if(txt==""){
			locations.push_back(vec);
		}
		else{
			vector<long> n;
			while (regex_search(txt,digit,regex("\\d+"))){
				n.push_back(stol(digit[0].str()));
				txt=digit.suffix().str();
			}
			vec.push_back(n);
		}
		txt=digit.suffix().str();
	}
	locations.push_back(vec);

	// Parse data
	vector<long> result;
	for (auto seed:seeds){
		cout<<"Checking seed:"<<seed<<endl;
		long value=seed;
		for (auto location:locations){
			for (auto line:location){
				long destination_start=line[0];
				long range_start=line[1];
				long range_length=line[2];
				if (range_start>value){continue;}
				if (range_start+range_length<value){continue;}
				long num=value-range_start;
				value=destination_start+num;
				break;
			}
			cout<<"Value:"<<value<<endl;
		}
		cout<<endl<<"LOCATION:"<<value<<endl;
		result.push_back(value);
	}
	long lowest=0;
	for (long i=0;i<result.size();i++){
		if (result[i]<result[lowest]){
			lowest=i;
		}
	}
	cout<<"LOWEST:"<<result[lowest]<<endl;
}