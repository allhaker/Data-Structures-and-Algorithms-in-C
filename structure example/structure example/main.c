//
//  main.c
//  structure example
//
//  Created by Mironov Oleg on 06.01.16.
//  Copyright © 2016 Mironov Oleg. All rights reserved.
//

#include <stdio.h>
#include "user.h"

int main(int argc, const char * argv[]) {
    struct TUser oleg;
    struct TUser john;
    
    oleg.userID = 1;
    oleg.age = 22;
    puts("Enter the first name of user 1");
    gets(oleg.firstName);
    puts("Enter the last name of user 1");
    gets(oleg.lastName);
    
    printf("User data: %d, %d, %s, %s\n", oleg.userID, oleg.age, oleg.firstName, oleg.lastName);
    
    return 0;
}
