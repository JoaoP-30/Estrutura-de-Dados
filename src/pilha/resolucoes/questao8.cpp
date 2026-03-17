/*
 Implemente uma estrutura de dados do tipo pilha com as operações básicas de empilhar e desempilhar.
 Faça um método adicional que retorne o menor valor da pilha sem que haja quebra da estrutura e sem
 ordenar seus elementos. Faça um programa com suporte as seguintes operações:

    e - empilhar um valor X passado como parâmetro.
    d - desempilhar um valor, que deve ser impresso. Se a pilha estiver vazia, imprimir "VAZIA".
    m - retornar o menor valor armazenado na pilha. Se a pilha estiver vazia, imprimir "VAZIA".
    s - imprimir todos os valores armazenados na pilha e encerrar.

DICA: A solução utiliza duas pilhas: a pilha principal e uma pilha auxiliar para que haja o intercâmbio de elementos entre elas.

Entradas:

    1 - Operações a serem realizadas sobre a estrutura

Saídas:

    1 - Retorno correspondente a cada operação executada
*/

#include <iostream>

class pilha
{
private:
    int capacidade;
    int tamanhoP;
    int tamanhoM;
    int *pilhaPrincipal;
    int *pilhaMenor;

public:
    pilha()
    {
        capacidade = 20;
        tamanhoP = 0;
        tamanhoM = 0;
        pilhaPrincipal = new int[capacidade];
        pilhaMenor = new int[capacidade];
    }

    ~pilha()
    {
        delete[] pilhaPrincipal;
        delete[] pilhaMenor;
    }

    void empilhar(int e)
    {
        if (tamanhoM == 0 || e <= pilhaMenor[tamanhoM - 1])
        {
            pilhaMenor[tamanhoM++] = e;
        }

        pilhaPrincipal[tamanhoP++] = e;
    }

    void desempilhar()
    {
        if (tamanhoP == 0)
        {
            std::cout << "VAZIA\n";
            return;
        }

        if (pilhaMenor[tamanhoM - 1] == pilhaPrincipal[tamanhoP - 1])
        {
            tamanhoM--;
        }

        std::cout << pilhaPrincipal[tamanhoP - 1] << ' ';

        tamanhoP--;
    }

    void menor()
    {
        if (tamanhoM == 0)
        {
            std::cout << "VAZIA\n";
            return;
        }

        std::cout << pilhaMenor[tamanhoM - 1];
    }

    void imprimirEDesempilhar()
    {
        while (tamanhoP > 0)
        {
            desempilhar();
        }
        std::cout << '\n';
    }
};

int main()
{
    pilha p;

    char opcao;

    while (true)
    {
        std::cin >> opcao;

        if (opcao == 'e')
        {
            int elemento;
            std::cin >> elemento;
            p.empilhar(elemento);
        }

        if (opcao == 'd')
        {
            p.desempilhar();
            std::cout << '\n';
        }

        if (opcao == 'm')
        {
            p.menor();
            std::cout << '\n';
        }

        if (opcao == 's')
        {
            p.imprimirEDesempilhar();
            break;
        }
    }

    return 0;
}