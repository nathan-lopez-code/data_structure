#include "bst_operations.h"

top createBST(value key)
{
    top racine = (top)malloc(sizeof(struct top));

    if (racine != NULL){
        racine->key = key;
        racine->left = NULL;
        racine->rigth = NULL;
        racine->pere = NULL;
    }
    return racine;

};

value getvalue(top _top)
{
    if(_top != NULL)
    {
        return _top->key;
    }
    return 0;
};


/* creation d'un arbre binaire de recherche  */
top createtop(value key, top _top)
{
    top new_top =(top)malloc(sizeof(struct top));
    if(new_top)
    {
        new_top->key = key;
        new_top->pere = _top;
        new_top->rigth = NULL;
        new_top->left = NULL;
        return new_top;
    }else{
        perror("allocation impossible");
        exit(EXIT_FAILURE);
    }
};

/* insertion de valeur dans un arbre binaire de recherche */

void addrigth(top _top, top new_top)
{



    if(_top->rigth != NULL){
        _top = _top->rigth;
        if(new_top->key > _top->key)
        {
            addrigth(_top, new_top);
        }else{
            addleft(_top, new_top);
        }
    }else{
        _top->rigth = new_top;
        new_top->pere = _top;
    }

};

void addleft(top _top, top new_top)
{
    if(_top->left != NULL){
        _top = _top->left;
        if(new_top->key < _top->key)
        {
            addleft(_top, new_top);
        }else{
            addrigth(_top, new_top);
        }
    }else{
        _top->left = new_top;
         new_top->pere = _top;
    }

};

void addtop(top tree, value key){
    
    if(tree != NULL)
    {
       top new_top = createtop(key, tree);
       if(new_top)
       {

           if(key > tree->key){
               addrigth(tree, new_top);
           }else if(new_top->key < tree->key){
               addleft(tree, new_top);
           }else{
                perror("valeur existant");
                exit(EXIT_FAILURE);
           }
       }
    }
};


/* rechercher un sommet apartir d'une clé */
top searchrigth(top _top, value key)
{
    if(_top->key == key){
        return _top;
    }else if(key >= getvalue(_top)){
        if(_top->rigth){
            top new_top = _top->rigth;
            return searchrigth(new_top, key);
        }else{
            return 0;
        }
    }else if(key <= getvalue(_top)){
        if(_top->left){
            top new_top = _top->left;
            return searchleft(new_top, key);

        }else{
            return 0;
        }
    }
};


top searchleft(top _top, value key)
{
    if(_top->key == key){
        return _top;
    }else if(key >= getvalue(_top)){
        if(_top->rigth){
            top new_top = _top->rigth;
            return searchrigth(new_top, key);
        }else{
           return 0;
        }
    }else if(key <= getvalue(_top)){
        if(_top->left){
            top new_top = _top->left;
            return searchleft(new_top, key);

        }else{
            return 0;
        }
    }
};


top seachtop(top tree, value key)
{
    if(tree->key){
        if(tree->key <= key){
            /* rercher à droit */
            return searchrigth(tree, key);
        }else if(tree->key >= key){
            /* rechercher à gauche */
            return searchleft(tree, key);
        }else{
            return NULL;
        }
    }
};

top searchvalue(top tree, value key)
{
    top checking  = seachtop(tree, key);
    if(checking == 0){
        printf("\nla valeur %d n'est pas dans l'arbre", key);
        return 0;
    }else{
        printf("\n la valeur %d a été trouvé dans l'arbre", checking->key);
        return checking;
    }
}

/* suppression d'un sommet */

int check_child(top _top, char type)
{
    if(type == 'r'){
        if(_top->rigth != NULL){
            return 1;
        }else{
            return 0;
        }
    }else if(type == 'l'){
        if(_top->left != NULL){
            return 1;
        }else{
            return 0;
        }
    }
};

top mostleft(top _top)
{
    /* _top = valeur la plus a gauche */
    if(check_child(_top, 'r')){
        return mostleft(_top->rigth);
    }else if(check_child(_top, 'l')){
        return _top->left;
    }
    return _top;

};

void deletetop(top racine, value key)
{
    top _top = seachtop(racine, key);
    if(check_child(_top, 'l') && check_child(_top, 'r')){
        top pere = _top->pere;
        top remplace = mostleft(_top);
        remplace->left = _top->left;
        remplace->rigth = _top->rigth;
        if(pere->key < _top->key){
            pere->rigth = remplace;
        }else{
            pere->left = remplace;
        }
        free(_top);

    }else if(check_child(_top, 'l')){
        top child = _top->left;
        top pere = _top->pere;
        if(pere->key < _top->key){
            pere->rigth = child;
        }else{
            pere->left = child;
        }
        free(_top);
    }else if(check_child(_top, 'r')){
        top child = _top->rigth;
        top pere = _top->pere;
        if(pere->key < _top->key){
            pere->rigth = child;
        }else{
            pere->left = child;
        }
        free(_top);
    }else{
        top pere = _top->pere;
        top child = NULL;
        if(pere->key < _top->key){
            pere->rigth = child;
        }else{
            pere->left = child;
        }
        free(_top);

    }
}


void destroyBST(top racine)
{   
    if(racine != NULL)
    {
       free(racine);
    }
};



