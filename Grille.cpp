#include <cstdlib>
#include <iostream>
#include "Coord.hpp"
#include "Grille.hpp"
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl

using namespace std;

void initialiseGrilleVide(Grille &gri) {
	Case caseVide;
	caseVide.brindille = -1;
	caseVide.termite = -1;

	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			gri.tab[i][j] = caseVide;		
		}
	}
}

bool estVide(Grille gri, Coord co) {
	if (gri.tab[getX(co)][getY(co)].brindille != -1 or gri.tab[getX(co)][getY(co)].termite != -1)
	{
		return false;
	}
	return true;
}

bool dansGrille(Grille gri, Coord co) {
	if (getX(co) >= 20 or getX(co) <= -1)
	{
		return false;
	}
	if (getY(co) >= 20 or getY(co) <= -1)
	{
		return false;
	}
	return true;
}

bool contientBrindille(Grille gri, Coord co) {
	if (gri.tab[getX(co)][getY(co)].brindille == 0)
	{
		return true;
	}
	return false;
}

int numeroTermite(Grille gri, Coord co) {
	return gri.tab[getX(co)][getY(co)].termite;
}

void poseBrindille(Grille &gri, Coord co) {
	if (estVide(gri, co) == true)
	{
		gri.tab[getX(co)][getY(co)].brindille = 0;
	}
}

void enleveBrindille(Grille &gri, Coord co) {
	gri.tab[getX(co)][getY(co)].brindille = -1;
}

void poseTermite(Grille &gri, Coord co, int numTermite) {
	if (numTermite >= 0)
	{
		if (estVide(gri, co) == true)
		{
			gri.tab[getX(co)][getY(co)].termite = numTermite;
		}
	}
}

void enleveTermite(Grille &gri, Coord co) {
	gri.tab[getX(co)][getY(co)].termite = -1;
}