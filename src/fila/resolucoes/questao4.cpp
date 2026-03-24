/*
A agência bancária decidiu contratar uma pessoa para fazer o programa que gerencia as senhas de 
atendimento nos caixas expressos. Você será responsável por essa implementação e as instruções 
passadas a você são: existem dois tipos de senha, as prioritárias e as normais; as senhas são 
chamadas de modo a serem chamadas 3 prioritárias para então uma normal. Não havendo prioridades, 
as pessoas com senha normal podem ser atendidas normalmente. Sempre que um atendimento normal for 
realizado, os próximos três devem ser prioritários, se possível. Se estiver na hora de realizar um 
atendimento de cliente normal mas não houver nenhum cliente normal, deve ser chamado um nome do 
atendimento preferencial, se houver. Você deverá usar uma estrutura de dados do tipo fila e poderá 
usar código fornecido.

O programa deve ler comandos representados por palavras e seus respectivos argumentos assim:

    O comando "normal" seguido de um nome (sem espaços) representa retirada de uma senha normal, ou seja, 
    uma pessoa entrou na fila "normal".
    O comando "prioridade" seguido de um nome (sem espaços) representa retirada de uma senha prioritária, 
    ou seja, uma pessoa entrou na fila "prioridade".
    O comando "atender" representa uma senha sendo chamada.
    O comando "fim" solicita o fim da execução do programa.

Para cada comando de atendimento, o programa deverá escrever o nome da pessoa que deve ser atendida, 
de acordo com as regras de atendimento vistas. Caso não haja cliente a ser chamado, o programa deve 
escrever "AGUARDE" (letras maiúsculas). A cada atendimento normal, a contagem para prioritários deve ser 
reiniciada.

Entradas:

    Sequência de comandos, seguindo as instruções acima.

Saídas:

    Somente o comando "atender" gera saída, conforme instruções acima.

*/


#include <iostream>

using namespace std;

typedef string T;

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
        while (!vazio())
        {
            remove();
        }
    }

    bool vazio()
    {
        return tamanho == 0;
    }

    void inserir(T valor)
    {
        No *n = new No;
        n->valor = valor;
        n->proximo = NULL;

        if (inicio == NULL)
        {
            inicio = n;
        }
        else
        {
            fim->proximo = n;
        }

        fim = n;

        tamanho++;
    }

    T remove()
    {
        if(vazio()){
            return "\0";
        }
        
        No *temp = inicio;
        T valor = temp->valor;
        inicio = inicio->proximo;

        if (inicio == NULL)
        {
            fim = NULL;
        }

        tamanho--;

        delete temp;

        return valor;
    }
};

int main()
{
    Fila normal;
    Fila preferencial;
    string comando, pessoa;
    int atendimento = 0;

    while (cin >> comando, comando != "fim")
    {
        if (comando == "normal")
        {
            cin >> pessoa;
            normal.inserir(pessoa);
        }

        if (comando == "prioridade")
        {
            cin >> pessoa;
            preferencial.inserir(pessoa);
        }

        if (comando == "atender")
        {
            if (normal.vazio() && preferencial.vazio())
            {
                cout << "AGUARDE\n";
            }
            else if (atendimento < 3 && !preferencial.vazio())
            {
                cout << preferencial.remove() << '\n';
                atendimento++;
            }
            else if (!normal.vazio())
            {
                cout << normal.remove() << '\n';
                atendimento = 0;
            }
            else
            {
                cout << preferencial.remove() << '\n';
                atendimento++;
            }
        }
    }

    return 0;
}