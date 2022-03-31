#include <cstdlib>
#include <iostream>
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl
#ifndef Coord_hpp
#define Coord_hpp

using namespace std;

/** @file
 ** Structures de données pour représenter des Coordonées
 **/
struct Coord {
  int ligne;
  int colonne;
};

/** @file
 ** Type énuméré pour représenter des Directions
 **/
enum Direction { nord_ouest, nord, nord_est, est, sud_est, sud, sud_ouest, ouest };

/** Cree une Coord à partir d'une ligne et d'une colonne
* @param[in] lig : la ligne
* @param[in] col : la colonne
**/
Coord creeCoord(int lig, int col);

/** Affiche une Coord
* @param[in] co : une Coord
**/
void afficheCoord(Coord co);

/** Retourne la ligne d'une Coord
* @param[in] co : une Coord
**/
int getX(Coord co);

/** Retourne la colonne d'une Coord
* @param[in] co : une Coord
**/
int getY(Coord co);

/** Retourne vrai si deux Coord sont égales
* @param[in] co1 : une Coord
* @param[in] co2 : une Coord
**/
bool egalCoord(Coord co1, Coord co2);

/** Affiche une Direction
* @param[in] direc : une Direction
**/
void afficheDirection(Direction direc);

/** Retourne la direction située à gauche
* @param[in] direc : une Direction
**/
Direction aGauche(Direction direc);

/** Retourne la direction située à droite
* @param[in] direc : une Direction
**/
Direction aDroite(Direction direc);

/** Retourne la Coord devant une coord et une direction donnée
* @param[in] co : une Coord
* @param[in] direc : une Direction
**/
Coord devantCoord(Coord co, Direction direc);


int main();

#endif