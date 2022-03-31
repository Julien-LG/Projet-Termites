#include <cstdlib>
#include <iostream>
#include "Coord.hpp"
#include "Grille.hpp"
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl

using namespace std;


void testEgalCoord(){
	Coord co1 = creeCoord(2,3);
	Coord co2 = creeCoord(2,3);
	ASSERT(egalCoord(co1, co2) == true);
}

void testDirection1() {
	Direction direc1 = nord;
	Direction direc2 = nord;
	direc2 = aGauche(direc2);
	direc2 = aDroite(direc2);	
	ASSERT(direc1 == direc2);
}

void testDirection2() {
	Direction direc1 = nord;
	Direction direc2 = nord;
	//afficheDirection(direc2);
	for (int i = 0; i < 8; i++)
	{
		direc2 = aGauche(direc2);
	}
	//afficheDirection(direc2);
	for (int i = 0; i < 8; i++)
	{
		direc2 = aDroite(direc2);
	}
	//afficheDirection(direc2);
	ASSERT(direc1 == direc2);
}

void testDevantcoord1() {
	Coord co1 = creeCoord(5, 5);
	Direction direc1 = nord;
	//afficheCoord(co1);
	Coord co2 = creeCoord(4, 5);
	//afficheCoord(co2);	
	ASSERT(egalCoord(devantCoord(co1, direc1), co2) == true);
	//afficheCoord(devantCoord(co1, direc1));
}

void testDevantcoord2() {
	Coord co1 = creeCoord(5, 5);
	Direction direc1 = sud_ouest;
	//afficheCoord(co1);
	Coord co2 = creeCoord(6, 4);
	//afficheCoord(co2);
	ASSERT(egalCoord(devantCoord(co1, direc1), co2) == true);
	//afficheCoord(devantCoord(co1, direc1));
}

void testCoord1() {
	Coord co1 = creeCoord(5, 5);
	Coord co2 = co1;
	Direction direc1 = nord;
	//afficheCoord(co1);

	//avance de 1 case vers le nord
	co1 = devantCoord(co1, direc1);
	for (int i = 0; i < 4; i++)
	{
		direc1 = aDroite(direc1);
	}
	//afficheCoord(co1);
	co1 = devantCoord(co1, direc1);

	//afficheCoord(co1);
	//afficheCoord(co2);
	ASSERT(egalCoord(co1, co2) == true);
}

int main(){
	Coord c1 = creeCoord(2, 1);
	afficheCoord(c1);
	cout << endl;
	testEgalCoord();
	testDirection1();
	testDirection2();
	testDevantcoord1();
	testDevantcoord2();
	testCoord1();
	return 0;
}