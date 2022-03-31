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
 ** Structures de données pour représenter des Cases
 **/
typedef struct Case {
	int brindille;
	int termite;
}Case;

/** @file
 ** Structures de données pour représenter une grille (un tableur 2D de Case)
 **/
struct Grille {
	Case tab[taille][taille];
};

/** Initialise une Grille à vide
* @param[in/out] gri : une Grille
**/
void initialiseGrilleVide(Grille &gri);

/** Retourne vrai si la Grille ne contient ni Brindille, ni Termite à la Coord donnée
* @param[in] gri : une Grille
* @param[in] co : une Coord
**/
bool estVide(Grille gri, Coord co);

/** Retourne vrai si la Coord indiquée est bien dans la Grille
* @param[in] gri : une Grille
* @param[in] co : une Coord
**/
bool dansGrille(Grille gri, Coord co);

/** Retourne vrai si la Grille contient une Brindille à la Coord indiquée
* @param[in] gri : une Grille
* @param[in] co : une Coord
**/
bool contientBrindille(Grille gri, Coord co);

/** Retourne le numero du Termite qui est dans la Grille à la Coord indiquée, -1 s'il n'y a pas de Termite à cet endroit
* @param[in] gri : une Grille
* @param[in] co : une Coord
**/
int numeroTermite(Grille gri, Coord co);

/** Pose une Brindille dans la Grille à la Coord donnée
* @param[in/out] gri : une Grille
* @param[in] co : une Coord
**/
void poseBrindille(Grille &gri, Coord co);

/** Enlève de la Grille la Brindille située à la Coord donnée
* @param[in/out] gri : une Grille
* @param[in] co : une Coord
**/
void enleveBrindille(Grille &gri, Coord co);

/** Pose une Termite dans la Grille à la Coord donnée
* @param[in/out] gri : une Grille
* @param[in] co : une Coord
* @param[in] numTermite : un entier correspondant au numéro du Termite
**/
void poseTermite(Grille &gri, Coord co, int numTermite);

/** Enlève de la Grille le Termite située à la Coord donnée
* @param[in/out] gri : une Grille
* @param[in] co : une Coord
**/
void enleveTermite(Grille &gri, Coord co);

int main();

#endif