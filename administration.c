#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "administration.h"



conge Rconge()
{
	conge C;
	printf("\t\tCONGE\n");
	printf("Entrer le motif du conge :\n");
	scanf("%s",C.motif);
	printf("Date de depart :\n");
	C.dateD=Date();
	C.dateD.annee=A_c;
	printf("Date de retour \n");
	C.dateF=Date();
	do{
		printf("Annee :\n");
		scanf("%d",&C.dateF.annee);
	}while(C.dateF.annee<A_c);

	return C;

}
sanction Rsanction()
{
	int C;
	sanction S;
	printf("\t\tSANCTION\n");
	printf("Entrer le motif de la sanction :\n");
	scanf("%s",S.motif);
	printf("la sanction est pour :\n");
	do{
		printf("1-pour toujours donc renvoie immediat\n2-renvoie pour quelques jours\n");
		scanf("%d",&C);
	}while(C<0 || C>2);
	if(C==2)
	{
		printf("Date de depart :\n");
		S.dateD=Date();
		S.dateD.annee=A_c;
		printf("Date de retour \n");
		S.dateF=Date();
		do{
			printf("Annee :\n");
			scanf("%d",&S.dateF.annee);
		}while(S.dateF.annee<A_c);
	}


	return S;
}
