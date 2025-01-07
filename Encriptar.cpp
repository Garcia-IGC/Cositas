#include <iostream>

using namespace std;

class A{
    public:
    
    void p(){cout<<"A::p"<<endl;}
    virtual void q(){cout<<"A::q"<<endl;}

    void f(){
        p();
        q();
    }


};

class B: public A{
    public:

    void o(){cout<<"B::o"<<endl;}
    void p(){cout<<"B::p"<<endl;}
    void q(){cout<<"B::q"<<endl;}

};

class C: public B{

    void q(){cout<<"C::q"<<endl;}

};

class Nodo{

    public:
    int dato;
    Nodo* sig;

    Nodo(){
        sig = nullptr;
    }
};

//Metodo para insertar un nodo dentro de una lista de nodos de forma "ordenada" de menor a mayor
Nodo* insertarNodoOrdenado(Nodo* head, Nodo* nodoNuevo){



    if(head == nullptr){
        return nodoNuevo;
    }

    if(head -> dato > nodoNuevo -> dato){
        nodoNuevo->sig = head;
        return nodoNuevo;
    }
    
    Nodo* aux = head;




    while(aux->sig!=nullptr){

        if(aux->sig->dato > nodoNuevo->dato){

            nodoNuevo->sig=aux->sig;
            aux->sig=nodoNuevo;

            return head;

        }


        aux = aux->sig;
    }

    aux->sig =nodoNuevo;

    return head;

    




}
//Metodo para imprimir una lista de Nodos
void imprimirLista(Nodo* head){

    Nodo *aux = head;

    while(aux!=nullptr){

        cout<<aux->dato<<",";

        aux = aux->sig;

    }

    cout<<endl;

}
//Metodo para encriptar(Intercambiar) un lista cada k veces
Nodo* encriptarLista(Nodo* head, int k){

    if(head == nullptr || head->sig == nullptr){
        return head;
    }

    int ctr = 1;

    Nodo* aux = head;
    Nodo* auxAnt = nullptr;
    

    while(aux->sig!=nullptr){

    
        if(ctr == k){

            if(auxAnt!=nullptr){

               

                auxAnt -> sig = aux->sig;
                aux -> sig = auxAnt ->sig ->sig;
                auxAnt -> sig -> sig = aux;
                if(k==1){
                    auxAnt=auxAnt->sig;
                }
                

            } else if(auxAnt == nullptr) {

                auxAnt = aux->sig;
                head = aux->sig;
                Nodo *aux2 = aux->sig;
                aux -> sig = aux->sig->sig;
                aux2->sig = aux;
                
            }
            
            ctr=1;

        }

        if(k!=1){
            ctr++;

            auxAnt=aux;
            aux=aux->sig;

            

        } 
        

    }


    return head;

}
//Metodo para desecriptar una lista cada k veces (Metodo inverso de "encriptarLista")
Nodo* desencriptarLista(Nodo* head, int k){

    if(head == nullptr || head->sig==nullptr){return head;}

    Nodo* aux = head;
    Nodo* auxAnt;

    if(k==1){

        while(aux->sig!=nullptr){

            auxAnt=aux;
            aux=aux->sig;

        }

        auxAnt->sig = nullptr;

        aux->sig = head;

        return aux;

    } else if (k!=1) {

        head = encriptarLista(head,k);

        return head;

    }

    return head;

}


int main() {

    Nodo* n1 = new Nodo();

    n1->dato=1;

    Nodo* n2 = new Nodo();

    n2->dato=2;

    Nodo* n3 = new Nodo();

    n3->dato=3;

    Nodo* head = n1;

    head->sig=n2;
    head->sig->sig=n3;

    Nodo* n5 = new Nodo();

    n5->dato=5;

    Nodo* n4 = new Nodo();

    n4->dato=4;

    Nodo* n0 = new Nodo();

    n0->dato=0;

    imprimirLista(head);

    head = insertarNodoOrdenado(head,n0);

    imprimirLista(head);

    head = insertarNodoOrdenado(head,n5);

    imprimirLista(head);

    head = insertarNodoOrdenado(head,n4);
    
    imprimirLista(head);

    head = encriptarLista(head,1);

    imprimirLista(head);

    head = desencriptarLista(head,1);

    imprimirLista(head);

    head = encriptarLista(head,2);

    imprimirLista(head);

    head = desencriptarLista(head,2);

    imprimirLista(head);
    


    return 0;

}