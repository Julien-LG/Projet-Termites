#include <cstdlib>
#include <iostream>
#include "Coord.hpp"
#include "Grille.hpp"
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl

using namespace std;

Grille grille;
void testInitialiseGrilleVide() {
	initialiseGrilleVide(grille);
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{	
			Coord co = creeCoord(i, j);
			ASSERT(estVide(grille, co) == true);
		}
	}
}

void testEstVide() {
	initialiseGrilleVide(grille);
	grille.tab[1][1].brindille = 0; //crée un brindille dans la case 1;1
	grille.tab[2][2].termite = 5; //crée un termite dans la case 2;2
	Coord co1 = creeCoord(1, 1);
	Coord co2 = creeCoord(2, 2);
	Coord co3 = creeCoord(3, 3);

	ASSERT(estVide(grille, co1) == false);
	ASSERT(estVide(grille, co2) == false);
	ASSERT(estVide(grille, co3) == true);
	/*cout << grille.tab[1][1].brindille << " " << grille.tab[1][1].termite << endl;
	cout << grille.tab[2][2].brindille << " " << grille.tab[2][2].termite << endl;
	cout << grille.tab[3][3].brindille << " " << grille.tab[3][3].termite << endl;*/
}

void testDansGrille() {
	Coord co1 = creeCoord(-1, -1);
	Coord co2 = creeCoord(800, 800);
	Coord co3 = creeCoord(9, 9);
	ASSERT(dansGrille(grille, co1) == false);
	ASSERT(dansGrille(grille, co2) == false);
	ASSERT(dansGrille(grille, co3) == true);
}

void testContientBrindille() {
	initialiseGrilleVide(grille);
	grille.tab[1][1].brindille = 0;
	//cout << "ligne 52 " << grille.tab[1][1].brindille << " " << grille.tab[1][1].termite << endl;
	Coord co1 = creeCoord(1, 1);
	Coord co2 = creeCoord(1, 2);
	ASSERT(contientBrindille(grille, co1) == true);
	ASSERT(contientBrindille(grille, co2) == false);
}

void testNumeroTermite() {
	initialiseGrilleVide(grille);
	//Coord co1 = creeCoord(1, 1);
	//cout << numeroTermite(grille, creeCoord(1,1)) << endl;
	//poseTermite(grille, co1, 1);
	grille.tab[1][1].termite = 1;
	//cout << numeroTermite(grille, co1) << endl;
	grille.tab[2][2].termite = 2;

	grille.tab[0][0].termite = 0;

	Coord co1 = creeCoord(1, 1);
	Coord co2 = creeCoord(2, 2);
	Coord co3 = creeCoord(3, 3);

	//grille.tab[1][1].brindille = 0;
	//grille.tab[1][1].termite = 1;
	//cout << numeroTermite(grille, co1) << " " << grille.tab[1][1].brindille << " ; " << grille.tab[1][1].termite << endl;
	//cout << numeroTermite(grille, co1) << endl;
	//cout << grille.tab[1][1].termite << endl;

	ASSERT(numeroTermite(grille, co1) == 1);
	//cout << numeroTermite(grille, co1) << endl;
	//poseTermite(grille, co1, 1);
	//cout << numeroTermite(grille, co1) << endl;
	ASSERT(numeroTermite(grille, co2) == 2);
	//cout << numeroTermite(grille, co2) << endl;
	ASSERT(numeroTermite(grille, co3) == -1);
	//cout << numeroTermite(grille, co3) << endl;
}

void testPoseBrindille() {
	initialiseGrilleVide(grille);

	Coord co1 = creeCoord(1, 1);
	Coord co2 = creeCoord(2, 2);
	Coord co3 = creeCoord(3, 3);

	poseBrindille(grille, co1);
	poseBrindille(grille, co2);

	poseTermite(grille, co3, 100);
	poseBrindille(grille, co3);

	ASSERT(contientBrindille(grille, co1) == true);
	ASSERT(contientBrindille(grille, co2) == true);
	ASSERT(contientBrindille(grille, co3) == false);
}

void testEnleveBrindille() {
	initialiseGrilleVide(grille);

	Coord co1 = creeCoord(1, 1);
	Coord co2 = creeCoord(2, 2);

	poseBrindille(grille, co1);
	poseBrindille(grille, co2);

	enleveBrindille(grille, co1);
	enleveBrindille(grille, co2);

	ASSERT(contientBrindille(grille, co1) == false);
	ASSERT(contientBrindille(grille, co2) == false);
}

void testPoseTermite() {
	initialiseGrilleVide(grille);

	Coord co1 = creeCoord(1, 1);
	Coord co2 = creeCoord(2, 2);
	Coord co3 = creeCoord(3, 3);
	Coord co4 = creeCoord(4, 4);
	Coord co5 = creeCoord(5, 5);

	poseTermite(grille, co1, 1);
	poseTermite(grille, co2, 2);

	poseBrindille(grille, co3);
	poseTermite(grille, co3, 3);

	poseTermite(grille, co4, 4);
	poseTermite(grille, co4, 5);

	poseTermite(grille, co5, -2);
	poseTermite(grille, co5, -1);
	poseTermite(grille, co5, 5);
	poseTermite(grille, co5, -5);

	ASSERT(numeroTermite(grille, co1) == 1);
	ASSERT(numeroTermite(grille, co2) == 2);
	ASSERT(numeroTermite(grille, co3) == -1);
	ASSERT(numeroTermite(grille, co4) == 4 );
	ASSERT(numeroTermite(grille, co5) == 5);
}

void testEnleveTermite() {
	initialiseGrilleVide(grille);

	Coord co1 = creeCoord(1, 1);
	Coord co2 = creeCoord(2, 2);

	poseTermite(grille, co1, 1);
	poseTermite(grille, co2, 2);

	enleveTermite(grille, co1);
	enleveTermite(grille, co2);

	ASSERT(numeroTermite(grille, co1) == -1);
	ASSERT(numeroTermite(grille, co2) == -1);
}



int main(){

	testEstVide();
	testDansGrille();
	testContientBrindille();
	testNumeroTermite();
	testPoseBrindille();
	testEnleveBrindille();
	testPoseTermite();
	testEnleveTermite();


	return 0;
}

