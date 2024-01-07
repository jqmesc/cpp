/* Pre completion notes
What we want: Avg Speed and Avg Velocity
What we need: Dist, Displacement, Time

Steps: 
- Create an object that moves
- Store position
- Move object and calculate
- Print all values
*/

/* Post completion notes
- Needed to store every movement to get avg between two points
- Only need user to provide initial distance, time/displacement unnecessary
- Works only in ticks every 1
- Cant do abs(x) if x is a float??
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

class object{
public:
	object();
	object(double);
	double get_time();
	double get_distance();
	double get_displacement();
	double get_step(double);
	std::vector<double> get_steps();
	void set_time(double);
	void set_distance(double);
	void set_displacement(double);
	void set_steps(std::vector<double>);
	void wait(double);
	void move(double);
	void step(double);
	double avg_speed();
	double avg_velocity();
	void print();
private:
	double time;
	double distance;
	double displacement;
	std::vector<double> steps;
};

// Constructors
object::object(){
	this->time=0;
	this->distance=0;
	this->displacement=0;
	this->step(0);
}
object::object(double x){ // Position
	this->time=0;
	this->distance=x;
	this->displacement=0;
	this->step(x);
}

// Getters
double object::get_time(){
	return time;
}
double object::get_distance(){
	return distance;
}
double object::get_displacement(){
	return displacement;
}
std::vector<double> object::get_steps(){
	return steps;
}
double object::get_step(double x){
	return steps[x];
}

// Setters
void object::set_time(double x){
	time=x;
}
void object::set_distance(double x){
	distance=x;
}
void object::set_displacement(double x){
	displacement=x;
}
void object::set_steps(std::vector<double> x){
	steps=x;
}
void object::wait(double x){
	this->set_time(this->get_time()+x);
}
void object::move(double x){
	this->set_displacement(this->get_displacement()+x);
	this->set_distance(this->get_distance()+abs(x));
	this->set_time(this->get_time()+1);
	this->step(this->get_displacement());
}
void object::step(double x){
	std::vector<double> current=this->get_steps();
	current.push_back(x);
	this->set_steps(current);
}

// Algorithm
double object::avg_speed(){
	return this->get_distance()/this->get_time();
}
double object::avg_velocity(){
	double dx=this->get_displacement();this->get_step(0);
	return dx/this->get_time();
}

// Display
void object::print(){
	std::cout<<"Time Passed:"<<this->get_time()<<std::endl;
	std::cout<<"Distance Traveled:"<<this->get_distance()-this->get_step(0)<<std::endl;
	std::cout<<"Total Displacement:"<<this->get_displacement()<<std::endl;
	std::cout<<"Average Speed:"<<this->avg_speed()<<std::endl;
	std::cout<<"Average Velocity:"<<this->avg_velocity()<<std::endl;
}

int main(){
	// Example 1
	std::cout<<"Example 1:"<<std::endl<<std::endl;
	const double x1=50; // 50m
	const double x2=30.5; // 30.5m
	double dx=x2-x1;

	object obj(x1); // Initial position
	obj.move(dx); // Move final position
	obj.wait(2); // Pass 2 seconds
	obj.print();

	std::cout<<std::endl;
	std::cout<<std::endl;
	// Example 2
	std::cout<<"Example 2:"<<std::endl<<std::endl;
	// Given
	const int time=60*60*2.5; // 2.5 Hours
	const double rate=18; // 18 km/h
	double kps=rate/60/60; // km/s

	object obj_2;
	for (int i=0;i<time;i++){
		obj_2.move(kps);
	}
	obj_2.print();

	std::cout<<std::endl;
	std::cout<<std::endl;
	// Example 3
	std::cout<<"Example 3:"<<std::endl<<std::endl;
	const double rate_1=50; // 50 km/h
	const double dist_1=100; // 100 km
	const double rate_2=100; // 100 km/h
	const double dist_2=100; // 100 km
	double time_1=dist_1/rate_1;
	double time_2=dist_2/dist_2;

	object obj_3;
	for (int i=0;i<time_1;i++){
		obj_3.move(rate_1);
	}
	for (int i=0;i<time_2;i++){
		obj_3.move(rate_2);
	}
	obj_3.print();
	std::cout<<std::endl;
}