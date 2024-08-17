#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define TAB 9
#define SPACE 32
#define DELETE 83
// ; = 59
// r = 114
// R = 82

int main() {
    int keyPressed;

    printf("Pressione as teclas e o número correspondente será exibido.\n");
    printf("Pressione '0' para sair do programa.\n");

    while (1) {
        if (_kbhit()) {
            keyPressed = _getch();
            printf("Tecla pressionada: %d\n", keyPressed);
            if (keyPressed == '0') {
                printf("Saindo do programa...\n");
                break;
            }
        }
        Sleep(100); // Pequeno delay para evitar uso excessivo da CPU
    }

    return 0;
}
