#pragma once
#include <vector>
#include <iostream>
#include "Plane.h"
using namespace std;

#include "ATC.h"
ATC::ATC() {};

ATC::~ATC() {}; // decontructor


void ATC::register_plane(Plane &A) {
	registered_planes[i] = &A;
	i++;
}

void ATC::get_registered_plane() {
	cout << registered_planes[1][0].getvel() << endl;
}

void ATC::control_traffic() {
	int landed_planes = 0;
	int i = 0;
	for (int j = 0; j < numplanes; j++) {
		//cout << " A destination: " << registered_planes[0].getdestination() << endl;
		//cout << "A at SCE (in ATC) : " << registered_planes[0].getat_SCE() << endl;
		if (i < numplanes) {
			landed_planes += registered_planes[i][0].getat_SCE();
			i++;
		}
	}

	//cout << "num registered planes = " << size(registered_planes) << endl;
	// cout << " num landed planes = " << landed_planes << endl;
	if (landed_planes >= MAX_LANDED_PLANE_NUM) {
		i = 0;
		if (i < numplanes) {
			for (i = 0; i < numplanes; i++) {
				if (registered_planes[i][0].getat_SCE() == 0
					&& registered_planes[i][0].distance_to_SCE() <= AIRSPACE_DISTANCE
					&& registered_planes[i][0].getloiter_time() == 0)
				{
					registered_planes[i][0].setloiter_time(100);
					i++;
				}
			}
		}
	}
}