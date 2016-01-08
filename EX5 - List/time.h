//
//  time.h
//  EX2 - Component nature of ADT
//
//  Created by Mironov Oleg on 06.01.16.
//  Copyright © 2016 Mironov Oleg. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef struct {
    int hour;
    int minute;
} Ttime;

void read_time(Ttime *myTime);
void print_time(Ttime myTime);
void print_time_with_prompt(Ttime myTime, char *prompt);
Ttime time_diff(Ttime time1, Ttime time2);
int to_minutes (Ttime time);
Ttime to_time (int mm);
int compare_times(Ttime time1, Ttime time2);
