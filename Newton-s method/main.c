//
//  main.c
//  A program that uses Newton's method as taught in the AE2220-I Applied Numerical Analysis course.
//
//  Created by Cihangir Ozbek on 27-02-17.
//  Copyright © 2017 Cihangir Ozbek. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Your polynomional:

float fofx(float x){
    float y;
    
    y = pow(x,3) - x -1;
    
    return y;
}


// The derivitave of your formula

float dfofx(float x){
    float y;
    
    y = 3* pow(x,2) - 1;
    
    return y;
    
    
}
float fofx(float x);
float dfofx(float x);


int main() {
    
    float xn = 123;
    float xnmin1 = 1;
    float test =1;
    bool tat = true;
    
    
    
    // Ask user what his x0 is:
    printf("What is your inital point:");
    scanf("%f", &xnmin1);
    fpurge( stdin);
    
    
    
    while (tat == true) {
        xn = xnmin1 - fofx((xnmin1)) / dfofx((xnmin1));
        
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
    printf("Your error equals:\n");
    printf("%f\n", (0 - fofx(xn)));
    
    return 0;
}
