/*
Dado um arquivo texto chamado palavras.txt que possua várias palavras (no máximo 50), uma em cada linha, 
suponha que exista um arquivo texto numeros.txt com uma sequência de números inteiros positivos onde cada 
número representa a posição da palavra no arquivo palavras.txt (1 representa a primeira palavra, 2 a segunda, 
etc.). Faça um programa que leia os dois arquivos e gere um arquivo texto de saída frase.txt formado pela 
substituição dos números do arquivo numeros.txt pelas palavras do arquivo palavras.txt.

Entradas (arquivos):

    Arquivo texto denominado palavras.txt com uma palavra em cada linha.
    Arquivo texto denominado numeros.txt com uma sequência de números.

Saídas (arquivos):

    Arquivo texto denominado frase.txt com a substituição dos números do arquivo numeros.txt pelas palavras do arquivo palavras.txt.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string palavra;
    string palavras[50];
    int index = 0;

    ifstream arqPalavras("palavras.txt");
    ifstream arqNumeros("numeros.txt");
    ofstream arqFrase("frase.txt");

    if (!arqPalavras.is_open() || !arqNumeros.is_open())
    {
        cout << "Falha ao abir arquivos!\n";
        return -1;
    }

    if (!arqFrase.is_open())
    {
        cout << "Falha ao criar arquivos!\n";
        return -1;
    }

    while (getline(arqPalavras, palavra))
    {
        palavras[index++] = palavra;
    }

    while (!arqNumeros.eof())
    {
        int n;
        arqNumeros >> n;
        arqFrase << palavras[n - 1] << '\n';
    }

    arqPalavras.close();
    arqNumeros.close();
    arqFrase.close();

    return 0;
}