/*
   PROJETO: Sistema Interativo de Gestão de Cafetaria.
   OBJETIVO: Gerir múltiplos pedidos de clientes, acumulando o total da fatura com base em um menu predefinido e validando as quantidades solicitadas.
   CONCEITOS: Modularização intensa, Passagem de Parâmetros por Referência (&), Switch-case e controle de fluxo com 'conio.h' (_getch).
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

// Protótipos para organização modular
void exibirMenuEObterCodigo(int& codigo);
void calcularAcumulado(int codigo, float& total);

int main()
{
    SetConsoleOutputCP(1252);
    int codigo;
    float totalFatura = 0;

    // Loop principal (Vários clientes)
    do {
        totalFatura = 0; // Zera a fatura para o novo cliente

        // Loop secundário (Vários itens para o mesmo cliente)
        do {
            // As funções alteram as variáveis originais via referência (&)
            exibirMenuEObterCodigo(codigo);
            calcularAcumulado(codigo, totalFatura);

            std::cout << "\n\tDeseja adicionar outro item a este pedido (S/N)? ";
        } while (toupper(_getch()) == 'S');

        std::cout << "\n\n\t=====================================";
        std::cout << "\n\tTOTAL A PAGAR: " << totalFatura << " €";
        std::cout << "\n\t=====================================\n";

        std::cout << "\n\tDeseja iniciar o atendimento de um NOVO CLIENTE (S/N)? ";
    } while (toupper(_getch()) == 'S');

    std::cout << "\n\tSistema encerrado.\n";
    return 0;
}

// Função 1: Mostra o cardápio e valida o código do produto
void exibirMenuEObterCodigo(int& codigo) {
    do {
        system("cls");
        std::cout << "\n\t==========================================================";
        std::cout << "\n\tProduto                            Código       Preço";
        std::cout << "\n\t==========================================================";
        std::cout << "\n\tCachorro Quente                    100          2.50 €";
        std::cout << "\n\tHambúrguer Simples                 101          3.50 €";
        std::cout << "\n\tHambúrguer Especial                102          4.50 €";
        std::cout << "\n\tBifana Simples                     103          2.70 €";
        std::cout << "\n\tBifana com queijo e bacon          104          3.55 €";
        std::cout << "\n\tRefrigerante                       105          1.75 €";
        std::cout << "\n\tSumo Laranja Natural               106          2.50 €";
        std::cout << "\n\tÁgua                               107          0.35 €";
        std::cout << "\n\tCafé                               108          0.50 €";
        std::cout << "\n\t----------------------------------------------------------";

        std::cout << "\n\n\tInsira o Código do Produto: ";
        if (std::cin >> codigo && codigo >= 100 && codigo <= 108) break;

        std::cout << "\n\t[ERRO] Código não encontrado no menu!";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        Sleep(1200); // Pausa para leitura do erro antes de limpar a tela
    } while (true);
}

// Função 2: Pede a quantidade e soma ao total da fatura
void calcularAcumulado(int codigo, float& total) {
    int quantidade;
    do {
        std::cout << "\tInsira a Quantidade (1-9): ";
        if (std::cin >> quantidade && quantidade > 0 && quantidade < 10) break;

        std::cout << "\t[ERRO] Quantidade inválida!";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    } while (true);

    switch (codigo) {
        case 100: total += 2.50f * quantidade; break;
        case 101: total += 3.50f * quantidade; break;
        case 102: total += 4.50f * quantidade; break;
        case 103: total += 2.70f * quantidade; break;
        case 104: total += 3.55f * quantidade; break;
        case 105: total += 1.75f * quantidade; break;
        case 106: total += 2.50f * quantidade; break;
        case 107: total += 0.35f * quantidade; break;
        case 108: total += 0.50f * quantidade; break;
    }
}
