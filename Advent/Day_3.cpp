#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
using namespace std;

// Day 1
// vector<string> lines;
// bool check_left(smatch base){
// 	string prefix=base.prefix().str();
// 	if (prefix.size()==0){return false;}
// 	if (prefix.substr(prefix.size()-1,1)=="."){return false;}
// 	return true;
// }
// bool check_right(smatch base){
// 	string suffix=base.suffix().str();
// 	if (suffix.size()==0){return false;}
// 	if (suffix.substr(0,1)=="."){return false;}
// 	return true;
// }

// bool check_top(smatch base,int index,int start){
// 	string prefix=base.prefix().str();
// 	string suffix=base.suffix().str();
// 	string line=lines[index];
// 	string top=lines[index-1];
// 	if (index==0){return false;}
// 	//int start=line.find(base.prefix().str()+base[0].str())+base.prefix().str().size();
// 	int end=start+base[0].str().size();
// 	if (start==0){start=1;}
// 	if (end>=lines[0].size()){end=lines[0].size()-2;}
// 	for (int i=start-1;i<end+1;i++){
// 		if (top.substr(i,1)!="."){return true;}
// 	}
// 	return false;
// }

// bool check_bottom(smatch base,int index,int start){
// 	string prefix=base.prefix().str();
// 	string suffix=base.suffix().str();
// 	string line=lines[index];
// 	string top=lines[index+1];
// 	if (index==lines.size()-1){return false;}
// 	int end=start+base[0].str().size();
// 	if (start==0){start=1;}
// 	if (end>=lines[0].size()){end=lines[0].size()-2;}
// 	for (int i=start-1;i<end+1;i++){
// 		if (top.substr(i,1)!="."){return true;}
// 	}
// 	return false;
// }

// int main(){
// 	fstream input("input.txt");
// 	string txt;
// 	while (getline(input,txt)){lines.push_back(txt);}
// 	int total=0;
// 	int line_num=0;
// 	for (auto line:lines){
// 		smatch base;
// 		int index=0;
// 		while (regex_search(line,base,regex("\\d+"))){
// 			index+=base.prefix().str().size();
// 			bool left=check_left(base);
// 			bool right=check_right(base);
// 			bool top=check_top(base,line_num,index);
// 			bool bottom=check_bottom(base,line_num,index);
// 			index+=base[0].str().size();
// 			if (left==true||right==true||top==true||bottom==true){
// 				int Num=stoi(base[0].str());
// 				total+=Num;
// 			}
// 			line=base.suffix().str();
// 		}
// 		line_num+=1;
// 	}
// 	cout<<"Total: "<<total<<endl;
// 	return 0;
// }

// Day 2
vector<string> lines;

string check_left(int index,int start){
	string result="-1";
	string prefix=lines[index].substr(0,start);
	smatch match;
	while (regex_search(prefix,match,regex("\\d+"))){
		if (match.suffix().str().size()==0){result=match[0].str();}
		prefix=match.suffix().str();
	}
	return result;
}

string check_right(int index,int start){
	string result="-1";
	string suffix=lines[index].substr(start+1);
	smatch match;
	if (regex_search(suffix,match,regex("\\d+"))){
		if (match.prefix().str().size()==0){result=match[0].str();}
	}
	return result;
}

string check_top(int index,int start){
	string result="-1";
	if (index==0){return "-1";}
	smatch top;
	// Directly above
	string c=lines[index-1].substr(start,1);
	if (regex_search(c,top,regex("\\d"))){
		result="0";
		string L=check_left(index-1,start);
		string R=check_right(index-1,start);
		if (L!="-1"){result+=L;}
		result+=top[0].str();
		if (R!="-1"){result+=R;}
	}
	return result;
}
string check_bottom(int index,int start){
	string result="-1";
	if (index==lines.size()-1){return "-1";}
	smatch bot;
	// Directly below
	string c=lines[index+1].substr(start,1);
	if (regex_search(c,bot,regex("\\d"))){
		result="0";
		string L=check_left(index+1,start);
		string R=check_right(index+1,start);
		if (L!="-1"){result+=L;}
		result+=bot[0].str();
		if (R!="-1"){result+=R;}
	}
	return result;
}

string check_top_left(int index,int start){
	if (index==0){return "-1";}
	return (check_left(index-1,start));
}
string check_top_right(int index,int start){
	if (index==0){return "-1";}
	return (check_right(index-1,start));
}
string check_bottom_left(int index,int start){
	if (index==lines.size()-1){return "-1";}
	return (check_left(index+1,start));
}
string check_bottom_right(int index,int start){
	if (index==lines.size()-1){return "-1";}
	return (check_right(index+1,start));
}

int main(){
	fstream input("input.txt");
	string txt;
	while (getline(input,txt)){lines.push_back(txt);}

	int line_num=0;
	int total=0;
	for (auto line:lines){
		//cout<<line<<endl;
		smatch base;
		int index=0;
		while (regex_search(line,base,regex("\\*"))){
			vector<int> positives;
			cout<<lines[line_num]<<endl;
			index+=base.prefix().str().size();
			int left=stoi(check_left(line_num,index));
			int right=stoi(check_right(line_num,index));
			int top=stoi(check_top(line_num,index));
			int bottom=stoi(check_bottom(line_num,index));
			int top_left=stoi(check_top_left(line_num,index));
			int top_right=stoi(check_top_right(line_num,index));
			int bottom_left=stoi(check_bottom_left(line_num,index));
			int bottom_right=stoi(check_bottom_right(line_num,index));

			int total_negatives=0;
			if (left==-1){total_negatives++;}
			else{positives.push_back(left);}
			if (right==-1){total_negatives++;}
			else{positives.push_back(right);}
			if (top==-1){
				total_negatives++;
				if (top_left==-1){total_negatives++;}
				else{positives.push_back(top_left);}
				if (top_right==-1){total_negatives++;}
				else{positives.push_back(top_right);}
			}
			else{positives.push_back(top);}
			if (bottom==-1){
				total_negatives++;
				if (bottom_left==-1){total_negatives++;}
				else{positives.push_back(bottom_left);}
				if (bottom_right==-1){total_negatives++;}
				else{positives.push_back(bottom_right);}
			}
			else{positives.push_back(bottom);}
			if (top!=-1){total_negatives+=2;}
			if (bottom!=-1){total_negatives+=2;}

			if (total_negatives==6){
				cout<<"Total positives:"<<positives.size()<<endl;
				cout<<"Multiplying:"<<positives[0]<<", "<<positives[1]<<endl;
				total+=positives[0]*positives[1];
			}

			line=base.suffix().str();
			index+=1;
			cout<<endl;
		}
		line_num+=1;
	}
	cout<<"Total:"<<total<<endl;
}