/*
De acordo com a geometria básica, podemos definir três figuras simples: um círculo, um triângulo e um retângulo. 
A dimensão de um círculo é basicamente representada pelo seu raio, um retângulo necessita de dois parâmetros, base e altura, 
e um triângulo é representado por três valores, um para cada um de seus lados. Munido dessas informações, pode-se calcular o 
perímetro e a área de qualquer uma dessas figuras citadas utilizando o método matemático correto.

Faça um programa que, referente a essas 3 figuras geométricas, receba as informações de 5 figuras quaisquer do usuário, sendo 
que cada figura será composta pelo tipo dela (adotando uma nomenclatura 'C' 'R' 'T' para identificá-las) além de, de acordo com a 
figura indicada, receber os parâmetros geométricos que as representam (suas dimensões). Por fim, exibir o nome, a área e o perímetro 
de cada uma dessas 5 figuras fornecidas pelo usuário.

Obs.: As figura devem ser identificadas por um caracter da seguinte maneira:

    'C' = Círculo (parâmetro: raio)
    'R' = Retângulo (parâmetros: base e altura)
    'T' = Triângulo (parâmetros: 3 lados - podendo ser diferentes)

Obs.: Para o valor de PI utilize a constante M_PI disponível na biblioteca cmath.

Sugestão: O cálculo da área de um triângulo pode ser feito através do Teorema de Herão.

Entrada:

    Um caracter representando o tipo da figura geométrica.
    Os valores de suas dimensões (raio, lado, etc.) em ponto flutuante (float).

Saída:

    Nome da figura geométrica.
    Perímetro da figura.
    Área da figura.

*/


#include <iostream>
#include <cmath>

struct figura
{
    std::string nomenclatura;
    float perimetro;
    float area;
};

int main()
{
    figura fig[5];

    for (int i = 0; i < 5; i++)
    {
        char tipofigura;
        std::cin >> tipofigura;

        if (tipofigura == 'C')
        {
            float raio;
            std::cin >> raio;

            fig[i].nomenclatura = "Circulo";
            fig[i].area = raio * raio * M_PI;
            fig[i].perimetro = 2 * M_PI * raio;
        }
        else if (tipofigura == 'T')
        {
            float ladoA, ladoB, ladoC;

            std::cin >> ladoA;
            std::cin >> ladoB;
            std::cin >> ladoC;

            float p = (ladoA + ladoB + ladoC) / 2.0;

            fig[i].nomenclatura = "Triangulo";
            fig[i].area = sqrt(p * (p - ladoA) * (p - ladoB) * (p - ladoC));
            fig[i].perimetro = ladoA + ladoB + ladoC;
        }
        else if (tipofigura == 'R')
        {
            float base, altura;
            std::cin >> base;
            std::cin >> altura;

            fig[i].nomenclatura = "Retangulo";
            fig[i].area = base * altura;
            fig[i].perimetro = (base + altura) * 2;
        }
    }

    for (figura f : fig)
    {
        std::cout << f.nomenclatura << " " << f.perimetro << " " << f.area << '\n';
    }

    return 0;
}