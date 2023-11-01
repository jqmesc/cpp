/* Insertion Sort */
/* Insert each value back to correct position */

#include <iostream>
#include <vector>
using namespace std;

int findPos(vector<int> &v,int p){
	for (int i=0;i<v.size();i++){
		if (v[i]>p||v[i]==p){
			return i;
		}
	}
	return v.size();
}

void Sort(vector<int> &v){
	for (int i=0;i<v.size();i++){
		int p=findPos(v,v[i]);
		v.insert(v.begin()+p,v[i]);
		v.erase(v.begin()+i+1);
	}
}

int main() {
    vector<int> v={9,32,8,49,20,1}; // Unsorted

	cout<<"Unsorted:"<<endl;
    for (int i=0;i<v.size();i++){
    	cout<<v[i]<<" ";
    }
    cout<<endl;
    Sort(v);
	cout<<"Sorted:"<<endl;
    for (int i=0;i<v.size();i++){
    	cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}