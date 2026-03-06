/*
   PROJETO: Sistema de Apuração Eleitoral.
   OBJETIVO: Criar um simulador de votação que processe códigos de candidatos, contabilize votos (válidos, brancos e nulos) usando arrays e determine o vencedor, incluindo lógica para verificar empates.
   CONCEITOS: Arrays para contagem de frequência, Operador Ternário, Loops Aninhados, Lógica de Máximos e Sistema de Menus.
*/

#include <iostream>
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(1252);

    const int MAX = 6;      // 4 candidatos + 1 branco + 1 nulo
    int cand[MAX] = {};     // Inicializa todos os contadores com zero
    int voto;

    // --- CICLO PRINCIPAL DE VOTAÇÃO ---
    do {
        // Ciclo de validação de entrada e exibição do menu
        do {
            system("cls");
            std::cout << "\n\t=================================================";
            std::cout << "\n\t           ELEIÇÕES PRESIDENCIAIS 2024           ";
            std::cout << "\n\t=================================================";
            std::cout << "\n\t 1, 2, 3, 4   - Código dos candidatos";
            std::cout << "\n\t 5            - Voto em branco";
            std::cout << "\n\t Outro número - Voto nulo";
            std::cout << "\n\t 0            - Encerrar votação e apurar";
            std::cout << "\n\t-------------------------------------------------";
            std::cout << "\n\n\tDigite o seu voto:  ";
            
            if (std::cin >> voto) break;

            std::cin.clear();
            std::cin.ignore(100, '\n');
        } while (true);

        // Processamento do Voto usando Operador Ternário
        if (voto != 0) {
            // Se entre 1 e 5, incrementa cand[voto-1], senão incrementa o nulo (posicao MAX-1)
            (voto > 0 && voto < MAX) ? cand[voto - 1]++ : cand[MAX - 1]++;
        }

    } while (voto != 0);

    // --- IMPRESSÃO DOS RESULTADOS ESTATÍSTICOS ---
    system("cls");
    std::cout << "\n\t=========== RESULTADOS DA APURAÇÃO ===========";
    
    for (int i = 0; i < MAX - 2; i++) {
        std::cout << "\n\tCandidato " << i + 1 << ": \t" << cand[i] << " votos";
    }
    std::cout << "\n\t----------------------------------------------";
    std::cout << "\n\tVotos Brancos: \t" << cand[MAX - 2];
    std::cout << "\n\tVotos Nulos:   \t" << cand[MAX - 1];
    std::cout << "\n\t==============================================";

    // --- LÓGICA DO VENCEDOR E EMPATES ---
    int maiorVotos = 0;
    int vencedor;

    // 1. Encontrar a maior quantidade de votos entre os candidatos
    for (int i = 0; i < MAX - 2; i++) {
        if (cand[i] > maiorVotos) {
            maiorVotos = cand[i];
            vencedor = i + 1;
        }
    }

    // 2. Contar quantos candidatos têm essa quantidade máxima
    int empates = 0;
    for (int i = 0; i < MAX - 2; i++) {
        if (cand[i] == maiorVotos) {
            empates++;
        }
    }

    // 3. Apresentar resultado final
    if (maiorVotos == 0) {
        std::cout << "\n\n\t[INFO] Não houve votos válidos para candidatos.\n";
    }
    else if (empates == 1) {
        std::cout << "\n\n\t🏆 O Candidato " << vencedor << " VENCEU AS ELEIÇÕES!\n";
    }
    else {
        std::cout << "\n\n\t⚠️ EMPATE TÉCNICO! \n\tCandidatos empatados com " << maiorVotos << " votos: ";
        for (int i = 0; i < MAX - 2; i++) {
            if (cand[i] == maiorVotos) {
                std::cout << " [" << i + 1 << "] ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
