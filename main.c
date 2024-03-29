#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>

#include "administration.h"

#include "personnel.h"

int nbre_P=0;

int menu();
int  main()
{

	personnel *Personnel;
	Personnel=malloc(100*sizeof(personnel));
	int r=-1;

	FILE *F=fopen("a.txt","a+");


	int choix;
	do{
		choix=menu();


		if(choix==1)
		{
			system("CLS");
			Personnel[nbre_P]=enregistrementP();
			fprintf(F, "1-%s\n",Personnel[nbre_P].nom );
			Personnel[nbre_P].nbrS=0;
			Personnel[nbre_P].nbrFCnge=0;
			system("CLS");
			afficherP(Personnel,nbre_P);
			nbre_P++;
		}
		else if (choix==2)
		{
			r=rechercheP(Personnel, nbre_P);
			system("CLS");
			if(r!=-1){
				if(Personnel[r].nbrFCnge<15){
					Personnel[r].Conge[Personnel[r].nbrFCnge]=Rconge();
					system("CLS");
					printf("LISTE DES CONGES \n");

					for (size_t i = 0; i <=Personnel[r].nbrFCnge ; i++) {
							printf("Date de depart : %d-%d-%d\n", Personnel[r].Conge[i].dateD.jour,Personnel[r].Conge[i].dateD.mois,Personnel[r].Conge[i].dateD.annee );
							printf("Date de retour : %d-%d-%d\n",Personnel[r].Conge[i].dateF.jour,Personnel[r].Conge[i].dateF.mois,Personnel[r].Conge[i].dateF.annee );
							printf("Motif :%s\n",Personnel[r].Conge[i].motif );
							printf("_______________________________________________________\n");
						}
					Personnel[r].nbrFCnge++;
				}
				else{
					printf("LISTE DES CONGES \n");

					for (size_t i = 0; i <=Personnel[r].nbrFCnge ; i++) {
							printf("Date de depart : %d-%d-%d\n", Personnel[r].Conge[i].dateD.jour,Personnel[r].Conge[i].dateD.mois,Personnel[r].Conge[i].dateD.annee );
							printf("Date de retour : %d-%d-%d\n",Personnel[r].Conge[i].dateF.jour,Personnel[r].Conge[i].dateF.mois,Personnel[r].Conge[i].dateF.annee );
							printf("Motif :%s\n",Personnel[r].Conge[i].motif );
							printf("_______________________________________________________\n");
						}
					printf("nombre de conges maxi atteint \n");
				}
			}
			else
				printf("Pas retrouver.\n");
		}
		else if (choix==3)
		{
			r=rechercheP(Personnel, nbre_P);
			system("CLS");
			if(r!=-1){
				if(Personnel[r].nbrS<3){
					Personnel[r].Sanction[Personnel[r].nbrS]=Rsanction();
					printf("\tLISTE DES SANCTIONS \n");
					for (size_t i = 0; i <= Personnel[r].nbrS; i++) {
						printf("Date de depart : %d-%d-%d\n", Personnel[r].Sanction[i].dateD.jour,Personnel[r].Sanction[i].dateD.mois,Personnel[r].Sanction[i].dateD.annee );
						printf("Date de retour : %d-%d-%d\n",Personnel[r].Sanction[i].dateF.jour,Personnel[r].Sanction[i].dateF.mois,Personnel[r].Sanction[i].dateF.annee );
						printf("Motif :%s\n",Personnel[r].Sanction[i].motif );
						printf("_______________________________________________________\n");
					}
					Personnel[r].nbrS++;
				}
				else
				{
					printf("\tLISTE DES SANCTIONS \n");
					for (size_t i = 0; i <= Personnel[r].nbrS; i++) {
						printf("Date de depart : %d-%d-%d\n", Personnel[r].Sanction[i].dateD.jour,Personnel[r].Sanction[i].dateD.mois,Personnel[r].Sanction[i].dateD.annee );
						printf("Date de retour : %d-%d-%d\n",Personnel[r].Sanction[i].dateF.jour,Personnel[r].Sanction[i].dateF.mois,Personnel[r].Sanction[i].dateF.annee );
						printf("Motif :%s\n",Personnel[r].Sanction[i].motif );
						printf("_______________________________________________________\n");
					}
					printf("vous avez atteint le nombre maxi de sanction par consequent vous etes renvoyer \n");
				}
			}
			else
				printf("Pas retrouver.\n");
		}
		else if (choix==4)
		{
				r=rechercheP(Personnel, nbre_P);
				system("CLS");
				if(r!=-1){
					afficherP(Personnel,r);
				}
				else
					printf("Pas retrouver.\n");
		}
		else if (choix==5)
		{
			printf("Liste du personnel :\n");
				listAfficherP(Personnel, nbre_P);
		}
		else if (choix==6)
		{
			r=rechercheP(Personnel, nbre_P);
			system("CLS");
			if(r!=-1){
					personnel personne=enregistrementP();
					modificationP(Personnel,personne,r);
			}
			else
				printf("Pas retrouver.\n");
		}
		else if (choix==7)
		{
			r=rechercheP(Personnel, nbre_P);
			system("CLS");
			if(r!=-1)
				afficherP(Personnel,r);
			else
				printf("Pas retrouver.\n");

		}
		else if (choix==8)
		{
				r=rechercheP(Personnel, nbre_P);
				if (r==-1)
					printf("Pas retrouve\n");
				suppressionP(Personnel,r);
				system("CLS");
				printf("Personnel supprime \n");
		}
		printf("\nVOULEZ VOUS CONTINUER\n");
		printf("1-oui \n2- non\n");
		scanf("%d",&choix);
	}while(choix ==1);


	fclose(F);
	getch();
	return 0;
}

int menu()
{
	int C;
	do{
		printf("\t\tMenu:\n");
		printf("1-enregistrement personnel\n2-gestion des conges\n3-gestion des sanctions\n4-afficher une personne");
		printf("\n5-afficher la liste du personnel\n6-modifier une personne\n7-rechercher une personne\n8-supprimer un personnel\n");
		scanf("%d",&C);
		return C;
	}while(C<0 || C>8);
}
