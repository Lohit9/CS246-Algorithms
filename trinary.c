#include "trinary.h"

// Your Name
// CS136, Winter 2015
// Assignment 7, Problem 7

//void trinary_search(int *a, int n, int v) {}

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void suc() {
    printf("Search successful\n");
}

void fai() {
    printf("Search not succesful\n");
}

void com(int n) {
    printf("A total of %d comparisons were made\n", n);
}

void equ(int a, int b) {
    printf("Checking if %d is equal to %d\n", a, b);
}

void les(int a, int b) {
    printf("Checking if %d is less than %d\n", a, b);
}

void trinary_search(int *a, int n, int v) {
    /*if the size of the search region is <= 4
      perform a linear search for v
else
     select indexes ind1 and ind2
     if a[ind1] is equal to v
          stop, we have found v
     else if v < a[ind1]
          repeat with Region 1 being the new search region
     else if a[ind2] is equal to v
          stop, we have found v
     else if v < a[ind2]
           repeat with Region 2 being the new search region
     else
           repeat with Region 3 being the new search region
           */
    int lo = 0, hi = n-1;
    int cnt = 0;
    int ans = -1;
    while(hi-lo+1 > 4) {
        int len = hi-lo+1 - 2;
        int ind1 = lo + (len + 2)/3;
        len = hi-ind1 - 1;
        int ind2 = ind1+1 + (len+1)/2;
        equ(v, a[ind1]); cnt++;
        if(a[ind1] == v) {
            ans = ind1;
            goto end;
        }
        les(v, a[ind1]); cnt++;
        if(v < a[ind1]) {
            hi = ind1-1;
            continue;
        }
        equ(v, a[ind2]); cnt++;
        if(a[ind2] == v) {
            ans = ind2;
            goto end;
        }
        les(v, a[ind2]); cnt++;
        if(v < a[ind2]) {
            lo = ind1+1;
            hi = ind2-1;
            continue;
        }
        lo = ind2 + 1;
    }
    for(int i = lo; i <= hi; i++) {
        equ(v, a[i]); cnt++;
        if(a[i] == v) {
            ans = i;
            break;
        }
    }
    end:
    if(ans == -1) fai();
    else {
        suc();
        printf("%d is located at index %d\n", v, ans);
    }
    com(cnt);
}













