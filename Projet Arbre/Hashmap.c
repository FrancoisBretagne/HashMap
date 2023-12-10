#include "fonction.h"


void add_in_tree(Hashmap *root, char *name, int niveau){  // Fonction which help me to get the size of the hashmap. This function count every time we add an element
    root->size++;
    root->head = Create_List_in_Tree(root->head, name, niveau);
}

Hashmap *supp_in_tree( Hashmap *root, char *name, int lenth){ // Fonction which help me to get the size of the hashmap. This function count every time we delete an element
    root->size--;
    root->head = Delete_Tree ( root->head, name, lenth);
    return root;
}

Hashmap * create_hm(char *name, int niveau)   // Create the hashmap and initialise the size of the hashmap
{
    Hashmap *new = NULL;
    new = malloc(sizeof(Hashmap));
    if(new == NULL){
        printf("Error with the allocation of the hm");
        exit(1);
    }
    new->size = 1;
    new->head = Create_Tree(name, niveau);
    return new;
}