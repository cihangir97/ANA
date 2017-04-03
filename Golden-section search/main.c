//
//  main.c
//  A program that uses Golden-section search method as taught in the AE2220-I Applied Numerical Analysis course.
//
//  Created by Cihangir Ozbek on 24-02-17.
//  Copyright © 2017 Cihangir Ozbek. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Your polynomional:
double fofx(double x){
    double y;
    
    y = pow(x,5) + pow(x,2) + 1;
    
    return y;
}


// Golden-section search:

double golden_section_search(double a, double b, double N_max){
    
    double phi = ( ( 1 + sqrt(5) ) / 2); // This is your golden ratio
    double phi_inv = 1 / phi ; // This is the inverse of phi
    double X_L; // Point that is closes to b
    double X_R; // Point that is closes to a
    
    double C; // Your minimum found by (a+b )/ 2
    
    int i; // Counter
    
    
    // Your recursive method:
    for (i=0; i == N_max; i++) {
        
        X_L = a + (1 - phi_inv) * (b - a); // definition of X_L
        X_R = a + phi_inv * (b-a) * phi_inv; // definition of X_R
        
        // checking which x has a greater y and accordingly change your points and creating a new interval
        if (fofx(X_L) < fofx(X_R) ) {
            b = X_R;
        }
        
        if (fofx(X_L) > fofx(X_R) ) {
            a = X_L;
        }
        
        
    }
    
    C = (a+b)/2 ;
    
    return C;
}



int main() {
    
    double esad;
    float left ;
    float right ;
    float steps;
    
    
    
    printf("What is your left boundary?:");
    scanf("%f", &left);
    fpurge( stdin);
    
    printf("\nWhat is your right boundary?:");
    scanf("%f", &right);
    fpurge( stdin);
    
    printf("What is your amount of steps ?:");
    scanf("%f", &steps);
    fpurge( stdin);
    
    esad = golden_section_search(left, right, steps);
    
    printf(" The local minimum is at: %f \n", esad);
    printf(" The corresponding value with this minimum is: %f\n", fofx(esad));
    
    return 0;
}
