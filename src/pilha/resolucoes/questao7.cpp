/*
Considere os TADs e métodos estudados para a implementação de uma pilha. Implemente um método inverter() que,
dada a chamada P1.inverter(), a ordem dos elementos de P1 é invertida. Os elementos da pilha devem continuar
armazenados em P1 após a inversão.

Dica: utilize estruturas auxiliares para a inversão.

Entradas:

    1 - Número de elementos a serem inseridos em P1.
    2 - Elementos de P1 em ordem de inserção

Saídas:

    1 - Elementos da pilha P1, após inversão
*/

#include <iostream>

class pilha
{
private:
    int capacidade;
    int tamanho;
    int *p;

public:
    pilha(int cap)
    {
        capacidade = cap;
        tamanho = 0;
        p = new int[capacidade];
    }

    ~pilha()
    {
        delete[] p;
    }

    bool vazio() { return tamanho == 0; }

    void empilhar(int elemento)
    {
        p[tamanho++] = elemento;
    }

    int desempilhar()
    {
        return p[--tamanho];
    }

    void inverter()
    {
        int tamanhoAtual = tamanho;
        pilha p1(tamanhoAtual);
        pilha p2(tamanhoAtual);

        while (!vazio())
        {
            p1.empilhar(desempilhar());
        }

        while (!p1.vazio())
        {
            p2.empilhar(p1.desempilhar());
        }

        while (!p2.vazio())
        {
            empilhar(p2.desempilhar());
        }
    }

    void imprimirEDesempilhar()
    {
        while (!vazio())
        {
            std::cout << desempilhar() << ' ';
        }
        cout << '\n';
    }
};

using namespace std;

int main()
{
    int qntElementos, elemento;
    std::cin >> qntElementos;

    pilha p(qntElementos);

    for (int i = 0; i < qntElementos; i++)
    {
        std::cin >> elemento;
        p.empilhar(elemento);
    }

    p.inverter();

    p.imprimirEDesempilhar();

    return 0;
}