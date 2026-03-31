/*
O professor Bruno, com o intuito de motivar ainda mais os alunos a realizarem as atividades propostas para a
sua disciplina, resolveu presentear o aluno que mais teve boas notas em suas atividades. Para isso, você deverá
fazer um programa que faça esta classificação, com o intuito de automatizar o processo e aplicar os conceitos
das estruturas vistas em Estruturas de Dados.

Os dados são classificados pelas informações básicas do aluno (matricula e nome) e uma lista de atividades realizadas.
Para cada atividade, existe sua nota e também a quantidade de tentativas que o aluno realizou.

Observações: Para facilitar, a classificação deverá ser feita utilizando a média aritmética simples das notas dos
alunos nas atividades (a quantidade de atividades informada será fixa para todos os alunos). O critério de desempate
deve ser tomado por: 1) quantidade de tentativas e 2) ordem alfabética.

A resolução deste problema deve ser feita utilizando a estrutura de dados Heap genérica. Ou seja, a implementação dos
critérios de desempate não deverá ser realizada dentro de sua estrutura, e sim no TAD especifico para o aluno. Você
pode utilizar o código fornecido para agilizar o processo de implementação.

Entradas:

    Quantidade de alunos que serão informados.
    Número de atividades que será informado de cada aluno.
    Matricula (número natural) e nome (texto sem espaços) de cada aluno, seguido das atividades do mesmo (nota e tentativas)

Saídas:

    Matrícula e nome do aluno destaque no formato: [Matricula] Nome.

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct Atividade
{
    int nota;
    int tentativas;
};

class Aluno
{
private:
    unsigned matricula;
    std::string nome;
    unsigned capAtividades;
    Atividade *vetAtividades;
    unsigned nroAtividades;

public:
    Aluno() : matricula(0), nome(""), capAtividades(0), nroAtividades(0)
    {
        vetAtividades = NULL;
    }

    Aluno(unsigned matr, const std::string &n, unsigned capAtiv) : matricula(matr), nome(n), capAtividades(capAtiv), nroAtividades(0)
    {
        vetAtividades = new Atividade[capAtiv];
    }

    Aluno(const Aluno &umAluno)
    {
        matricula = umAluno.matricula;
        nome = umAluno.nome;
        capAtividades = umAluno.capAtividades;
        nroAtividades = umAluno.nroAtividades;

        vetAtividades = new Atividade[capAtividades];

        copy(umAluno.vetAtividades, umAluno.vetAtividades + capAtividades, vetAtividades);
    }

    ~Aluno()
    {
        delete[] vetAtividades;
    }

    void InserirAtividade(const Atividade &a)
    {
        vetAtividades[nroAtividades] = a;
        nroAtividades++;
    }

    std::string Nome() const
    {
        return nome;
    }

    unsigned Matricula()
    {
        return matricula;
    }

    float Media() const
    {
        float soma = 0.0f;

        for (unsigned i = 0; i < nroAtividades; i++)
        {
            soma += float(vetAtividades[i].nota);
        }

        return soma / float(nroAtividades);
    }

    int Tentativas() const
    {
        int tentativas = 0;

        for (unsigned i = 0; i < nroAtividades; i++)
        {
            tentativas += vetAtividades[i].tentativas;
        }

        return tentativas;
    }

    Aluno &operator=(const Aluno &umAluno)
    {
        if (this == &umAluno)
        {
            return *this;
        }

        matricula = umAluno.matricula;
        nome = umAluno.nome;
        capAtividades = umAluno.capAtividades;
        nroAtividades = umAluno.nroAtividades;
        delete[] vetAtividades;
        vetAtividades = new Atividade[capAtividades];
        std::copy(umAluno.vetAtividades, umAluno.vetAtividades + capAtividades, vetAtividades);
        return *this;
    }

};

bool operator>(const Aluno &a, const Aluno &b)
{

    // MÉDIA

    if (a.Media() > b.Media())
    {
        return true;
    }

    if (a.Media() < b.Media())
    {
        return false;
    }

    // DESEMPATE 1 - Nro de Tentativas

    if (a.Tentativas() < b.Tentativas())
    {
        return true;
    }

    if (a.Tentativas() > b.Tentativas())
    {
        return false;
    }

    // DESEMPATE 2 - Ordem Alfabética

    if (a.Nome() < b.Nome())
    {
        return true;
    }

    if (a.Nome() > b.Nome())
    {
        return false;
    }

    return false;
}


typedef Aluno T;

class Heap
{
private:
    int size;
    int capacity;
    Aluno *heap;

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

        if (i != largest)
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
        heap = new Aluno[capacity];
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

    T getRoot() const
    {
        if (size == 0)
        {
            throw underflow_error("O heap está vazio!");
        }

        return heap[0];
    }
};

int main()
{
    unsigned qtdeAlunos;
    cin >> qtdeAlunos;

    unsigned qtdeAtividades;
    cin >> qtdeAtividades;

    Heap heap(qtdeAlunos);

    Atividade atividade;

    string nome;
    unsigned matricula;

    for (unsigned i = 0; i < qtdeAlunos; i++)
    {
        cin >> matricula >> nome;
        Aluno aluno(matricula, nome, qtdeAtividades);

        for (unsigned i = 0; i < qtdeAtividades; i++)
        {
            cin >> atividade.nota >> atividade.tentativas;
            aluno.InserirAtividade(atividade);
        }

        heap.add(aluno);
    }

    Aluno alunoDestaque(heap.remove());

    cout << '[' << alunoDestaque.Matricula() << "] " << alunoDestaque.Nome() << endl;

    return 0;
}
