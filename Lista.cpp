#include <stdio.h>
#include <stdlib.h>

#define MAX 50 
typedef int TIPOCHAVE;
int nroElem;

typedef struct{
	TIPOCHAVE matricula;
	float salario;
}REGISTRO;

typedef struct{
	REGISTRO X[MAX];
	int nroElem;
} LISTA;

void inicializarLista(LISTA* L);
int tamanho(LISTA* L);
void exibirLista(LISTA* L);
int buscaSequencial(LISTA* L, TIPOCHAVE matricula);
bool inserirElemLista(LISTA* L, REGISTRO reg, int i);
bool excluirElemLista(TIPOCHAVE matricula, LISTA* L);
void reinicializarLista(LISTA* L);
bool inserirElemInicio(LISTA* L, REGISTRO reg, int i);
bool inserirElemFim(LISTA* L, REGISTRO reg);
REGISTRO novoRegistro();

int main(){
	int op = 0, posicaoNaLista, tamanhoDaLista, localizacao;
	TIPOCHAVE matricula;
	bool inserido = true;
	bool exclusao = false;
	char resposta;
	LISTA listaDeProducao;
	LISTA* enderecoLista = &listaDeProducao;
	REGISTRO novo_reg;
		
		
		do{
			
			printf("----------------------------------------------------\n");
			printf("Selecione uma opcao\n");
			printf("---------------------------------------------------\n");
			printf("1 - Inicializar Lista\n");
			printf("2 - Exibir tamanho da lista\n");
			printf("3 - Exibir lista\n");
			printf("4 - Localizar elemento na Lista\n");
			printf("5 - Inserir elemeno na lista em posicao especifica\n");
			printf("6 - Excluir elemento especifico da Lista\n");
			printf("7 - Reiniciar Lista\n");
			printf("8 - Inserir elemento no inicio da lista\n");
			printf("9 - Inserir elemento no fim da lista\n");
			
			
			scanf("%i", &op);
			
			
			
			switch(op)
			{
				case 1: 
					inicializarLista(enderecoLista);
					printf("Lista iniciada!!! \n");
				break;
				case 2: tamanhoDaLista = tamanho(enderecoLista);
				if (tamanhoDaLista == 1){
					printf("A lista tem %i registro! \n", tamanhoDaLista);
				}else
					printf("A lista tem %i registros!! \n", tamanhoDaLista);
				break;
				case 3: exibirLista(enderecoLista);
				break;
				case 4: printf("Qual matricula esta buscando? \n");
				scanf("%i", &matricula);
				
				localizacao = buscaSequencial(enderecoLista, matricula);
			
				if (localizacao == -1){
					printf("Nao a registro!\n");
				}else
					printf("Registro localizado na posicao %i \n", localizacao);
				break;
				case 5: printf("Onde deseja posicionar seu elemento?\n");
						scanf("%i", &posicaoNaLista);
						
						novo_reg = novoRegistro();
						
						inserido = inserirElemLista(enderecoLista, novo_reg, posicaoNaLista);
						
						if(inserido == true){
							printf("Registrado com sucesso!\n");
						}else
						printf("Registro nao realizado!\n");
						break;
				case 6: printf("Qual matricula sera excluida?\n");
						scanf("%i", &matricula);
					 	
						exclusao = excluirElemLista(matricula, enderecoLista);
					
						if(exclusao == true){
							printf("Excluido com sucesso\n");
						}else
							printf("Registro inexistente\n");
						break;
						 
				case 7: reinicializarLista(enderecoLista);
					printf("Reiniciada com sucesso!\n");
				break;
				case 8: printf("valor à ser inserido no inicio da lista: \n");
				posicaoNaLista=0;
				
				novo_reg = novoRegistro();
				
				inserido = inserirElemInicio(enderecoLista, novo_reg, posicaoNaLista);
						
				if(inserido == true){
					printf("Registro inserido com sucesso!! \n");
				}else 
					printf("Registro nao inserido! \n");
				break;
				case 9: printf("O valor sera inserido no final da lista.\n");
				printf("____________________________________________\n");
				posicaoNaLista = tamanho(enderecoLista);
				
				novo_reg = novoRegistro();
				
				inserido = inserirElemInicio(enderecoLista, novo_reg, posicaoNaLista);
				
				if (inserido == true){
					printf("Registro inserido com sucesso!!\n");
				} else 
					printf("Registro nao inserido!\n");
				
				break;
				break;
				default: printf("Opção Invalida!!!");
			}
			printf("Deseja continuar? s - SIM, n - NAO!!! \n");
			scanf("%s", &resposta);
			system("cls");
		}while(resposta=='s');
		
}

REGISTRO novoRegistro(){
	float salario;
	int matricula;
	
	printf("Digite o salario: \n");
	scanf("%f", &salario);
				
	printf("Digite uma chave: \n");
	scanf("%i", &matricula);
	
	REGISTRO novo_reg;
	novo_reg.salario = salario;
	novo_reg.matricula = matricula;
	
	return novo_reg;
}


void inicializarLista(LISTA* L){
	L->nroElem = 0;
	printf("lista inicializada\n");
}

int tamanho(LISTA* L){
	return L->nroElem; 
}

void exibirLista(LISTA* L) {
	
	int i;
	
	
	if(L->nroElem == 0){
		printf("A lista esta vazia \n");
	}
	else{
	
	
	for(i = 0; i < L->nroElem; i++) {
		printf("%i ", L->X[i].matricula);
	}
	printf("\"\n");
}

}
int buscaSequencial(LISTA* L, TIPOCHAVE matricula){
	int i = 0;
	while(i < L->nroElem){
		if(matricula == L->X[i].matricula) return i;
			
		else i++;
	}
	return -1;
}

bool inserirElemInicio(LISTA* L, REGISTRO reg, int i){
int j;

if((L->nroElem == MAX) || (i < 0) || (i > L->nroElem)){
	return false;
}
 for(j = L->nroElem; j > i; j--) L->X[j] = L->X[j-1];
 L->X[i] = reg;
 L->nroElem++;
 return true;
}

bool inserirElemLista(LISTA* l, REGISTRO reg, int i){
int j;
	if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
return false;
for (j = l->nroElem; j > i; j--) l->X[j] = l->X[j-1];
	l->X[i] = reg;
	l->nroElem++;
return true;
}


bool excluirElemLista(TIPOCHAVE matricula, LISTA* L) {
int pos, j;

	pos = buscaSequencial(L, matricula);
	printf("%i ", buscaSequencial(L, matricula));
	printf("%i ", pos);

	if(pos == -1){
	 
		return false;
		}
		
for(j = pos; j < L->nroElem-1; j++){


L->X[j] = L->X[j+1];

}
L->nroElem--;




return true;

}

void reinicializarLista(LISTA* L) {
L->nroElem = 0;
}


	
	


