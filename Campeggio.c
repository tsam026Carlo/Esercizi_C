#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
typedef struct casa{
	char * anagrafica;
	char * data_entrata;
	char * data_uscita;
}casa_t; 

casa_t prenotazioni[15];

void allocaContratto(casa_t * elemento1){
	elemento1->anagrafica= (char*) malloc(100*sizeof(char));
	elemento1->data_entrata= (char*) malloc(10*sizeof(char));
	elemento1->data_uscita= (char*) malloc(10*sizeof(char));
}

void inserimento(casa_t * elemento1 , casa_t * elemento2){
	strcpy(elemento1->anagrafica,elemento2->anagrafica);
	strcpy(elemento1->data_entrata,elemento2->data_entrata);
	strcpy(elemento1->data_uscita,elemento2->data_uscita);
}

void pagamento(){
	int vNumeroPersone=1, vGiorniTrascorsi;
	char vModuloAbitativo, vModuloDiViaggio;
	float vCalcAbitazione, vCalcVeicolo;
	float vRisultato=4;
	printf("quanti giorni ti sei fermato\n");
	scanf(" %i", &vGiorniTrascorsi);
		
	printf("quanti civili hanno occupato il modulo abitativo \n");
	scanf(" %i", &vNumeroPersone);
	
	printf("dove hai vissuto? (t:tenda r:rulot)\n");
	scanf(" %c",&vModuloAbitativo);
	
	printf("qual'e' il tuo modulo di viaggio?(m:moto a:auto)'\n");
	scanf(" %c",&vModuloDiViaggio);

	if(vModuloAbitativo=='t'){
			vCalcAbitazione = 4;
	}
	else if(vModuloAbitativo=='r'){
			vCalcAbitazione = 4.5;
	}
	else{
			vCalcAbitazione = 1;

	}
	
	if(vModuloDiViaggio=='m'){
			vCalcVeicolo = 5.5;
	}
	else if(vModuloDiViaggio=='a'){
			vCalcVeicolo = 3.5;
	}
	else{
			vCalcVeicolo = 1;

	}
	vRisultato = (vCalcVeicolo+vCalcAbitazione+vNumeroPersone)*vGiorniTrascorsi;
	printf("devi pagare: %f ", vRisultato);
	
}

void ins_prenotazioni(){
	casa_t nuovo;
	allocaContratto(&nuovo);
	
	printf("come ti chiami?\n");
	scanf(" %100[0-9a-zA-Z ]" ,&nuovo.anagrafica[0]);
	
	printf("inizi che giorno?(gg/mm/aaaa)\n");
	scanf(" %s",&nuovo.data_entrata[0]);
	
	printf("finisci che giorno?(gg/mm/aaaa)\n");
	scanf(" %s",&nuovo.data_uscita[0]);
	
	printf("%s\n",nuovo.anagrafica);
	
	int i;
	for(i=0; i<15; i++){
		if(prenotazioni[i].anagrafica == NULL){
			allocaContratto(&prenotazioni[i]);
			inserimento(&prenotazioni[i],&nuovo);
			break;
		}
		
	    int compare = strcmp(nuovo.anagrafica,prenotazioni[i].anagrafica);
		if(compare<0){
			casa_t _tmp;
			allocaContratto(&_tmp);
			inserimento(&_tmp, &prenotazioni[i]);
			inserimento(&prenotazioni[i],&nuovo);
			inserimento(&nuovo , &_tmp);
		}
	}
	
	printf("inserito con successo\n");
}

void let_prenotazioni(){
	int i=0;
	for(i=0; i<15; i++){
		if(prenotazioni[i].anagrafica == NULL){
			break;
		}
		printf("[%d] = %s\t %s \t %s \n",i,prenotazioni[i].anagrafica, prenotazioni[i].data_entrata, prenotazioni[i].data_uscita);
	}
}

void prenotazionii(){
	int scelta=0;
	printf("MENU'\n1:inserimento prenotazione\n2:lettura stack\n3:uscita\nSCELTA: ");
	scanf("%d", &scelta);
	switch (scelta){
		case 1:{
			ins_prenotazioni();
			break;
		}
		case 2:{
			let_prenotazioni();
			break;
		}
		case 3:{
			break;
		}
		default:{
			printf("errore nella scelta\n");
			break;
		}
	}
}

int main(){
	int scelta;
	int uscita=0;
	while(uscita==0){
		printf("MENU'\n1:pagamento uscita\n2:prenotazioni casette\n3:uscita\nSCELTA: ");
		scanf("%d",&scelta);
		switch(scelta){
			case 1:{
				pagamento();
				break;
			}
			case 2:{
				prenotazionii();
				break;
			}
			case 3:{
				uscita=1;
				break;
			}
			default:{
				printf("errore nella scelta\n");
				break;
			}
		}
		system("pause");
		system("cls");
	}
	
	return 0;
}
