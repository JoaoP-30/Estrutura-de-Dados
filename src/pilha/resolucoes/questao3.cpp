/*
Faça um programa que lê uma linha de texto e verifica se todo parênteses tem um correspondente. Assuma que cada
sinal de "fecha parênteses" fecha o último "abre parênteses".

Caso não existam parênteses correspondentes em todos os casos, o programa deve escrever a posição do erro. A posição
do primeiro caractere é zero. Se todos os parênteses têm correspondentes, o programa deverá escrever "correto"
(letras minúsculas). A posição do erro no caso de um "fecha parênteses" sem correspondente é a dele mesmo, pois não é
preciso olhar o resto do texto para saber que há erro. A posição do erro no caso de um "abre parênteses" sem correspondente
é a do último "abre parênteses" visto, pois só é possível saber que ele não tem correspondente ao final do texto.

Este é um exercício de solução de problema usando pilha. A pilha deve ser parte importante da solução. Faça um programa
utilizando somente a estrutura de dado pilha, respeitando todas as suas propriedades e não utilizando a STL.

Entradas:

    1 - Uma linha de texto (não mais do que 254 caracteres).

Saídas:

    1 - A palavra "correto" se todos tiverem correspondentes ou então a posição do erro.
*/

#include <iostream>
#include <string>

using namespace std;

class pilha
{
private:
    int capacidade;
    int tamanho;
    int *p;

public:
    pilha()
    {
        capacidade = 254;
        tamanho = 0;
        p = new int[capacidade];
    }

    ~pilha()
    {
        delete[] p;
    }

    bool vazio() { return tamanho == 0; }

    void empilha(char c)
    {
        p[tamanho++] = c;
    }

    int desempilha()
    {
        return p[--tamanho];
    }

    int topo()
    {
        return p[tamanho - 1];
    }
};

int main()
{
    pilha p;
    string str;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if (c == '(')
        {
            p.empilha(i);
        }
        else if (c == ')')
        {
            if (p.vazio())
            {
                cout << i << '\n';
                return 0;
            }

            p.desempilha();
        }
    }

    if (p.vazio())
    {
        cout << "correto\n";
    }
    else
    {
        cout << p.topo() << '\n';
    }

    return 0;
}