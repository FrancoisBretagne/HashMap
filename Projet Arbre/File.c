#include "fonction.h"




Node *CreateNode (char *mot, int niveau){    //  fonction to create a node in the list
    Node *new=NULL;
    new = malloc(sizeof(Node));
    if ( new==NULL ){exit(1);}
    new->name = malloc((strlen(mot)+1)*sizeof(char));
    if ( new->name==NULL){exit(2);}
    strcpy ( new->name , mot);
    new->niv = niveau;
    new->next = NULL;
    return new;
}

Node *AddNode ( Node *head, char *mot, int niveau){ // fonction to add a node in the list
    Node *Tampon = NULL;
    Tampon = CreateNode ( mot, niveau);
    if(head == NULL){
        head = Tampon;
        head->next =NULL;
    }
    else{
        Tampon->next=head;
    }
    return Tampon;
}


int Exist_in_list ( Node *head, char *name){    // Fonction to search if the word exist in the list
    if ( head == NULL){ exit(15);}
    while ( head!= NULL) {
       if ( strcmp ( head->name, name) == 0 ){
            return 1;
       }
       head = head->next;
    }
    return 0;
}

