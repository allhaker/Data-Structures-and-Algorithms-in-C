//
//  main.c
//  Pointers Training
//
//  Created by Mironov Oleg on 05.01.16.
//  Copyright © 2016 Mironov Oleg. All rights reserved.
//

#include <stdio.h>
void basicPointers();
void arrayPointers();
int main(int argc, const char * argv[]) {
    //basicPointers();
    arrayPointers();
    
    return 0;
}

void basicPointers() {
    int tuna = 19;
    int *pTuna = &tuna; //Reading tuna memory address to a pointer
    
    printf("Address \t name \t Value \n");
    printf("%p \t %s \t %d \n", pTuna, "tuna", tuna);
    printf("%p \t %s \t %p \n", &pTuna, "tuna", pTuna);
    
    printf("\n *pTuna: %d \n", *pTuna); //Dereferencing of a Pointer
    
    *pTuna = 71; //Dereferencing of a Pointer
    
    printf("\n *pTuna: %d \n", *pTuna);
}

void arrayPointers() {
    int i;
    int meatBalls[5] = {1,2,5,10,3};
    for (i = 0; i < 5; i++) {
        printf("meatBalls[%d] \t %p \t %d \n", i, &meatBalls[i], meatBalls[i]);
    }
    printf("\nmeatBalls %p\n", meatBalls);
    
    printf("\n*meatBalls %d\n", *meatBalls);
    printf("\n*(meatBalls + 2) %d\n", *(meatBalls+2)); //third emelent in the array dereferenced
    
}
