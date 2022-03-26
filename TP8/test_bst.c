#include "bst_operations.c"




 void main(){


  printf("\n[INFO] creation d'une table...");
  top racine = createBST(6);
  printf("\n************************success***********************\n");
  
  printf("\n[INFO] ajout de valeur dans l'arbre...");
  addtop(racine, 2);
  addtop(racine, 19);
  addtop(racine, 5);
  addtop(racine, 12);
  addtop(racine, 1);
  addtop(racine, 4);
  addtop(racine, 20);
  printf("\n************************success***********************\n");

  printf("\n[INFO] affichage de l'arbre");

  printf("\n\n     %d", racine->key);

  printf("\n  %d", (racine->left)->key);
  printf("       %d", (racine->rigth)->key);
  printf("\n**********************");
  printf("\n%d", (racine->left)->left->key);
  printf("   %d", (racine->left)->rigth->key);
  printf("    %d", (racine->rigth)->left->key);
  printf("     %d", (racine->rigth)->rigth->key);
  printf("\n***********************");
  printf("\n  %d", ((racine->left)->rigth)->left->key);

  printf("\n************************success***********************\n");


  /* test recherche 

  rechercher un sommet
   top test = seachtop(racine, 100);
   printf("%d", (test->left)->key);

  */
  
  printf("\n[INFO] recherche d'une valeur apartir de sa valeur \n");
  top pere = seachtop(racine, 19)->pere;
  printf("%d", pere->key);
  printf("\n************************success***********************\n");

  printf("\n[INFO] recherche une valeur dans un arbre test avec 45...\n  \n");
  top check = searchvalue(racine, 45);
  printf("\n************************success***********************\n");

  printf("\n[INFO] recherche une valeur dans un arbre test avec 4...  \n");
  top check2 = searchvalue(racine, 4);
  printf("\n************************success***********************\n");
  

  printf("\n[INFO] suppresion d'un sommet apartir de sa valeur/ supprimer : 2");
  deletetop(racine, 2);
  printf("\n************************success***********************\n");

  printf("\n[INFO] affichage de l'arbre après suppression");

  printf("\n\n     %d", racine->key);
  printf("\n  %d", (racine->left)->key);
  printf("       %d", (racine->rigth)->key);
  printf("\n************************************************\n");
  printf("\n%d", (racine->left)->left->key);
  printf("   %d", (racine->left)->rigth->key);
  printf("    %d", (racine->rigth)->left->key);
  printf("     %d", (racine->rigth)->rigth->key);
  printf("\n************************success***********************\n");

  exit(EXIT_SUCCESS);

  

 };