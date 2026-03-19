#include <iostream>

struct No
{
    char valor;
    No *proximo;
};

class Pilha
{
private:
    No *topo;
    int tamanho;

public:
    Pilha()
    {
        topo = NULL;
        tamanho = 0;
    }

    ~Pilha()
    {
        while (tamanho > 0)
        {
            No *topoAtual = topo;
            topo = topo->proximo;
            delete topoAtual;
            tamanho--;
        }
    }

    bool vazia()
    {
        return tamanho == 0;
    }

    int obterTamanho()
    {
        return tamanho;
    }

    void empilha(char v)
    {
        No *novoNo = new No;
        novoNo->valor = v;
        novoNo->proximo = topo;
        topo = novoNo;
        tamanho++;
    }

    char desempilha()
    {
        if (vazia())
        {
            return ' ';
        }

        No *topoAtual = topo;
        char c = topoAtual->valor;
        topo = topo->proximo;
        delete topoAtual;
        tamanho--;
        return c;
    }
};

int main()
{
    Pilha pA;
    Pilha pC;
    char c = ' ';
    int fase = 0;
    int Cs = 0;

    while (std::cin >> c && c != 'X')
    {
        if (fase == 0)
        {
            if (c == 'A')
            {
                pA.empilha('A');
                pC.empilha('C');
                pC.empilha('C');
            }
            else if (c == 'B')
            {
                fase = 1;
            }
            else
            {
                std::cout << "nao " << pA.obterTamanho() << ' ' << pC.obterTamanho() << '\n';
                return 0;
            }
        }
        else if (fase == 1)
        {
            if (c == 'C')
            {
                if (pC.vazia())
                {
                    std::cout << "nao " << pA.obterTamanho() << " " << pC.obterTamanho() << '\n';
                    return 0;
                }

                pC.desempilha();
                Cs++;

                if (Cs == 2)
                {
                    if (pA.vazia())
                    {
                        std::cout << "nao " << pA.obterTamanho() << " " << pC.obterTamanho() << '\n';
                        return 0;
                    }
                    pA.desempilha();
                    Cs = 0;
                }
            }
            else
            {
                std::cout << "nao " << pA.obterTamanho() << ' ' << pC.obterTamanho() << '\n';
                return 0;
            }
        }
    }

    if (pA.vazia() && pC.vazia() && Cs == 0 && fase == 1)
    {
        std::cout << "sim " << pA.obterTamanho() << ' ' << pC.obterTamanho() << '\n';
    }
    else
    {
        std::cout << "nao " << pA.obterTamanho() << ' ' << pC.obterTamanho() << '\n';
    }

    return 0;
}