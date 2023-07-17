#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arbre.h"

main()
{
    struct noeud* exp;
    //exp=construire('*',construire('+',NULL,NULL),LL);
    exp=construire(20,construire(10,construire(5,NULL,NULL),construire(15,NULL,NULL)),construire(30,construire(25,NULL,NULL),construire(35,NULL,NULL)));
    //exp=construire('*',construire('+',construire('a',NULL,NULL),construire('b',NULL,NULL)),construire('-',construire('c',NULL,NULL),construire('d',NULL,NULL)));
    printf("taille = %d\n",taille(exp));
    printf("nombre de feuilles = %d\n",nb_feuille(exp));
    printf("la racine de l'arbre est %d\n",lire_racine(exp));
    printf("la hauteur de larbre:%d\n",hauteur(exp));

}




