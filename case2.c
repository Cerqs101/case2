#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void exibeLog (FILE *f) {
    char usuario[15];
    char status[10];
    int brasil[2] = {0,0}, mexico[2] = {0,0}, chile[2] = {0,0};

    while(fscanf(f, "%s %s", usuario, status) > 0) {
        switch (usuario[1]) {
            case '5': {
                brasil[0] += 1;
                if (status[0] == 'a') brasil[1] += 1;
                break;
            }

            case '6': {
                chile[0] += 1;
                if (status[0] == 'a') chile[1] += 1;
                break;
            }

            case '2': {
                mexico[0] += 1;
                if (status[0] == 'a') mexico[1] += 1;
                break;
            }
        }
    }
    printf("Brasil - %d, %d\n", brasil[0], brasil[1]);
    printf("Chile - %d, %d\n", chile[0], chile[1]);
    printf("Mexico - %d, %d\n", mexico[0], mexico[1]);

    return;
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf ("insira o nome do arquivo como argumento\n");
        exit(1);
    }

    FILE *flog;
    if((flog = fopen(argv[1], "r")) == NULL) {
        printf("erro na abertura do arquivo");
        exit(1);
    }

    exibeLog(flog);

    fclose(flog);
    return 0;
}