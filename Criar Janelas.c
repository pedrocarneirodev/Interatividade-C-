#include <windows.h>
#include <stdio.h>

int main() {
    int width, height;

    // Solicita ao usuário o tamanho da janela
    printf("Digite a largura da janela: ");
    scanf("%d", &width);
    printf("Digite a altura da janela: ");
    scanf("%d", &height);

    // Define o tamanho da janela
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, width - 1, height - 1};
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);

    // Cria um novo processo para o PowerShell
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    si.cb = sizeof(si);

    // Ajusta o comando para abrir o PowerShell
    char command[100];
    sprintf(command, "powershell -noexit -command \"Write-Host 'Hello, world!'\"");
    
    // Cria o processo
    CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);

    // Espera o usuário pressionar Enter antes de encerrar
    printf("Pressione Enter para sair...");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Espera o Enter

    return 0;
}
