/*
   EXERCÍCIO: Validação de Ano Bissexto.
   OBJETIVO: Implementar a regra: um ano é bissexto se for divisível por 400 OU (divisível por 4 E não por 100).
   CONCEITOS: Operadores lógicos (&&, ||), If/Else e validação de intervalo.
*/

#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1252);
    int ano;

    std::cout << "--- VALIDADOR DE ANO BISSEXTO ---" << std::endl;
    std::cout << "Digite um ano (entre 1000 e 2100): ";
    
    if (std::cin >> ano && ano >= 1000 && ano <= 2100) {
        if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
            std::cout << "\nO ano " << ano << " é BISSEXTO." << std::endl;
        else
            std::cout << "\nO ano " << ano << " é um ano COMUM." << std::endl;
    } else {
        std::cout << "\n[ERRO] Entrada inválida! Digite um ano no intervalo correto." << std::endl;
    }

    return 0;
}
