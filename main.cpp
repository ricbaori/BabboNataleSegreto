#include <iostream>
#include "bns.h"
#include <ctime>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int file[5];
	int dest[5];
	nomifile nomi[6]={"Riccardo.txt","Andrea.txt","Alessandro.txt","Tullio.txt","Domenico.txt","Luca.txt"};
	
	srand(time(NULL));

	while(!crea_ordine(file));
	
	do
	{
		trova_destinatari(file, dest);
	}while(destinatari_ripetuti(dest));
	
	ordina_lista(file, dest);
	
	for(int i=0; i<6; i++)
	{
		crea_file(file[i], dest, nomi[file[i]]);
	}
	
	
	for(int i=0;i<6;i++)
	{
		cout<<file[i]<<" --> ?"<<endl;  //aggiungere <<dest[i] per il debug
	}
	return 0;
}
