#include <cstdlib>
#include <iostream>
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl
#ifndef Grille_hpp
#define Grille_hpp

using namespace std;


//Constante pour la taille de la grille
const int taille = 20;


/** @file
 ** Structures de donn�es pour repr�senter des Cases
 **/
typedef struct Case {
	int brindille;
	int termite;
}Case;

/** @file
 ** Structures de donn�es pour repr�senter une grille (un tableur 2D de Case)
 **/
struct Grille {
	Case tab[taille][taille];
};

/** Initialise une Grille � vide
* @param[in/out] gri : une Grille
**/
void initialiseGrilleVide(Grille &gri);

/** Retourne vrai si la Grille ne contient ni Brindille, ni Termite � la Coord donn�e
* @param[in] gri : une Grille
* @param[in] co : une Coord
**/
bool estVide(Grille gri, Coord co);

/** Retourne vrai si la Coord indiqu�e est bien dans la Grille
* @param[in] gri : une Grille
* @param[in] co : une Coord
**/
bool dansGrille(Grille gri, Coord co);

/** Retourne vrai si la Grille contient une Brindille � la Coord indiqu�e
* @param[in] gri : une Grille
* @param[in] co : une Coord
**/
bool contientBrindille(Grille gri, Coord co);

/** Retourne le numero du Termite qui est dans la Grille � la Coord indiqu�e, -1 s'il n'y a pas de Termite � cet endroit
* @param[in] gri : une Grille
* @param[in] co : une Coord
**/
int numeroTermite(Grille gri, Coord co);

/** Pose une Brindille dans la Grille � la Coord donn�e
* @param[in/out] gri : une Grille
* @param[in] co : une Coord
**/
void poseBrindille(Grille &gri, Coord co);

/** Enl�ve de la Grille la Brindille situ�e � la Coord donn�e
* @param[in/out] gri : une Grille
* @param[in] co : une Coord
**/
void enleveBrindille(Grille &gri, Coord co);

/** Pose une Termite dans la Grille � la Coord donn�e
* @param[in/out] gri : une Grille
* @param[in] co : une Coord
* @param[in] numTermite : un entier correspondant au num�ro du Termite
**/
void poseTermite(Grille &gri, Coord co, int numTermite);

/** Enl�ve de la Grille le Termite situ�e � la Coord donn�e
* @param[in/out] gri : une Grille
* @param[in] co : une Coord
**/
void enleveTermite(Grille &gri, Coord co);

int main();

#endif