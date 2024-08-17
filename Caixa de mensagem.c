#include <windows.h>

int main() {
    // Texto da mensagem a ser exibida
    LPCSTR messageText = "Olá, mundo!";
    // Título da caixa de mensagem
    LPCSTR messageTitle = "Exemplo de caixa de mensagem";
    
    // Cria e exibe a caixa de mensagem
    int response = MessageBox(
        NULL,               // Handle da janela proprietária. NULL se não houver janela proprietária.
        messageText,        // Texto da mensagem.
        messageTitle,       // Título da caixa de mensagem.
        MB_OK | MB_ICONINFORMATION  // Botões e ícone da caixa de mensagem.
    );

    // Verifica a resposta do usuário
    if (response == IDOK) {
        MessageBox(NULL, "Você clicou em OK!", "Resposta", MB_OK | MB_ICONINFORMATION);
    }

    return 0;
}
