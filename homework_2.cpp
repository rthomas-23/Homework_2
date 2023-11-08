// homework.cpp : Defines the entry point for the application.
//

#include "homework_2.h"
#include "ATC.h"
#include "Plane.h"
#include <map>
#include <string>
#include <random>
using namespace std;


int main(int argc, char** argv)
{
	map<string, int> journeys;
	journeys.insert(pair<string, int>("PHL", 160)); // state college to philly distance in miles
	journeys.insert(pair<string, int>("ORD", 640)); // state college to chicago ""
	journeys.insert(pair<string, int>("EWR", 220)); // state college to newark ""
	
	// Instantiate Objects
	Airliner A("AA", "SCE", "PHL");
	A.setvel(470); // MPH
	Airliner B("UA", "SCE", "ORD");
	B.setvel(515);
	Airliner C("UA", "SCE", "EWR");
	C.setvel(480);
	Airliner D("AA", "SCE", "ORD");
	D.setvel(500);
	GeneralAviation E("SCE", "PHL");
	E.setvel(140);
	GeneralAviation F("SCE", "EWR");
	F.setvel(160);
	GeneralAviation G("SCE", "ORD");
	G.setvel(180);

	///////////////////////////////////////////////////
	int num_planes = 5;
	Plane** planes = new Plane * [num_planes];
	planes[0] = &A;
	planes[1] = &B;
	//cout << planes[0]->getvel() << endl;
	A.setvel(100);
	//cout << planes[0]->getvel() << endl;

	// Update plane register
	ATC atc;
	atc.register_plane(A);
	atc.register_plane(B);
	atc.register_plane(C);
	atc.register_plane(D);
	atc.register_plane(E);
	atc.register_plane(F);
	atc.register_plane(G);


	//vector<Plane> a = atc.get_registered_planes();
	//cout << a[0].getdestination() << endl;



	double dt = 50; // seconds
	dt = dt / (60 * 60); // in hours
	double T = 0;
	while (true) {
		T = T + dt;
		A.operate(dt);
		atc.control_traffic();
		B.operate(dt);
		atc.control_traffic();
		C.operate(dt);
		atc.control_traffic();
		D.operate(dt);
		atc.control_traffic();
		E.operate(dt);
		atc.control_traffic();
		F.operate(dt);
		atc.control_traffic();
		G.operate(dt);
		atc.control_traffic();
		//cout << "B at sce? " << B.getat_SCE() <<endl;
		//cout << "A....Position = " << A.getpos() << " miles. Destination = " << A.getdestination() << " time = " << T << " hours" << " at SCE? "<< A.getat_SCE()<< endl;
		//cout << "B....Position = "<<B.getpos()<< " miles. Destination = "<<B.getdestination() << " time = " << T << " hours"<< " at SCE? " << B.getat_SCE()<< endl;
		//cout << "C....Position = " << C.getpos() << " miles. Destination = " << C.getdestination() << " time = " << T << " hours" << " at SCE? " << C.getat_SCE()<<endl;
		//cout << "D....Position = " << D.getpos() << " miles. Destination = " << D.getdestination() << " time = " << T << " hours" << " at SCE? " << D.getat_SCE()<<endl;
		//cout << "E....Position = " << E.getpos() << " miles. Destination = " << E.getdestination() << " time = " << T << " hours" << " at SCE? " << E.getat_SCE()<<endl;
		//cout << "F....Position = " << F.getpos() << " miles. Destination = " << F.getdestination() << " time = " << T << " hours" << " at SCE? " << F.getat_SCE()<<endl;
		//cout << "G....Position = " <<G.getpos()<< " miles. Destination = "<<G.getdestination() << " time = " << T << " hours"<< " at SCE? " << G.getat_SCE()<<endl;
	}

	

	return 0;
}
