#include <cstdlib>
#include <iostream>
#include "Coord.hpp"
#include "Grille.hpp"
#include "Termite.hpp"
#include "ctime"
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl

using namespace std;

int aleaInferieur_a(int a) {
	return rand() % a;
}

Direction directionTermite(Termite term) {
	return term.direction;
}

Coord devantTermite(Termite term) {
	return devantCoord(term.coo, term.direction);
}

bool porteBrindille(Termite term) {
	if (term.brindille == -1)
	{
		return false;
	}
	return true;
}

void tourneADroite(Termite &term) {
	term.direction = aDroite(term.direction);
}

void tourneAGauche(Termite &term) {
	term.direction = aGauche(term.direction);
}

void tourneAleat(Termite &term) {
	term.direction = (Direction)aleaInferieur_a(8);
}

bool laVoieEstLibre(Grille gri, Termite term) {
	Coord coDevant = devantTermite(term);
	if (estVide(gri, coDevant) == true)
	{
		return true;
	}
	return false;
}

bool brindilleEnFace(Grille gri, Termite term) {
	Coord coDevant = devantTermite(term);
	if (contientBrindille(gri, coDevant) == true)
	{
		return true;
	}
	return false;
}

bool pasEnferme(Grille gri, Termite term) {
	for (int i = 0; i < 7; i++)
	{
		tourneADroite(term);
		if (laVoieEstLibre(gri, term))
		{
			return true;
		}
	}
	return false;
}

void avanceTermite(Grille &gri, Termite &term) {
	Coord coDevant = devantTermite(term);
	if (dansGrille(gri, coDevant) == true)
	{
		enleveTermite(gri, term.coo);
		poseTermite(gri, coDevant, term.numero);
		term.coo = coDevant;
	}
	else
	{
		/*cout <<  "Coo avant traitement : ";
		afficheCoord(coDevant);*/
		int x = getX(coDevant);
		int y = getY(coDevant);
		if (x == -1)
		{
			x = taille - 1;
		}
		if (y == -1)
		{
			y = taille - 1;
		}
		if (x == taille)
		{
			x = 0;
		}
		if (y == taille)
		{
			y = 0;
		}
		coDevant = creeCoord(x, y);
		/*cout << "Coo apres traitement : ";
		afficheCoord(coDevant);*/
		enleveTermite(gri, term.coo);
		poseTermite(gri, coDevant, term.numero);
		term.coo = coDevant;
	}
}

void dechargeTermite(Grille &gri, Termite &term) {
	Coord coDevant = devantTermite(term);
	poseBrindille(gri, coDevant);
	term.brindille = -1;
}

void chargeTermite(Grille &gri, Termite &term) {
	Coord coDevant = devantTermite(term);
	enleveBrindille(gri, coDevant);

	term.brindille = 0;
}

void marcheAleatoire(Grille &gri, Termite &term) {
	/*Si le nombre aléatoire est différent de 0 alors le termite avance, équivalent à 90% de chance d'avancer*/
	if (aleaInferieur_a(probaTermiteAvance) != 0)
	{
		if (laVoieEstLibre(gri, term) == true)
		{
			avanceTermite(gri, term);
		}
		else
		{
			if (dansGrille(gri, devantTermite(term)) == true)
			{
				tourneAleat(term);
			}
			else
			{
				avanceTermite(gri, term);
			}
		}
	}
	else
	{
		tourneAleat(term);
	}
}

void rassemblerBrindille2(Grille& gri, Termite& term) {
	if (term.tourneSurPlace == true)
	{
		tourneADroite(term);
		if (laVoieEstLibre(gri, term) and pasEnferme(gri, term))
		{
			dechargeTermite(gri, term);
			term.sablier = 0;
			term.tourneSurPlace = false;
		}
	}
	else
	{
		if (term.sablier >= nbDeplacement)
		{
			if (brindilleEnFace(gri, term) == true)
			{
				if (porteBrindille(term) == true)
				{
					tourneADroite(term);
					term.tourneSurPlace = true;
					if (laVoieEstLibre(gri, term) and pasEnferme(gri, term))
					{
						dechargeTermite(gri, term);
						term.sablier = 0;
						term.tourneSurPlace = false;
					}
				}
				else
				{
					chargeTermite(gri, term);
					term.sablier = 0;
				}
			}
			else
			{
				marcheAleatoire(gri, term);
				term.sablier++;
			}
		}
		else
		{
			marcheAleatoire(gri, term);
			term.sablier++;
		}
	}
	/*
	cout << "Num termite : " << term.numero << endl;
	cout << "Coo : ";
	afficheCoord(term.coo);
	cout << "Sablier : " << term.sablier << endl;
	cout << "Chargé ? (-1 pour non, 0 pour oui) : " << term.brindille << endl;*/
}
