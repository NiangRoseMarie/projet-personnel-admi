#ifndef __ADMINISTRATION__H__
#define __ADMINISTRATION__H__

#include "date.h"


#define A_c 2019

struct conge
{
	char motif[256];
	date dateD;
	date dateF;
};
typedef struct conge conge;
struct sanction
{
	char motif[256];
	int verdicte;
	date dateD;
	date dateF;
};
typedef struct sanction sanction;
conge Rconge();
sanction Rsanction();


#endif
