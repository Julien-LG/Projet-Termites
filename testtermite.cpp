#include <cstdlib>
#include <iostream>
#include "Coord.hpp"
#include "Grille.hpp"
#include "Termite.hpp"
#include "ctime"
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl

using namespace std;

Grille grille2;

void testAleaInferieur_a() {
	ASSERT(aleaInferieur_a(8) < 8);
}

void testDirectionTermite() {
	Termite ter;
	ter.direction = sud;

	ASSERT(directionTermite(ter) == sud);

	ter.direction = nord_est;
	ASSERT(directionTermite(ter) != sud);
}

void testDevantTermite() {
	initialiseGrilleVide(grille2);
	Termite ter;
	Coord co1 = creeCoord(2, 2);
	Coord co2 = creeCoord(1, 2);
	ter.coo = co1;
	//poseTermite(grille2, co1, 1);
	ter.direction = nord;
	
	ASSERT(egalCoord(devantTermite(ter), co2) == true);
	//cout << "TEST DE DEVANT TERMITE" << endl;
}

void testPorteBrindille() {
	Termite ter;
	ter.brindille = 0;

	ASSERT(porteBrindille(ter) == true);
	ter.brindille = -1;
	ASSERT(porteBrindille(ter) == false);
}

void testTourneADroite() {
	Termite ter;
	ter.direction = sud;
	tourneADroite(ter);

	ASSERT(directionTermite(ter) == sud_ouest);
	tourneADroite(ter);
	ASSERT(directionTermite(ter) == ouest);

	ter.direction = ouest;
	tourneADroite(ter);
	ASSERT(directionTermite(ter) == nord_ouest);
}

void testTourneAGauche() {
	Termite ter;
	ter.direction = sud;
	tourneAGauche(ter);

	ASSERT(directionTermite(ter) == sud_est);
	tourneAGauche(ter);
	ASSERT(directionTermite(ter) == est);

	ter.direction = nord_ouest;
	tourneAGauche(ter);
	ASSERT(directionTermite(ter) == ouest);
}

void testLaVoieEstLibre() {
	initialiseGrilleVide(grille2);
	Termite ter;
	Coord co1 = creeCoord(2, 2);
	ter.coo = co1;
	//poseTermite(grille2, co1, 1);
	ter.direction = sud;

	tourneAGauche(ter);
	ASSERT(laVoieEstLibre(grille2, ter) == true);
	tourneAGauche(ter);
	ASSERT(laVoieEstLibre(grille2, ter) == true);
	tourneAGauche(ter);
	ASSERT(laVoieEstLibre(grille2, ter) == true);
	tourneAGauche(ter);
	ASSERT(laVoieEstLibre(grille2, ter) == true);
	tourneAGauche(ter);
	ASSERT(laVoieEstLibre(grille2, ter) == true);
}

void testBrindilleEnFace() {
	initialiseGrilleVide(grille2);
	Termite ter;
	Coord co1 = creeCoord(2, 2);
	ter.coo = co1;
	//poseTermite(grille2, co1, 1);
	ter.direction = nord;

	poseBrindille(grille2, creeCoord(1, 2));
	
	ASSERT(brindilleEnFace(grille2, ter) == true);
	tourneAGauche(ter);
	ASSERT(brindilleEnFace(grille2, ter) == false);
}

void testPasEnferme() {
	initialiseGrilleVide(grille2);
	Termite ter1;
	Termite ter2;

	Coord co1 = creeCoord(5, 5);
	Coord co2 = creeCoord(10, 10);
	ter1.coo = co1;
	ter2.coo = co2;
	ter1.direction = nord;
	ter2.direction = nord;

	poseBrindille(grille2, creeCoord(4, 4));
	poseBrindille(grille2, creeCoord(4, 5));
	poseBrindille(grille2, creeCoord(4, 6));
	poseBrindille(grille2, creeCoord(5, 4));
	poseBrindille(grille2, creeCoord(5, 6));
	poseBrindille(grille2, creeCoord(6, 4));
	poseBrindille(grille2, creeCoord(6, 5));
	poseBrindille(grille2, creeCoord(6, 6));

	poseBrindille(grille2, creeCoord(9, 9));
	poseBrindille(grille2, creeCoord(9, 10));
	poseBrindille(grille2, creeCoord(9, 11));
	poseBrindille(grille2, creeCoord(10, 9));
	poseBrindille(grille2, creeCoord(10, 11));
	poseBrindille(grille2, creeCoord(11, 9));
	poseBrindille(grille2, creeCoord(11, 10));
	//poseBrindille(grille2, creeCoord(11, 11));

	ASSERT(pasEnferme(grille2, ter1) == false);
	ASSERT(pasEnferme(grille2, ter2) == true);

}

void testAvanceTermite() {
	initialiseGrilleVide(grille2);
	Termite ter;
	Coord co1 = creeCoord(2, 2);
	ter.coo = co1;
	//poseTermite(grille2, co1, 1);
	ter.direction = nord;
	ter.numero = 1;

	avanceTermite(grille2, ter);
	ASSERT(numeroTermite(grille2, creeCoord(1,2)) == 1);
}

void testDechargeTermite() {
	initialiseGrilleVide(grille2);
	Termite ter;
	Coord co1 = creeCoord(2, 2);
	ter.coo = co1;
	//poseTermite(grille2, co1, 1);
	ter.brindille = 0;
	ter.direction = nord;

	dechargeTermite(grille2, ter);
	ASSERT(contientBrindille(grille2, creeCoord(1, 2)) == true);
	ASSERT(porteBrindille(ter) == false);
}

void testChargeTermite() {
	initialiseGrilleVide(grille2);
	Termite ter;
	Coord co1 = creeCoord(2, 2);
	ter.coo = co1;
	//poseTermite(grille2, co1, 1);
	ter.brindille = -1;
	ter.direction = nord;

	poseBrindille(grille2, creeCoord(2, 1));

	chargeTermite(grille2, ter);
	ASSERT(contientBrindille(grille2, creeCoord(1, 2)) == false);
	ASSERT(porteBrindille(ter) == true);
}

void testMarcheAleatoire() {
	//
}

int main() {

	srand(time(NULL));
	/*
	cout << aleaInferieur_a(8) << endl;
	cout << aleaInferieur_a(8) << endl;
	cout << aleaInferieur_a(8) << endl;
	cout << aleaInferieur_a(8) << endl;
	cout << aleaInferieur_a(8) << endl;
	cout << endl;

	//Direction dir = 0;
	Direction dir = nord;
	dir = (Direction)(2-1);
	if (dir == 1)
	{
		cout << dir << endl;
	}
	else
	{
		cout << "nope" << endl;
	}
	*/

	testAleaInferieur_a();
	testDirectionTermite();
	testDevantTermite();
	testPorteBrindille();
	testTourneADroite();
	testTourneAGauche();
	testLaVoieEstLibre();
	testBrindilleEnFace();
	testPasEnferme();
	testAvanceTermite();
	testDechargeTermite();
	testChargeTermite();
	testMarcheAleatoire();

	return 0;
}