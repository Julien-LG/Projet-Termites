#include <cstdlib>
#include <iostream>
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl
#ifndef Termite_hpp
#define Termite_hpp

using namespace std;

//Constante pour le nombre total de Termite
const int nbTermites = 20;

//Constante pour le nombre de d�placement avant de charger ou de poser une brindille
const int nbDeplacement = 7;

//Constante pour le pour la proba que le termite avance (ex : 10 (1 chance sur 10))
const int probaTermiteAvance = 10;


/** Retourne un nombre al�atoire entre [0;a[ (entre 0 compris et le param "a" non compris
* @param[in] a : une entier indiquant le nombre max � ne pas d�passer
**/
int aleaInferieur_a(int a);

/** @file
 ** Structures de donn�es pour repr�senter des Termites
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
 ** Structures de donn�es pour repr�senter un tableau de Termites (un tableur 1D de Termite)
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

/** Le Termite tourne � droite
* @param[in/out] term : un Termite
**/
void tourneADroite(Termite &term);

/** Le Termite tourne � gauche
* @param[in/out] term : un Termite
**/
void tourneAGauche(Termite &term);

/** Le Termite tourne al�atoirement
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

/** Avance le Termite (la case est suppos�e libre)
* @param[in] gri : une Grille
* @param[in] term : un Termite
**/
void avanceTermite(Grille &gri, Termite &term);

/** Le Termite pose sa Brindille (case suppos�e libre)
* @param[in/out] gri : une Grille
* @param[in/out] term : un Termite
**/
void dechargeTermite(Grille &gri, Termite &term);

/** Le Termite prend une Brindille (case suppos�e contenir une Brindille)
* @param[in/out] gri : une Grille
* @param[in/out] term : un Termite
**/
void chargeTermite(Grille &gri, Termite &term);

/** Le Termite fait un d�placement al�atoire
* @param[in/out] gri : une Grille
* @param[in/out] term : un Termite
**/
void marcheAleatoire(Grille &gri, Termite &term);

/** Le Termite se d�place pour rassembler des brindilles
* @param[in/out] gri : une Grille
* @param[in/out] term : un Termite
**/
void rassemblerBrindille2(Grille &gri, Termite &term);

int main();

#endif