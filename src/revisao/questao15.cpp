/*
Faça um programa que abra um arquivo texto chamado "Meu_Arquivo.txt" e conte o número de caracteres não brancos nele. 
Escreva o resultado da contagem na saída padrão.

Entrada:

    O arquivo de texto "Meu_Arquivo.txt".

Saída:

    Número de caracteres não brancos dentro do arquivo.

*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int cont = -1;
    char l;

    ifstream arq("arquivos/Meu_Arquivo.txt");

    if (!arq.is_open())
    {
        return -1;
    }

    while (!arq.eof())
    {
        arq >> l;

        if (l != ' ')
        {
            cont++;
        }
    }

    arq.close();

    cout << cont << '\n';

    return 0;
}