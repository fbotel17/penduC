#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>

#include "dico.h"	// Pour utiliser le dictionnaire de mots

using namespace std;

int main(int argc, char ** argv)
{
	char lettre;
	int nombreCoup;
	char mot[100];
	piocherMot(mot);

	cout << "Bienvenue dans le Pendu !" << endl;
	
	cout << "mot secret : ";
	for (int i = 0; i < strlen(mot); i++)
	{
		cout << "*";
	}

	do {
		cout << "Proposez une lettre : ";
		cin >> lettre;
		if (lettre >= 97 and lettre <= 122)
		{
			lettre = lettre - 32;
		}
		else if (lettre >= 65 and lettre <= 90)
		{
			lettre = lettre;
		}
		else
		{
			cout << "saisie incorrecte, retapez votre lettre : ";
		}
	}while(!(lettre >= 65 and lettre <= 90));
	cout << lettre << endl;

	
	//--------------------------------------------------
	// Exemple d'utilisation du dictionnaire de mot : 
	//piocherMot(mot);	// Pour le moment la fonction renvoi toujours
						// le même mot. Vous devez implémenter la fonction
						// int nombreAleatoire(int nombreMax) dans le fichier
						// dico.c pour que cela fonctionne correctement.
	//printf("Pioche : %s", mot);

	//--------------------------------------------------

	return 0;
}