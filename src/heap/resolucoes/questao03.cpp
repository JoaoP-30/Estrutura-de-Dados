/*
Implemente uma classe MaxHeap que tem um construtor que recebe um vetor de elementos. 
Durante a criação do MaxHeap, alguns elementos deverão ser reposicionados para que passem 
a ter as propriedades de um max heap. O construtor (ou método usado no construtor) deverá 
escrever passo a passo como fica o armazenamento após a correção descendo de cada posição.

Note que não é para escrever os valores do heap após cada troca, os valores do heap devem 
ser escritos após todas as trocas (zero ou mais) realizadas para a correção de uma posição.

Implemente a função principal que cria um heap a partir do vetor.

Entradas:

    A quantidade de elementos a serem lidos.
    Os elementos (números inteiros) a serem armazenados no heap.

Saídas:

Para cada posição a ser corrigida:

    A posição, seguida de dois pontos;
    Todos os elementos armazenados após a reorganização iniciada na posição em questão.

Note a ausência de espaço antes do dois pontos e a presença do espaço depois, como em qualquer
sinal de pontuação.
*/

#include <iostream>
#include <cstring>

typedef int T;

class Heap
{
private:
    int capacidade;
    int tamanho;
    T *heap;

    void heapify(int i)
    {
        int maior = i;
        int esquerda = 2 * i + 1;
        int direita = 2 * i + 2;

        if (esquerda < tamanho && heap[esquerda] > heap[maior])
        {
            maior = esquerda;
        }

        if (direita < tamanho && heap[direita] > heap[maior])
        {
            maior = direita;
        }

        if (i != maior)
        {
            std::swap(heap[i], heap[maior]);
            heapify(maior);
        }
    }

public:
    Heap(T vet[], int tam)
    {
        capacidade = tam;

        heap = new T[capacidade];

        memcpy(heap, vet, tam * sizeof(T));

        tamanho = tam;

        for (int i = (tamanho - 1) / 2; i >= 0; i--)
        {
            heapify(i);

            std::cout << i << ": ";

            for (int i = 0; i < tamanho; i++)
            {
                std::cout << heap[i] << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main()
{
    int tam;
    std::cin >> tam;
    int vet[tam];

    for (int i = 0; i < tam; i++)
    {
        std::cin >> vet[i];
    }

    Heap heap(vet, tam);

    return 0;
}