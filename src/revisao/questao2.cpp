/*
Na matemática a união de dois conjuntos A e B é representada por A ∪ B e é formada por todos os elementos
pertencentes a A ou B. Por exemplo, seja A = {1, 2, 3} e B = {4, 5}, então a união destes dois conjuntos
será A ∪ B = {1, 2, 3, 4, 5}, porém caso um elemento esteja em ambos os conjuntos ele não irá aparecer duas
vezes no conjunto união, por exemplo, seja A = {1, 2, 3} e B = {1, 2, 4}, assim a união será A ∪ B = {1, 2, 3, 4}.

Utilizando os conceitos de conjunto faça um programa que leia dois vetores A e B e determine a união. O tamanho de
cada vetor será informado pelo usuário.

Obs.: Considere que não existirão vetores vazios.

Obs.2: Os vetores devem ser alocados dinamicamente.

Entradas:

    Tamanho do vetor A.
    Elementos do vetor A.
    Tamanho do vetor B.
    Elementos do vetor B.

Saídas:

    Vetor C representado a união dos vetores A e B.
*/

#include <iostream>

void uniao(int *vetA, int tamA, int *vetB, int tamB, int *vetC, int &tamC);
bool elementoRepetido(int elemento, int *vetor, int tam);

int main()
{
    int tamA, tamB, tamC;
    int *vetA, *vetB, *vetC;
    int valor;

    std::cin >> tamA;

    vetA = new int[tamA];

    for (int i = 0; i < tamA; i++)
    {
        std::cin >> valor;

        vetA[i] = valor;
    }

    std::cin >> tamB;

    vetB = new int[tamB];

    for (int i = 0; i < tamB; i++)
    {
        std::cin >> valor;

        vetB[i] = valor;
    }

    tamC = tamA + tamB;
    vetC = new int[tamC];

    uniao(vetA, tamA, vetB, tamB, vetC, tamC);

    for (int i = 0; i < tamC; i++)
    {
        std::cout << vetC[i] << ' ';
    }
    std::cout << '\n';

    delete[] vetA;
    delete[] vetB;
    delete[] vetC;

    return 0;
}

void uniao(int *vetA, int tamA, int *vetB, int tamB, int *vetC, int &tamC)
{
    tamC = 0;

    for (int i = 0; i < tamA; i++)
    {
        vetC[i] = vetA[i];
        tamC++;
    }

    for (int j = 0; j < tamB; j++)
    {
        int valor = vetB[j];

        if (!elementoRepetido(valor, vetC, tamA))
        {
            vetC[tamC] = valor;
            tamC++;
        }
    }
}

bool elementoRepetido(int elemento, int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (elemento == vetor[i])
        {
            return true;
        }
    }

    return false;
}