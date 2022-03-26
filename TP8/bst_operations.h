#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#ifndef SEARCH_BINAIRE_TREE
#define SEARCH_BINAIRE_TREE


typedef unsigned int value;
typedef struct top *top;

struct top
{
    value key;
    top  left;
    top  rigth;
    top pere;
};

#endif

/* creation d'un arbre binaire de recherche et destruction */

top createBST();
void destroyBST(top racine); 

/* retourne la valeur de la position d'un element dans l'abre */

value getvalue(top _top);

/* creation d'un sommet */

top createtop(value key, top _top);

/* inserer une nouvelle valeur dans l'arbre */

void addleft(top _top, top new_top);
void addrigth(top _top, top new_top);
void addtop(top _bst, value key);

/* trouver un sommet apartir d'une valeur */

top searchrigth(top _top, value key);
top searchleft(top _top, value key);
top seachtop(top tree, value key);

/* rechercher une valeur dans l'arbre */

top searchvalue(top tree, value key);

/* supprimer un sommet apartir de sa valeur */

top mostleft(top _top);
void deletetop(top racine, value key);

