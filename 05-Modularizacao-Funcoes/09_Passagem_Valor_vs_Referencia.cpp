/*
   EXERCÍCIO: Estudo de Passagem de Parâmetros.
   OBJETIVO: Demonstrar a diferença técnica entre passar uma cópia de um dado (valor) e passar o endereço original da informação (referência).
   CONCEITOS: Protótipos de funções, Scopes de variáveis e Operador de Endereço (&).
*/

#include <iostream>
#include <Windows.h>

// --- PROTÓTIPOS ---
void trocaPorValor(int a, int b);
void trocaPorReferencia(int& a, int& b); // O símbolo '&' faz a mágica

int main() {
    SetConsoleOutputCP(1252);
    int x = 10, y = 20;
    
    std::cout << "--- TESTE DE MEMÓRIA (Modularização) ---" << std::endl;
    std::cout << "Valores iniciais: x = " << x << " | y = " << y << std::endl;
    
    // Tentativa 1: Por valor (copia os números)
    trocaPorValor(x, y);
    std::cout << "\nApós tentativa por VALOR: x = " << x << " | y = " << y;
    std::cout << " (Sem alteração no main)" << std::endl;
    
    // Tentativa 2: Por referência (acessa os números originais)
    trocaPorReferencia(x, y);
    std::cout << "Após troca por REFERÊNCIA: x = " << x << " | y = " << y;
    std::cout << " (Valores alterados no main!)" << std::endl;
    
    return 0;
}

// Esta função recebe cópias. O que acontece aqui, "morre" aqui.
void trocaPorValor(int a, int b) { 
    int aux = a; a = b; b = aux; 
}

// Esta função recebe os endereços reais das variáveis.
void trocaPorReferencia(int& a, int& b) { 
    int aux = a; a = b; b = aux; 
}
