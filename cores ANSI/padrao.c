#include <stdio.h>

int main() {
    // Texto vermelho
    printf("\033[31mEste texto é vermelho\033[0m\n");
    // Fundo azul
    printf("\033[44mEste fundo é azul\033[0m\n");
    // Texto verde com fundo magenta
    printf("\033[32;45mTexto verde com fundo magenta\033[0m\n");

    // Testando todas as cores de texto
    printf("\033[30mTexto preto\033[0m\n");
    printf("\033[31mTexto vermelho\033[0m\n");
    printf("\033[32mTexto verde\033[0m\n");
    printf("\033[33mTexto amarelo\033[0m\n");
    printf("\033[34mTexto azul\033[0m\n");
    printf("\033[35mTexto magenta\033[0m\n");
    printf("\033[36mTexto ciano\033[0m\n");
    printf("\033[37mTexto branco\033[0m\n");

    // Testando todas as cores de fundo
    printf("\033[40mFundo preto\033[0m\n");
    printf("\033[41mFundo vermelho\033[0m\n");
    printf("\033[42mFundo verde\033[0m\n");
    printf("\033[43mFundo amarelo\033[0m\n");
    printf("\033[44mFundo azul\033[0m\n");
    printf("\033[45mFundo magenta\033[0m\n");
    printf("\033[46mFundo ciano\033[0m\n");
    printf("\033[47mFundo branco\033[0m\n");

    return 0;
}
