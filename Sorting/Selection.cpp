/* Selection Sort */
/* Swap each value with the lowest */

#include <iostream>
#include <vector>
using namespace std;

int findLowest(vector<int> &v, int index){
	int lowest=index;
	for(int i=index;i<v.size();i++){
		if (v[i]<v[lowest]){
			lowest=i;
		}
	}

	return lowest;
}

void swap(vector<int> &old,int p1, int p2){
	int p3=old[p1];
	old[p1]=old[p2];
	old[p2]=p3;
}

void Sort(vector<int> &old){
	for (int i=0;i<old.size();i++){
		int lowest=findLowest(old,i);
		swap(old,i,lowest);
	}
}

int main(){
    vector<int> v={9,32,8,49,20,1}; // Unsorted

	cout<<"Unsorted:"<<endl;
	for (int i=0;i<un_sorted.size();i++){
		cout<<un_sorted[i]<<' ';
	}
	Sort(un_sorted);
	cout<<"\nSorted:"<<endl;
	for (int i=0;i<un_sorted.size();i++){
		cout<<un_sorted[i]<<' ';
	}
	return 0;
}


