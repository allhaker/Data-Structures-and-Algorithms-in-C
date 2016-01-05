//
//  main.c
//  Exerccise1_Rewind
//
//  Created by Mironov Oleg on 16.12.15.
//  Copyright © 2015 Mironov Oleg. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef struct {
    int hour;
    int minute;
} Ttime;

void read_time(Ttime *myTime);
void print_time(Ttime myTime);
Ttime time_diff(Ttime time1, Ttime time2);
int to_minutes (Ttime time);
Ttime to_time (int mm);
int compare_times(Ttime time1, Ttime time2);

int main(int argc, const char * argv[]) {
    Ttime myTime, myTime2, timeRes;
    
    read_time(&myTime);
    read_time(&myTime2);
    
    timeRes = time_diff(myTime, myTime2);
    
    print_time(timeRes);
    
    printf("\n");
    return 0;
}

Ttime time_diff(Ttime time1, Ttime time2) {
    if (compare_times(time1, time2) == 1) {
        return to_time(to_minutes(time1) - to_minutes(time2));
    } else return to_time(to_minutes(time2) - to_minutes(time1));
}

int to_minutes (Ttime time) {
    return time.hour * 60 + time.minute;
}

Ttime to_time (int mm) {
    Ttime time;
    time.hour = round(mm/60);
    time.minute = mm%60;
    return time;
}

void read_time(Ttime *myTime) {
    printf("Please, enter time in format hh:mm - ");
    scanf("%d:%d",&myTime->hour,&myTime->minute);
}

void print_time(Ttime myTime) {
    printf("The given time is %d:%d", myTime.hour, myTime.minute);
}

int compare_times(Ttime time1, Ttime time2) {
    int min1 = to_minutes(time1);
    int min2 = to_minutes(time2);
    
    if (min1 > min2) return 1;
    else if (min1 < min2) return -1;
        else return 0;
}