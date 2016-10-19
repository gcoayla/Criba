#include <iostream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
class nodo{
public:
	ZZ dato;
	nodo *next;
	nodo(){
		next=0;
	}
};
class lista{
public:
	nodo *head;
	nodo *tail;
	ZZ tamano;
	lista(){
		head=0;
		tail=0;
		tamano=ZZ(0);
	}
	bool buscar(nodo** &p,ZZ n){
		for(p=&head;p!=0 && (*p)->dato!=n;p=&((*p)->next));
		return p!=0;
	}
	bool insertar(ZZ n){
		cout<<n<<endl;
		if(head!=0){
			nodo *t=new nodo();
			tail->next=t;
			t->dato=n;
			tail=t;
			tamano++;
			return 1;
			
		}
		nodo** p=&head;
		while((*p)!=0){
			p=&((*p)->next);
		}
		nodo *t=new nodo();
		t->dato=n;
		(*p)=t;
		tail=t;
		tamano++;
		return 1;
	}
	void imprimir(){
		nodo* p=head;
		while(p!=0){
			cout<<" "<<p->dato<<endl;
			p=(p->next);
		}	
	}
};
