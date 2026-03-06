/*
   EXERCÍCIO: Gerador de Tabuada Automática.
   OBJETIVO: Receber um número e gerar instantaneamente a tabuada de 1 a 10.
   CONCEITOS: Loop 'for' (iteração definida), operadores aritméticos e saída formatada.
*/

#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1252);
    int num;

    std::cout << "--- GERADOR DE TABUADA ---" << std::endl;
    std::cout << "Indique o valor para a tabuada (inteiro): ";
    std::cin >> num;

    std::cout << "\nTabuada do " << num << ":" << std::endl;
    
    // O loop 'for' executa o bloco 10 vezes automaticamente
    for (int i = 1; i <= 10; i++) {
        std::cout << "\t" << num << " x " << i << " = " << num * i << std::endl;
    }

    std::cout << "\n--------------------------" << std::endl;
    return 0;
}
