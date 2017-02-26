//
//  main.c
//  A program that uses the Recursive Bisection method as taught in the AE2220-I Applied Numerical Analysis course.
//
//  Created by Cihangir Ozbek on 24-02-17.
//  Copyright © 2017 Cihangir Ozbek. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Your polynomional:
float fofx(float x){
    float y;
    
    y = pow(x,6) + pow(x,5) + pow(x,4) + pow(x,3) + pow(x,2) + x - 1    ;
    
    return y;
}

// First derivitave of the polynomional:
float dfofx(float x){
    float y;
    
    y = 3*pow(x,2) - 1;
    
    return y;
}

// Second derivivate of the polynomional:
float ddfofx(float x){
    float y;
    
    y = 6*x;
    
    return y;
}

//Recursive bisection:

float recursive_bisection(float leftbound, float rightbound, float min_error){
    
    
    float cbound;
    float test;
    // Your initial interval is from leftbound to rightbound
    // There exist a root if fofx(leftbound) * fofox(rightbound) < 0
    // cbound is the middle between a and b:
    cbound = 1;
    
    
    if (fofx(leftbound)*fofx(rightbound) < 0) {
        
        //Interate till desired minimum error is reached
        while (0.5* fabs((rightbound - leftbound)) > min_error){
            
            
            
            
            cbound = 0.5*(leftbound + rightbound);
            
            
            //If the value at cbound is bigger than 0 your root should be in interval leftbound, cbound
            if (fofx(cbound) > 0) {
                
                rightbound = cbound;
                
            }
            // If the value at cbound is smaller than 0 your root should be in interval cbound, rightbound
            else if (fofx(cbound) < 0 ){
                leftbound = cbound;
            }
            
            else{
                printf("Your root is found:\n");
                printf("%f", cbound);
    
            }
            // This piece of code is to assure that if cbound doesnt change any more and it get stucks in the while loop:
            if (test == cbound) {
                break;
            }
            test = cbound;
            
            
        }
        printf("Your root is found at:\n");
        printf("%f\n", cbound);
        
        
        
        
    
        
    }
    
    else{
        printf("This polynomional doesn't contain any roots in the given interval");
    }
    
    return 0;
}

float recursive_bisection(float leftbound, float rightbound, float min_error);
float fofx(float x);

int     main()
{

    float a ;
    float b ;
    float minerror;
    float thefunc;
    
    printf("What is your left boundary?:");
    scanf("%f", &a);
    fpurge( stdin);
    
    printf("\nWhat is your right boundary?:");
    scanf("%f", &b);
    fpurge( stdin);
    
    printf("What is your minimum ?:");
    scanf("%f", &minerror);
    fpurge( stdin);
    
    thefunc = recursive_bisection(a, b, minerror);
    
    
    return 0;
}


