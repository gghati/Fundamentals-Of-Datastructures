/*
==========================================================================

Name :  Set Operators
Author : Gaurav Ghati
Class : SE 10
Batch : F 10
Description : Assignment 1 in C, Ansi-style

==========================================================================
*/

#include<stdio.h>
#include<stdlib.h>

void input(int a[], int x){
  int z, e=0, d=0;
  printf("Enter First element\n");
  scanf("%d", &z);

  if(z>0 && z<100){
    a[0] = z;
  }else{
    printf("Sorry Enter Again\n", );
  }


}
