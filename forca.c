#include <stdio.h>

void jogoDuo() {
	char palavra[46], adivinha[46], resultados[46];
	short int tentativas = 5; //numero de tentativas

	for (short int i = 0; i <= 45; i++) { //inicializacao de variaveis
		palavra[i] = '\0';
		adivinha[i] = '\0';
		resultados[i] = '\0';
	}

	printf("Escreva a palavra a adivinhar:\n"); //pedir palavra a ser adivinhada
	scanf("%s", &palavra); //ler palavra a ser adivinhada

	for (short int i = 0; i <= 45; i++) { //inicializar os resultados
		if (palavra[i] != '\0') {
			resultados[i] = '_';
		}
		else {
			break;
		}
	}

	while (tentativas > 0) { //comecar o jogo
		short int acertou = 0, fim = 0;
		printf("\n%s\nTentativas:%d\nFaca a sua adivinha:\n", resultados, tentativas); //pedir tentativa
		scanf("%s", &adivinha); //ler tentativa

		if (adivinha[1] == '\0') { //verificar se a tentativa se trata de uma letra ou de uma palavra
			for (short int i = 0; i <= 45; i++) { //caso seja uma unica letra
				if (palavra[i] == adivinha[0]) {
					acertou = 1;
					resultados[i] = adivinha[0]; //colocar as letras presentes na palavra no conjunto de resultados
				}
			}
		}
		else { //caso seja uma palavra
			acertou = 1;
			for (short int i = 0; i <= 45; i++) {
				if(adivinha[i] != palavra[i]) { //verificar se as letras da palavra correspondem as da adivinha
					acertou = 0; //caso alguma delas nao corresponda parar o ciclo
				}
			}
			if (acertou == 1) { //caso todas as letras correspondam
				for (short int j = 0; j <= 45; j++) { //colocar nos resultados
					resultados[j] = adivinha[j];
				}
			}
		}
		if (acertou == 1) { //se tiver acertado numa letra ou na palavra
			fim = 1;
			for (short int i = 0; i <= 45; i++) {
				if (palavra[i] != resultados[i]) { //caso alguma letra nos resultados seja diferente da palavra
					for (short int j = 0; j <= 45; j++) {
						printf("%c", palavra[j]);
					}
					fim = 0; //o jogo nao se termina
					break; //o ciclo acaba
				}
			}
		}
		else { //caso nao tenha acertado numa letra ou na palavra
			tentativas--; //retirar turno
		}
		if (fim == 1) { //caso o jogo tenha terminado
			printf("GANHOU!");
			break; //terminar o ciclo do jogo
		}
	}
	if (tentativas == 0) { //caso o numero de tentativas seja 0
		printf("Perdeu");
	}

	return; //retornar jogoDuo
}

int jogoSolo() {
	char palavra[46], adivinha[46], resultados[46];
	short int tentativas = 5; //numero de tentativas

	for (short int i = 0; i <= 45; i++) { //inicializacao de variaveis
		palavra[i] = '\0';
		adivinha[i] = '\0';
		resultados[i] = '\0';
	}

	printf("Escreva a palavra a adivinhar:\n"); //pedir palavra a ser adivinhada
	scanf("%s", &palavra); //ler palavra a ser adivinhada

	for (short int i = 0; i <= 45; i++) { //inicializar os resultados
		if (palavra[i] != '\0') {
			resultados[i] = '_';
		}
		else {
			break;
		}
	}

	while (tentativas > 0) { //comecar o jogo
		short int acertou = 0, fim = 0;
		printf("\n%s\nTentativas:%d\nFaca a sua adivinha:\n", resultados, tentativas); //pedir tentativa
		scanf("%s", &adivinha); //ler tentativa

		if (adivinha[1] == '\0') { //verificar se a tentativa se trata de uma letra ou de uma palavra
			for (short int i = 0; i <= 45; i++) { //caso seja uma unica letra
				if (palavra[i] == adivinha[0]) {
					acertou = 1;
					resultados[i] = adivinha[0]; //colocar as letras presentes na palavra no conjunto de resultados
				}
			}
		}
		else { //caso seja uma palavra
			acertou = 1;
			for (short int i = 0; i <= 45; i++) {
				if(adivinha[i] != palavra[i]) { //verificar se as letras da palavra correspondem as da adivinha
					acertou = 0; //caso alguma delas nao corresponda parar o ciclo
				}
			}
			if (acertou == 1) { //caso todas as letras correspondam
				for (short int j = 0; j <= 45; j++) { //colocar nos resultados
					resultados[j] = adivinha[j];
				}
			}
		}
		if (acertou == 1) { //se tiver acertado numa letra ou na palavra
			fim = 1;
			for (short int i = 0; i <= 45; i++) {
				if (palavra[i] != resultados[i]) { //caso alguma letra nos resultados seja diferente da palavra
					for (short int j = 0; j <= 45; j++) {
						printf("%c", palavra[j]);
					}
					fim = 0; //o jogo nao se termina
					break; //o ciclo acaba
				}
			}
		}
		else { //caso nao tenha acertado numa letra ou na palavra
			tentativas--; //retirar turno
		}
		if (fim == 1) { //caso o jogo tenha terminado
			printf("GANHOU!");
			break; //terminar o ciclo do jogo
		}
	}
	if (tentativas == 0) { //caso o numero de tentativas seja 0
		printf("Perdeu");
	}

	return; //retornar
}

int main() { //teste
	int repetir = 0;
	do {
		short int escolha;
		do {
			printf("Opcoes de jogo:\n(1)Jogar Sozinho\n(2)Jogar Com Um Amigo\n(3)Sair\n");
			scanf("%d", &escolha);
		} while(escolha>=4 || escolha<=0);
		if(escolha==1){
			printf("\nnao feito");
			//jogoSolo();
		}
		else if(escolha==2){
			jogoDuo();
		}
		else {
			break;
		}
		printf("\nVoltar a Jogar?\n(1)Sim\n(2)Nao\n");
		scanf("%d", &repetir);
		if(repetir == 2) {
			break;
		}
	} while(repetir != 0);

	return 0;
}
