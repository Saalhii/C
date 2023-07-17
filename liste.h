#include "arbre.h"
  /*représentation physique*/
struct element
{
	struct noeud *cle ;//puisque on va inserer dans la liste des elements de type struct noeud
	struct element *suivant ;
};

struct liste
{
	struct element *premier ;
	struct element *dernier ;
};
//les services a exporter
void creer_liste(struct liste *);
void inserer_enqueue(struct noeud*, struct liste*);

