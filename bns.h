#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
using namespace std;

typedef struct
{
	char nome[20]; 
} nomifile;

bool crea_ordine(int[]);
bool compatibile(int, int);
bool trova_destinatari(int[], int &);
bool destinatari_ripetuti(int[]);
void crea_file(int, int[], nomifile);
void ordina_lista(int[], int[]);
	
bool crea_ordine(int lista[])
{
	bool s=true;
	for(int i=0; i<6; i++)
	{
		lista[i]=rand() % 6;
	}
	for(int j=0; j<6; j++)
	{
		for(int k=0; k<6; k++)
		{
			if(k!=j)
			{
				if(lista[j]==lista[k]) s=false;
			}
		}
	}
	return s;
}

bool compatibile(int dest, int ric)
{
	bool c=false;
	switch(dest)
	{
		case (0):
				if(ric!=0&&ric!=1&&ric!=4) 
				{
					c=true; 
					break;
				}
				else break;
		case (1): if(ric!=1&&ric!=0) 
				{
					c=true; 
					break;
				}
				else break;		 
		case (2): if(ric!=2&&ric!=1&&ric!=3) 
				{
					c=true; 
					break;
				}
				else break;
		case (3): if(ric!=3&&ric!=5&&ric!=4) 
				{
					c=true; 
					break;
				}
				else break;
		case (4): if(ric!=4&&ric!=2&&ric!=5) 
				{
					c=true; 
					break;
				}
				else break;
		case (5): if(ric!=5&&ric!=3&&ric!=2) 
				{
					c=true; 
					break;
				}
				else break;
	}
	return c;				
}

bool trova_destinatari(int lista[], int dest[])
{

	for(int i=0; i<6; i++)
	{
		do
		{	
			dest[i]=rand()%6;
		}
		while(!compatibile(lista[i],dest[i])&&destinatari_ripetuti);
	}
}

bool destinatari_ripetuti(int dest[])
{

	bool s=false;
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(i!=j)
			{
				if(dest[i]==dest[j]) s=true;
			}
		}
	}
	return s;
}

void crea_file(int n, int lista[], nomifile file1)
{
	fstream miofile;
    miofile.open(file1.nome,ios::out);
    miofile<<lista[n];
    miofile.close();
}

void ordina_lista(int lista[], int dest[])
{
	int templ, tempd;
	for(int j=0; j<6; j++)
	{
		for(int i=0; i<6; i++)
		{
			if(lista[i]>lista[i+1])
			{
				templ=lista[i];
				tempd=dest[i];
				lista[i]=lista[i+1];
				dest[i]=dest[i+1];
				lista[i+1]=templ;
				dest[i+1]=tempd;
			}
		}
	}
	
}

