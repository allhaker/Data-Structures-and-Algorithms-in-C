//
//  main.c
//  heap and structure
//
//  Created by Mironov Oleg on 05.01.16.
//  Copyright © 2016 Mironov Oleg. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    //Setting up Variables
    int i, howMany;
    int total;
    float average;
    int  * pointsArray;
    
    //User input of how many numbers
    printf("How many numbers do you want to average?\n");
    scanf(" %d", &howMany);
    
    //Array memory allocation
    pointsArray = (int *) malloc(howMany * sizeof(int));
    
    printf("Enter the numbers! \n");
    
    //Filling up array and counting total
    for (i = 0; i<howMany; i++) {
        scanf("%d", &pointsArray[i]);
        total += pointsArray[i];
    }
    
    //Counting average and printing the array
    average = (float)total / (float)howMany;
    printf("Average is %f\n", average);
    for (i = 0; i<howMany; i++) {
        printf("%d\n", pointsArray[i]);
    }
    return 0;

}
