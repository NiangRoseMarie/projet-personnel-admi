#ifndef __DATE__H__
#define __DATE__H__


struct date
{
	int jour ;
	int mois ;
	int annee;
};

typedef struct date date;
date Date ();
#endif