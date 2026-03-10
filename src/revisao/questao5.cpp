/*
 Luthor irá mais uma vez tentar algo contra o Super-Homem. Dessa vez, ele irá tentar o plano XTPO-3000-PlusAzul. 
 Para isso, ele fez uma lista com os materiais necessários e verificou que alguns itens estavam em falta. Ele 
 tem uma relação em computador dos itens que precisa para a invenção e uma lista dos itens que tem em posse na sua 
 fábrica (alguns dos quais não serão necessários no plano, inclusive). Assim, ele precisa verificar quais itens da 
 primeira lista não constam na segunda lista para poder ir buscá-los em seu estoque no subsolo.

Para ajudá-lo, você irá implementar um algoritmo que recebe duas listas de materiais (dois vetores de strings) e imprime 
todos os itens que constam na primeira lista mas não constam na segunda lista. Os vetores devem ser implementados utilizando 
alocação dinâmica. A impressão deverá ser feita seguindo a ordem da primeira lista. Considere que os itens das listas não 
possuem espaço, cada lista contém o número de materiais no topo e que nenhuma lista possui itens repetidos na própria lista. 
Caso todos os itens da primeira lista estejam presentes na segunda, imprima NADA (todo em maiúsculo).

Entradas:

    1 - Número de ingredientes da primeira lista.
    2 - ingredientes (strings) da primeira lista, separados por espaço.
    3 - Número de ingredientes da segunda lista.
    4 - ingredientes (strings) da segunda lista, separados por espaço.

Saídas:

    1 - Elementos da lista resultante.

*/

#include <iostream>
#include <string>

using namespace std;

bool contemItem(string *lista, int tam, string item);

int main()
{
    string *listaA, *listaB, item;
    int tamA, tamB;

    cin >> tamA;

    listaA = new string[tamA];

    for (int i = 0; i < tamA; i++)
    {
        cin >> item;

        listaA[i] = item;
    }

    cin >> tamB;

    listaB = new string[tamB];

    for (int i = 0; i < tamB; i++)
    {
        cin >> item;

        listaB[i] = item;
    }

    cout << '\n';

    int cont = tamA;

    for (int i = 0; i < tamA; i++)
    {
        if (!contemItem(listaB, tamB, listaA[i]))
        {
            cout << listaA[i] << '\n';
        }
        else{
            cont--;
        }
    }

    if(cont == 0){
        cout << "NADA\n";
    }

    delete [] listaA;
    delete [] listaB;

    return 0;
}

bool contemItem(string *lista, int tam, string item)
{
    for (int i = 0; i < tam; i++)
    {
        if (lista[i] == item)
        {
            return true;
        }
    }

    return false;
}
