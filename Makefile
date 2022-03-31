# Fichier makefile pour projet termite
######################################
##
# Tout ce qui est après un # sur une ligne est en commentaire.
##
# Quelques variables de configuration du compilateur
####################################################
# Le compilateur à utiliser
CXX = g++
# Les options du compilateur
CXXFLAGS = -Wall -std=c++11 -g
# Les programmes principaux
###########################
# On donne le fichier .cpp et la liste des fichiers .o qu’ils utilisent
projet: projet.cpp Coord.o Grille.o Termite.o # autre fichiers utiles
testcoord: testcoord.cpp Coord.o
testgrille: testgrille.cpp Grille.o Coord.o
testtermite: testtermite.cpp Termite.o Grille.o Coord.o
# Les différents composants
###########################
# on donne le fichier .cpp ainsi que la liste
# des fichiers .hpp dont ils dépendent
Coord.o: Coord.cpp Coord.hpp
Grille.o: Grille.cpp Grille.hpp Coord.hpp
Termite.o: Termite.cpp Termite.hpp Grille.hpp Coord.hpp
# Pour faire le ménage
clean:
	rm -f projet test *.o
# Attention dans la ligne ci-dessus il faut écrire
# un seul caractère de tabulation et pas 8 espaces.
