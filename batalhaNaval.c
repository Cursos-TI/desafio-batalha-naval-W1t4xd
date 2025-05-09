#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro do Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para verificar se uma posição está ocupada por outro navio
int verificarSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 0) {  // Horizontal
            if (tabuleiro[linha][coluna + i] != 0) {
                return 1;  // Posição já ocupada
            }
        } else if (orientacao == 1) {  // Vertical
            if (tabuleiro[linha + i][coluna] != 0) {
                return 1;  // Posição já ocupada
            }
        } else if (orientacao == 2) {  // Diagonal Principal
            if (tabuleiro[linha + i][coluna + i] != 0) {
                return 1;  // Posição já ocupada
            }
        } else if (orientacao == 3) {  // Diagonal Inversa
            if (tabuleiro[linha + i][coluna - i] != 0) {
                return 1;  // Posição já ocupada
            }
        }
    }
    return 0;  // Não há sobreposição
}

// Função para posicionar o navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Navio não cabe horizontalmente na posição dada
    }
    if (verificarSobreposicao(tabuleiro, linha, coluna, 0, TAMANHO_NAVIO)) {
        return 0; // Posição já ocupada
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
    return 1; // Navio posicionado com sucesso
}

// Função para posicionar o navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Navio não cabe verticalmente na posição dada
    }
    if (verificarSobreposicao(tabuleiro, linha, coluna, 1, TAMANHO_NAVIO)) {
        return 0; // Posição já ocupada
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
    return 1; // Navio posicionado com sucesso
}

// Função para posicionar o navio diagonalmente (diagonal principal)
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Navio não cabe na diagonal principal na posição dada
    }
    if (verificarSobreposicao(tabuleiro, linha, coluna, 2, TAMANHO_NAVIO)) {
        return 0; // Posição já ocupada
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
    return 1; // Navio posicionado com sucesso
}

// Função para posicionar o navio diagonalmente (diagonal inversa)
int posicionarNavioDiagonalInversa(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0) {
        return 0; // Navio não cabe na diagonal inversa na posição dada
    }
    if (verificarSobreposicao(tabuleiro, linha, coluna, 3, TAMANHO_NAVIO)) {
        return 0; // Posição já ocupada
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
    }
    return 1; // Navio posicionado com sucesso
}

int main() {
    // Inicializa o tabuleiro com 0 (águas)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas para os navios
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 3;
    int linhaNavioVertical = 5, colunaNavioVertical = 6;
    int linhaNavioDiagonalPrincipal = 0, colunaNavioDiagonalPrincipal = 0;
    int linhaNavioDiagonalInversa = 7, colunaNavioDiagonalInversa = 9;

    // Posiciona os navios
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Erro ao posicionar o navio horizontal!\n");
    }
    if (!posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Erro ao posicionar o navio vertical!\n");
    }
    if (!posicionarNavioDiagonalPrincipal(tabuleiro, linhaNavioDiagonalPrincipal, colunaNavioDiagonalPrincipal)) {
        printf("Erro ao posicionar o navio diagonal principal!\n");
    }
    if (!posicionarNavioDiagonalInversa(tabuleiro, linhaNavioDiagonalInversa, colunaNavioDiagonalInversa)) {
        printf("Erro ao posicionar o navio diagonal inversa!\n");
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
