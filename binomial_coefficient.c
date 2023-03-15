#include <stdio.h>
int binomial_coefficient(int n, int k){
    int a = binomial_coefficient(n-1,k-1);
    int b = binomial_coefficient(n-1,k);
    return a+b;
}

int main(){
    int n;
    int k;
    printf("%d",binomial_coefficient(n,k));
}