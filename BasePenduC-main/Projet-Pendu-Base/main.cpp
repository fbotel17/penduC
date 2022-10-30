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
	char lettre; //l'utilisateur rentre sa lettre a chaque coup
	int compteur; //compteur pour la boucle de jeu
	char modeJeu; //d�finie mode solo ou duo
	int nombreCoup = 0; //compteur de coup
	char mot[100]; //tableau de char pour le mot a deviner
	char tablettre[100]; //tableau qui va servir � l'affichage
	int j = 0;
	char arret; //d�finie si on relance le jeu ou non
	int temp1; //palier au probl�me du compteur

	for (int i = 0; i < strlen(mot); i++)
	{
		piocherMot(mot);
		cout << mot[i];
	}

	//boucle do while qui prend fin lorsque le joueur saisi '0' � la fin d'une partie
	//si il saisi n'importe quelle touche � la fin d'une partie, alors la boucle recommence
	do
	{
		//clear la fenetre
		system("CLS"); 

		compteur = 0;
		cout << "Bienvenue dans le Pendu !" << endl<<endl;

		do
		{
			//choix du mode de jeu
			//si la saisie n'est pas 1 ou 2 alors on repose la question
			cout << "Mode solo - tapez 1" << endl;
			cout << "Mode duo - tapez 2" << endl;
			cin >> modeJeu;
			if (modeJeu != '1' and modeJeu != '2')
			{
				cout << "Saisie incorrecte" << endl;
			}
		} while (modeJeu != '1' and modeJeu != '2');

		//d�fini en 1 le jeu solo, en 2 le jeu duo
		if (modeJeu == '1')
		{
			piocherMot(mot);
		}
		else
		{
			cout << "Joueur 1 entre ton mot, ne pas montrer a Joueur 2 (en MAJUSCULE) :"<<endl;
			cin >> mot;
		}

		//rempli le tableau tablettre de * pour l'affiche utilisateur
		for (int i = 0; i < strlen(mot)+1; i++)
				{
					tablettre[i] = '*';
				}

		//affiche * autant de fois que la taille du tableau pour donner � l'utilisateur le nombre de lettre
		cout << endl << "mot secret : ";
		for (int i = 0; i < strlen(mot); i++)
		{
			cout << "*";
		}
		//demande le nombre d'essais pour r�ussir et stocke dans nombreCoup
		//si le nombre de coup pr�cis� est inf�rieur � 0 alors on repose la question
		cout << endl << "Combien d'essais pour reussir ? : ";
		cin >> nombreCoup;
		while (nombreCoup < 0)
		{
			cout << "Nombre d'essais insuffisant pour r�ussir, retapez un nombre d'essais ? : ";
			cin >> nombreCoup;

		}

		//d�but de la boucle de jeu
		//boucle s'arrete quand nombreCoup �gal 0
		do
		{
			cout << "Il reste " << nombreCoup << " coups" << endl;
			//saisie d'une lettre
			//on demande � ce que le lettre entr�e soit en majuscule, mais si elle est en minuscule alors le programme d'adapte
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


			//sert � palier au probl�me du compteur
			temp1 = 0;

			//boucle d'analyse
			//parcours la longueur du mot
			//regarde � chaque lettre du mot � trouver si elle correspond avec celle entr�e par l'utilisateur
			//si oui avec l'index du tableau tablettre prend sa valeur, compteur prend +1 � chaque lettre trouv�e
			//temp1+1 afin qu'il n'y ait pas le compteur qui prennent plus que 1 +1 si le mot poss�de plusieurs lettres identiques
			//si la valeur de l'index de tablettre est diff�rent de *, alors il garde sa valeur, cela permet de conserver l'affichage des lettres trouv�s auparavant
			//si aucune lettre trouv�, alors la l'index de tablettre prend pour valeur *
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

			//cette condition sert � ne pas d�compter 1 coup lorsque la lettre est trouv�. Ex si il restait 2 coups et que la lettre entr�e est bonne, alors il restera toujours 2 coups
			}
			if (temp1 >= 1)
			{
				nombreCoup++;
			}

			//affiche la chaine de caract�re tablettre, cela va donc afficher les lettres trouv�s, et celles non trouv�es par *
			for (int y = 0; y < strlen(mot); y++)
			{
				cout << tablettre[y];
			}

			//retour � la ligne pour l'affichage utilisateur
			cout << endl;

			//condition de si le compteur atteint le meme nombre que la grandeur du mot, alors on sort de la boucle while
			if (compteur == strlen(mot))
			{
				break;
			}

			//retire 1 � la valeur de nombreCoup pour savoir quand la boucle s'arrete, et indiquer � l'utilisateur combien de coup il lui reste � jouer
			nombreCoup--;

		} while (nombreCoup != 0);


		//condition si le compteur a atteint la longueur du mot, alors on indique la victoire
		//sinon on indique que la partie est perdue, en indiquant le mot qui �tait � trouver
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

		//demande � l'utilisateur si il souhaite relancer une partie, si non il rentre '0' � la saisie
		cout << endl << "Une partie va se relancer, si vous ne souhaitez pas rejouer ecrivez 0, sinon appuyez sur une touche pour rejouer" << endl;
		cin >> arret;

	}while (arret != '0');

	return 0;
}