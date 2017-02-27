//
//  main.c
//  A program that uses the fixed-point iteration method as taught in the AE2220-I Applied Numerical Analysis course.
//
//  Created by Cihangir Ozbek on 27-02-17.
//  Copyright © 2017 Cihangir Ozbek. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int main() {
    
    float xn;
    float xnmin1;
    float test;
    bool tat;
    
    
    // Ask user what his x0 is:
    printf("What is your inital point:");
    scanf("%f", &xnmin1);
    fpurge( stdin);
    
    //Initial conditions, test is for the amount of iteration, tat is to get out of while loop when amount of iterations are done, xn is just to give an random initial value/
    test = 1;
    tat = true;
    xn = 123;
    
    // Fixed Point Iteration:
    while (tat == true) {
        
        
        xn = pow((xnmin1+1), 0.3333333);
        
        xnmin1 = xn;
        
        // Amount of iterations that are needed:
        if (test == 10000) {
            tat = false;
        }
        test = test + 1;
    }
    
    // Printing your root:
    printf("Your root is at:\n");
    printf("%f\n", xn);
    
    
    return 0;
}
