#include <stdio.h>

typedef struct
{
    int num;
    int den;
} Frazione;

int MCD(int a, int b)
{
    while (a != b)
        if (a > b)
            a = a - b;
        else
            b = b - a;
    return a;
}

int valAssoluto(int n)
{
    if (n > 0)
        return n;
    else
        return -n;
}

void fraz(int n, int d, Frazione *pf) //con il *pf non serve restituire qualcosa
{
    int m = MCD(valAssoluto(n), valAssoluto(d));
    (*pf).num = n / m;
    (*pf).den = d / m;
    //equivalgono a tra loro
    //pf->num = n/m;
    //pf->den = d/m;
}

void stampa(Frazione *pf)
{
    printf("%d/%d\n", pf->num, pf->den);
}

void leggiFraz(Frazione *pf)
{
    /*printf("Inserisci il Numeratore: ");
    scanf("%d", &pf->num);
    printf("\nInserisci il Numeratore: ");
    scanf("%d", &pf->den);*/
    //metodo alternativo
    scanf("%d%d", &pf->num, &pf->den);
}

int main()
{
    Frazione g;
    leggiFraz(&g);
    fraz(g.num, g.den, &g); //non serve fare 'g=...' perchè usiamo i puntatori
    stampa(&g);             //usando la & passiamo l'indirizzo di g

    return 0;
}
