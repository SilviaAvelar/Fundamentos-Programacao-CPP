/*
   EXERCÍCIO: Validação Robusta de Entrada de Dados.
   OBJETIVO: Garantir que o programa aceite apenas números entre 0 e 20, limpando o erro caso o utilizador digite letras ou símbolos.
   CONCEITOS: Loop infinito 'while(true)', cin.clear() (limpeza de sinal de erro) e cin.ignore() (limpeza de memória temporária/buffer).
*/

#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1252);
    float nota;

    // Loop que só termina quando a entrada for perfeita
    while (true) {
        std::cout << "Digite a nota do aluno (0 a 20): ";

        // Tenta ler o valor e verifica se está no intervalo
        if (std::cin >> nota && nota >= 0 && nota <= 20) {
            break; // Sucesso! Sai do loop.
        }

        // Se chegou aqui, a entrada foi inválida
        std::cout << "\n[ERRO] Entrada inválida! Por favor, digite um número entre 0 e 20.\n";

        std::cin.clear();           // Limpa o estado de erro do sistema
        std::cin.ignore(100, '\n'); // Descarta caracteres "sujos" que ficaram no buffer
    }

    std::cout << "\nNota " << nota << " validada com sucesso no sistema." << std::endl;
    return 0;
}
