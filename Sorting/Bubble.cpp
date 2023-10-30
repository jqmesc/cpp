/* Bubble Sort */
/* Swap each adjacent value */

#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &v,int p1, int p2){
	int p3=v[p1];
	v[p1]=v[p2];
	v[p2]=p3;
}

void Sort(vector<int> &v) {
	for (int n=0;n<v.size();n++){
		for (int i=0;i<v.size()-1;i++){
			if (v[i]>v[i+1]){
				swap(v,i,i+1);
			}
		}
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
