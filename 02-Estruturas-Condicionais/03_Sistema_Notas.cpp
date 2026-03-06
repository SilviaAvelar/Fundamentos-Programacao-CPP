/*
   EXERCÍCIO: Sistema Escolar de Notas e Recuperação.
   OBJETIVO: Calcular a média e decidir o fluxo do aluno (Aprovado, Recuperação ou Reprovado).
   CONCEITOS: If/Else aninhados e tomada de decisão baseada em médias.
*/

#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1252);
    float n1, n2, media;

    std::cout << "--- SISTEMA DE GESTÃO DE NOTAS ---" << std::endl;
    std::cout << "Digite a primeira nota (0-20): ";
    std::cin >> n1;
    std::cout << "Digite a segunda nota (0-20): ";
    std::cin >> n2;

    media = (n1 + n2) / 2;

    if (media >= 10) {
        std::cout << "\nResultado: APROVADO DIRETO! Média: " << media << std::endl;
    } 
    else {
        float rec;
        std::cout << "\nResultado: EM RECUPERAÇÃO (Média atual: " << media << ")" << std::endl;
        std::cout << "Digite a nota da prova de recuperação: ";
        std::cin >> rec;

        // Nova média considerando a recuperação
        if ((media + rec) / 2 >= 10)
            std::cout << "Resultado: APROVADO APÓS RECUPERAÇÃO!" << std::endl;
        else
            std::cout << "Resultado: REPROVADO." << std::endl;
    }

    return 0;
}
