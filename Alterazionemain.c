#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include "AlterazioneWindowing.h"
#define file "micro100-10000.txt"

int main(){
    FILE *f = fopen("input.txt","r");
    int e,ts;
    FILE *ff = fopen(file,"w");
    fprintf(ff,"SIZE_WINDOW: 100\n");
    fprintf(ff,"SIZE_BUFFER: 10000\n");
    fclose(ff);
    // per memorizzare il tempo di esecuzione del codice
    double time_spent = 0.0;

    clock_t begin = clock();

    // fai delle cose qui
   /* while (!(feof(f))){
        fscanf(f,"%d %d",&e,&ts);
        windowing(e,ts);
    }*/

    for (int i = 1; i <= 5000; i++) {
        windowing(i,i);
    }


    clock_t end = clock();

    // calcola il tempo trascorso trovando la differenza (end - begin) e
    // dividendo la differenza per CLOCKS_PER_SEC per convertire in secondi
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    ff = fopen(file,"a");
    fprintf(ff,"The elapsed time of the window function is %f seconds", time_spent);
    fclose(ff);


    return 0;
}
