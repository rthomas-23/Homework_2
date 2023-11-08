#pragma once
#include <vector>
#include "Plane.h"
using namespace std;

class ATC {
private: 
	int i = 0;
	int numplanes = 7;
	int MAX_LANDED_PLANE_NUM = 2;
	int AIRSPACE_DISTANCE = 50;
	Plane** registered_planes = new Plane * [numplanes];


public:
	ATC() ; // constructor
	~ATC(); // deconstructor



	void register_plane(Plane &A);
	void get_registered_plane();
	void control_traffic();
};