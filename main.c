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
	Personnel=malloc(100*sizeof(int));
	int r;
	int C;

	FILE *F=NULL;
	F=fopen("gestion_du_personnel_A.txt","w+");
	if(F==NULL){
		printf("fichier ne souvre pas\n");
		return 1;
	}
	int choix;
	do{
		choix=menu();
		fprintf(F, "bon \n" );
	
		if(choix==1)
		{
			Personnel[nbre_P]=enregistrementP();
			
			Personnel[nbre_P].nbrS=0;
			Personnel[nbre_P].nbrFCnge=0;
			nbre_P++;
			
		}
		else if (choix==2)
		{
			r=rechercheP(Personnel, nbre_P);
			if(r!=-1){
				Personnel[r].Conge[Personnel[r].nbrFCnge]=Rconge();
				Personnel[r].nbrFCnge++;
			}
			else
				printf("Pas retrouver.\n");
		}
		else if (choix==3)
		{
			r=rechercheP(Personnel, nbre_P);
			if(r!=-1){
				Personnel[r].Sanction[Personnel[r].nbrS]=Rsanction();
				Personnel[r].nbrS++;
			}
			else
				printf("Pas retrouver.\n");
		}
		else if (choix==4)
		{
				r=rechercheP(Personnel, nbre_P);
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
			if(r!=-1)
				afficherP(Personnel,r);
			else
				printf("Pas retrouver.\n");

		}
		else if (choix==8)
		{
			
		}
		printf("VOULEZ VOUS CONTINUER\n");
		scanf("%d",&C);
	}while(C==1);
	
	
	
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
	}while(C<0 || C>8);
}