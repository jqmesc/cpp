#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
using namespace std;

vector<string> lines;
bool check_left(smatch base){
	string prefix=base.prefix().str();
	if (prefix.size()==0){return false;}
	if (prefix.substr(prefix.size()-1,1)=="."){return false;}
	return true;
}
bool check_right(smatch base){
	string suffix=base.suffix().str();
	if (suffix.size()==0){return false;}
	if (suffix.substr(0,1)=="."){return false;}
	return true;
}

bool check_top(smatch base,int index,int start){
	string prefix=base.prefix().str();
	string suffix=base.suffix().str();
	string line=lines[index];
	string top=lines[index-1];
	if (index==0){return false;}
	//int start=line.find(base.prefix().str()+base[0].str())+base.prefix().str().size();
	int end=start+base[0].str().size();
	if (start==0){start=1;}
	if (end>=lines[0].size()){end=lines[0].size()-2;}
	for (int i=start-1;i<end+1;i++){
		if (top.substr(i,1)!="."){return true;}
	}
	return false;
}

bool check_bottom(smatch base,int index,int start){
	string prefix=base.prefix().str();
	string suffix=base.suffix().str();
	string line=lines[index];
	string top=lines[index+1];
	if (index==lines.size()-1){return false;}
	int end=start+base[0].str().size();
	if (start==0){start=1;}
	if (end>=lines[0].size()){end=lines[0].size()-2;}
	for (int i=start-1;i<end+1;i++){
		if (top.substr(i,1)!="."){return true;}
	}
	return false;
}

int main(){
	fstream input("input.txt");
	string txt;
	while (getline(input,txt)){lines.push_back(txt);}
	int total=0;
	int line_num=0;
	for (auto line:lines){
		smatch base;
		int index=0;
		while (regex_search(line,base,regex("\\d+"))){
			index+=base.prefix().str().size();
			bool left=check_left(base);
			bool right=check_right(base);
			bool top=check_top(base,line_num,index);
			bool bottom=check_bottom(base,line_num,index);
			index+=base[0].str().size();
			if (left==true||right==true||top==true||bottom==true){
				int Num=stoi(base[0].str());
				total+=Num;
			}
			line=base.suffix().str();
		}
		line_num+=1;
	}
	cout<<"Total: "<<total<<endl;
	return 0;
}