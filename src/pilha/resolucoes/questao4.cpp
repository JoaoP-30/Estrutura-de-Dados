/*
Usando o código com as especificações de métodos e atributos mais um programa que usa a classe Pilha,
crie uma classe pilha com armazenamento dinâmico.

O método Desempilhar deve escrever alguma mensagem de erro na saída de erros quando não for possível desempilhar.

Entradas:

O programa passado aceita os seguintes comandos:

    i seguido de um valor inteiro: para inserir um item na pilha
    r: para remover um item da pilha
    l: para limpar (remover todos) os itens da pilha
    t: para consultar o tamanho da pilha
    e: para espiar o topo da pilha (escreve o topo sem removê-lo)
    f: para finalizar a execução do programa

Saídas:

Todas as saídas de comandos já estão implementadas na função principal. Ao terminar a execução do programa,
todos os itens da pilha são desempilhados e escritos, mesmo assim, o destrutor deve desalocar memória de todos os itens da pilha.
*/

#include <iostream>

typedef int Dado;

/*
class Noh
{
private:
    Dado valor;
    Noh *proximo;

public:
    Noh(int valor)
    {
        this->valor = valor;
    }

    friend class Pilha;
};
*/

struct Noh
{
    int valor;
    Noh *proximo;
};

class Pilha
{
private:
    Noh *mPtTopo;
    unsigned mTamanho;

public:
    // Constrói pilha vazia.
    Pilha()
    {
        mPtTopo = NULL;
        mTamanho = 0;
    }

    // Destrutor que desaloca memória.
    ~Pilha()
    {
        LimparTudo();
    }

    // Retira e retorna o valor que estiver no mPtTopo da pilha.
    // Escreve uma mensagem de erro se não for possível desempilhar.
    // Retorna 0 caso pilha esteja vazia
    Dado Desempilhar()
    {
        if (mTamanho == 0)
        {
            std::cout << "Não foi possível remover topo!\n";
            return 0;
        }

        Dado topo = mPtTopo->valor;
        Noh *topoAntigo = mPtTopo;
        mPtTopo = mPtTopo->proximo;
        mTamanho--;

        delete topoAntigo;

        return topo;
    }

    // retorna o mPtTopo da Pilha
    // Insere um valor na pilha.
    void Empilhar(const Dado &d)
    {
        Noh *novoNo = new Noh;
        novoNo->valor = d;

        mTamanho++;

        if (mTamanho == 0)
        {
            mPtTopo = novoNo;
            return;
        }

        novoNo->proximo = mPtTopo;

        mPtTopo = novoNo;
    }

    // Apagar todos os dados da pilha.
    void LimparTudo()
    {
        while (mTamanho > 0)
        {
            Noh *noTemp = mPtTopo;

            mPtTopo = mPtTopo->proximo;

            mTamanho--;

            delete noTemp;
        }
    }

    // Informa quantos valores existem na pilha.
    unsigned Tamanho() { return mTamanho; }

    // Retorna o valor que está no mPtTopo sem desempilhar.
    Dado Topo() const
    {
        if (mTamanho == 0)
        {
            std::cout << "Não foi possível retornar o topo!\n";
            return 0;
        }

        return mPtTopo->valor;
    }

    // Informa se a pilha está Vazia.
    bool Vazia() const
    {
        return mTamanho == 0;
    }
};

int main()
{
    Pilha pilha;
    Dado valor;
    char comando;
    do
    {
        std::cin >> comando;
        switch (comando)
        {
        case 'i': // inserir
            std::cin >> valor;
            pilha.Empilhar(valor);
            break;
        case 'r': // remover
            std::cout << pilha.Desempilhar() << std::endl;
            break;
        case 'l': // limpar tudo
            pilha.LimparTudo();
            break;
        case 't': // consultar tamanho
            std::cout << pilha.Tamanho() << std::endl;
            break;
        case 'e': // espiar
            std::cout << pilha.Topo() << std::endl;
            break;
        case 'f': // finalizar
            // checado no do-while
            break;
        default:
            std::cerr << "comando inválido\n";
        }
    } while (comando != 'f'); // finalizar execução
    while (not pilha.Vazia())
    {
        std::cout << pilha.Desempilhar() << ' ';
    }
    std::cout << std::endl;
    return 0;
}