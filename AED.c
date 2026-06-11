#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void cor(int codigo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), codigo);
}

int main() {
    char palavra[11] = "REPROVAREI";
    char tentativa[11];
    char matriz[6][11];

    int linha = 0;
    int venceu = 0;
    int i, j;

    
    cor(10); // verde

    printf("ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
    printf("o                                                             o\n");
    printf("o      JJJJJJJ   OOOOOOO    GGGGGGG   OOOOOOO                 o\n");
    printf("o         J     OO     OO  GG        OO     OO                o\n");
    printf("o         J     OO     OO  GG  GGGG  OO     OO                o\n");
    printf("o     J   J     OO     OO  GG     GG OO     OO                o\n");
    printf("o      JJJ       OOOOOOO    GGGGGGG   OOOOOOO                 o\n");
    printf("o                                                             o\n");
    printf("o                 D E   A T O A                               o\n");
    printf("o                                                             o\n");
    printf("ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
    printf("o                                                             o\n");
    printf("o                VOCE TEM 6 TENTATIVAS                        o\n");
    printf("o                                                             o\n");
    printf("ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");

    cor(7); // branco
    while (linha < 6 && venceu == 0) {
        printf("Tentativa %d: ", linha + 1);
        scanf("%s", tentativa);

        while (strlen(tentativa) != 10) {
            printf("Escreva uma palavra com 10 letras: ");
            scanf("%s", tentativa);
        }

        for (i = 0; i < 10; i++) {
            tentativa[i] = toupper(tentativa[i]);
            matriz[linha][i] = tentativa[i];
        }
        matriz[linha][10] = '\0';

        printf("\nResultado:\n");

        for (i = 0; i < 10; i++) {
            if (tentativa[i] == palavra[i]) {
                cor(10); // verde
                printf("[%c] ", tentativa[i]);
                cor(7);
            } else {
                int existe = 0;

                j = 0;
                while (j < 10 && existe == 0) {
                    if (tentativa[i] == palavra[j]) {
                        existe = 1;
                    }
                    j++;
                }

                if (existe == 1) {
                    cor(6); // laranja/amarelo
                    printf("[%c] ", tentativa[i]);
                    cor(7);
                } else {
                    cor(8); // cinza
                    printf("[%c] ", tentativa[i]);
                    cor(7);
                }
            }
        }

        printf("\n\n");

        if (strcmp(tentativa, palavra) == 0) {
            venceu = 1;
        }

        linha++;
    }

    if (venceu == 1) {
        cor(10);
        printf(" Acertou \n");
        cor(7);
    } else {
        cor(12);
        printf("Vc e burro! a palavra era: %s\n", palavra);
        cor(7);
    }

    return 0;
}