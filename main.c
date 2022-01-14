#include <stdio.h>
#include <stdlib.h>

char X_O[3][3];
void desenho(),jogador(),condicao();
int jogadores[2], jogadas=5;
int vez=0;
int x=0;

int main(void) {
	jogadores[vez]=1;

	
	/*X_O[0][0]='X';
	X_O[1][1]='X';
	X_O[0][2]='X';
	//X_O[0][1]='O';

	desenho();
	if(X_O[0][0]==X_O[1][1]==X_O[2][2]){
		printf("funcionou");
	}else{
		printf("erro");
	}*/
	//condicao();
	for(x=0 ; x <= 9 ; x++){
		X_O[0][0]='O';
		X_O[1][2]='O';
		X_O[1][1]='X';
		X_O[2][0]='X';

		system("clear");//só funciona em linux
		desenho();
		condicao();
		jogador();
	}

	//system("clear");//só funciona em linux	
  return 0;
}

void desenho(){
	printf("\nPara colocar 'X' e o 'O' onde quer coloca é preciso localizar com as linha e colunas com números, começando do 1 e indo até 3, espero que tenha entendido e bom jogo.\n\n");
	for(int x = 0 ; x <= 2 ; x++){
		for(int y = 0 ; y <= 2 ; y++){
			if(y==2 && x==2){
				printf("  %c \n\n",X_O[x][y]);
			}
			else if(x==0 && y==0){
				printf("     %d     %d     %d\n\n1    %c  |",x+1,x+2,x+3,X_O[x][y]);
			}
			else if(y==0 && x!=0){
				printf("%d    %c  |",x+1,X_O[x][y]);
			}
			else if(y==2){
				printf("  %c \n   -----|-----|-----\n",X_O[x][y]);
			}
			else{
				printf("  %c  |",X_O[x][y]);
			}
		}
	}		
}
void jogador(){
	int linha,coluna;
	printf("Vez do jogador %d\n\n",jogadores[vez]);
	printf("Escolha a linha: ");
	scanf("%d",&linha);
	printf("Escolha a coluna: ");
	scanf("%d",&coluna);
	if(linha<=3 && coluna<=3){
		if(jogadores[vez]==1){
			if(X_O[linha-1][coluna-1]==' '){
				X_O[linha-1][coluna-1]='X';
				vez++;
				jogadas++;
			}
		}else{
			if(X_O[linha-1][coluna-1]==' '){
				X_O[linha-1][coluna-1]='O';
				vez--;
				jogadas++;
			}
		}
	}else{
		printf("Erro Valor invalido !!!\n");
		setbuf(stdin,NULL);
		getchar();

	}
}
void zerar(){
	x=0;
	for(int x = 0 ; x <= 2 ; x++){//adicionar valores padrão
				for(int y = 0 ; y <= 2 ; y++){
					X_O[x][y]=' ';
				}
			}
}
void condicao(){
	if(jogadas>3){
		
		int num=0;
		for(int x=0 ; x < 3 ; x++){		
			if( (X_O[x][0]!=' ' && X_O[x][0] == X_O[x][1] && X_O[x][0]== X_O[x][2]) 
			||(X_O[0][x]!=' ' && X_O[0][x] == X_O[1][x] && X_O[0][x]== X_O[2][x])
			||(X_O[0][0]!=' ' && X_O[0][0] == X_O[1][1] && X_O[0][0]==X_O[2][2])
			||(X_O[1][1]!=' ' && X_O[0][2] == X_O[1][1] && X_O[1][1]== X_O[2][0])){
				if(vez==1){
					printf("\nParabéns Jogador 1\n");
					exit(0);
				}else{
					printf("\nParabéns Jogador 2\n");
					exit(0);
				}
			}
		}
	}if(jogadas==9 || x==0){
		if(x==0){
			zerar();
		}else{
			int o;
			int cond;
			do{
				printf("Deu Velha !!!\n \nDeseja jogar de novo (se sim digite[1] se não digite[0]): ");
				scanf("%d",&o);
				switch(o){
					case 1:
						zerar(); 
						cond=0;
					break;
					case 0: exit(0);
					break;
					default : 
						printf("\nValor errado\n");
						cond=1;
				}
			}while(cond);
		}
	}
}
