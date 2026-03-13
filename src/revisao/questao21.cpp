/*
Faça um programa que leia de um arquivo tipado cujo nome é "menor.bin" um vetor, alocado dinamicamente,
de 10 números reais e determina, de forma recursiva, o menor elemento. O arquivo não tem cabeçalho.

Podemos usar a seguinte ideia:

    O menor elemento de um vetor de uma única posição é o seu único elemento.
    O menor elemento de um vetor de mais de uma posição é o menor entre o primeiro elemento e o menor do restante do vetor.

Entradas:

    10 números reais (float) a serem lidos do arquivo "menor.bin".

Saídas

    Menor valor lido.
*/

#include <iostream>
#include <fstream>
#include <climits>

float menor(float *nums, int tam);

int main()
{
    float *nums = new float[10];

    std::ifstream arq("arquivos/menor.bin", std::ios::binary);

    if (!arq)
    {
        return -1;
    }

    for (int i = 0; i < 10; i++)
    {
        arq.read((char *)&nums[i], sizeof(float));
    }

    std::cout << menor(nums, 10) << '\n';

    arq.close();
    delete[] nums;

    return 0;
}

float menor(float *nums, int tam)
{
    if (tam == 1)
    {
        return nums[0];
    }

    float m = menor(nums, tam - 1);

    return (nums[tam - 1] < m) ? nums[tam - 1] : m;
}
