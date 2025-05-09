#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define HABILIDADE_SIZE 5 // Tamanho das matrizes de habilidade

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro do Batalha Naval com Habilidades:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" 0 ");  // Água
            else if (tabuleiro[i][j] == 3)
                printf(" N ");  // Navio
            else if (tabuleiro[i][j] == 5)
                printf(" H ");  // Área afetada pela habilidade
        }
        printf("\n");
    }
    printf("\n");
}

// Função para aplicar a habilidade de Cone no tabuleiro
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    // Definindo a área do Cone com base na origem
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j <= i; j++) {
            if (origemLinha + i < TAMANHO_TABULEIRO && origemColuna - j >= 0 && origemColuna + j < TAMANHO_TABULEIRO) {
                tabuleiro[origemLinha + i][origemColuna - j] = 5;
                tabuleiro[origemLinha + i][origemColuna + j] = 5;
            }
        }
    }
}

// Função para aplicar a habilidade de Cruz no tabuleiro
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    // Cruz com origem no centro
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        if (origemLinha + i < TAMANHO_TABULEIRO) {
            tabuleiro[origemLinha + i][origemColuna] = 5;  // Vertical
        }
        if (origemColuna + i < TAMANHO_TABULEIRO) {
            tabuleiro[origemLinha][origemColuna + i] = 5;  // Horizontal
        }
    }
}

// Função para aplicar a habilidade de Octaedro no tabuleiro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    // Octaedro com origem no centro
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j <= i; j++) {
            if (origemLinha + i < TAMANHO_TABULEIRO && origemColuna + j < TAMANHO_TABULEIRO) {
                tabuleiro[origemLinha + i][origemColuna + j] = 5;
                tabuleiro[origemLinha + i][origemColuna - j] = 5;
                tabuleiro[origemLinha - i][origemColuna + j] = 5;
                tabuleiro[origemLinha - i][origemColuna - j] = 5;
            }
        }
    }
}

int main() {
    // Inicializa o tabuleiro com 0 (águas)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definir as coordenadas dos navios
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 3;
    int linhaNavioVertical = 5, colunaNavioVertical = 6;

    // Posiciona os navios
    if (linhaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
        }
    }
    if (colunaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
        }
    }

    // Definir as coordenadas das habilidades
    int origemHabilidadeConeLinha = 0, origemHabilidadeConeColuna = 4;
    int origemHabilidadeCruzLinha = 5, origemHabilidadeCruzColuna = 5;
    int origemHabilidadeOctaedroLinha = 4, origemHabilidadeOctaedroColuna = 4;

    // Aplicar as habilidades (aplicar após os navios para evitar sobrescrita)
    aplicarHabilidadeCone(tabuleiro, origemHabilidadeConeLinha, origemHabilidadeConeColuna);
    aplicarHabilidadeCruz(tabuleiro, origemHabilidadeCruzLinha, origemHabilidadeCruzColuna);
    aplicarHabilidadeOctaedro(tabuleiro, origemHabilidadeOctaedroLinha, origemHabilidadeOctaedroColuna);

    // Exibir o tabuleiro com as áreas de efeito das habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}
