/*
Faça um programa para controlar a fila de um banco, usando a estrutura heap (fila de prioridades). 
Para agilizar o desenvolvimento, use este código fornecido.

No banco podem chegar 4 tipos de pessoas, na ordem de preferência de atendimento: os que têm 
prioridade por lei (P), os clientes vip (V), os clientes normais (C) e os não-clientes (N).

Para cada tipo, deve existir um contador que vai decrementando a cada pessoa que chega na fila. Se 
um contador chega em zero (zero é um valor inválido), ele deve voltar ao valor inicial. Os valores 
iniciais são respectivamente 50, 46, 42 e 38.

O programa tem opções para registrar a entrada de alguém na fila e para atender (retirar da fila). 
Quando chega alguém o programa deve ser informado o tipo da pessoa e produzir uma senha 
(número positivo sequencial). A primeira senha é 1. Quando alguém for atendido, o programa deve 
informar a senha da pessoa a ser atendida.

Entradas:

    A capacidade da fila do sistema
    Comandos de chegada e de atendimento

Saídas:

A cada comando de chegada o sistema deve produzir um número identificador sequencial. A cada comando 
de atendimento, o programa deve informar o identificador da pessoa a ser atendida.
*/

#include <iostream>

using namespace std;

struct Pessoa
{
    int senha;
    int prioridade;
};

bool operator>(const Pessoa &p1, const Pessoa &p2)
{
    return p1.prioridade > p2.prioridade;
}

typedef Pessoa T;

class Heap
{
private:
    int capacity;
    int size;
    T *heap;

    void heapify(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    Heap(int cap)
    {
        capacity = cap;
        size = 0;
        heap = new T[capacity];
    }

    ~Heap()
    {
        delete[] heap;
    }

    void add(const T &val)
    {
        if (size == capacity)
        {
            throw overflow_error("O heap está cheio!");
        }

        heap[size++] = val;

        int i = size - 1;

        while (i != 0 && heap[i] > heap[(i - 1) / 2])
        {
            swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2;
        }
    }

    T remove()
    {
        if (size == 0)
        {
            throw underflow_error("O heap está vazio!");
        }

        T val = heap[0];

        swap(heap[0], heap[size - 1]);

        size--;

        heapify(0);

        return val;
    }
};

unsigned Indice(char tipo)
{
    // Funcao para converter tipo de pessoa na fila para indices no vetor de contadores.
    switch (tipo)
    {
    case 'P':
        return 0;
    case 'V':
        return 1;
    case 'C':
        return 2;
    case 'N':
        return 3;
    }
    return 0;
}

void Decrementar(unsigned &contador, char tipo)
{
    // Funcao para decretar um contador de prioridades.
    --contador;
    if (contador == 0)
    {
        switch (tipo)
        {
        case 'P':
            contador = 50;
            break;
        case 'V':
            contador = 46;
            break;
        case 'C':
            contador = 42;
            break;
        case 'N':
            contador = 38;
            break;
        }
    }
}

int main()
{
    int capacidade;
    
    cin >> capacidade;
    
    Heap heap(capacidade);
    
    char comando;
    
    unsigned indice;
    
    unsigned vetContadores[] = {50, 46, 42, 38};
    
    char tipo;
    
    unsigned senha = 0;
    
    Pessoa pessoa;

    while (cin >> comando, comando != 's')
    {
        switch (comando)
        {
        case 'c': // chegada
            cin >> tipo;

            indice = Indice(tipo);

            pessoa.senha = ++senha;

            pessoa.prioridade = vetContadores[indice];

            heap.add(pessoa);

            Decrementar(vetContadores[indice], tipo);

            cout << pessoa.senha << ' ' << pessoa.prioridade << endl;

            break;

        case 'a': // atendimento
            try
            {
                pessoa = heap.remove();

                cout << pessoa.senha << '\n';
            }
            catch (const underflow_error &e)
            {
                cout << e.what() << '\n';
            }
            break;

        case 's': // sair do programa
            break;
        }
    }

    return 0;
}