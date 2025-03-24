#include <stdio.h>
#include <string.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[10][10] = {0};
    int tamanho_navio = 3;

    // Navio vertical
    for (int i = 0; i < tamanho_navio; i++)
        tabuleiro[0][i] = 3;

    // Navio horizontal
    for (int i = 0; i < tamanho_navio; i++)
        tabuleiro[4 + i][8] = 3;

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    for (int i = 0; i < tamanho_navio; i++) {
        // De cima para canto inferior direito
        tabuleiro[3 + i][3 + i] = 3;
        // De baixo para canto superior direito
        tabuleiro[0 + i][9 - i] = 3;
    }

    // Percorre as linhas
    for (int y = 0; y < 10; y++) {
        // Percorre as colunas
        for (int x = 0; x < 10; x++) {
            printf("%d ", tabuleiro[x][y]);
        }

        printf("\n");
    }
    printf("\n");

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    int cone[5][3] = {0};
    // Posição horizontal inicial do poder
    int x_inicial = 2,
        y_inicial = 0;

    printf("CONE\n");
    // Percorre todas as linhas
    for (int y = 0; y < 3; y++) {
        // Define o tamanho do poder, que nesse caso é igual ao índice da linha atual,
        // assim permitindo que ele se expanda baseado na altura e formando uma pirâmide.
        int tamanho = y + 1;
        for (int i = 0; i < tamanho; i++) {
            cone[x_inicial + i][y_inicial + y] = 1;
            cone[x_inicial - i][y_inicial + y] = 1;
        }

        for (int x = 0; x < 5; x++) {
            printf("%d ", cone[x][y]);
        }

        printf("\n");
    }

    printf("CONE NO TABULEIRO\n");
    int ctabuleiro[10][10] = {0};
    // Copia tabuleiro para que possa ser reutilizado sem que os poderes o afete.
    memcpy(ctabuleiro, tabuleiro, sizeof(tabuleiro));

    int x_atq = 1,
        y_atq = 6;

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 5; x++) {
            int valor = cone[x][y];

            // Essa condição previne que os arredores sejam deletados pelo vazio do cone.
            if (valor != 0) {
                ctabuleiro[x_atq + x][y_atq + y] = valor;
            }
        }
    }

    // Percorre as linhas
    for (int y = 0; y < 10; y++) {
        // Percorre as colunas
        for (int x = 0; x < 10; x++) {
            printf("%d ", ctabuleiro[x][y]);
        }

        printf("\n");
    }
    printf("\n");
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    int octaedro[5][3] = {0};
    int tamanho = 3;
    x_inicial = 2;
    y_inicial = 1;
    
    printf("OCTAEDRO\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == 0) {
                octaedro[2][j] = 1;
            } else {
                octaedro[1 + j][1] = 1;
            }
        }
    }

    // Percorre as linhas
    for (int y = 0; y < 3; y++) {
        // Percorre as colunas
        for (int x = 0; x < 5; x++) {
            printf("%d ", octaedro[x][y]);
        }

        printf("\n");
    }

    memcpy(ctabuleiro, tabuleiro, sizeof(tabuleiro));
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 5; x++) {
            int valor = octaedro[x][y];
            if (valor != 0) {
                ctabuleiro[x_atq + x][y_atq + y] = valor;
            }
        }
    }

    printf("OCTAEDRO NO TABULEIRO\n");
    // Percorre as linhas
    for (int y = 0; y < 10; y++) {
        // Percorre as colunas
        for (int x = 0; x < 10; x++) {
            printf("%d ", ctabuleiro[x][y]);
        }

        printf("\n");
    }
    printf("\n");

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    int cruz[5][3] = {0};
    
    printf("CRUZ\n");
    for (int y = 0; y < 3; y++) {
        cruz[2][y] = 1;
    }
    for (int x = 0; x < 5; x++) {
        cruz[x][1] = 1;
    }

    // Percorre as linhas
    for (int y = 0; y < 3; y++) {
        // Percorre as colunas
        for (int x = 0; x < 5; x++) {
            printf("%d ", cruz[x][y]);
        }

        printf("\n");
    }

    memset(ctabuleiro, 0, sizeof(ctabuleiro));
    memcpy(ctabuleiro, tabuleiro, sizeof(tabuleiro));
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 5; x++) {
            int valor = cruz[x][y];
            if (valor != 0) {
                ctabuleiro[x_atq + x][y_atq + y] = valor;
            }
        }
    }

    printf("CRUZ NO TABULEIRO\n");
    // Percorre as linhas
    for (int y = 0; y < 10; y++) {
        // Percorre as colunas
        for (int x = 0; x < 10; x++) {
            printf("%d ", ctabuleiro[x][y]);
        }

        printf("\n");
    }
    printf("\n");

    return 0;
}
