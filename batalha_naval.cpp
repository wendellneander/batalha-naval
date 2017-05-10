#include <iostream>
#include <cstring>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Variaveis
const int CAMPO_LARGURA = 11;
const int QNT_EMBARCACOES = 4;
string campo[CAMPO_LARGURA][CAMPO_LARGURA];
string letras[10] = {"A ", "B ", "C ", "D ", "E ", "F ", "G ", "H ", "I ", "J "};
string numeros[10] = {"1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10"};

// Embarcacoes
struct ship {
	string tipo;
	int tamanho;
	string img[5];
};

ship submarino;
ship cruzador;
ship encouracado;
ship portaAvioess;
ship embarcacoes[QNT_EMBARCACOES];


// Prototipos
void desenha_campo();
void popula_campo();
void busca_posicao(int x, int y);
void cria_embarcacoes();
void inicia_embarcacoes();
int randInt(int intMax);

main(){
	
	popula_campo();
	desenha_campo();
	inicia_embarcacoes();
	cria_embarcacoes();

}

void desenha_campo(){
	system("cls");
	int x = 0;
	int y = 0;
	
	cout << endl << endl;
	for(y=0;y<CAMPO_LARGURA;y++){
		for(x=0;x<CAMPO_LARGURA;x++){
			cout << campo[y][x];
		}
		cout << endl;
	}
	cout << endl << endl;
}

void popula_campo(){
	int x = 0;
	int y = 0;
	
	for(y=0;y<CAMPO_LARGURA;y++){
		for(x=0;x<CAMPO_LARGURA;x++){
			if(y==0 && x==0){
				campo[y][x] = "  ";
			}else{
				if(y==0){
					campo[y][x] = letras[x - 1];
				}else if(y>0 && x == 0){
					campo[y][x] = numeros[y - 1];
				}else{
					if(campo[y][x] == "X " || campo[y][x] == NULL){
						campo[y][x] = "X ";
					}
				}
			}
		}
	}
}

void busca_posicao(int x, int y){
	
	if(campo[y+1][x+1] == "X "){
		cout << "Bomba :/" << endl;
	}else{
		cout << "Acertou!" << endl;
	}
	
}

void cria_embarcacoes(){
	
	for(int i=0;i<QNT_EMBARCACOES;i++){
		
		int inicioX = randInt(CAMPO_LARGURA - 1);
		int inicioY = randInt(CAMPO_LARGURA - 1);
		int lado;
		
		// Verifica se o ponto inicial da embarcacao esta vazio
		if(campo[inicioY][inicioX] == "X "){
			
			bool positive = true;
			
			// Verifica se tem espaco no campo para colocar a embarcacao
			// Verifica os campos para DIREITA
			for(int j=1; j<embarcacoes[i].tamanho; j++){
				if(campo[inicioY][inicioX + j] != "X "){
					positive = false;
				}
			}
			if(positive){
				lado = 0;
			}
			
			// Verifica os campos para ESQUERDA
			if(!positive){
				for(int j=1; j<embarcacoes[i].tamanho; j++){
					if(campo[inicioY][inicioX - j] != "X "){
						positive = false;
					}
				}
			}
			
			if(positive){
				lado = 1;
			}
			
			
			// Verifica os campos para CIMA
			if(!positive){
				for(int j=1; j<embarcacoes[i].tamanho; j++){
					if(campo[inicioY + j][inicioX] != "X "){
						positive = false;
					}
				}
			}
			
			if(positive){
				lado = 2;
			}
			
			// Verifica os campos para BAIXO
			if(!positive){
				for(int j=1; j<embarcacoes[i].tamanho; j++){
					if(campo[inicioY - j][inicioX] != "X "){
						positive = false;
					}
				}
			}
			
			if(positive){
				lado = 2;
			}
			
			if(positive){
				switch(lado){
					case 0:
						for(int y=1; y<embarcacoes[i].tamanho; y++){
							campo[inicioY][inicioX + 1] = embarcacoes[i].img[y];
						}
						desenha_campo();
						break;
					case 1:
						for(int y=1; y<embarcacoes[i].tamanho; y++){
							campo[inicioY][inicioX - 1] = embarcacoes[i].img[y];
						}
						desenha_campo();
						break;
					case 2:
						for(int y=1; y<embarcacoes[i].tamanho; y++){
							campo[inicioY + 1][inicioX] = embarcacoes[i].img[y];
						}
						desenha_campo();
						break;
					case 3:
						for(int y=1; y<embarcacoes[i].tamanho; y++){
							campo[inicioY - 1][inicioX + 1] = embarcacoes[i].img[y];
						}
						desenha_campo();
						break;
				}
				
				desenha_campo();
				cout << "E positivo\n";
				
			}else{
				cout << "Nao e positivo\n";
			}
			
			cout << "E vazio o primeiro\n";
		}else{
			cout << "Nao e vazio o primeiro\n";
		}
		
			
	}
	
}

void inicia_embarcacoes(){
	portaAvioess.tamanho = 5;
	portaAvioess.tipo = "portaAvioess";
	portaAvioess.img[0] = "P1";
	portaAvioess.img[1] = "P2";
	portaAvioess.img[2] = "P3";
	portaAvioess.img[3] = "P4";
	portaAvioess.img[3] = "P4";
	embarcacoes[3] = submarino;
	
	
	encouracado.tamanho = 4;
	encouracado.tipo = "encouracado";
	encouracado.img[0] = "E1";
	encouracado.img[1] = "E2";
	encouracado.img[2] = "E3";
	encouracado.img[3] = "E4";
	embarcacoes[2] = submarino;
	
	cruzador.tamanho = 2;
	cruzador.tipo = "cruzador";
	cruzador.img[0] = "C1";
	cruzador.img[1] = "C2";
	embarcacoes[1] = submarino;
	
	submarino.tamanho = 1;
	submarino.tipo = "submarino";
	submarino.img[0] = "S ";
	embarcacoes[0] = submarino;
	
}

int randInt(int intMax){
    srand(time(NULL));
    return rand() % (intMax+1);
}



