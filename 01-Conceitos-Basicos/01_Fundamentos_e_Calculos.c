/*
   EXERCÍCIO: Exploração de Tipos de Dados e Operadores Aritméticos.
   OBJETIVO: Demonstrar a manipulação de variáveis (int, float, char), o uso da tabela ASCII e cálculos matemáticos básicos.
   CONCEITOS: sizeof (memória), máscaras de formatação (%d, %f, %c), divisão inteira vs real e operador de módulo (%).
*/
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Exemplo de Tipagem e Memória
    int valor = 10;
    char letra = 'A';
    printf("--- Fundamentos ---\n");
    printf("Valor: %d | Código ASCII da letra %c: %d\n", valor, letra, letra);
    printf("Espaço ocupado pelo int: %d bytes\n", (int)sizeof(int));

    // Exemplo de Operadores
    int x = 5, y = 3;
    printf("\n--- Operadores ---\n");
    printf("Soma: %d + %d = %d\n", x, y, x + y);
    printf("Divisão Inteira: %d / %d = %d\n", x, y, x / y);
    printf("Resto da Divisão: %d %% %d = %d\n", x, y, x % y);

    return 0;
}
