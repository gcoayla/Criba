#include <iostream>
#include <NTL/ZZ.h>
#include <stdio.h>
#include <time.h>
#include "funciones.h"
#include "lista.h"
using namespace std;
using namespace NTL;
bool analizar(ZZ &numero,lista &primos){
	ZZ sq=SqrRoot(numero);
	nodo* p=primos.head->next->next;
	ZZ ind=p->dato;
	for(ZZ i=ZZ(0);i<primos.tamano && ind<=sq;i++){
		ind=p->dato;
		p=p->next;
		if(mod(numero,ind)==0){
			return 0;
		}
	}
	return 1;
	}
void funcion(ZZ numero,lista &primos){

	primos.insertar(ZZ(2));
	primos.insertar(ZZ(3));
	primos.insertar(ZZ(5));

	for(ZZ i=ZZ(7);i<numero;i=i+ZZ(6)){
		if(analizar(i,primos)){
			primos.insertar(i);
		}
		i=i+ZZ(4);
		if(analizar(i,primos)){
			primos.insertar(i);
		}
		i=i+ZZ(2);
		if(analizar(i,primos)){
			primos.insertar(i);
		}
		i=i+ZZ(4);
		if(analizar(i,primos)){
			primos.insertar(i);
		}
		i=i+ZZ(2);
		if(analizar(i,primos)){
			primos.insertar(i);
		}
		i=i+ZZ(4);
		if(analizar(i,primos)){
			primos.insertar(i);
		}
		i=i+ZZ(6);
		if(analizar(i,primos)){
			primos.insertar(i);
		}
		i=i+ZZ(2);
		if(analizar(i,primos)){
			primos.insertar(i);
		}
	}
}
int main(){
	lista primos;
	ZZ numero=RandomLen_ZZ(20);
	clock_t inicio,fin;
	inicio=clock();
	funcion(ZZ(100000000),primos);
	fin=clock();
	
	cout<<"fin"<<endl;
	primos.imprimir();
	cout<<primos.tamano<<endl;
	cout<<"fin"<<endl;
	//cout<<numero<<endl;
	cout<<(double)(fin - inicio) / CLOCKS_PER_SEC<<endl;
	return 0;
}
