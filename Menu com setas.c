#include <windows.h>
#include <stdio.h>

// Função para configurar o modo do console
void SetConsoleModeCustom(HANDLE consoleHandle, DWORD mode) {
    if (!SetConsoleMode(consoleHandle, mode)) {
        fprintf(stderr, "Erro ao definir o modo do console\n");
        exit(1);
    }
}

// Função para ler a entrada do console
void ReadConsoleInputCustom(HANDLE consoleHandle, INPUT_RECORD *inputRecord) {
    DWORD eventsRead;
    if (!ReadConsoleInput(consoleHandle, inputRecord, 1, &eventsRead)) {
        fprintf(stderr, "Erro ao ler entrada do console\n");
        exit(1);
    }
}

// Função para exibir o menu
void DisplayMenu(int selectedOption) {
    system("cls"); // Limpa a tela do console
    printf("Menu:\n");
    printf("%s 1. Opcao 1\n", selectedOption == 1 ? ">" : " ");
    printf("%s 2. Opcao 2\n", selectedOption == 2 ? ">" : " ");
    printf("%s 3. Opcao 3\n", selectedOption == 3 ? ">" : " ");
}

int main() {
    HANDLE consoleInputHandle = GetStdHandle(STD_INPUT_HANDLE);
    if (consoleInputHandle == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Erro ao obter o handle para a entrada padrão\n");
        return 1;
    }

    DWORD originalConsoleMode;
    if (!GetConsoleMode(consoleInputHandle, &originalConsoleMode)) {
        fprintf(stderr, "Erro ao obter o modo do console\n");
        return 1;
    }

    DWORD newConsoleMode = originalConsoleMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
    SetConsoleModeCustom(consoleInputHandle, newConsoleMode);

    int selectedOption = 1;
    DisplayMenu(selectedOption);

    INPUT_RECORD inputRecord;
    while (1) {
        ReadConsoleInputCustom(consoleInputHandle, &inputRecord);

        if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
            switch (inputRecord.Event.KeyEvent.wVirtualKeyCode) {
                case VK_DOWN:
                    if (selectedOption < 3) {
                        selectedOption++;
                        DisplayMenu(selectedOption);
                    }
                    break;
                case VK_UP:
                    if (selectedOption > 1) {
                        selectedOption--;
                        DisplayMenu(selectedOption);
                    }
                    break;
                case VK_RETURN:
                    printf("Opcao %d selecionada!\n", selectedOption);
                    SetConsoleModeCustom(consoleInputHandle, originalConsoleMode);
                    return 0;
            }
        }
    }

    // Restaura o modo original do console antes de sair (caso saia do loop de outra forma).
    SetConsoleModeCustom(consoleInputHandle, originalConsoleMode);

    return 0;
}
