#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "arbre.h"
#include "liste.h"
#include "file.h"

//creation d'un pointeur vers un arbre vide
struct noeud*creer_arbre()
{
    return NULL;
}
//arbre vide c'est a dire le pointeur de l'arbre se pointe sur le pointeur NULL
unsigned vide(struct noeud*ab)
{
    return ab==NULL;
}
/*La fonction construire permet de créer un nouveau nœud pour un arbre binaire
en spécifiant la valeur du nœud ainsi que ses nœuds fils droit et gauche.*/
struct noeud* construire(char val, struct noeud*droite,struct noeud*gauche)
{
    struct noeud*ar;
    ar=(struct noeud*)malloc(sizeof(struct noeud));
    ar->info=val;
    ar->sad=droite;
    ar->sag=gauche;
    return ar;
}
void ajouter_noeud_abr(int info,noeud** ar)
{
	noeud* e;
	if(!(*ar)) /*ar==NULL*/
	{
		e=(noeud*)malloc(sizeof(noeud));
		e->cle=info;
		e->sag=NULL;
		e->sad=NULL;
		*ar=e;
	}
	else //ar!=NULL
	{
		if(info<=(*ar)->cle)
			ajouter_noeud_abr(info,&((*ar)->sag));
		else
			ajouter_noeud_abr(info,&((*ar)->sad));
	}
}
//retourne ce qui trouve a gauche du noeud
struct noeud* gauche(struct noeud*ab)
{
    assert(ab!=NULL);
    return ab->sag;
}
//retourne ce qui trouve a droite du noeud
struct noeud*droite(struct noeud*ab)
{
    assert (ab!=NULL);
    return ab->sad;
}
//retoune la racine de larbre
char lire_racine(struct noeud*ab)
{
    assert(ab!=NULL);
    return ab->info;
}
//retourne la taille de larbre
int taille(struct noeud*ab)
{
    if (ab==NULL)
        return 0;
    else
        return 1+taille(ab->sad)+taille(ab->sag);
}
/* nombre de feuilles d'un arbre en C fait référence au nombre de nœuds
dans l'arbre qui n'ont pas d'enfants*/
int nb_feuille(struct noeud*ab)
{
    if (ab==NULL)
        return 0;
    else if ((ab->sad==NULL) && (ab->sag==NULL))
        return 1;
    else
        return nb_feuille(ab->sad)+nb_feuille(ab->sag);
}
// rechrche d'un element dans larbre binaire en routourant son adresse
struct noeud* rechercheBinaire(struct noeud* racine, int x)
{
    if (racine == NULL || racine->info == x) {
        return racine; // Retourner l'adresse de l'élément trouvé (ou NULL si non trouvé)
    }
    else if (x < racine->info) {
        return rechercheBinaire(racine->sag, x); // Rechercher dans le sous-arbre gauche
    }
    else {
        return rechercheBinaire(racine->sad, x); // Rechercher dans le sous-arbre droit
    }
}
//cette fonction permet juste de verifier si element existe ou pas
unsigned rechercheABR(struct nœud *racine; int cle)
{
    if (racine==NULL)
        return 0;
    if (racine->info==cle)
        return 1;
    else if (cle < racine->info)
        return rechercheABR(racine->sag, cle);
    else
        return rechercheABR(racine->sad, cle);
}
int max(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;

}
int hauteur(struct noeud*ab)
{
    if(vide(ab))
        return -1;
    return 1+max(hauteur(ab->sad),hauteur(ab->sag));
}
void afficher_par_niveau(struct noeud* ab)
{
    assert(ab != NULL); // Correction : Vérifier que l'arbre n'est pas vide
    struct file* f;
    struct noeud* p;
    creer_file(&f); // Correction : Il faut passer l'adresse de la file
    enfiler(f, ab);
    printf("%d", ab->info);
    while(!vide_file(f)) // Correction : Utiliser la négation
    {
        p = depiler(f);
        if(p->sad != NULL)
        {
            enfiler(f, p->sad);
            printf("%d", p->sad->info);
        }
        if(p->sag != NULL)
        {
            enfiler(f, p->sag);
            printf("%d", p->sag->info);
        }
    }
}

void inOrder(struct noeud*ab)
{
     if(ab!=NULL)
    {
        inOrder(ab->sag);
        printf("%d ",ab->info);
        inOrder(ab->sad);
    }
}
void preOrder(struct noeud*ab)
{
    if(ab!=NULL)
    {
        printf("%d",ab->info);
        preOrder(ab->sag);
        preOrder(ab->sad);
    }
}
static struct noeud *q ;
static void supp(struct noeud **r)
{
	ab=*r;
	if((ab)->sad)
		supp(&ab->sad) ;
	else
	{
		q->cle=ab->cle ;
		q=ab ;
		ab=ab->sag ;
	}
}
void supprimer_noeud_abr(struct noeud **ab,int x)
{
    ar=*ab;
	//ar est le parametre in out 'passage par adresse
	//recherche de la position de l'element a supprimer
	if(ar== NULL) /* x pas dans l'arbre */
        return;
	else if(x<ar->cle)
        supprimer_noeud_abr(&ar->sag),x) ;
	else if(x>ar->cle)
        supprimer_noeud_abr(&ar->sad),x) ;
	else
	{
		//on a trouver l'element a supprimer
		q=ar;
		if(q->sad == NULL)//si lelement a supprimer n'a pas de sous arbre droite
			ar=q->sag ;//il va pointer sur le sous arbre gauche
		else if(q->sag == NULL)//si lelement a supprimer n'a pas de sous arbre gauche
			ar=q->sad ;//il va pointer sur ke sous arbre droite
		else//si le noeud a supprimer a des sous arbres droites ou gauche ,dans ce cas on doit parcours
            //le contenue de sous arbre jusqu'a trouver la valeur a remplacer dans la racine
			supp(&(q->sag)) ;//appel a la fonction supprimer qui permet de faire cette operation
        free(q) ;//suppression
}
}


int Verifie_ABR(struct noeud* ab, int min, int max)
{
    if (ab == NULL) {
        return 1; // Arbre vide, il est considéré comme un ABR
    }
    if (ab->info > max || ab->info < min) {
        return 0; // L'élément n'est pas dans l'intervalle [min, max], ce n'est pas un ABR
    }
    else {
        return Verifie_ABR(ab->sag, min, ab->info - 1) && Verifie_ABR(ab->sad, ab->info + 1, max);
        // Vérification récursive pour les sous-arbres gauche et droit
    }
}



void get_noeuds_feuilles(struct noeud*ab,struct liste*l)
{
    if (ab==NULL)//c'est le cas ou larbre est vide ou on a terminer le parcours de larbre
        return NULL;
    if (ab->sad==NULL)&&(ab->sag==NULL)//si on trouve une feuille on linsere dans la liste
        endequer(ab,l);
    else//le parcous recursif de larbre
    {
        if (ab->sad!=NULL)//si
            return get_noeuds_feuilles(ab->sad,l);
        if (ab->sag!=NULL)
            return get_noeuds_feuilles(ab->sag,l);

}
}
int compare(struct noeud*ab1,struct noeud*ab2)
{
    if (ab1==NULL)
        return(ab2!=NULL);
    else
    {
        if (ab2==NULL)
            return 1;
        else
        {
            return ((ab1->info!=ab2->info))||compare(ab g et ab g)||compare(ab d et ab d)
        }
    }
}
// Fonction récursive pour vérifier si un arbre est dégénéré
bool estArbreDegenere(struct Noeud* racine) {
    // Si l'arbre est vide ou s'il n'a pas d'enfant, il est considéré comme dégénéré
    if (racine == NULL || (racine->gauche == NULL && racine->droit == NULL))
        return true;

    // Si un nœud a à la fois un enfant gauche et un enfant droit, l'arbre n'est pas dégénéré
    if (racine->gauche != NULL && racine->droit != NULL)
        return false;

    // Vérifier récursivement pour les sous-arbres gauche et droit
    if (racine->gauche != NULL)
        return estArbreDegenere(racine->gauche);
    else
        return estArbreDegenere(racine->droit);
}






