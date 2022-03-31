#include <cstdlib>
#include <iostream>
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl
#ifndef Termite_hpp
#define Termite_hpp

using namespace std;

//Constante pour le nombre total de Termite
const int nbTermites = 20;

//Constante pour le nombre de déplacement avant de charger ou de poser une brindille
const int nbDeplacement = 7;

//Constante pour le pour la proba que le termite avance (ex : 10 (1 chance sur 10))
const int probaTermiteAvance = 10;


/** Retourne un nombre aléatoire entre [0;a[ (entre 0 compris et le param "a" non compris
* @param[in] a : une entier indiquant le nombre max à ne pas dépasser
**/
int aleaInferieur_a(int a);

/** @file
 ** Structures de données pour représenter des Termites
 **/
typedef struct Termite {
	int numero;
	Coord coo;
	Direction direction = (Direction)aleaInferieur_a(8);
	int brindille = -1;
	int sablier = 0;
	bool tourneSurPlace = false;
}Termite;

/** @file
 ** Structures de données pour représenter un tableau de Termites (un tableur 1D de Termite)
 **/
struct tabTermites {
	Termite tab[nbTermites];
};

/** Retourne la direction du Termite
* @param[in] term : un Termite
**/
Direction directionTermite(Termite term);

/** Retourne la Coord de la case devant le Termite
* @param[in] term : un Termite
**/
Coord devantTermite(Termite term);

/** Retourne vrai si le Termite porte une Brindille
* @param[in] term : un Termite
**/
bool porteBrindille(Termite term);

/** Le Termite tourne à droite
* @param[in/out] term : un Termite
**/
void tourneADroite(Termite &term);

/** Le Termite tourne à gauche
* @param[in/out] term : un Termite
**/
void tourneAGauche(Termite &term);

/** Le Termite tourne aléatoirement
* @param[in/out] term : un Termite
**/
void tourneAleat(Termite &term);

/** Retourne vrai si la case devant le Termite est libre
* @param[in] gri : une Grille
* @param[in] term : un Termite
**/
bool laVoieEstLibre(Grille gri, Termite term);

/** Retourne vrai si la case devant le Termite contient une Brindille
* @param[in] gri : une Grille
* @param[in] term : un Termite
**/
bool brindilleEnFace(Grille gri, Termite term);

/** Retourne vrai si Termite ne s'enferme pas s'il pose une Brindille devant lui (il reste une case voisine pour qu'il puisse sortir)
* @param[in] gri : une Grille
* @param[in] term : un Termite
**/
bool pasEnferme(Grille gri, Termite term);

/** Avance le Termite (la case est supposée libre)
* @param[in] gri : une Grille
* @param[in] term : un Termite
**/
void avanceTermite(Grille &gri, Termite &term);

/** Le Termite pose sa Brindille (case supposée libre)
* @param[in/out] gri : une Grille
* @param[in/out] term : un Termite
**/
void dechargeTermite(Grille &gri, Termite &term);

/** Le Termite prend une Brindille (case supposée contenir une Brindille)
* @param[in/out] gri : une Grille
* @param[in/out] term : un Termite
**/
void chargeTermite(Grille &gri, Termite &term);

/** Le Termite fait un déplacement aléatoire
* @param[in/out] gri : une Grille
* @param[in/out] term : un Termite
**/
void marcheAleatoire(Grille &gri, Termite &term);

/** Le Termite se déplace pour rassembler des brindilles
* @param[in/out] gri : une Grille
* @param[in/out] term : un Termite
**/
void rassemblerBrindille2(Grille &gri, Termite &term);

int main();

#endif