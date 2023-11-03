// homework.cpp : Defines the entry point for the application.
//

#include "homework_2.h"
#include "Plane.h"
#include <map>
#include <string>
#include <random>
using namespace std;


int main()
{
	map<string, int> journeys;
	journeys.insert(pair<string, int>("PHL", 160)); // state college to philly distance in miles
	journeys.insert(pair<string, int>("ORD", 640)); // state college to chicago ""
	journeys.insert(pair<string, int>("EWR", 220)); // state college to newark ""
	
	// Instantiate Objects
	Airliner A("AA", "SCE", "PHL");
	A.setvel(470); // MPH
	//A.setloiter_time(10);
	//A.setwait_time(100);
	cout <<A.getdistance() << A.getdestination() << endl;

	double dt = 50; // seconds
	dt = dt / (60 * 60); // in hours
	double T = 0;
	while (true) {
		T = T + dt;
		A.operate(dt);
		//cout << A.getvel();
		//cout << A.getdistance();
		cout << "Position = "<<A.getpos()<< " miles. Destination = "<<A.getdestination() << " time = " << T << " hours"<< endl;
	}

	///////////////////////
	//Airliner B("UA", "SCE", "ORD");
	//B.setvel(515);
	//Airliner C("UA", "SCE", "EWR");
	//C.setvel(480);
	//Airliner D("AA", "SCE", "ORD");
	//D.setvel(500);
	//GeneralAviation E("SCE", "PHL");
	//E.setvel(140);
	//GeneralAviation F("SCE", "EWR");
	//F.setvel(160);
	//GeneralAviation G("SCE", "ORD");
	//G.setvel(180);

	// Operating
	//double dt = 50;
	//while (true) {
	//	A.operate(dt);
	//	cout << A.getpos();
	//	B.operate(dt);
	//	C.operate(dt);
	//	D.operate(dt);
	//	E.operate(dt);
	//	F.operate(dt);
	//	G.operate(dt);
	//}

	return 0;
}
