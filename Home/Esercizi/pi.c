/*
    Calcolare il Pi Greco:
    Chiedere all'utente con che formula calcolare il pi greco:
    1. Formula di Leibniz
        pi/4 = 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
        Per calcolare il pi greco basterà moltiplicare quindi tutto per 4
        pi = 4/1 - 4/3 + 4/5 - 4/7 + 4/9 - ...
        Da notare come il denominatore aumenta sempre di due e che si alternano somma e sottrazione
    2. Formula di Nilakantha
        pi - 3 = 1/(1*2*3) - 1/(2*3*5) + 1/(3*4*7) - 1/(4*5*9)
        Da cui si ricava
        pi = 3 + 1/(1*2*3) - 1/(2*3*5) + 1/(3*4*7) - 1/(4*5*9)
        Da notare come al denominatore, il primo numero sia uguale a quello centrale della frazione precedente,
        seguito da n+1 e da n+i. Si nota inoltre l'alternarsi di somma e sottrazione
    Chiedere all'utente quante volte eseguire il ciclo

    Infine, dopo aver chiesto all'utente il raggio di un cerchio, calcolane l'area e ed il perimetro.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    return 0;
}