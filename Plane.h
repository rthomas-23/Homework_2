#pragma once
#include <map>
#include <string>
using namespace std;


class Plane {
	double pos, vel, distance, loiter_time;
	bool at_SCE;
	string origin, destination;
	map<string, int> journeys;

protected:
	double wait_time;

public:
	Plane(string from, string to); // constructor overloaded with "to" and "from"
	virtual ~Plane(); // virtual deconstructor
	void operate(double dt);
	double getpos();
	double getvel();
	double getloiter_time();
	string getorigin();
	string getdestination();
	bool getat_SCE();
	void setvel(double A);
	void setloiter_time(double A);
	double distance_to_SCE();
	double virtual time_on_ground();
	string virtual plane_type();
	double static draw_from_normal_dist(double mean, double std);

	void setwait_time(double A); // my additional functions
	double getdistance();
};

class Airliner : public Plane {
private:
	string Airline;
public:
	Airliner(string Airline, string from, string to); // constructor
	~Airliner(); // deconstructor
	string virtual plane_type();
	double time_on_ground();
};

class GeneralAviation : public Plane {
public:
	GeneralAviation(string from, string to); // constructor
	~GeneralAviation();
	double time_on_ground();
};