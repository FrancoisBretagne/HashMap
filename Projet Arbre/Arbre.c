#include "fonction.h"



int left_is_declared(Tree *headT){              // In order to know if there is a left son
    if(headT->left_node == NULL) return 0;
    return 1;
}

int right_is_declared(Tree *headT){             // In order to know if there is a right son
    if(headT->right_node == NULL) return 0;
    return 1;
}

Tree* Create_Tree(char *name , int niveau1 ){   // create my tree
    Tree *new = NULL;
    new = malloc(sizeof(Tree));

    if(new == NULL) exit(11);
    new->left_node = new->right_node = NULL;
    new->data = strlen (name);
    new->list = CreateNode (name, niveau1);
    return new;
}


Tree* Create_List_in_Tree ( Tree *headT, char *name, int niveau){       // I add here the element in the three. If there is no element for the number 8
    int lenth;                                                          // in the tree I create a new node but if there is something I add in the list present in the node
    lenth = strlen(name);
    if ( headT == NULL){
        headT = Create_Tree ( name, niveau);
    }
    else if ( lenth > (headT->data)){
        headT->right_node = Create_List_in_Tree ( headT->right_node, name, niveau);
    }
    else if ( lenth < (headT->data)){
        headT->left_node = Create_List_in_Tree ( headT->left_node, name, niveau);
    }
    else if (lenth == (headT->data)){
        headT->list = AddNode ( headT->list ,name, niveau); 
    }
    return headT;
}

Tree *Modify_in_List ( Tree *headT, char *name, int niveau){ // It modify the level of the player present in the list of the node we are on
    Node *Liste;
    if (headT->list == NULL || headT == NULL){
        exit (16);
    }
    Liste = headT->list;
    while ( Liste != NULL ){
        if (strcmp(Liste->name,name) == 0){
            Liste->niv = niveau;
        }
        Liste = Liste->next;
    }
    return headT;
}


Tree *Modify_in_Tree (Tree *headT, char *name, int niveau){ // We move on until we find the right node to modify
    if ( headT == NULL){
        return headT;
    }
    else if ( strlen(name) > (headT->data) ){
        headT->right_node = Modify_in_Tree ( headT->right_node , name, niveau);
    }
    else if ( strlen (name) < (headT->data) ){
        headT->left_node = Modify_in_Tree ( headT->left_node, name, niveau);
    }
    else {
        if ( Exist_in_list ( headT->list, name) == 0){  // We check if the player exist in the list of the node
            printf ( "Ce mot n'existe pas");
            return headT;
        }
        headT = Modify_in_List (headT, name, niveau);  // Then we call the function to modify the level of the player in the list of the node
    }
    return headT;
}

Tree *SuppMax ( Tree *headT, Tree *Root ,int *lenth ){   // Change the node we want to delete with the biggest node of is left son tree. Then we delete the node we wanted to delete
    Tree *Tampon = NULL;
    if ( right_is_declared(headT) == 1){
        headT->right_node = SuppMax ( headT->right_node, Root, lenth);
    }
    else{
        *lenth = headT->data;
        Root->list = headT->list;
        Tampon = headT;
        headT = headT->left_node;
        free ( Tampon );
    }
    return headT;
}

Tree *Delete_in_liste (Tree *headT, char *name){  // Supervise every case of the suppression
    Node *Tampon = NULL;
    Tree *Tampon2 = NULL;
    Node *Liste = NULL; 
    int count = 0;
    if (headT->list == NULL || headT == NULL){
        exit (16);
    }
    Liste = headT->list;
    while ( Liste != NULL){    // we check how much node we got in the list
        count++;
        Liste = Liste->next;
    }
    if ( count == 1 ){   // if there is only one node we just free the list
        Tampon = headT->list;
        headT->list = headT->list->next;
        free (Tampon);
        if ( left_is_declared(headT) == 0){  // Then if there is no left son of the Tree's node, we delete the tree's node
            Tampon2 = headT;
            headT = headT->right_node;
            free ( Tampon2 );
        }
        else{
            headT->left_node = SuppMax ( headT->left_node, headT, &(headT->data) ); // if there is a left son we use the fonction suppmax explain above
        }
    }
    else {
        if ( strcmp(headT->list->name, name ) == 0 ){  // the case if there is more than one element in the list of the Tree's node
            Tampon = headT->list;                      // here we compare the first element of the list if he is the one we want to delete we delete it.
            headT->list = headT->list->next;
            free ( Tampon );
        }
        else{
            Liste = headT->list;   
            while ( Liste != NULL){                     // if this not the first element, we compare until we find the element we want to delete and then we delete it.
                if ( strcmp ( Liste->next->name, name) == 0){
                    Tampon = Liste->next;
                    Liste->next = Tampon->next;
                    free ( Tampon );
                }
                Liste = Liste->next;
            }
        }
    }
    return headT;
}

Tree *Delete_Tree ( Tree *headT, char *name, int lenth){   // We move with this function until we find the node of the tree we were searching for.
    Tree *Tampon = NULL;
    Tree *Root = NULL;
    if ( headT == NULL){
        return headT;
    }
    else if ( lenth > (headT->data) ){
        headT->right_node = Delete_Tree ( headT->right_node , name, lenth);
    }
    else if ( lenth < (headT->data) ){
        headT->left_node = Delete_Tree ( headT->left_node, name, lenth);
    }
    else {
        if ( Exist_in_list ( headT->list, name) == 0){    // if the player doesn't exist in the list of the node tree we're in we say that the word doesn't exist and we return 
            printf ( "Ce mot n'existe pas");
            return headT;
        }
        headT = Delete_in_liste (headT, name);   // if the player exist we call the function explain above
    }
    return headT;
}

void PrintList ( Node *head){    // function to print the list in the node
    while( head != NULL){
        printf ("       -> %s - %d \n", head->name, head->niv);
        head = head->next;
    }
}

void PrintTree ( Tree *headT){    // function to print the tree and the element inside ( the list)
    if ( headT == NULL){ return ;}
    PrintTree ( headT->left_node);
    printf ("| %d : \n", (headT->data));
    PrintList ( headT->list);
    PrintTree ( headT->right_node);
}                   



