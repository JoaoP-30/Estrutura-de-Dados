/*
Faça um programa que receba três listas de strings. Cada lista representa um conjunto de elementos. 
Cada lista será digitada em uma linha específica. Será garantido que as duas primeiras listas serão 
diferentes.

Seu programa deverá exibir no dispositivo de saída padrão, para cada palavra da terceira lista, se a palavra em 
questão apareceu em nenhuma, uma ou nas duas listas iniciais.

Entradas:

    1 - Três listas de strings. Cada lista será fornecida em uma linha específica, com a quantidade de palavras no início.

Saídas:

    1 - Sequência de valores que denotam se cada palavra da terceira lista apareceu em nenhuma, uma ou nas duas listas iniciais.
*/

#include <iostream>
#include <string>

using namespace std;

int contemString(string str, string *lista, int tamLista);

int main()
{
    string *listaA, *listaB, *listaC, str;
    int tamA, tamB, tamC;

    cin >> tamA;

    listaA = new string[tamA];

    for (int i = 0; i < tamA; i++)
    {
        cin >> str;

        listaA[i] = str;
    }

    cin >> tamB;

    listaB = new string[tamB];

    for (int i = 0; i < tamB; i++)
    {
        cin >> str;

        listaB[i] = str;
    }

    cin >> tamC;

    listaC = new string[tamC];

    for (int i = 0; i < tamC; i++)
    {
        cin >> str;

        listaC[i] = str;
    }

    for (int i = 0; i < tamC; i++)
    {
        cout << (contemString(listaC[i], listaA, tamA) + contemString(listaC[i], listaB, tamB)) << ' ';
    }
    cout << '\n';

    delete[] listaA;
    delete[] listaB;
    delete[] listaC;

    return 0;
}

int contemString(string str, string *lista, int tamLista)
{
    int cont = 0;

    for (int i = 0; i < tamLista; i++)
    {
        if (str == lista[i])
        {
            cont++;
        }
    }

    return cont;
}