/*
Implemente uma pilha, utilizando armazenamento dos dados em arranjos (vetores). Segue esboço da implementação: 

        typedef int Dado; // para facilitar a troca de int para outro tipo
        
        // pilha implementada em arranjo 
        class pilhav {
            private:
                int capacidade;
                Dado *dados;
                int tamanho;
                int posTopo;
            public:
                pilhav(int cap = 100);
                ~pilhav();
                void empilha(Dado valor);
                Dado desempilha();
                Dado espia(); // acessa elemento do topo, mas não retira
                void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
                void info();  // imprime informações da pilha (tamanho e  posição do topo)
        };


    Não é necessário tratar problemas do tipo retirada de elemento de pilha vazia ou empilhamento em pilha cheia. A aplicação principal deverá criar uma pilha com capacidade para 20 elementos e realizar as seguintes operações na ordem apresentada:

    Empilhar cinco elementos
    Desempilhar três elementos (imprimindo-os)
    Empilhar mais quatro elementos
    Desempilhar três elementos (imprimindo-os)
    Imprime o topo da pilha, sem desempilhar (espia())
    Imprime os elementos restantes da pilha (depura())
    Imprime tamanho e posição do topo (info())


    Entradas:

    1 - Cinco valores a serem empilhados
    2 - Quatro valores a serem empilhados

    Saídas:

    1 - Três elementos desempilhados
    2 - Três elementos desempilhados
    3 - Topo da pilha
    4 - Elementos restantes da pilha
    5 - Tamanho e posição do topo
*/

#include <iostream>

using namespace std;

typedef int Dado;

class pilhav
{
private:
    int capacidade;
    int tamanho;
    int posTopo;
    Dado *dados;

public:
    pilhav(int cap)
    {
        capacidade = cap;
        tamanho = 0;
        posTopo = 0;
        dados = new Dado[capacidade];
    }

    ~pilhav()
    {
        delete[] dados;
    }

    void empilha(Dado valor)
    {
        dados[tamanho++] = valor;
        posTopo = tamanho - 1;
    }

    Dado desempilha()
    {
        tamanho--;
        return dados[posTopo--];
    }

    Dado espia()
    {
        Dado d = dados[posTopo];
        return d;
    }

    void depura()
    {
        for (int i = 0; i < tamanho; i++)
        {
            cout << dados[i] << ' ';
        }
        cout << '\n';
    }

    void info()
    {
        cout << tamanho << ' ' << posTopo << '\n';
    }
};

int main()
{
    pilhav pilha(20);
    int elemento;

    for (int i = 0; i < 5; i++)
    {
        cin >> elemento;
        pilha.empilha(elemento);
    }

    cout << pilha.desempilha() << ' ' << pilha.desempilha() << ' ' << pilha.desempilha() << '\n';

    for (int i = 0; i < 4; i++)
    {
        cin >> elemento;
        pilha.empilha(elemento);
    }

    cout << pilha.desempilha() << ' ' << pilha.desempilha() << ' ' << pilha.desempilha() << '\n';

    cout << pilha.espia() << '\n';

    pilha.depura();

    pilha.info();
    
    return 0;
}