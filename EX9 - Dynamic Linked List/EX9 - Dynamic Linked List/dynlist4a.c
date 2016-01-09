/* dynlist4a.c -- Dynamic linked linear list
 *
 * The abstraction is ok, because first and last are are
 * incapsulated inside datatype Tlist and all paramaters of
 * operation functions are of this type.
 */

#include <stdio.h>
#include <stdlib.h>

typedef char Titem;

// Interface of list
typedef struct node *Tpointer;
typedef struct node {
    Titem item;
    Tpointer next;
} Tnode;
typedef Tpointer Tlist;
void initialize_list (Tlist *list);
void insert_to_list_end(Tlist *list, Titem data);
void print_list (Tlist list);
void cleanup_list(Tlist *list);

// Application
int main (void)  {
    Tlist list;
    
    initialize_list(&list);
    insert_to_list_end(&list, 'a');
    insert_to_list_end(&list, 'b');
    insert_to_list_end(&list, 'c');
    insert_to_list_end(&list, 'd');
    insert_to_list_end(&list, 'e');
    insert_to_list_end(&list, 'f');
    insert_to_list_end(&list, 'g');
    
    print_list(list);
    cleanup_list(&list);
    
    fflush(stdin); getchar();
}


// Implementation of list (only obj is need in appl)
void initialize_list (Tlist *list) {
    *list = NULL;
}

void cleanup_list(Tlist *list) {
    Tpointer aux1, aux2;
    
     aux1 = *list;
     while (aux1 != NULL) {
	    aux2 = aux1->next;
	    free(aux1);
	    printf("\nDeleted"); //for testing purposes
	    aux1 = aux2;
     }
    initialize_list(list);
}

void insert_to_list_end(Tlist *list, Titem data) {
    Tpointer newnode;
    Tpointer temp = *list;
    
    newnode = (Tpointer) malloc(sizeof(Tnode));
    newnode -> item = data;
    if (*list == NULL) {
        *list = newnode;
        (*list)->next = NULL;
    } else if ((*list)->next == NULL) {
        (*list)->next = newnode;
    } else {
        while (temp -> next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void print_list (Tlist list) {
    Tpointer what;
    
    printf("\nList 4 :");
    what = list;
    while (what != NULL) {
        printf("%c ", what->item);
        what = what->next;
    }
}