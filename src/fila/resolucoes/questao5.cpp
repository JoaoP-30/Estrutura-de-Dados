/*
Implemente uma estrutura do tipo fila com as operações básicas de inserção e remoção. Com a estrutura 
implementada, faça um programa que utilize a fila para gerar números binários de 1 a N. O trecho a seguir 
dá uma dica de como resolver o problema:

	inicio = "1"
	enfileira (inicio) // fila = (1)
	laço
		enfileira(inicio + “0”) // fila = (1, 10)
		enfileira(inicio + “1”) // fila(1, 10, 11)
		elemento = desenfileira() 
	fim  do laço


	Note que como cada passo do laço enfileira por padrão dois elementos, você precisará inserir um controle 
	adicional no laço ou na impressão para evitar enfileirar um elemento a mais, dependendo da entrada.

Entradas:

    Número inteiro positivo representando N

Saídas:

    Números binários gerados de 1 a N
*/

#include <iostream>
#include <string>

typedef std::string T;

struct No{
	T valor;
	No* proximo;
};

class Fila{
private:
	No *primeiro;
	No *ultimo;
	int tamanho;

public:
	Fila(){
		primeiro = NULL;
		ultimo = NULL;
		tamanho = 0;
	}

	~Fila(){
		while(!vazio()){
			remove();
		}
	}

	bool vazio(){
		return tamanho == 0;
	}

	void adiciona(T valor){
		No *n = new No;
		n->valor = valor;
		n->proximo = NULL;

		if(primeiro == NULL){
			primeiro = n;
		}
		else{
			ultimo->proximo = n;
		}

		ultimo = n;

		tamanho++;
	}

	T remove(){
		No *n = primeiro;
		T valor = n->valor;
		primeiro = primeiro->proximo;

		if(primeiro == NULL){
			ultimo = NULL;
		}

		delete n;
		tamanho--;
		return valor;
	}

	int getTamanho(){
		return tamanho;
	}

};

int main(){
	Fila f1;
	int N;
	std:: cin >> N;

	f1.adiciona("1");

	for(int i = 0; i < N; i++){
		std::string primeiro = f1.remove();

		std::cout << primeiro << ' ';

		if(i + f1.getTamanho() < N){
			f1.adiciona(primeiro + '0');
		}

		if(i + f1.getTamanho() < N){
			f1.adiciona(primeiro + '1');
		}
	}

	std::cout << '\n';
	return 0;
}