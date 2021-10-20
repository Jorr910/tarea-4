#include<iostream>
#include<string>
using namespace std; 

struct administrar 
{
    int id;
    string perfil, nombre_usuario;
};

administrar solicitarDatos(void) 
{
    administrar p;
    cout << "Ingrese su id: ";
    cin >> p.id;

    cin.ignore(1000,'\n');

    cout << "Ingrese su nombre: ";

    getline (cin, p.nombre_usuario);

    cout << "Escriba su perfil: " << endl;

    cout << "administrador, trabajador o cliente"<< endl;

    getline (cin, p.perfil);   
    
    return p;

}

void mostrarDatos(administrar d)
{
    cout << endl;

    cout << "id: " << d.id << endl;
    cout << "Nombre: " << d.nombre_usuario << endl;

    cout << "perfil: " << d.perfil << endl;
}


typedef administrar T;
const T noValido = {0};

struct nodo
{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble
{
    private:
        nodo *pInicio;

    public:
        ListaDoble();
        ~ListaDoble();
        void InsInicio(T);
        void InsFinal(T);
        void mostrarLista(void);
        void mostrarListaAlreves(void);
        bool empty(void);
};


ListaDoble::ListaDoble(void)
{
    pInicio = NULL;
}

ListaDoble::~ListaDoble()
{
    cout << "Destructor ejecutándose" << endl;
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::InsInicio(T dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void ListaDoble::InsFinal(T dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}


void ListaDoble::mostrarLista(void)
{
    nodo *saltarin = pInicio;
    while(saltarin != NULL)
    {
        mostrarDatos(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

void ListaDoble::mostrarListaAlreves(void)
{
    if(!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while(p)
    {
        q = p;
        p = p->sig;
    }
    while(q)
    {
        mostrarDatos(q->dato);
        q = q->ant;
    }
}