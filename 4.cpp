#include"04.hpp" 


int menu(){

    int opcion = 0;
    cout << endl;
    cout << "INGRESAR LOS DATOS DEL USUARIO"<< endl;

    cout <<" 1- Ingresar datos" <<endl;

    cout <<" 2- Ingresar datos al final" <<endl;

    cout <<" 3- Mostrar datos"<<endl;

    cout <<" 4- Mostrar datos al reves " <<endl;

    cout <<" 5- Salir" << endl;

    cin >> opcion; cin.ignore();

    return opcion;
}


int main (void){
  

ListaDoble datos;

    bool continuar = true;
    administrar p;
    do{
        
        
        switch (menu()){
            case 1:
                    p = solicitarDatos();
                    datos.InsInicio(p);

                    cout << "\n----------datos ingresados correctamente---------\n";
                    break;
            case 2: 
                    p = solicitarDatos();
                    datos.InsFinal(p);
                    break;
            case 3: 
                    datos.mostrarLista();
                    break;
            case 4:
                    datos.mostrarListaAlreves();
                    break;

            case 5: 
                   continuar = false;
                   cout <<"Os esperamos nuevamente."<<endl;
                   break;
        default:
            cout <<"\n Ingrese una opcion valida." << endl << endl;
            break;
        }
    } while (continuar);
    
    return 0;

}