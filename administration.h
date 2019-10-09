#ifndef __ADMINISTRATION__H__
#define __ADMINISTRATION__H__

#include "date.h"

#define A_c 2019

struct conge
{
	char motif[256];
	date dateD;
	date dateF;
	int nbrFCnge;

};
struct sanction
{
	char motif[256];
	int nbrS;
	int verdicte;
	date dateD;
	date dateF;
};

typedef struct conge conge;
typedef struct sanction sanction;
conge Rconge();
sanction Rsanction();
void afficheConge();
void afficheSanction();


#endif
