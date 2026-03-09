/*
Faça um programa para receber nove números inteiros positivos, armazená-los em um vetor, calcular e
exibir no dispositivo de saída padrão aqueles números que são primos e suas respectivas posições no vetor.
Se nenhum número primo for fornecido, nenhuma mensagem precisará ser exibida.

Entradas:

    1 - Nove números inteiros positivos a serem armazenados em um vetor.

Saídas:

    1 - Sequência de números primos e suas respectivas posições (índices no vetor). Obs.: Aqueles números que forem primos 
    e suas respectivas posições deverão ser exibidos aos pares.
*/

#include <iostream>

bool ehPrimo(int valor);

int main()
{
    int vetor[9];
    int valor;

    for (int i = 0; i < 9; i++)
    {
        std::cin >> valor;
        vetor[i] = valor;
    }

    for (int i = 0; i < 9; i++)
    {
        if (ehPrimo(vetor[i]))
        {
            std::cout << vetor[i] << ' ' << i << '\n';
        }
    }

    return 0;
}

bool ehPrimo(int valor)
{
    for (int i = 2; i < valor; i++)
    {
        if (valor % i == 0)
        {
            return false;
        }
    }

    return true;
}