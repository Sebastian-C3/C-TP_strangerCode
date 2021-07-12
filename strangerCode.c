#include <stdio.h>

const float MULTIPLICADOR_CONFIANZA_BAJA = 0.7;
const float MULTIPLICADOR_CONFIANZA_MEDIA = 1.3;
const float MULTIPLICADOR_CONFIANZA_ALTA = 3.7;
const int ANIMO_MIN = 1;
const int ANIMO_MAX = 100;
const int CONFIANZA_MIN = 1;
const int CONFIANZA_MAX = 3;

#define OPC_1_BAJA 1
#define OPC_2_MEDIA 2
#define OPC_3_ALTA 3

#define MSJ_VALOR_INCORRECTO "Valor Incorrecto"
#define MSJ_INGRESO_ANIMO "Indique estado de animo(1-100): " 
#define MSJ_MENU "Indique nivel de confianza"
#define MSJ_NIVEL_CONFIANZA "Nivel de confianza:"
#define MSJ_MENU_BAJA "[1] - Baja"
#define MSJ_MENU_MEDIA "[2] - Media"
#define MSJ_MENU_ALTA "[3] - Alta"
#define MSJ_MENU_OPCION "Opcion: "
#define MSJ_RESULTADO_DESCONOCIDO "Resultado desconocido, Eleven y el Demogorgon desaparecieron en el enfrentamiento"
#define MSJ_RESULADO_POSITIVO "Resultado positivo,"
#define MSJ_ELEVEN_VICTORIA_DEBIL "Eleven apenas tuvo fuerza para vencer al Demogorgon y se encuentra muy debil"
#define MSJ_ELEVEN_VICTORIA_COMPLETA "Eleven logro vencer al Demogorgon completamente"
#define MSJ_ESTADO_ANIMO "Estado de animo:"
#define MSJ_FUERZA_PSIQ "Fuerza psiquica:"

/*Descripcion: pide el estado de animo al usuario y la devuelve
 *Pre: el valor debe ser entre 1 y 100
 *Post: devuelve el valor ingresado por el usuario
*/
int pedirEstadoAnimo (int animo){
	int corte = 1;
	do{
		printf("\n\n\n%s", MSJ_INGRESO_ANIMO);
		scanf("%i", &animo);
		if (animo < ANIMO_MIN || animo > ANIMO_MAX)
		{
			printf("\n%s", MSJ_VALOR_INCORRECTO);
		}else{
			corte = 0;
		}
	}while(corte);

	return(animo);
}

/*Descripcion: pide el nivel de confianza al usuario y lo devuelve
 *Pre: el valor debe ser entre 1 y 3
 *Post: devuelve el valor ingresado por el usuario
*/
int pedirNivelConfianza (int confianza){
	int corte = 1;
	do{
		printf("\n%s", MSJ_MENU);
		printf("\n\t%s\n\t%s\n\t%s", MSJ_MENU_BAJA, MSJ_MENU_MEDIA, MSJ_MENU_ALTA);
		printf("\n%s", MSJ_MENU_OPCION);
		scanf("%i", &confianza);
		if(confianza<CONFIANZA_MIN || confianza > CONFIANZA_MAX)
		{
			printf("\n%s", MSJ_VALOR_INCORRECTO);
		}else{
			corte = 0;
		}
	}while(corte);

	return(confianza);
}

/*Descripcion: calcula la fuerza psiquica
 *Pre: -.se deben tener los valores de confianza y animo
 *Post: devuelve el valor de la multiplicacion
*/
float calcularFuerzaPsiquica (int confianza, float animo){
	float fuerza;

	switch(confianza){
		case OPC_1_BAJA:
			fuerza = animo * MULTIPLICADOR_CONFIANZA_BAJA;
			break;
		case OPC_2_MEDIA:
			fuerza = animo * MULTIPLICADOR_CONFIANZA_MEDIA;
			break;
		case OPC_3_ALTA:
			fuerza = animo * MULTIPLICADOR_CONFIANZA_ALTA;
			break;
	}

	return(fuerza);

}

/*Descripcion: muestra el resultado de la pelea
 *Pre: recibe el velor de fuerza psiquica
 *Post: imprime el mensaje del resultado de la pelea
*/
void resultadoPelea (float fuerza){
	if (fuerza < 65)
	{
		printf("\n\n%s\n\n", MSJ_RESULTADO_DESCONOCIDO);
	}else if (fuerza > 232)
	{
		printf("\n\n%s %s\n\n", MSJ_RESULADO_POSITIVO, MSJ_ELEVEN_VICTORIA_COMPLETA);
	}else{
		printf("\n\n%s %s\n\n", MSJ_RESULADO_POSITIVO, MSJ_ELEVEN_VICTORIA_DEBIL);
	}

}

/*Descripcion: muestra el nivel de confianza
 *Pre: recibe el valor de confianza
 *Post: imprime el mensaje del nivel de confiaza
*/
int nivelConfianza (int confianza){

	switch(confianza){
		case OPC_1_BAJA:
			printf("\n%s %s", MSJ_NIVEL_CONFIANZA, MSJ_MENU_BAJA);
			break;
		case OPC_2_MEDIA:
			printf("\n%s %s", MSJ_NIVEL_CONFIANZA, MSJ_MENU_MEDIA);
			break;
		case OPC_3_ALTA:
			printf("\n%s %s", MSJ_NIVEL_CONFIANZA, MSJ_MENU_ALTA);
			break;
	}

}

void imagen(){
	char c;

	FILE * puntero;
	puntero = fopen("imagen.txt", "r");

	while(!feof (puntero)){
		c = getc (puntero);
		printf("%c", c);
	}
	fclose(puntero);

}

int main(){

	float estadoAnimo = 0;
	float estadoConfianza = 0;
	float fuerzaPsiquica = 0;

	imagen();

	estadoAnimo = pedirEstadoAnimo(estadoAnimo);
	estadoConfianza = pedirNivelConfianza(estadoConfianza);

	printf("\n%s %.0f",MSJ_ESTADO_ANIMO, estadoAnimo);
	nivelConfianza(estadoConfianza);

	fuerzaPsiquica = calcularFuerzaPsiquica(estadoConfianza, estadoAnimo);

	printf("\n%s %.1f",MSJ_FUERZA_PSIQ, fuerzaPsiquica);

	resultadoPelea(fuerzaPsiquica);
	return 0;
}