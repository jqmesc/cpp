/* Operator Overloading */

#include <iostream>
using namespace std;

class Integer{
public:
	Integer();
	Integer(int);
	int tostring();
	int get_value();
private:
	int Value;
};

Integer::Integer(){
	this->Value=0;
}
Integer::Integer(int Value){
	this->Value=Value;
}

int Integer::get_value(){
	return Value;
}

int operator+(Integer i,int Value){
	return i.get_value()+Value;
}

int operator-(Integer i,int Value){
	return i.get_value()-Value;
}

int operator++(Integer i,int){
	return i.get_value()+1;
}

int operator--(Integer i,int){
	return i.get_value()-1;
}

int Integer::tostring(){
	return this->Value;
}

int main(){
	Integer Value=Integer();
	Value=Value+5;
	Value=Value--;
	cout<<Value.tostring();
	return 0;
}