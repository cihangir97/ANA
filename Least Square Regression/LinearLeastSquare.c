//
//  LinearLeastSquare.c
//
//  This program uses the least square approximation for a set of datapoints given in C.
//  The line that it fittes is linear.
//
//  Created by Cihangir Ozbek on 27-02-17.
//  Copyright © 2017 Cihangir Ozbek. All rights reserved.
//  A part of the GaussJordan function is taken from http://www.codewithc.com/c-program-for-lagrange-interpolation/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>



int GaussJordan(float a11, float a12, float a21, float a22, float f1, float f2){
    
    
    int i, j, k, n = 2; //Counters
    float A[4][4], c, x[4]; //Matrices input Ax=x[i],
    // Declaring your two a0 a1 output struct
    
    
    A[1][1] = a11;
    A[1][2] = a12;
    A[1][3] = f1;
    A[2][1] = a21;
    A[2][2] = a22;
    A[2][3] = f2;
    
    
    // Finding the elements of the diagonal matrix:
    
    for (j=1; j<=n; j++) {
        
        for (i=1; i<=n; i++) {
            
            if (i!=j) {
                
                c = A[i][j] / A[j][j];
                
                for (k=1; k<=n+1; k++) {
                    A[i][k] = A[i][k] - c*A[j][k];
                    
                }
            }
        }
    }
    
    for(i=1; i<=n; i++)
    {
        x[i]=A[i][n+1]/A[i][i];
    }
    
    
    printf("y = %f + %f * x\n", x[1], x[2]);
    
    
    return 0;
}


int main() {
    
    int i, n; // Counters
    float data[20][20]; // Your datapoints and their corresponding values are stored here: xi = data[i][i] , fi = data[i][i+1]
    bool cond = false;
    char correct, enter = 'k';
    
    float a11 = 0, a12 = 0, a21 = 0, a22 = 0; // These are the entries for the matrix that we want to solve
    float f1 = 0, f2 = 0; // These are the entries for the f vector
    int GaussJordan(float a11, float a12, float a21, float a22, float f1, float f2); // Declaring our GaussJordan elimiation method thingy
    
    
    while (cond == false) {
        
        //Request how many datapoints the user has:
        printf("Enter the amount of datapoints that you have:");
        scanf("%d", &n);
        
        //Request the datapoints and corresponding values from the user:
        
        printf("\n Enter the datapoints with their corresponding value: \n");
        
        for (i=1; i<=n; i++) {
            
            // Ask for data point:
            printf("x%d : ", i);
            scanf("%f", &data[i][1]);
            // Ask for corresponding f
            printf("f%d : ", i);
            scanf("%f", &data[i][2]);
            
            
        }
        
        
        
        // Print the user input values:
        printf("\n Your input:\n");
        
        for(i=1; i<=n; i++){
            
            printf("x%d = %f f%d = %f\n", i, data[i][1], i, data[i][2]);
        }
        
        
        
        // Ask user if there input is oke:
        printf("\n Are these input values correct? [y/n]:");
        scanf(" %c", &correct);
        fpurge( stdin);
        
        // If it is we get out of the while loop:
        if (correct == 'y') {
            printf("Lets continiue....\n");
            cond = true;
        }
        
        // If it is not, we ask if we want to re enter the data:
        if (correct == 'n') {
            printf("Do you want to start all over again ? [y/n]:");
            scanf(" %c", &correct);
            fpurge( stdin);
            
            // Lets start over:
            if (enter == 'y') {
                printf("\nLets start over....\n ");
            }
            // lets quit :)
            else{
                printf("Thanks for using my program!!!!\n");
                return 0;
            }
            
        }
        
        
        
        // Now that we have the datapoints and put them in the data array we can start using the least square method for linear fit.
        // the first entery a11 is the sum_i=1^n  (1)
        for (i=1; i < n; i++) {
            a11 = 1+i;
        }
        
        
        
        // the second entry a12 is the sum of all x values
        
        for (i=1; i<=n; i++) {
            a12 = a12 + data[i][1];
        }
        
        
        
        // the third entry a21 is the same as a12
        
        for (i=1; i<=n; i++) {
            a21 = a21 + data[i][1];
        }
        
        
        
        // The fourth entry a22 is the sum of all x^2
        
        for (i=1; i<=n; i++) {
            a22 = a22 + pow(data[i][1],2);
        }
        
        // Now we start with the f matrix:
        
        // f1 = sum of all f values
        for (i=1; i<=n; i++) {
            f1 = f1 + data[i][2];
        }
        
        // f2 = sum of all f values times all their corresponding x values
        for (i=1; i<=n; i++) {
            f2 = f2 + data[i][2] * data[i][1];
        }
        
        // Now that we have all the matrices we can compute the unknown coefficients For this we use the function GaussJordan
        
        GaussJordan(a11, a12, a21, a22, f1, f2);
    }
    
    
    return 0;
}
