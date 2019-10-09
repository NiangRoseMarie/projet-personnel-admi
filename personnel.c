#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "date.h"
#include "personnel.h"


personnel enregistrementP()
{
	int r ;
	do{
	personnel P;
	printf("Nom :\n");
	scanf("%s",P.nom);
	printf("Prenom :\n");
	scanf("%s",P.prenom);
	printf("Date de Naissance :\n");
	P.dateAnniv=Date();
	do{
		printf("Annee :\n");
		scanf("%d",&P.dateAnniv.annee);
	}while(P.dateAnniv.annee<0 || P.dateAnniv.annee>A_c);
	////////////////////
	printf("Contact :\n");
	scanf("%s",P.contact);

	printf("Lieu d'habitation :\n");
	scanf("%s",P.habitation);
	do{
		printf("Choisissez votre fonction :\n");
		printf("1-Professeur\n2-technicien de surface\n3-gardien\n4-restaurateur\n5-comptable");
		printf("\n6-secretaire\n7-directeur\n8-chauffeur\n");
		scanf("%d",&P.fonction);
	}while(P.fonction<0 || P.fonction>8);

	printf("Date de venue :\n");
	P.dateV=Date();
	P.dateV.annee=A_c;

	printf("Etes vous sur des informations rentrees?\n1-oui\n2-non\n");
	scanf("%d",&r );
	return P;
	}while (r==2);


}

void modificationP(personnel *P,personnel personne,int position)
{
	strcpy(P[position].nom,personne.nom);
	strcpy(P[position].prenom,personne.prenom);
	strcpy(P[position].contact,personne.contact);
	P[position].fonction=personne.fonction;
	strcpy(P[position].habitation,personne.habitation);
}
void afficherP(personnel * P,int position)
{
	printf("Nom : %s\n",P[position].nom);
	printf("Prenom :%s\n",P[position].prenom);
	printf("Date de Naissance : %d/%d/%d\n",P[position].dateAnniv.jour,P[position].dateAnniv.mois,P[position].dateAnniv.annee);
	printf("Contact :%s\n",P[position].contact);
	printf("Lieu d'habitation %s:\n",P[position].habitation);
	printf("Date de venue :%d/%d/%d\n",P[position].dateV.jour,P[position].dateV.mois,P[position].dateV.annee);
	if(P[position].fonction==1)
			printf("Fonctioon : Professeur\n");
	else if(P[position].fonction==2)
		printf("Fonctioon : technicien de surface");
	else if(P[position].fonction==3)
		printf("Fonctioon : gardien");
	else if(P[position].fonction==4)
		printf("Fonctioon :restaurateur ");
	else if(P[position].fonction==5)
		printf("Fonctioon : comptable");
	else if(P[position].fonction==6)
		printf("Fonctioon :secretaire ");
	else if(P[position].fonction==7)
		printf("Fonctioon : directeur ");
	else if(P[position].fonction==8)
		printf("Fonctioon :chauffeur ");
}

void suppressionP(personnel *P,int position)
{
	personnel sp;
	///////////////
	strcpy(sp.nom,P[100].nom);
	strcpy(sp.prenom,P[100].prenom);
	strcpy(sp.contact,P[100].contact);
	sp.fonction=P[100].fonction;
	strcpy(sp.habitation,P[100].habitation);
	sp.dateAnniv=P[100].dateAnniv;
	sp.dateV=P[100].dateV;
//////////////////////////////////
	strcpy(P[100].nom,P[100].nom);
	strcpy(P[100].prenom,P[100].prenom);
	strcpy(P[100].contact,P[100].contact);
	P[100].fonction=P[100].fonction;
	strcpy(P[100].habitation,P[100].habitation);
	P[100].dateAnniv=P[100].dateAnniv;
	P[100].dateV=P[100].dateV;
//////////////////////////////////
	strcpy(P[position].nom,sp.nom);
	strcpy(P[position].prenom,sp.prenom);
	strcpy(P[position].contact,sp.contact);
	P[position].fonction=sp.fonction;
	strcpy(P[position].habitation,sp.habitation);
	P[position].dateAnniv=sp.dateAnniv;
	P[position].dateV=sp.dateV;

	P=realloc(P,99);
	P=realloc(P,100);

}
int rechercheP(personnel *P, int n)
{
	char code [7];
	printf("entrer votre contact\n");
	scanf("%s",code);
	for(int i=0;i<n;i++)
	{
		if(strcmp(P[i].contact,code)==0)
		{
			return i;
		}
	}
	return -1;
}
void listAfficherP(personnel *P, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Nom : %s\n",P[i].nom);
		printf("Prenom :%s\n",P[i].prenom);
		printf("Date de Naissance : %d/%d/%d\n",P[i].dateAnniv.jour,P[i].dateAnniv.mois,P[i].dateAnniv.annee);
		printf("Contact :%s\n",P[i].contact);
		printf("Lieu d'habitation %s:\n",P[i].habitation);
		printf("Date de venue :%d/%d/%d\n",P[i].dateV.jour,P[i].dateV.mois,P[i].dateV.annee);
		if(P[i].fonction==1)
			printf("Fonctioon : Professeur\n");
		else if(P[i].fonction==2)
			printf("Fonctioon : technicien de surface");
		else if(P[i].fonction==3)
			printf("Fonctioon : gardien");
		else if(P[i].fonction==4)
			printf("Fonctioon :restaurateur ");
		else if(P[i].fonction==5)
			printf("Fonctioon : comptable");
		else if(P[i].fonction==6)
			printf("Fonctioon :secretaire ");
		else if(P[i].fonction==7)
			printf("Fonctioon : directeur ");
		else if(P[i].fonction==8)
			printf("Fonctioon :chauffeur ");
		printf("___________________________________________________________________\n");
	}
}
