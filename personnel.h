#ifndef __PERSONNEL__H__
#define __PERSONNEL__H__

#include"date.h"


#include"administration.h"

struct personnel
{
	char nom[15];
	char prenom[20];
	char contact[10];
	date dateV;
	date dateAnniv;
	int fonction;
	char habitation[15];
	conge Conge[15];
	sanction Sanction[3];
	int nbrFCnge;
	int nbrS;
};

typedef struct personnel personnel;

personnel enregistrementP();
void modificationP(personnel *P,personnel personne,int position);
void suppressionP(personnel *P,int position, int n );
void afficherP(personnel *P,int position);
int rechercheP(personnel *P, int n );
void listAfficherP(personnel *P, int n );


#endif