#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
using namespace std;

int total_wins(vector<int> win,vector<int> you){
	int total=0;
	for (auto Y:you){
		for (auto W:win){
			if (Y==W){
				total+=1;
			}
		}
	}
	return total;
}

vector<vector<int>> wins;
vector<vector<int>> yous;

// Day 1
/*
int main(){
	// Input data
	fstream input("input.txt");
	string txt;
	while (getline(input,txt)){
		int game_num=wins.size();
		smatch base,divider,digit;

		// Remove game #
		regex_search(txt,base,regex(":"));
		txt=base.suffix().str();
		regex_search(txt,divider,regex("\\|"));

		// Insert winning #s
		vector<int> win;
		string prefix=divider.prefix().str();
		while (regex_search(prefix,digit,regex("\\d+"))){
			win.push_back(stoi(digit[0].str()));
			prefix=digit.suffix().str();
		}

		// Insert your #s
		vector<int> you;
		string suffix=divider.suffix().str();
		while (regex_search(suffix,digit,regex("\\d+"))){
			you.push_back(stoi(digit[0].str()));
			suffix=digit.suffix().str();
		}

		// Insert to total
		wins.push_back(win);
		yous.push_back(you);
	}
	int total=0;
	for (int i=0;i<wins.size();i++){
		int sum=0;
		int winning_numbers=total_wins(wins[i],yous[i]);
		for (int n=0;n<winning_numbers;n++){
			if (n==0){sum+=1;}
			else{sum*=2;}
		}
		total+=sum;
	}
	cout<<"Total:"<<total<<endl;
}
*/

vector<int> duplicates;
int main(){
	// Input data
	fstream input("input.txt");
	string txt;
	while (getline(input,txt)){
		int game_num=wins.size();
		smatch base,divider,digit;

		// Remove game #
		regex_search(txt,base,regex(":"));
		txt=base.suffix().str();
		regex_search(txt,divider,regex("\\|"));

		// Insert winning #s
		vector<int> win;
		string prefix=divider.prefix().str();
		while (regex_search(prefix,digit,regex("\\d+"))){
			win.push_back(stoi(digit[0].str()));
			prefix=digit.suffix().str();
		}

		// Insert your #s
		vector<int> you;
		string suffix=divider.suffix().str();
		while (regex_search(suffix,digit,regex("\\d+"))){
			you.push_back(stoi(digit[0].str()));
			suffix=digit.suffix().str();
		}

		// Insert to total
		wins.push_back(win);
		yous.push_back(you);
		duplicates.push_back(0);
	}
	int total=wins.size();

	// Insert duplicates
	for (int i=0;i<wins.size();i++){
		int winning_numbers=total_wins(wins[i],yous[i]);
		cout<<"Total winning numbers:"<<winning_numbers<<endl;
		for (int n=0;n<winning_numbers;n++){
			duplicates[i+n+1]+=1;
		}
		for (int j=0;j<duplicates[i];j++){
			for (int n=0;n<winning_numbers;n++){
				duplicates[i+n+1]+=1;
			}
		}
		total+=duplicates[i];
	}
	cout<<"Total:"<<total<<endl;
}
//(358343) too low