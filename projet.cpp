#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <iostream>
#include "Coord.hpp"
#include "Grille.hpp"
#include "Termite.hpp"
#include "ctime"
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl

using namespace std;

//Déclaration de la fenetre d'affichage avec son nom
sf::RenderWindow window(sf::VideoMode(1920, 1080), "Simulation de termites");

//Constante pour la taille d'un pixel (une case de la grille lors de l'affichage)
const int taillePixel = 50;

//Constante pour le pourcentage de Brindilles en fonction des Termites (exemple : 0.75 (75%))
const double pourcentageBrindille = 1.5;

//Déclaration d'un rectangle représentant une case de taille "taillePixel"
//------------------------------------------------------------------
sf::RectangleShape rectangle(sf::Vector2f(taillePixel, taillePixel));
//Déclaration d'un Sprite
sf::Sprite sprite;
//Déclaration d'un textureBrindille (l'apparence d'une brindille)
sf::Texture textureBrindille;
//Déclaration des textures des Termites à vide
sf::Texture textureNord;
sf::Texture textureNordEst;
sf::Texture textureEst;
sf::Texture textureSudEst;
sf::Texture textureSud;
sf::Texture textureSudOuest;
sf::Texture textureOuest;
sf::Texture textureNordOuest;
//Déclaration des textures des Termites chargés avec une Brindilles
sf::Texture textureNordBrindille;
sf::Texture textureNordEstBrindille;
sf::Texture textureEstBrindille;
sf::Texture textureSudEstBrindille;
sf::Texture textureSudBrindille;
sf::Texture textureSudOuestBrindille;
sf::Texture textureOuestBrindille;
sf::Texture textureNordOuestBrindille;


/** La Grille est préparée : initialisé, et se voit ajouté des termites et des brindilles à des Coord aléatoire
* @param[in/out] gri : une Grille
* @param[in/out] tabTerm : un tableau de Termites
**/
void prepareGrille(Grille &gri, tabTermites &tabTerm) {
	initialiseGrilleVide(gri);

	for (int i = 0; i < nbTermites; i++)
	{
		Termite term;
		Coord co = creeCoord(aleaInferieur_a(taille), aleaInferieur_a(taille));
		while (estVide(gri, co) == false)
		{
			co = creeCoord(aleaInferieur_a(taille), aleaInferieur_a(taille));
		}
		if (estVide(gri, co))
		{
			poseTermite(gri, co, i);
			term.coo = co;
			term.numero = i;
			tabTerm.tab[i] = term;
		}
	}

	// Le nombre de brindilles équivaut à pourcentageBrindille% du nombre de termites
	int nbBrindilles = pourcentageBrindille * nbTermites;
	for (int i = 0; i < (nbBrindilles); i++)
	{
		Coord co = creeCoord(aleaInferieur_a(taille), aleaInferieur_a(taille));
		while (estVide(gri, co) == false)
		{
			co = creeCoord(aleaInferieur_a(taille), aleaInferieur_a(taille));
			cout<< endl;
		}

		if (estVide(gri, co))
		{
			poseBrindille(gri, co);
		}
	}
}

/** La Grille est affichée
* @param[in/out] gri : une Grille
* @param[in/out] tabTerm : un tableau de Termites
**/
void afficheGrille(Grille gri, tabTermites tabTerm) {
	cout << "## # # # # # # # # # # # # # # # # # # # #" << endl;

	for (int i = 0; i < taille; i++)
	{
		cout << "#";
		for (int j = 0; j < taille; j++)
		{
			Coord coActuelle = creeCoord(i, j); // j, i
			//Défini la position d'un eventuel Rectangle ou d'un eventuel Sprite
            sf::Vector2i position{j*taillePixel, i*taillePixel};
			rectangle.setPosition(sf::Vector2f(position));
            sprite.setPosition(sf::Vector2f(position));

			if (numeroTermite(gri, coActuelle) != -1)
			{
				int numTerm = numeroTermite(gri, coActuelle);

				Direction direcTermActuelle = tabTerm.tab[numTerm].direction;
				/*if (direcTermActuelle == nord_ouest or direcTermActuelle == sud_est)
				{
					cout << "\\" << " ";
				}
				if (direcTermActuelle == nord_est or direcTermActuelle == sud_ouest)
				{
					cout << "/" << " ";
				}
				if (direcTermActuelle == est or direcTermActuelle == ouest)
				{
					cout << "-" << " ";
				}
				if (direcTermActuelle == nord or direcTermActuelle == sud)
				{
					cout << "|" << " ";
				}*/
				if (direcTermActuelle == nord_ouest)
				{
					cout << "\\" << " ";
                    if(porteBrindille(tabTerm.tab[numTerm]) == true){
                        sprite.setTexture(textureNordOuestBrindille);
                    }
                    else{
                        sprite.setTexture(textureNordOuest);
                    }
                    window.draw(sprite);
				}
				if (direcTermActuelle == sud_est)
				{
					cout << "\\" << " ";
                    if(porteBrindille(tabTerm.tab[numTerm]) == true){
                        sprite.setTexture(textureSudEstBrindille);
                    }
                    else{
                        sprite.setTexture(textureSudEst);
                    }
                    window.draw(sprite);
				}
				if (direcTermActuelle == nord_est)
				{
					cout << "/" << " ";
                    if(porteBrindille(tabTerm.tab[numTerm]) == true){
                        sprite.setTexture(textureNordEstBrindille);
                    }
                    else{
                        sprite.setTexture(textureNordEst);
                    }
                    window.draw(sprite);
				}
				if (direcTermActuelle == sud_ouest)
				{
					cout << "/" << " ";
                    if(porteBrindille(tabTerm.tab[numTerm]) == true){
                        sprite.setTexture(textureSudOuestBrindille);
                    }
                    else{
                        sprite.setTexture(textureSudOuest);
                    }
                    window.draw(sprite);
				}
				if (direcTermActuelle == est)
				{
					cout << "-" << " ";
                    if(porteBrindille(tabTerm.tab[numTerm]) == true){
                        sprite.setTexture(textureEstBrindille);
                    }
                    else{
                        sprite.setTexture(textureEst);
                    }
                    window.draw(sprite);
				}
				if (direcTermActuelle == ouest)
				{
					cout << "-" << " ";
                    if(porteBrindille(tabTerm.tab[numTerm]) == true){
                        sprite.setTexture(textureOuestBrindille);
                    }
                    else{
                        sprite.setTexture(textureOuest);
                    }
                    window.draw(sprite);
				}
				if (direcTermActuelle == nord)
				{
					cout << "|" << " ";
                    if(porteBrindille(tabTerm.tab[numTerm]) == true){
                        sprite.setTexture(textureNordBrindille);
                    }
                    else{
                        sprite.setTexture(textureNord);
                    }
                    window.draw(sprite);
				}
				if (direcTermActuelle == sud)
				{
					cout << "|" << " ";
                    if(porteBrindille(tabTerm.tab[numTerm]) == true){
                        sprite.setTexture(textureSudBrindille);
                    }
                    else{
                        sprite.setTexture(textureSud);
                    }
                    window.draw(sprite);
				}
			}

			if (contientBrindille(gri, coActuelle) == true)
			{
				cout << "*" << " ";
                sprite.setTexture(textureBrindille);
                window.draw(sprite);
			}
			if(estVide(gri, coActuelle) == true)
			{
				cout << " " << " ";
				rectangle.setFillColor(sf::Color::Black);
                window.draw(rectangle);
			}
		}
		cout << "#" << endl;
	}
	cout << "## # # # # # # # # # # # # # # # # # # # #" << endl;
	cout << endl;
	//Création d'une barre verticale pour délimiter la grille
	for(int y = 0; y < taille; y++){
        rectangle.setFillColor(sf::Color::White);
        sf::Vector2i position{taille*taillePixel, y*taillePixel};
        rectangle.setPosition(sf::Vector2f(position));
		window.draw(rectangle);
	}
	//Affiche tout dans la fenetre
	window.display();
}

/** Demande à l'utilisateur une saisie clavier pour continuer l'éxecution de simulation, retourne un caractère
**/
char getcar() {
	/*char car;
	car = cin.get();
	if (car == '\n')
		return ' ';

	return car;*/
	sf::Event event;

	while (window.pollEvent(event))
    {
        if (event.type == sf::Event::TextEntered)
        {
            if(static_cast<char>(event.text.unicode)== '*' or static_cast<char>(event.text.unicode)== '/' or static_cast<char>(event.text.unicode)== '.' or event.text.unicode == 13)
            {
                    //cout << "Detection appuie d'une touche !!!" << endl;
                if(event.text.unicode == 13)
                {
                    //cout << "Touche entrée détéctée" << endl;
                    return ' ';
                }
                else
                {
                    //cout << "Return autre touches : " << static_cast<char>(event.text.unicode) << endl;
                    return static_cast<char>(event.text.unicode);
                }
            }
        }
    }
}

/** Execute la simulation des termites, utilise getchar pour gérer la simulation (ex: "entrée" pour éxecuté, "*" pour doublé le nombre de passes, "/" pour divisé par 2 le nombre de passes, "." pour stoppé)
* @param[in/out] gri : une Grille
* @param[in/out] tabTerm : un tableau de Termites
**/
void simulation(Grille &gri, tabTermites &tabTerm) {
	int y = 0;
	char car = ' ';
	int nbPasse = 10;
	int totPasse = 0;
	int i = 0;

	//Déclaration du texte avec sa taille, sa couleur, sa police et un texte par défaut
	sf::Text text;
    sf::Font font;
    font.loadFromFile("sansation.ttf");
    text.setFont(font);
    text.setString("Hello world");
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(24);

		while (car != '.' or !window.isOpen())
        {
			if (y >= nbTermites)
			{
				y = 0;
			}
			//marcheAleatoire(gri, tabTerm.tab[y]);
			rassemblerBrindille2(gri, tabTerm.tab[y]);
			y++;
			i++;
			totPasse++;

			if (i == nbPasse)
			{
			    //Nettoie la fenetre
			    window.clear();
			    //Affichage du nombre de passes, et des commandes
			    text.setPosition(1300.f, 10.f);
                text.setString("Nombre de passes totale : " + to_string(totPasse));
                window.draw(text);
                text.setPosition(1300.f, 40.f);
                text.setString("Nombre de passes : " + to_string(nbPasse));
                window.draw(text);
                text.setPosition(1300.f, 850.f);
                text.setString("Commandes : ");
                window.draw(text);
                text.setPosition(1380.f, 880.f);
                text.setString("\"Entrée\" pour continuer");
                window.draw(text);
                text.setPosition(1380.f, 910.f);
                text.setString("\"*\" pour multiplier par deux le nombre d'itération");
                window.draw(text);
                text.setPosition(1380.f, 940.f);
                text.setString("\"/\" pour diviser par deux le nombre d'itération");
                window.draw(text);
                text.setPosition(1380.f, 970.f);
                text.setString("\".\" pour quitter");
                window.draw(text);

                //Affiche la grille et son contenu
                afficheGrille(gri, tabTerm);

				//Demande une saisie clavier
				car = getcar();
				i = 0;
				cout << "Nombre de passes totale :" << totPasse << endl;
				cout << "Nombre de passes : " << nbPasse << endl;

				window.display();

				if (car == '*')
				{
					nbPasse = nbPasse * 2;
				}
				if (car == '/' and nbPasse > 1)
				{
					nbPasse = nbPasse / 2;
				}
			}
		}
}

int main() {
    textureBrindille.loadFromFile("Termites/Brindille.png");
    //------------------------------------------------------------------
    textureNord.loadFromFile("Termites/TermiteNord3.png");
    textureNordEst.loadFromFile("Termites/TermiteNordEst3.png");
    textureEst.loadFromFile("Termites/TermiteEst3.png");
    textureSudEst.loadFromFile("Termites/TermiteSudEst3.png");
    textureSud.loadFromFile("Termites/TermiteSud3.png");
    textureSudOuest.loadFromFile("Termites/TermiteSudOuest3.png");
    textureOuest.loadFromFile("Termites/TermiteOuest3.png");
    textureNordOuest.loadFromFile("Termites/TermiteNordOuest3.png");

    //Arrondi les textures des Termites
    textureNord.setSmooth(true);
    textureNordEst.setSmooth(true);
    textureEst.setSmooth(true);
    textureSudEst.setSmooth(true);
    textureSud.setSmooth(true);
    textureSudOuest.setSmooth(true);
    textureOuest.setSmooth(true);
    textureNordOuest.setSmooth(true);

    //------------------------------------------------------------------

    textureNordBrindille.loadFromFile("Termites/TermiteNordBrindille.png");
    textureNordEstBrindille.loadFromFile("Termites/TermiteNordEstBrindille.png");
    textureEstBrindille.loadFromFile("Termites/TermiteEstBrindille.png");
    textureSudEstBrindille.loadFromFile("Termites/TermiteSudEstBrindille.png");
    textureSudBrindille.loadFromFile("Termites/TermiteSudBrindille.png");
    textureSudOuestBrindille.loadFromFile("Termites/TermiteSudOuestBrindille.png");
    textureOuestBrindille.loadFromFile("Termites/TermiteOuestBrindille.png");
    textureNordOuestBrindille.loadFromFile("Termites/TermiteNordOuestBrindille.png");

    //Arrondi les textures des Termites
    textureNordBrindille.setSmooth(true);
    textureNordEstBrindille.setSmooth(true);
    textureEstBrindille.setSmooth(true);
    textureSudEstBrindille.setSmooth(true);
    textureSudBrindille.setSmooth(true);
    textureSudOuestBrindille.setSmooth(true);
    textureOuestBrindille.setSmooth(true);
    textureNordOuestBrindille.setSmooth(true);
    //------------------------------------------------------------------

	//variable pour l'aléatoire
	srand(time(NULL));

	//Mise en place de l'icone de la fenetre
	sf::Image icon;
    if(!icon.loadFromFile("Termites/TermiteNordOuest.png"))
        EXIT_FAILURE;

    window.setIcon(100,100,icon.getPixelsPtr());


	Grille grille;
	tabTermites tabTerm;

	prepareGrille(grille, tabTerm);
	simulation(grille, tabTerm);

	return 0;
}
