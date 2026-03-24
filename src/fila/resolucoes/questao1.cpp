/*
Filas podem ser implementadas com armazenamento de dados em vetor, se a capacidade fixa não for um problema. 
Nesse caso, é importante controlar os índices para "dar a volta" no vetor sempre que for necessário. Uma fila 
assim pode ser chamada de fila circular.

Faça a implementação de uma fila circular fazendo com que a inserção (método Enfileirar) sempre use o início 
do vetor (posição zero) quando a fila estiver vazia.

Entradas:

Inicialmente, o programa lê um número inteiro que é capacidade da fila a ser criada.

Depois, o programa lê códigos de comandos a executar. Sempre um caractere identificando o comando seguido dos 
parâmetros necessários para executar o comando, se houverem. Os códigos de comandos são:

    t - para terminar a execução do programa
    e - para enfileirar um valor - seguido do valor (número inteiro)
    d - para desenfileirar um valor
    i - para escrever as informações da fila (atributos e conteúdo)

Saídas:

Os comandos d e i são os únicos que produzem saída de dados. Cada um pode ser observado no exemplo.

*/

#include <iostream>

typedef int T;

struct No
{
    T valor;
    No *proximo;
};

class Fila
{
private:
    No *inicio;
    No *fim;
    int tamanho;

public:
    Fila()
    {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }

    ~Fila()
    {
        while (!vazia())
        {
            desenfileirar();
        }
    }

    bool vazia()
    {
        return tamanho == 0;
    }

    void enfileirar(T val)
    {
        No *novoNo = new No;
        novoNo->valor = val;
        novoNo->proximo = NULL;

        if (vazia())
        {
            inicio = novoNo;
        }
        else
        {
            fim->proximo = novoNo;
        }

        fim = novoNo;

        tamanho++;
    }

    // Retorna -1 caso a fila esteja vazia
    T desenfileirar()
    {
        if (vazia())
        {
            return -1;
        }

        No *aux = inicio;
        T valor = aux->valor;
        inicio = inicio->proximo;

        if (inicio == NULL)
        {
            fim = NULL;
        }

        delete aux;
        tamanho--;
        return valor;
    }

    void diferenca(Fila &f)
    {
        Fila tempF1;
        int tamanhoF1 = tamanho;
        int tamanhoF2 = f.tamanho;

        for (int i = 0; i < tamanhoF1; i++)
        {
            T inicioF1 = desenfileirar();
            bool achou = false;

            for (int j = 0; j < tamanhoF2; j++)
            {
                T inicioF2 = f.desenfileirar();

                if (inicioF1 == inicioF2)
                {
                    achou = true;
                }

                f.enfileirar(inicioF2);
            }

            if (!achou)
            {
                tempF1.enfileirar(inicioF1);
            }
        }

        while (!tempF1.vazia())
        {
            T valor = tempF1.desenfileirar();

            std::cout << valor << ' ';

            enfileirar(valor);
        }
        std::cout << '\n';
    }
};

int main()
{
    Fila f1;
    Fila f2;

    int qntElementos, elemento;

    std::cin >> qntElementos;

    for (int i = 0; i < qntElementos; i++)
    {
        std::cin >> elemento;

        f1.enfileirar(elemento);
    }

    std::cin >> qntElementos;

    for (int i = 0; i < qntElementos; i++)
    {
        std::cin >> elemento;

        f2.enfileirar(elemento);
    }

    f1.diferenca(f2);


    return 0;
}