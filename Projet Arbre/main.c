#include "fonction.h"


int main (){
    
    Hashmap *root=create_hm("jean valjean", 1492);
    add_in_tree ( root, "Choupomoting", 2);
    add_in_tree ( root, "ratata", 21);
    add_in_tree ( root, "pikachu", 51);
    add_in_tree ( root, "John", 69);
    add_in_tree ( root, "culinaire", 0);
    add_in_tree ( root, "pate", 11);
    add_in_tree ( root, "Pierre", 19);
    add_in_tree ( root, "Sacha", 78);
    add_in_tree ( root, "Céleste", 25);
    add_in_tree ( root, "Octave", 44);
    add_in_tree ( root, "Abricot", 14);
    add_in_tree ( root, "Redbull", 14);
    add_in_tree ( root, "Donne des ailles", 50);
    add_in_tree ( root, "Amandine Leno", 100);
    PrintTree ( root->head);
    root = supp_in_tree ( root , "jean valjean", strlen("jean valjean"));
    root = supp_in_tree ( root , "Choupomoting", strlen("Choupomoting"));
    root->head = Modify_in_Tree ( root->head, "Céleste", 40);
    printf ( "\n\n\n After change in the tree : \n\n");
    PrintTree ( root->head);
    printf("\n The size of the hashmap : %d", root->size);
    return 0;
}