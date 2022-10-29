#define _CRT_SECURE_NO_WARNINGS

#include "dico.h"	// Pour utiliser le dictionnaire de mots

int main(int argc, char ** argv)
{
	//--------------------------------------------------
	// Exemple d'utilisation du dictionnaire de mot : 
	char mot[100];
	piocherMot(mot);	// Pour le moment la fonction renvoi toujours
						// le même mot. Vous devez implémenter la fonction
						// int nombreAleatoire(int nombreMax) dans le fichier
						// dico.c pour que cela fonctionne correctement.
	printf("Pioche : %s", mot);
	//--------------------------------------------------

	return 0;
}