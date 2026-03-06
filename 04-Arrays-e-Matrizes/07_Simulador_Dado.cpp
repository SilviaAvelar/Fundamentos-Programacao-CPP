/*
   EXERCÍCIO: Simulador de Lançamento de Dados com Estatística.
   OBJETIVO: Simular N lançamentos de um dado e calcular a frequência e a percentagem de saída de cada uma das 6 faces.
   CONCEITOS: Arrays (vetores), Geração de números aleatórios (rand), Acumuladores e Formatação de saída (setprecision).
*/

#include <iostream>
#include <iomanip>   // Para formatar casas decimais
#include <ctime>     // Para a função time()
#include <cstdlib>   // Para rand() e srand()
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1252);
    const int FACES = 6;
    int contadores[FACES] = {}; // Array que guarda a contagem de cada face
    int n;

    srand((unsigned int)time(0)); // Define a semente baseada na hora atual

    std::cout << "--- SIMULADOR DE DADOS ---" << std::endl;
    std::cout << "Quantos lançamentos deseja realizar? ";
    std::cin >> n;

    // Realiza os lançamentos e guarda no array
    for (int i = 0; i < n; i++) {
        int face = (rand() % 6); // Gera valor de 0 a 5
        contadores[face]++;      // Incrementa a posição correta do array
    }

    // Exibe os resultados
    std::cout << "\nRESULTADOS ESTATÍSTICOS:" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < FACES; i++) {
        float percentagem = (float)contadores[i] / n * 100;
        std::cout << "Face " << i + 1 << ": " << contadores[i] 
                  << " saídas (" << percentagem << "%)" << std::endl;
    }

    return 0;
}
