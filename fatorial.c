#include <stdio.h>

int main() {
    
    int numero,fatorial;

    printf("digite o numero a ser fatorado : ");

    scanf("%d",&numero);
    

    for(fatorial=1;numero>1;numero=numero-1){
    fatorial=fatorial*numero;}
    

    
    printf("%d",fatorial);
    
    return 0;
}