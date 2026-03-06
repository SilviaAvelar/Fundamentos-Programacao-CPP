/*
   EXERCÍCIO: Modularização e Reutilização de Código.
   OBJETIVO: Criar uma função genérica para ler e validar notas, evitando a repetição de blocos 'while' no main.
   CONCEITOS: Valor de Retorno (return), Parâmetros de entrada e abstração de lógica.
*/

#include <iostream>
#include <iomanip>
#include <Windows.h>

// Protótipo: a função recebe um texto e devolve um número real (float)
float lerNotaValidada(std::string mensagem);

int main() {
    SetConsoleOutputCP(1252);
    
    // Reutilizamos a mesma função para obter notas diferentes
    float n1 = lerNotaValidada("Digite a Nota 1 (0-20): ");
    float n2 = lerNotaValidada("Digite a Nota 2 (0-20): ");
    float n3 = lerNotaValidada("Digite a Nota 3 (0-20): ");

    float media = (n1 + n2 + n3) / 3;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- RELATÓRIO FINAL ---" << std::endl;
    std::cout << "Média calculada de forma modular: " << media << std::endl;

    return 0;
}

// Implementação da função reutilizável
float lerNotaValidada(std::string mensagem) {
    float nota;
    while (true) {
        std::cout << mensagem;
        if (std::cin >> nota && nota >= 0 && nota <= 20)
            return nota; // Devolve o valor e encerra a função

        std::cout << "[ERRO] Nota inválida! Tente novamente.\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
}
