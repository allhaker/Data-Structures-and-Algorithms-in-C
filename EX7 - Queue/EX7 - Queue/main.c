//
//  main.c
//  EX7 - Queue
//
//  Created by Mironov Oleg on 08.01.16.
//  Copyright © 2016 Mironov Oleg. All rights reserved.
//

#include <stdio.h>
/* arrque0.c -- An array implementation of Queue
 *
 * This is simple solution where array elements are moved
 * forward in the array in dequeue operation
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   //_getch*/
#include <termios.h>  //_getch*/
typedef char Titem;

/* The interface of queue */
typedef enum {NOT_OK, OK_OK } Tboolean;
typedef struct {
    Titem * array;
    int   number_of_items;
    int size;
} Tqueue;
void initialize_queue (Tqueue *Pqueue);
Tboolean enqueue(Tqueue *p, Titem item);
Tboolean dequeue(Tqueue *p, Titem *Pitem);
void print_queue(const Tqueue *Pqueue);
void enlarge_queue(Tqueue *Pqueue);
void cleanup_queue(Tqueue *Pqueue);
char getcha();

#define MAXSIZE 3

/* Application */
int main() {
    Tqueue queue;
    Tboolean succeed;
    char chr;
    
    initialize_queue(&queue);
    printf("\nEnter a letter to be queued ");
    printf("\nor digit 1 to dequeue a letter");
    printf("\nor Return to quit a program\n");
    
    chr = getcha(); // Get one character with echo in Windows
    while (chr != '\n' && chr != '\r') {
        if (isalpha(chr)) {
            succeed=enqueue(&queue, chr);
            print_queue(&queue);
            if (!succeed)
                printf("\n Enqueue operation failed\n");
        }
        if (chr == '1') {
            succeed = dequeue(&queue, &chr);
            if  (succeed) {
                printf("\na letter dequeued %c ", chr);
                print_queue(&queue);
            } else
                printf("\nDequeue operation failed\n ");
        }
        
        chr = getcha(); // Get one character with echo in Windows
    }
    cleanup_queue(&queue);
}

/* The implementations of operation functions of the queue */
void initialize_queue ( Tqueue *Pqueue)  {
    Pqueue->array = (Titem *) malloc(MAXSIZE * sizeof(Titem));
    Pqueue->number_of_items = 0;
    Pqueue->size = MAXSIZE;
}

Tboolean enqueue( Tqueue *Pqueue, Titem item) {
    if (Pqueue->number_of_items + 1 > Pqueue->size) {
        enlarge_queue(Pqueue);
        printf("\nQueue Enlarged\n");
        
    }
    Pqueue->array[Pqueue->number_of_items++] = item;
    return (OK_OK);
}

Tboolean dequeue( Tqueue *Pqueue, Titem *Pitem) {
    int i;
    
    if (Pqueue->number_of_items == 0)
        return(NOT_OK);
    else {
        *Pitem = Pqueue->array[0];
        for (i = 0 ; i < Pqueue->number_of_items-1 ; i++)
            Pqueue->array[i] = Pqueue->array[i+1];
        Pqueue->number_of_items--;
        
        return (OK_OK);
    }
}

void enlarge_queue(Tqueue *Pqueue) {
    Titem * array;
    Pqueue->size = MAXSIZE + Pqueue->size;
    array = (Titem *) malloc((Pqueue->size) * sizeof(Titem));
    for (int i = 0; i < Pqueue->number_of_items; i++) {
        array[i] = Pqueue->array[i];
    }
    cleanup_queue(Pqueue);
    Pqueue->array = array;
}

void print_queue (const Tqueue *Pqueue) {
    int i;
    
    printf("\nQueue now: \n\n");
    for (i = 0 ; i <  Pqueue->number_of_items ; i++ ) {
        printf(" %c ", Pqueue->array[i]);
    }
    printf("\n\n");
}


void cleanup_queue(Tqueue *Pqueue) {
    free(Pqueue->array);
    Pqueue->array = NULL;
}

char getcha(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
}
