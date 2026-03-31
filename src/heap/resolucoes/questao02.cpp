/*
Uma empresa de advocacia deseja resolver o problema de prioridade na análise de seus processos, 
pois alguns com menos importância estão sendo tratados antes dos processos que possuem relevância mais alta.

Com seus conhecimentos de Estrutura de Dados, implemente uma estrutura para definir corretamente a 
prioridade dos processos. A ideia do programa consiste no usuário solicitar qual processo deverá ser analisado 
e o programa toda vez informar aquele com prioridade mais alta no momento. Você poderá utilizar este código como 
base de implementação. Os processos são representados por um código e uma prioridade. Quando maior o valor da prioridade, 
mais urgente é o processo.

Comandos de utilização do programa:

    i: inserir um novo processo, seguido do código (número natural) e da prioridade (número inteiro) do processo.
    o: obter o processo que deverá ser tratado. Causa a retirada do processo mais prioritário do sistema e o programa 
    escreve seu código e sua prioridade. Caso não tenha um processo para ser obtido, o programa escreve "Nao encontrado".
    s: sair do programa.

No início da execução, o programa lê a capacidade máxima de processos para trabalhar. Em seguida começa a processar os comandos acima.
*/

#include <iostream>
#include <limits>
#include <stdexcept>

typedef unsigned TCodProcesso;
// Valor especial de codigo de processo, para significar ausência de valor:
const TCodProcesso INVALIDO = std::numeric_limits<TCodProcesso>::max();

class Processo
{
public:
    Processo();
    Processo(TCodProcesso cod, int prio);
    TCodProcesso codigo;
    int prioridade;
};

Processo::Processo()
    : codigo(INVALIDO), prioridade(0) {}

Processo::Processo(TCodProcesso cod, int prio)
    : codigo(cod), prioridade(prio) {}

bool operator>(const Processo &p1, const Processo &p2)
{
    return p1.prioridade > p2.prioridade;
}

typedef Processo T;

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
            std::swap(heap[maior], heap[i]);
            heapify(maior);
        }
    }

public:
    Heap(int cap)
    {
        capacidade = cap;
        tamanho = 0;
        heap = new T[capacidade];
    }

    ~Heap()
    {
        delete[] heap;
    }

    void inserir(const T &val)
    {
        if (tamanho == capacidade)
        {
            throw std::overflow_error("Heap está cheio");
        }

        heap[tamanho++] = val;

        int i = tamanho - 1;

        while (i != 0 && heap[i] > heap[(i - 1) / 2])
        {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    T remover()
    {
        if (tamanho == 0)
        {
            throw std::underflow_error("Nao encontrado");
        }

        T val = heap[0];

        std::swap(heap[0], heap[tamanho - 1]);

        tamanho--;

        heapify(0);

        return val;
    }
};

int main()
{
    int capacidade;
    std::cin >> capacidade;

    Heap heap(capacidade);

    char comando;
    Processo processo;

    while (std::cin >> comando, comando != 's')
    {
        switch (comando)
        {
        case 'i':
            std::cin >> processo.codigo >> processo.prioridade;
            heap.inserir(processo);
            break;
        case 'o':
            try
            {
                processo = heap.remover();

                std::cout << processo.codigo << ' ' << processo.prioridade << '\n';
            }
            catch (const std::underflow_error &e)
            {
                std::cout << e.what() << '\n';
            }
            break;
        case 's':
            break;
        }
    }

    return 0;
}