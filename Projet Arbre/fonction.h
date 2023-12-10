#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct node{
    struct node *next, *prev;
    int niv;
    char *name;
}Node;


typedef struct tree{
    struct tree *left_node, *right_node;
    int data;
    Node *list;
}Tree;

typedef struct{
    struct tree *head;
    int size;
}Hashmap;

Tree* Create_List_in_Tree ( Tree *headT, char *name, int niveau);
Tree* Create_Tree(char *name , int niveau1 );
int right_is_declared(Tree *headT);
int left_is_declared(Tree *headT);
void PrintList ( Node *head);
void PrintTree ( Tree *headT);

Tree *Delete_Tree ( Tree *headT, char *name, int lenth);
Tree *SuppMax ( Tree *headT, Tree *root, int *lenth);


Hashmap * supp_in_tree( Hashmap *root, char *name, int lenth);

Node *CreateNode (char *mot, int niveau);
Node *AddNode ( Node *head, char *mot, int niveau);


Hashmap * create_hm(char *name, int niveau);
void add_in_tree(Hashmap *root, char *name, int niveau);

int Exist_in_list ( Node *head, char *name);
Tree *Modify_in_List ( Tree *headT, char *name, int niveau);
Tree *Modify_in_Tree (Tree *headT, char *name, int niveau);