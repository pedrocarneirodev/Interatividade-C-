#include <stdio.h>

int main() {
    for (int i = 0; i < 256; i++) {
        printf("\033[38;5;%dm %.3d \033[0m", i, i);
    }
    printf("\n\n");
    for (int i = 0; i < 256; i++) {
        printf("\033[48;5;%dm %.3d \033[0m", i, i);
    }
    //printf("\033[38;5;34;48;5;232mEste texto tem a cor 34 com fundo 232\033[0m\n");
    return 0;
}
