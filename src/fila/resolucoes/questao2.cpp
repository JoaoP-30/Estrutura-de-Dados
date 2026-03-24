/*
Filas podem ser implementadas com armazenamento de dados em vetor, se a capacidade fixa não for um problema. Nesse caso, 
é importante controlar os índices para "dar a volta" no vetor sempre que for necessário. Uma fila assim pode ser chamada de fila circular.

Faça a implementação de uma fila circular fazendo com que a inserção (método Enfileirar) sempre use o início do vetor 
(posição zero) quando a fila estiver vazia.

Entradas:

Inicialmente, o programa lê um número inteiro que é capacidade da fila a ser criada.

Depois, o programa lê códigos de comandos a executar. Sempre um caractere identificando o comando seguido dos parâmetros 
necessários para executar o comando, se houverem. Os códigos de comandos são:

    t - para terminar a execução do programa
    e - para enfileirar um valor - seguido do valor (número inteiro)
    d - para desenfileirar um valor
    i - para escrever as informações da fila (atributos e conteúdo)

Saídas:

Os comandos d e i são os únicos que produzem saída de dados. Cada um pode ser observado no exemplo.

*/

#include <iostream>

typedef int T;

class fila
{
private:
    int capacidade;
    int tamanho;
    int inicio;
    int fim;
    T *dados;

public:
    fila(int cap)
    {
        capacidade = cap;
        tamanho = 0;
        inicio = 0;
        fim = 0;
        dados = new T[capacidade];
    }

    ~fila()
    {
        delete[] dados;
    }

    bool vazia()
    {
        return tamanho == 0;
    }

    void enfileirar(const T &dado)
    {

        if (vazia())
        {
            dados[0] = dado;
            fim++;
            tamanho++;
            return;
        }

        dados[fim % capacidade] = dado;
        fim++;
        tamanho++;
    }

    // Retorna -1 caso fila esteja vazia
    T desenfileirar()
    {
        if (vazia())
        {
            return -1;
        }

        T dado = dados[inicio % capacidade];
        inicio++;
        tamanho--;

        return dado;
    }

    void estadoFila()
    {
        std::cout << "tamanho=" << tamanho << " capacidade=" << capacidade << " inicio=" << obterInicio() << " fim=" << obterFim() << '\n';
        for (int i = inicio; i < fim; i++)
        {
            std::cout << dados[i % capacidade] << ' ';
        }
        std::cout << '\n';
    }

    int obterInicio()
    {
        return inicio % capacidade;
    }

    int obterFim()
    {
        return (fim - 1) % capacidade;
    }
};

int main()
{

    int cap;
    std::cin >> cap;
    char c = '\0';

    fila f(cap);

    while (c != 't')
    {
        std::cin >> c;

        if (c == 't')
        {
            break;
        }

        if (c == 'e')
        {
            int v;
            std::cin >> v;
            f.enfileirar(v);
        }

        if (c == 'd')
        {
            std::cout << f.desenfileirar() << '\n';
        }

        if (c == 'i')
        {
            f.estadoFila();
        }
    }

    return 0;
}