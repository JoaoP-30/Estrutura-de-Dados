/*
Na teoria de sistemas define-se como elemento minimax de uma matriz o menor elemento da linha onde se encontra o 
maior elemento da matriz. Escreva um programa que receba uma matriz quadrada de inteiros, 10x10, e retorne seu 
elemento minimax, seguido de sua posição. Em caso de números iguais considere o que aparece primeiro.

Entradas:

    1 - Um matriz de inteiros de tamanho 10x10.

Saídas:

    1 - O menor elemento da linha que tem o maior elemento da matriz.
    2 - A linha e a coluna onde está o elemento do item anterior.
*/


#include <iostream>
#include <climits>

int main()
{
    int matriz[10][10];
    int elemento;
    int maior = INT_MIN, menor = INT_MAX;
    int linha, coluna;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cin >> elemento;

            if (elemento > maior)
            {
                linha = i;
                maior = elemento;
            }

            matriz[i][j] = elemento;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (matriz[linha][i] < menor)
        {
            menor = matriz[linha][i];
            coluna = i;
        }
    }

    std::cout << menor << '\n';
    std::cout << linha << ' ' << coluna << '\n';

    return 0;
}