#include <map>
#include <string>
#include <random>
#include <string>
#include "Plane.h"
#include <iostream>
using namespace std;

//Plane::Plane() {
//	//double wait_time = 0;
//	//double pos, vel, distance, loiter_time;
//	//bool at_SCE;
//	//string origin, destination;
//	//map <string, int> journeys;
//}

// Get functions
double Plane::getpos() { return pos; };
double Plane::getvel() { return vel; };
double Plane::getloiter_time() { return loiter_time; };
string Plane::getorigin() { return origin; };
string Plane::getdestination() { return destination; };
bool Plane::getat_SCE() { return at_SCE; };

// Set functions
void Plane::setvel(double A) { vel = A; };
void Plane::setloiter_time(double A) { loiter_time = A; };

void Plane::setwait_time(double A) { wait_time = A; }; // my addition  public functions
double Plane::getdistance() { return distance; };

// Constructor
Plane::Plane(string from, string to) {
	origin = from;
	destination = to;
	// setup journeys map
	journeys.insert(pair<string, int>("PHL", 160)); // state college to philly distance in miles
	journeys.insert(pair<string, int>("ORD", 640)); // state college to chicago ""
	journeys.insert(pair<string, int>("EWR", 220)); // state college to newark

	distance = journeys[destination]; // THIS IS PROBABLY WRONG AS ONLY WORKS FOR OUTBOUND JOUNRYS FROM SCE
	pos = 0, vel = 0; wait_time = 0; loiter_time = 0; at_SCE = 0;
};

// Deconstructor
Plane::~Plane() {};

void Plane::operate(double dt) {
	if (loiter_time != 0) {
		loiter_time -= dt;
		if (loiter_time < 0) { loiter_time = 0; } // incase of negative time
	}
	else if (wait_time != 0) { 
		wait_time -= dt;
		if (wait_time < 0) { wait_time = 0; } // incase of negative time
	}
	else if (pos < distance) { pos += vel * dt; at_SCE = 0;}
	else if (destination == "SCE") { 
		at_SCE = 1;
		time_on_ground();
		string a = origin;
		string b = destination;
		destination = a; // swap origin and destination
		origin = b;
		pos = 0.0;}
	else {
		time_on_ground();
		string a = origin;
		string b = destination;
		destination = a;
		origin = b;
		pos = 0.0;
	}
}

double Plane::distance_to_SCE() {
	if (destination == "SCE") {
		return (abs(distance - pos));}
	else { return 0; }
	}

double Plane::time_on_ground()
{
	return 0.0;
}

string Plane::plane_type() { return "GA"; };

double Plane::draw_from_normal_dist(double mean, double std) {
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::normal_distribution<> d{ mean, std };
	return d(gen);
}

//////////////////////////////////////
// Airliner
Airliner::Airliner(string Airline, string from, string to) : Plane( from, to) { // constructor
	this->Airline = Airline;
	//Plane(from, to);
};

Airliner::~Airliner() {}; // deconstructor

string Airliner::plane_type() {
	return Airline;
}

double Airliner::time_on_ground() {
	double mean = 1800;
	double std = 600;
	return draw_from_normal_dist(mean, std);
}


// GeneralAviation
GeneralAviation::GeneralAviation(string from, string to) : Plane(from, to) { // constructor
	//Plane::Plane(from, to);
}

GeneralAviation::~GeneralAviation() {}; // deconstructor

double GeneralAviation::time_on_ground() {
	double mean = 600;
	double std = 60;
	return draw_from_normal_dist(mean, std);
}