//
//  process_times.c
//  EX2 - Component nature of ADT
//
//  Created by Mironov Oleg on 06.01.16.
//  Copyright © 2016 Mironov Oleg. All rights reserved.
//

#include <stdio.h>
#include "time.h"

int main(int argc, const char * argv[]) {
    Ttime myTime, myTime2, timeRes;
    
    read_time(&myTime);
    read_time(&myTime2);
    
    timeRes = time_diff(myTime, myTime2);
    
    print_time(timeRes);
    print_time_with_prompt(timeRes, "\nThe result of time comparasion is following: ");
    
    printf("\n");
    return 0;
}

