struct noeud
{
    char info;
    struct noeud *sad;
    struct noeud *sag;
};

//les services a exporter

struct noeud*creer_arbre();//mrigel
unsigned vide(struct noeud*);//mrigel
struct noeud* construire(char, struct noeud*,struct noeud*);//mrigel
struct noeud* ajout_arbre_binaire(struct noeud* test,int x);
struct noeud* gauche(struct noeud*);
struct noeud* droite(struct noeud*);
char lire_racine(struct noeud*);//mrigel
int taille(struct noeud*);//mrigel
int nb_feuille(struct noeud*);//mrigel
int recherche(struct noeud*,char );//mrigel
void afficher_par_niveau(struct noeud*);//mrigel
unsigned non_degenerer(struct noeud *);//mrigel
struct noeud* rechercheBinaire(struct noeud*,int);//ma3neha traja"li ladresse mte3ou
void inOrder(struct noeud*);
void preOrder(struct noeud*);
void postOrder(struct noeud*);
void supprimer_noeud_abr(struct noeud **,int );
struct noeud* rechercheBinaireMoinsUn(struct noeud*test,int x);
int Verifie_ABR(struct noeud*,int,int);
void get_noeuds_feuilles(struct noeud*,struct liste*);
int compare(struct noeud*,struct noeud*);
