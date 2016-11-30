#include<stdio.h>
#include<time.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct nodo {
    int soldi;
    char movimento;
    struct nodo * next;
} nodo_t;

int contoCorrente = 10000;
nodo_t * head = NULL;


int generaPin(){
	srand(time(NULL));
	int r = rand()%(899)+100; 
}

void MovimentoEffettuato(char amovimento,int asoldi)
{	
	if(head==NULL)
	{
		head = malloc(sizeof(nodo_t));
		head->soldi=asoldi;
		head->movimento=amovimento;
		head->next=NULL;
	}else{
		nodo_t * tmp;
		tmp= malloc(sizeof(nodo_t));
		tmp->soldi=asoldi;
		tmp->movimento=amovimento;
		tmp->next=head;
		head=tmp;
	} 
}
void Preleva(){
	int valuta=0;
	int PIN=generaPin();
	int controlloPin=0;
	bool control;
	while(true){
		printf("Quanto vuoi prelevare: ");
		scanf("%d",&valuta);
		if(valuta>contoCorrente){
			printf("Mi dispiace non hai tutti questi soldi\n");
		}
		else{
			break;
		}
		
	}
	printf("conferma la transazione con il seguente pin:(%d)",PIN);
	scanf("%d",&controlloPin);
	control=true;
	while(control){
		if(controlloPin==PIN){
			MovimentoEffettuato('O',valuta);
			contoCorrente-=valuta;
			control=false;
		}
		else{
			PIN=generaPin();
			printf("errore, riprovare con il seguente pin:(%d)",PIN);
			scanf("%d",&controlloPin);			
		}
	}
	printf("Transazione avvenuta, il conto ora contiene: %d\n",contoCorrente);
}
void Deposita(){
	int valuta=0;
	int PIN=generaPin();
	int controlloPin=0;
	bool control;
	printf("Quanto vuoi depositare: ");
	scanf("%d",&valuta);
	printf("conferma la transazione con il seguente pin:(%d)",PIN);
	scanf("%d",&controlloPin);
	control=true;
	while(control){
		if(controlloPin==PIN){
			MovimentoEffettuato('I',valuta);
			contoCorrente+=valuta;
			control=false;
		}
		else{
			PIN=generaPin();
			printf("errore, riprovare con il seguente pin:(%d)",PIN);
			scanf("%d",&controlloPin);			
		}
	}
	printf("Transazione avvenuta, il conto ora contiene: %d\n",contoCorrente);
	
}
void Movimenti(){
	nodo_t * tmp = head;
	while(tmp!=NULL){
		printf("Movimento: %c Soldi:%d \n",tmp->movimento,tmp->soldi);
		tmp=tmp->next;
	}
	
}
void SaldoConto(){
	printf("il tuo saldo conto risulta essere: %d\n",contoCorrente);
}
void EstrattoConto(){
	int scelta;
	printf("opzioni per Estratto Conto:\n1.Movimenti\n2.Saldo conto\n3.indietro\nScelta: ");
	scanf("%d",&scelta);	
	switch(scelta){
		case 1:{
			Movimenti();
			break;
		}
		case 2:{
			SaldoConto();
			break;
		}
		case 3:{
			break;
		}
		default:{
			printf("errore nella scelta, reindirizzo in home...\n");
			break;
		}
	}
}
int main(){
	head = NULL;
	bool exit = true;
	Beep(1000,400);
	Beep(800,200);
	Beep(600,300);
	Beep(1000,200);
	Beep(800,400);
	
	while(exit){
		int scelta=0;
		printf("Menu:\n1.Preleva\n2.Deposita\n3.Saldo Conto\n4.Esci\nScelta: ");
		scanf("%d",&scelta);
		switch(scelta){
			case 1:{
				Preleva();
				break;
			}	
			case 2:{
				Deposita();
				break;
			}
			case 3:{
				EstrattoConto();
				break;
			}
			case 4:{
				exit=false;
				break;
			}
			default:{
				printf("Scelta non valida\n");
				break;
			}
		}
		system("pause");
		system("cls");
	}
}
