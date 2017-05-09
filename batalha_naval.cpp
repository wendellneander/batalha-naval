#include <iostream>
#include <cstring>
using namespace std;

// Variaveis
string campo[8][8];
char letras[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

// Prototipos
void desenha_campo();
void popula_campo();
void busca_posicao(int x, int y);

main(){
	
	popula_campo();
	desenha_campo();
	

}

void desenha_campo(){
	int x = 0;
	int y = 0;
	
	for(y=0;y<8;y++){
		for(x=0;x<8;x++){
			cout << campo[y][x];
		}
		cout << endl;
	}
}

void popula_campo(){
	int x = 0;
	int y = 0;
	
	for(y=0;y<8;y++){
		for(x=0;x<8;x++){
			if(y==0){
				campo[y][x] = letras[x];
			}else{
				campo[y][x] = "X";
			}
			
		}
	}
}

void busca_posicao(int x, int y){
	
}
