#include <cstdlib>
#include <iostream>
#include "Coord.hpp"
#include "Grille.hpp"
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl

using namespace std;

Coord creeCoord(int lig, int col){
	Coord c;
	c.ligne = lig;
	c.colonne = col;

	return c;
}

void afficheCoord(Coord co){
	cout <<  co.ligne << "," << co.colonne << endl;
}

int getX(Coord co){
	return co.ligne;
}

int getY(Coord co){
	return co.colonne;
}

bool egalCoord(Coord co1, Coord co2){
	if(getX(co1) == getX(co2) and getY(co1) == getY(co2)){
		return true;
	}
	return false;
}

void afficheDirection(Direction direc){
	cout << direc << endl;
}

Direction aGauche(Direction direc){
	if (direc == 0)
	{
		//si on est a 0, on repasse a 7
		direc = (Direction)(7);
	}
	else
	{
		direc = (Direction)(direc - 1);
	}
	return direc;
}

Direction aDroite(Direction direc){
	if (direc == 7)
	{
		//si on est a 7, on repasse a 0
		direc = (Direction)(0);
	}
	else
	{
		direc = (Direction)(direc + 1);
	}
	return direc;
}

Coord devantCoord(Coord co, Direction direc) {

	int ligne = getX(co);
	int colonne = getY(co);

	if (direc == nord_ouest)
	{
		return creeCoord(ligne-1, colonne-1);
	}
	if (direc == nord)
	{
		return creeCoord(ligne-1, colonne);
	}
	if (direc == nord_est)
	{
		return creeCoord(ligne - 1, colonne + 1);
	}
	if (direc == est)
	{
		return creeCoord(ligne, colonne + 1);
	}
	if (direc == sud_est)
	{
		return creeCoord(ligne+1, colonne+1);
	}
	if (direc == sud)
	{
		return creeCoord(ligne + 1, colonne);
	}
	if (direc == sud_ouest)
	{
		return creeCoord(ligne + 1, colonne - 1);
	}
	if (direc == ouest)
	{
		return creeCoord(ligne, colonne - 1);
	}
}