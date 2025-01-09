#include <iostream>
#include <stack>
using namespace std;



class Nodo{

    public:

        int dato;

        Nodo* sig;

        Nodo(){sig = nullptr;}
        Nodo(int dato){
            sig = nullptr;
            this->dato = dato;
        }
};

void imprimirLista(Nodo* head){

    Nodo *aux = head;

    while(aux!=nullptr){

        cout<<aux->dato<<",";

        aux = aux->sig;

    }

    cout<<endl;

}




Nodo* insertarEnOrdenMayorAMenor(Nodo* head, Nodo* insertar){

    if(head == nullptr){return insertar;}

    if(head -> dato < insertar -> dato){
        insertar->sig = head;
        return insertar;
    }

    Nodo* aux = head;

    while(aux -> sig != nullptr){

        if(aux->sig->dato<insertar->dato){

            insertar->sig=aux->sig;
            aux->sig=insertar;

            return head;

        }

        aux=aux->sig;

    }

    aux->sig=insertar;

    return head;

}

Nodo* ordenarDeMayorAMenor(Nodo* head){

    if (head == nullptr || head->sig == nullptr) {
        return head;
    }

    Nodo* nuevoHead = nullptr;
    Nodo* actual = head;

    while (actual != nullptr) {
        Nodo* siguiente = actual->sig;
        actual->sig = nullptr;
        nuevoHead = insertarEnOrdenMayorAMenor(nuevoHead, actual);
        actual = siguiente;
    }

    return nuevoHead;
}




int main(){

    Nodo* n1 = new Nodo(8);
    Nodo* n2 = new Nodo(10);
    Nodo* n3 = new Nodo(9);
    Nodo* n4 = new Nodo(7);
    Nodo* n5 = new Nodo(12);
    Nodo* n6 = new Nodo(100);

    n1->sig = n2;
    n2->sig=n3;
    n3->sig=n4;
    n4->sig=n5;
    n5->sig=n6;

    Nodo* head = n1;

    imprimirLista(head);

    head = ordenarDeMayorAMenor(head);

    imprimirLista(head);


return 0;
}