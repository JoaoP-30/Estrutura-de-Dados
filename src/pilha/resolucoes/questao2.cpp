/*
Implemente um estrutura de dados do tipo pilha com as operações de empilhar e desempilhar.
Adicione um método que, utilizando uma pilha auxiliar, faça a ordenação crescente da pilha original,
com o menor elemento no topo da pilha. Nenhuma outra estrutura pode ser utilizada além da pilha auxiliar.

Entradas:

    1 - Quantidade de elementos a serem armazenados na pilha
    2 - Elementos da pilha

Saídas:

    1 - Elementos da pilha ordenados
*/

#include <iostream>
#include <stack>

using namespace std;

class pilha
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    pilha()
    {
    }

    void empilhar(int e)
    {
        if (s1.empty())
        {
            s1.push(e);
            return;
        }

        while (!s1.empty() && e > s1.top())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(e);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int desempilhar()
    {
        int e = s1.top();
        s1.pop();

        return e;
    }

    void imprimir()
    {
        stack<int> temp;

        while (!s1.empty())
        {
            cout << s1.top() << ' ';
            temp.push(s1.top());
            s1.pop();
        }

        while (!temp.empty())
        {
            s1.push(temp.top());
            temp.pop();
        }

        cout << '\n';
    }
};

int main()
{
    pilha p;

    int qntElementos, elemento;
    cin >> qntElementos;

    for (int i = 0; i < qntElementos; i++)
    {
        cin >> elemento;
        p.empilhar(elemento);
    }

    p.imprimir();

    return 0;
}