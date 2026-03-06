/*
   EXERCÍCIO: Manipulação de Arrays Bidimensionais (Matrizes).
   OBJETIVO: Demonstrar como declarar, preencher e imprimir uma tabela (matriz).
   CONCEITOS: Matrizes, Loops aninhados (um for dentro de outro) e acesso por índices [i][j].
*/

#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1252);
    
    // Matriz de 3 linhas e 3 colunas inicializada com zeros
    int matriz[3][3] = {};

    std::cout << "--- PREENCHIMENTO DE MATRIZ (3x3) ---" << std::endl;

    // Loop externo percorre as LINHAS (i)
    for (int i = 0; i < 3; i++) {
        // Loop interno percorre as COLUNAS (j)
        for (int j = 0; j < 3; j++) {
            std::cout << "Digite valor para [" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }

    // Impressão em formato de tabela
    std::cout << "\nTABELA RESULTANTE:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "\t";
        for (int j = 0; j < 3; j++) {
            std::cout << matriz[i][j] << "   ";
        }
        std::cout << std::endl; // Pula linha ao fim de cada linha da matriz
    }

    return 0;
}
