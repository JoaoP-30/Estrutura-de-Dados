/*
Suponha que um dado problema requer o uso de duas pilhas (identificadas pelo números 1 e 2), 
onde cada pilha suporta no máximo 50 elementos e em nenhum momento as duas pilhas terão juntas 
mais do que os mesmos 50 elementos. Sendo assim, é possível implementar as duas pilhas em um único 
vetor usando apenas 50 posições ao invés de 100. Utilizando a estrutura sugerida no código fornecido, 
implemente as operações de empilhar() e desempilhar(). As operações de empilhar (identificada pela letra E) 
e desempilhar (identificada pela letra D) devem ser descritas da seguinte forma:

    Operação a ser realizada, seguida da identificação da pilha. No caso da operação empilhar, deve ser informado, ainda, o 
    dado a ser armazenado. T é usado para terminar o programa.

Utilize um arranjo de 50 posições para armazenar estas duas pilhas.

    Caso seja solicitada uma operação de desempilhar e a respectiva pilha esteja vazia, deve ser impressa a palavra "VAZIA".
    Caso seja solicitada a inserção de mais de 50 elementos em uma das pilha, deve ser impressa a palavra "INVALIDO" (sem acentos).

Obs: sinta-se a vontade para modificar o código caso prefira utilizar outra estrutura. A única restrição 
é que as duas pilhas devem ser armazenadas em um mesmo ARRANJO de 50 posições.

Dica: utilize o início do arranjo para armazenar uma das pilhas e final do arranjo para armazenar a outra pilha.

Entradas:

    Conjunto de operações de inserção e remoção de dados em cada uma das pilhas

Saídas:

    Resultado das remoções em cada uma das pilhas.
*/

#include <iostream>

using namespace std;

class pilhaDupla
{
private:
    int topo1;
    int topo2;
    int tamanho1;
    int tamanho2;
    int dados[50];

public:
    pilhaDupla()
    {
        tamanho1 = 0;
        topo1 = -1;
        tamanho2 = 0;
        topo2 = 50;
    }

    // Método retorna true por padrão
    bool vazia(int escolha)
    {
        if (escolha == 1)
        {
            return tamanho1 == 0;
        }

        if (escolha == 2)
        {
            return tamanho2 == 0;
        }

        return true;
    }

    void empilha(int escolha, int elemento)
    {
        if ((tamanho1 + tamanho2) == 50)
        {
            cout << "INVALIDO\n";
            return;
        }

        if (escolha == 1)
        {
            dados[++topo1] = elemento;
            tamanho1++;
            return;
        }

        if (escolha == 2)
        {
            dados[--topo2] = elemento;
            tamanho2++;
            return;
        }
    }

    // Método retorna 0 por padrão
    int desempilha(int escolha)
    {
        if (escolha == 1)
        {
            tamanho1--;
            return dados[topo1--];
        }

        if (escolha == 2)
        {
            tamanho2--;
            return dados[topo2++];
        }

        return 0;
    }
};

int main()
{

    pilhaDupla PP;
    char opcao;
    int escolha;
    int valor;

    do
    {
        cin >> opcao;
        switch (opcao)
        {
        case 'E':
            cin >> escolha >> valor;
            PP.empilha(escolha, valor);
            break;
        case 'D':
            cin >> escolha;
            if (PP.vazia(escolha))
                cout << "VAZIA" << endl;
            else
                cout << PP.desempilha(escolha) << "\n";
            break;
        }
    } while (opcao != 'T');

    return 0;
}