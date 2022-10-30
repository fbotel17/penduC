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
	char modeJeu;
	int nombreCoup = 0;
	char mot[100];
	char tablettre[100];
	int j = 0;
	char arret;
	int temp1;

	do
	{
		system("CLS");


		
		compteur = 0;
		cout << "Bienvenue dans le Pendu !" << endl<<endl;

		do
		{
			cout << "Mode solo - tapez 1" << endl;
			cout << "Mode duo - tapez 2" << endl;
			cin >> modeJeu;
			if (modeJeu != '1' and modeJeu != '2')
			{
				cout << "Saisie incorrecte" << endl;
			}
		} while (modeJeu != '1' and modeJeu != '2');

		if (modeJeu == '1')
		{
			piocherMot(mot);
		}
		else
		{
			cout << "Joueur 1 entre ton mot, ne pas montrer a Joueur 2 (en MAJUSCULE) :"<<endl;
			cin >> mot;
		}
		for (int i = 0; i < strlen(mot)+1; i++)
				{
					tablettre[i] = '*';
				}

		cout << endl << "mot secret : ";
		for (int i = 0; i < strlen(mot); i++)
		{
			cout << "*";
		}

		cout << endl << "Combien d'essais pour reussir ? : ";
		cin >> nombreCoup;
		while (nombreCoup < 0)
		{
			cout << "Nombre d'essais insuffisant pour r�ussir, retapez un nombre d'essais ? : ";
			cin >> nombreCoup;

		}

		
		int temp2= 0;
		do
		{
			cout << "Il reste " << nombreCoup << " coups" << endl;
			//saisie d'une lettre
			do {
				cout << endl << "Proposez une lettre (en MAJUSCULE) : ";
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

			temp1 = 0;

			for (int i = 0; i < strlen(mot); i++)
			{

				if (lettre == mot[i])
				{

					tablettre[i] = lettre;
					compteur++;
					temp1++;
				}
				else if (tablettre[i] != '*')
				{
					tablettre[i] = tablettre[i];
				}
				else
				{
					tablettre[i] = '*';
				}

			}
			if (temp1 >= 1)
			{
				nombreCoup++;
			}

			for (int y = 0; y < strlen(mot); y++)
			{
				cout << tablettre[y];
			}


			cout << endl;

			if (compteur == strlen(mot))
			{
				break;
			}
			nombreCoup--;

		} while (nombreCoup != 0);

		if (compteur == strlen(mot))
		{
			cout << "VICTOIRE !" << endl;
		}
		else
		{
			cout << "C'est perdu ! le mot etait : ";
			for (int i = 0; i < strlen(mot); i++)
			{
				cout << mot[i];
			}
		}
		cout << endl << "Une partie va se relancer, si vous ne souhaitez pas rejouer ecrivez 0, sinon appuyez sur une touche pour rejouer" << endl;
		cin >> arret;

	}while (arret != '0');




	//--------------------------------------------------
	// Exemple d'utilisation du dictionnaire de mot : 
	//piocherMot(mot);	// Pour le moment la fonction renvoi toujours
						// le m�me mot. Vous devez impl�menter la fonction
						// int nombreAleatoire(int nombreMax) dans le fichier
						// dico.c pour que cela fonctionne correctement.
	//printf("Pioche : %s", mot);

	//--------------------------------------------------

	return 0;
}