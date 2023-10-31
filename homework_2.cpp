// homework.cpp : Defines the entry point for the application.
//

#include "homework_2.h"
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
	cout << "Hello CMake." << endl;
	return 0;
}
