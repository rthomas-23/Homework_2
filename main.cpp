#include "ATC.h"
#include "Plane.h"
#include <map>
#include <string>
#include <random>
#include "HW2_Visualizer.h"
using namespace std;


int main(int argc, char** argv)
{
	HW2_VIZ viz;

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
	// Update plane register
	ATC atc;
	atc.register_plane(A);
	atc.register_plane(B);
	atc.register_plane(C);
	atc.register_plane(D);
	atc.register_plane(E);
	atc.register_plane(F);
	atc.register_plane(G);

	double dt = 50; // seconds
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
		viz.visualize_plane(A.plane_type(), A.getorigin(), A.getdestination(), A.getpos());
		viz.visualize_plane(B.plane_type(), B.getorigin(), B.getdestination(), B.getpos());
		viz.visualize_plane(C.plane_type(), C.getorigin(), C.getdestination(), C.getpos());
		viz.visualize_plane(D.plane_type(), D.getorigin(), D.getdestination(), D.getpos());
		viz.visualize_plane(E.plane_type(), E.getorigin(), E.getdestination(), E.getpos());
		viz.visualize_plane(F.plane_type(), F.getorigin(), F.getdestination(), F.getpos());
		viz.visualize_plane(G.plane_type(), G.getorigin(), G.getdestination(), G.getpos());

		viz.update(dt);
	}

	return 0;
}
