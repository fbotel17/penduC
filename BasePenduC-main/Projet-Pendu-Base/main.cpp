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
	int compteur;
	int nombreCoup=0;
	char mot[100];
	char tablettre[100];

	piocherMot(mot);
	compteur = 0;
	cout << "Bienvenue dans le Pendu !" << endl;
	
	cout << endl << "mot secret : ";
	for (int i = 0; i < strlen(mot); i++)
	{
		cout << "*";
	}

	cout << "Combien d'essais pour reussir ? : ";
	cin >> nombreCoup;
	
	while (nombreCoup < strlen(mot))
	{
		cout << "Nombre d'essais insuffisant pour réussir, retapez un nombre d'essais ? : ";
		cin >> nombreCoup;

	}

	for (int i = 0; i < strlen(mot); i++)
	{
		cout <<endl<< mot[i];
	}

	int j = 0;
	int o = 0;
	do
	{
		cout << "Il reste " << nombreCoup - j << " coups" << endl;
		//saisie d'une lettre
		do {
			cout << endl << "Proposez une lettre : ";
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
				cout << "saisie incorrecte, retapez votre lettre";
			}
		} while (!(lettre >= 65 and lettre <= 90));



		for (int i = 0; i < strlen(mot); i++)
		{
			
			if (lettre == mot[i])
			{
				cout << mot[i];
				tablettre[o] = lettre;
				o++;
			}
			else if (tablettre[i] == mot[i])
			{
				cout << mot[i];
			}
			else
			{
				cout << "*";
			}
		
			
		}
		cout << endl;
		j++;
	} while (nombreCoup != j);
	//or compteur != strlen(mot)





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