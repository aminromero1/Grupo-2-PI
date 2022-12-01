#include <iostream>
#include <string>
using namespace std;

// *****************************************************************************************************
int codCategoria = 1;
int codPrestamos = 1;
int codPrestatario = 1;
int MAX = 100;
// Structs
struct Categoria{
    int codigoCategoria;
    string descripcion;
};
struct Prestatario{
    int codigoPrestatario;
    string nombre;
    string apellido;
};
struct Prestamo{
    Categoria categoria;
    Prestatario prestatario;
    string descripcion;
    bool estado;
};

//Nodos
struct NodoCategoria{
    Categoria categoria;
    NodoCategoria * sigCategoria;
};

struct NodoPrestatario{
    Prestatario prestatario;
    NodoPrestatario * sigPrestatario;
};

struct NodoPrestamo{
    Prestamo prestamo;
    NodoPrestamo * sigPrestamo;
};

// *****************************************************************************************************
// Variables
int opcionPrincipal;
char opcion;
string descripcion;
int codigo;
bool existe;
string apellido;
string nombre;
// *****************************************************************************************************
Prestatario prestatarios[15];
Prestamo prestamos[15];
Categoria categorias[15]; 

// *****************************************************************************************************
// *****************************************************************************************************
// Opcion 1 = Administrar y consultar Categorías y Prestatarios
// funciones secundarias de la opcion 1
NodoCategoria * guardarCategoria(NodoCategoria * inicioCategoria, NodoCategoria * nuevo){
    if (inicioCategoria == nullptr)
        inicioCategoria = nuevo;
    else
    {
        NodoCategoria *aux = inicioCategoria;
        while (aux->sigCategoria != nullptr)
        {
            aux = aux->sigCategoria;
        }
        aux->sigCategoria = nuevo;
    }
    return inicioCategoria;
}

NodoPrestatario * guardarPrestatario(NodoPrestatario * inicioPrestatario, NodoPrestatario * nuevo){
    if (inicioPrestatario == nullptr)
        inicioPrestatario = nuevo;
    else
    {
        NodoPrestatario *aux = inicioPrestatario;
        while (aux->sigPrestatario != nullptr)
        {
            aux = aux->sigPrestatario;
        }
        aux->sigPrestatario = nuevo;
    }
    return inicioPrestatario;
}

NodoPrestamo * guardarPrestamo(NodoPrestamo * inicioPrestamo, NodoPrestamo * nuevo){
    if (inicioPrestamo == nullptr)
        inicioPrestamo = nuevo;
    else
    {
        NodoPrestamo *aux = inicioPrestamo;
        while (aux->sigPrestamo != nullptr)
        {
            aux = aux->sigPrestamo;
        }
        aux->sigPrestamo = nuevo;
    }
    return inicioPrestamo;
}

void mostrarCategorias(NodoCategoria * inicioCategoria){
    cout << "Categorias: " << endl;
    for (NodoCategoria* aux=inicioCategoria; aux != nullptr; aux = aux->sigCategoria){
        cout << "   Codigo: " << aux->categoria.codigoCategoria << endl;
        cout << "   Descripcion: " << aux->categoria.descripcion << endl;
        cout << "   ************" << endl;
    }
}

bool existePrestamo(NodoPrestamo * inicioPrestamo, int codigo){
    for (NodoPrestamo * aux = inicioPrestamo; aux != nullptr; aux = aux->sigPrestamo){
        if (aux->prestamo.categoria.codigoCategoria == codigo){
            return true;
        }
    }
    return false;
}

bool existePrestatario(NodoPrestatario * inicioPrestatario, int codigo){
    for(NodoPrestatario * aux = inicioPrestatario; aux != nullptr; aux = aux->sigPrestatario){
        if(aux->prestatario.codigoPrestatario == codigo){
            return true;
        }
    }
    return false;
}

// *****************************************************************************************************
// *****************************************************************************************************
// Funciones principales de opcion 1

NodoCategoria * agregarCategoria (NodoCategoria * inicioCategoria, int codigo, string descripcion, int &odCategoria){
    cout<<"ingrese la descripcion de la nueva categoria (X para salir): ";
    cin >> descripcion;

    while(descripcion != "X" && descripcion != "x"){
        NodoCategoria * nuevo;
        nuevo = new NodoCategoria;
        nuevo -> categoria.descripcion = descripcion;

        nuevo -> categoria.codigoCategoria = codCategoria;
        nuevo -> sigCategoria = nullptr;
        // imprimimos la categoria agregada
        cout << "Categoria agregada: " << endl;
        cout << "   Codigo: " << nuevo->categoria.codigoCategoria << endl;
        cout << "   Descripcion: "<< nuevo->categoria.descripcion << endl;   

        inicioCategoria=guardarCategoria(inicioCategoria, nuevo);
        codCategoria++;

        cout << "Ingrese la descripcion de la nueva categoria (X para salir): ";
        cin >> descripcion;
    }

    return inicioCategoria;
}
// *****************************************************************************************************
NodoCategoria * modificarCategoria(NodoCategoria * inicioCategoria, int codigo, string descripcion){
    cout << "Modificar categoria: " << endl;
    
    // si la lista esta vacia
    if(inicioCategoria == nullptr){
        cout << "   No hay categorias cargadas" << endl;
    }
    else{
        mostrarCategorias(inicioCategoria);

        cout << "ingrese el codigo de la categoria a modificar(0 para salir): ";
        cin >> codigo;
        
        while(codigo !=0){
            for (NodoCategoria * i = inicioCategoria ; i != nullptr; i = i->sigCategoria){
                if (codigo == i->categoria.codigoCategoria){
                    cout << "La descripcion de la categoria es: " << i->categoria.descripcion << endl;
                    cout << "***********************" << endl;
                    cout << "Ingrese la nueva descripcion de la categoria: "<<endl;
                    cin >> descripcion;
                    i->categoria.descripcion=descripcion;
                    cout << "Categoria modificada: " << endl;
                    break;
                } 
            }   
        }
        
    }
    return inicioCategoria;  
}
// *****************************************************************************************************

NodoCategoria * eliminarCategoria(NodoCategoria *&inicioCategoria, int &codCategoria, int codigo){
    cout << "Eliminar categoria" << endl;
    mostrarCategorias(inicioCategoria);
    cout << "Ingrese el codigo de la categoria a eliminar(0 para salir): ";
    cin >> codigo;

    while(codigo != 0){
        NodoCategoria *aux = inicioCategoria;
        NodoCategoria *aEliminar;

        while(aux != nullptr){
            if (existePrestamo(inicioCategoria, codigo) == false){
                if (inicioCategoria != nullptr){
                    if (inicioCategoria->categoria.codigoCategoria == codigo){
                        aEliminar = inicioCategoria;
                        inicioCategoria = inicioCategoria->sigCategoria;
                        aux = inicioCategoria;
                        delete aEliminar;
                    }
                    else{
                        if (aux->sigCategoria != nullptr && aux->sigCategoria->categoria.codigoCategoria == codigo){
                            aEliminar = aux->sigCategoria;
                            aux->sigCategoria = aEliminar->sigCategoria;
                            delete aEliminar;
                        }
                        else{
                            aux = aux->sigCategoria;
                        }
                    }
                }
            }
            else{
                cout << "No se puede eliminar la categoria porque tiene prestamos asociados" << endl;
                break;
            }
        }
    }
    return inicioCategoria;
}

// *****************************************************************************************************
NodoPrestatario * agregarPrestatario(NodoPrestatario *&inicioPrestatario, string nombre, string apellido, int codPrestatario){
    cout << "Agregar prestatario" << endl;

    cout << "Ingrese el nombre del prestatario(X para salir): ";
    cin >> nombre;

    while(nombre != "X" && nombre !="x"){
        NodoPrestatario * nuevo;
        nuevo = new NodoPrestatario;
        nuevo->prestatario.nombre = nombre;
        cout << "Ingrese el apellido del prestatario: ";
        cin >> apellido;
        nuevo->prestatario.apellido = apellido;
        nuevo->prestatario.codigoPrestatario = codPrestatario;
        
        nuevo->sigPrestatario = nullptr;

        cout << "Prestatario agregado con exito \n   Codigo: " << nuevo->prestatario.codigoPrestatario << endl;
        cout << "   Nombre: " << nuevo->prestatario.nombre << " "<< nuevo->prestatario.apellido << endl;

        inicioPrestatario = guardarPrestatario(inicioPrestatario, nuevo);
        codPrestatario++;

        cout << "Ingrese el nombre del prestatario(X para salir): ";
        cin >> nombre;
    }
    return inicioPrestatario;
}

// *****************************************************************************************************
NodoPrestatario * modificarPrestatario(NodoPrestatario * inicioPrestatario, int codigo, string nombre, string apellido){
    cout << "Modificar prestatario" << endl;

    if(inicioPrestatario == nullptr){
        cout << "   No hay prestatarios cargados" << endl;
    }
    else{
        cout << "Ingrese el codigo del prestatario a modificar(0 para salir): ";
        cin >> codigo;

        while(codigo != 0){
            if(existePrestatario(inicioPrestatario, codigo) == true){
                for (NodoPrestatario * i = inicioPrestatario ; i != nullptr; i = i->sigPrestatario){
                    if (codigo == i->prestatario.codigoPrestatario){
                        cout << "El nombre del prestatario es: " << i->prestatario.nombre << " " << i->prestatario.apellido << endl;
                        cout << "***********************" << endl;
                        cout << "Ingrese el nuevo nombre del prestatario: "<<endl;
                        cin >> nombre;
                        i->prestatario.nombre=nombre;
                        cout << "Ingrese el nuevo apellido del prestatario: "<<endl;
                        cin >> apellido;
                        i->prestatario.apellido=apellido;
                        cout << "Prestatario modificado: " << endl;
                        break;
                    } 
                }    
            }
            else{
                cout << "No hay ningun prestatario con ese codigo" << endl;
            }
        }
    }
    return inicioPrestatario;
}

// for (int i=0; i=codPrestatario; i++){
//     if(codigoPrest==codPrestatario){
//         cout<<"ingrese el nuevo nombre del prestatario:";
//         cin>>nuevoNombre;
//         prestatarios[codPrestatario].nombre = nuevoNombre;
//         cout<<"ingrese el nuevo apellido del prestatario:";
//         cin>>apellidoNuevo;
//         prestatarios[codPrestatario].apellido = apellidoNuevo;
//     }
//     else{
//         cout << "no hay ningun prestatario registrado con ese nombre" << endl;
//     }
// }
// return 1;

// *****************************************************************************************************
NodoPrestatario * eliminarPrestatario(NodoPrestatario *&inicioPrestatario, NodoPrestamo *&inicioPrestamo, int codigo){
    cout << "Eliminar prestatario" << endl;
    cout << "Ingrese el codigo del prestatario a eliminar(0 para salir): " << endl;
    cin >> codigo;

    while(codigo != 0){
        if(existePrestamo(inicioPrestamo, codigo) == false){
            NodoPrestatario *aux = inicioPrestatario;
            NodoPrestatario *aEliminar;

            while(aux != nullptr) {
                if (inicioPrestatario != nullptr){
                    if (inicioPrestatario->prestatario.codigoPrestatario == codigo){
                        aEliminar = inicioPrestatario;
                        inicioPrestatario = inicioPrestatario->sigPrestatario;
                        aux = inicioPrestatario;
                        delete aEliminar;
                        cout << "Prestatario eliminado con exito" << endl;
                    }
                    else{
                        if (aux->sigPrestatario != nullptr && aux->sigPrestatario->prestatario.codigoPrestatario == codigo){
                            aEliminar = aux->sigPrestatario;
                            aux->sigPrestatario = aEliminar->sigPrestatario;
                            delete aEliminar;
                            cout << "Prestatario eliminado con exito" << endl;
                        }
                        else{
                            aux = aux->sigPrestatario;
                        }
                    }
                }
            }
        }
        else{
            cout << "No se puede eliminar el prestatario porque tiene prestamos pendientes" << endl;
        }
        cout << "Ingrese el codigo del prestatario a eliminar(0 para salir): " << endl;
        cin >> codigo;
    }
    return inicioPrestatario;
}

// *****************************************************************************************************
// *****************************************************************************************************
// Opcion 2 = Administrar Préstamos
// funciones secundarias de opcion 2
bool existeCategoria(NodoCategoria * inicioCategoria, int codigo){
    for(NodoCategoria * i = inicioCategoria; i != nullptr; i = i->sigCategoria){
        if(i->categoria.codigoCategoria == codigo){
            return true;
        }
    }
    return false;
}

void mostrarPrestatarios(NodoPrestatario * inicioPrestatario){
    cout << "Prestatarios:" << endl;
    for(NodoPrestatario * i = inicioPrestatario; i != nullptr; i = i->sigPrestatario){
        cout << "   Codigo: " << i->prestatario.codigoPrestatario << endl;
        cout << "   Nombre: " << i->prestatario.nombre << endl;
        cout << "   Apellido: " << i->prestatario..apellido << endl;
        cout << "****************" << endl;
    }
}


void imprimirPrestamo(NodoPrestamo * nuevo){
    cout << "**********************************" << endl;
    cout << "Prestamo agregado: " << endl;
    cout << "   Categoria Codigo: " << nuevo->prestamo.categoria.codigoCategoria << endl;
    cout << "   Categoria Descripcion: " << nuevo->prestamo.categoria.descripcion << endl;
    cout << "   Prestatario Codigo: " << nuevo->prestamo.prestatario.codigoPrestatario<< endl;
    cout << "   Prestatario Nombre: " << nuevo->prestamo.prestatario.nombre << endl;
    cout << "   Prestatario Apellido: " << nuevo->prestamo.prestatario.apellido << endl;
    cout << "   Descripcion del prestamo: " << nuevo->prestamo.descripcion << endl;

}
// *****************************************************************************************************
// *****************************************************************************************************
// Funciones principales de opcion 2

NodoPrestamo * agregarPrestamo(NodoCategoria * inicioCategoria, int &codCategoria,NodoPrestamo * inicioPrestamo, int &codPrestamos, NodoPrestatario * inicioPrestatario, int &codPrestatario, char opcion, int codigo, string descripcion){
    cout << "Agregar prestamo" << endl;
    cout << "Desea ver las categorias existentes? (S/N) (X para salir): ";
    cin >> opcion;

    opcion = tolower(opcion);
    if(opcion == 's' || opcion == 'n'){
        NodoPrestamo * nuevo;
        nuevo = new NodoPrestamo;
    }
    switch (tolower(opcion))
    {
        case 's':
            mostrarCategorias(inicioCategoria);
            cout << "Ingrese el codigo de la categoria(0 para salir): ";
            cin >> codigo;

            while(codigo != 0){
                if(existeCategoria(inicioCategoria, codigo) == true){
                    nuevo->prestamo.categoria.codigoCategoria = codigo;
                    for(NodoCategoria * i = inicioCategoria; i != nullptr; i = i->sigCategoria){
                        if(i->categoria.codigoCategoria == codigo){
                            nuevo->prestamo.categoria.descripcion = i->categoria.descripcion;
                        }
                    }
                }else{
                    cout << "No existe la categoria" << endl;
                }
                cout << "Ingrese el codigo de la categoria(0 para salir): ";
                cin >> codigo;  
            }
            break;
        case 'n':
             while(codigo != 0){
                if(existeCategoria(inicioCategoria, codigo) == true){
                    nuevo->prestamo.categoria.codigoCategoria = codigo;
                    for(NodoCategoria * i = inicioCategoria; i != nullptr; i = i->sigCategoria){
                        if(i->categoria.codigoCategoria == codigo){
                            nuevo->prestamo.categoria.descripcion = i->categoria.descripcion;
                        }
                    }
                }else{
                    cout << "No existe la categoria" << endl;
                }
                cout << "Ingrese el codigo de la categoria(0 para salir): ";
                cin >> codigo;  
            }
            break;
        case 'x':
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
            break;
    }
    // *PRESTATARIO*

    cout << "¿Desea ver los actuales prestatarios? (S/N) (X para salir): "; 
    cin >> opcion;

    switch (tolower(opcion))
    {

        case 's':
        {
            mostrarPrestatarios(inicioPrestatario);
            cout << "Ingrese el codigo del prestatario(0 para salir): ";
            cin >> codigo;

            while(codigo != 0){
                if(existePrestatario(prestatarios, codPrestatario, codigo) == true){
                    prestamos[codPrestamos].prestatario.codigoPrestatario = codigo;
                    for(NodoPrestatario * i = inicioPrestatario; i != nullptr; i = i->sigPrestatario){
                        if(i->prestatario.codigoPrestatario == codigo){
                            prestamos[codPrestamos].prestatario.nombre = i->prestatario.nombre;
                            prestamos[codPrestamos].prestatario.apellido = i->prestatario.apellido;
                        }
                    }
                    for(int i = 0; i < codPrestatario; i++){
                        if(prestatarios[i].codigoPrestatario == codigo){
                            nuevo->prestaamo.prestatario.nombre = i->prestatario.nombre;
                            nuevo->prestamo.prestatario.apellido = i->prestatario.apellido;
                        }
                    }
                    cout << "Ingrese la descripcion del prestamo: ";
                    cin >> descripcion;
                    nuevo->prestamo.descripcion = descripcion;
                    nuevo->prestamo.estado = true;
                    
                    cout << "Prestamo agregado con exito" << endl;

                    // imprimimos el prestamo agregado
                    imprimirPrestamo(nuevo);
                    inicioPrestamo=agregarPrestamo(inicioPrestamo, nuevo);
                    codPrestamos++;
                    break;
                }
                else{
                    cout << "Ingrese un codigo valido" << endl;
                }
                cout << "Ingrese el codigo del prestatario(0 para salir): ";
                cin >> codigo;
            }
            break;
        }
        case 'n':
            {
            cout << "Ingrese el codigo del prestatario(0 para salir): ";
            cin >> codigo;

            while(codigo != 0){
                if(existePrestatario(prestatarios, codPrestatario, codigo) == true){
                    prestamos[codPrestamos].prestatario.codigoPrestatario = codigo;
                    for(NodoPrestatario * i = inicioPrestatario; i != nullptr; i = i->sigPrestatario){
                        if(i->prestatario.codigoPrestatario == codigo){
                            prestamos[codPrestamos].prestatario.nombre = i->prestatario.nombre;
                            prestamos[codPrestamos].prestatario.apellido = i->prestatario.apellido;
                        }
                    }
                    for(int i = 0; i < codPrestatario; i++){
                        if(prestatarios[i].codigoPrestatario == codigo){
                            nuevo->prestaamo.prestatario.nombre = i->prestatario.nombre;
                            nuevo->prestamo.prestatario.apellido = i->prestatario.apellido;
                        }
                    }
                    cout << "Ingrese la descripcion del prestamo: ";
                    cin >> descripcion;
                    nuevo->prestamo.descripcion = descripcion;
                    nuevo->prestamo.estado = true;
                    
                    cout << "Prestamo agregado con exito" << endl;

                    imprimirPrestamo(nuevo);
                    inicioPrestamo=agregarPrestamo(inicioPrestamo, nuevo);
                    codPrestamos++;
                    break;
                }
                else{
                    cout << "Ingrese un codigo valido" << endl;
                }
                cout << "Ingrese el codigo del prestatario(0 para salir): ";
                cin >> codigo;
            }
            break;
        case 'x':
        {
            cout << "Saliendo..." << endl;
            }
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }  
    return inicioPrestamo;
}

// *****************************************************************************************************
int modificarPrestamo(NodoPrestatario * inicioPrestatario, NodoPrestamo * inicioPrestamo, int codigo, string description){
    cout << "Modificar prestamo" << endl;
    mostrarPrestatarios(inicioPrestatario);

    cout << "Ingrese el codigo del prestatario del cual quiere modificar un prestamo (0 para salir): ";
    cin >> codigo;
    
    while(codigo != 0){
        if(existePrestatario(inicioPrestatario, codigo) == true){
            cout << "Prestamos de: " <<  << " " << prestatarios[codigo].apellido << endl;
            for(int i = 0; i < codPrestamos; i++){
                if(prestamos[i].prestatario.codigoPrestatario == codigo){
                    if(prestamos[i].estado == true){
                        cout << "   Categoria: " << prestamos[i].categoria.descripcion << endl;
                        cout << "   Prestamo: " << prestamos[i].descripcion << endl;
                        cout << "   Numero de prestamo: " << i << endl;
                        cout << "*************************" << endl;  
                    }
                }
            }
            cout << "Ingrese el codigo del prestamo a devolver (0 para salir): ";
            int codigoAux;
            cin >> codigoAux;

            while(codigoAux != 0){
                for(int i = 0; i < codPrestamos; i++){
                    if(prestamos[i].prestatario.codigoPrestatario == codigo){
                        if(prestamos[i].estado == true){
                            if(i == codigoAux){
                                cout << "Ingrese la nueva descripcion del prestamo: ";
                                cin >> description;
                                prestamos[i].descripcion = description;

                                cout << "La nueva descripcion del prestamo es: " << prestamos[i].descripcion << endl;
                                cout << "**************************************" << endl;
                                cout << "Prestamo modificado con exito" << endl;
                            }
                        }
                    }
                    else{
                    cout << "El prestamo no existe" << endl;
                    }
                }
                
                cout << "Ingrese el codigo del prestamo a devolver (0 para salir): ";
                cin >> codigoAux;
            }
        }
        else{
            cout << "El prestatario no existe" << endl;
        }
        cout << "Ingrese el codigo del prestatario (0 para salir): ";
        cin >> codigo;
    }
    return 1;
}

// *****************************************************************************************************
int eliminarPrestamo(Prestamo prestamos[], int &codPrestamos, Prestatario prestatarios[], int &codPrestatario, int codigo){
    cout << "Eliminar prestamo" << endl;
    mostrarPrestatarios(prestatarios, codPrestatario);
    cout << "Ingrese el codigo del prestatario (0 para salir): ";
    cin >> codigo;
    
    while(codigo != 0){
        if(existePrestatario(prestatarios, codPrestatario, codigo) == true){
            cout << "Prestamos de: " << prestatarios[codigo].nombre << " " << prestatarios[codigo].apellido << endl;
            for(int i = 0; i < codPrestamos; i++){
                if(prestamos[i].prestatario.codigoPrestatario == codigo){
                    if(prestamos[i].estado == true){
                        cout << "   Categoria: " << prestamos[i].categoria.descripcion << endl;
                        cout << "   Prestamo: " << prestamos[i].descripcion << endl;
                        cout << "   Numero de prestamo: " << i << endl;
                        cout << "*************************" << endl;  
                    }
                }
            }
            cout << "Ingrese el codigo del prestamo a eliminar (0 para salir): ";
            int codigoAux;
            cin >> codigoAux;

            while(codigoAux != 0){
                for(int i = 0; i < codPrestamos; i++){
                    if(prestamos[i].prestatario.codigoPrestatario == codigo){
                        if(prestamos[i].estado == true){
                            if(i == codigoAux){
                                for(int j = i; j < codPrestatario; j++){
                                    prestatarios[j] = prestatarios[j+1];
                                }
                                codPrestatario--;
                                cout << "Prestamo eliminado con exito" << endl;
                            }
                        }
                    }
                    else{
                    cout << "El prestamo no existe" << endl;
                    }
                }
                
                cout << "Ingrese el codigo del prestamo a devolver (0 para salir): ";
                cin >> codigoAux;
            }
        }
        else{
            cout << "El prestatario no existe" << endl;
        }
        cout << "Ingrese el codigo del prestatario (0 para salir): ";
        cin >> codigo;
    }
    return 1;
}


// *****************************************************************************************************
int devolverPrestamo(Prestatario prestatarios[], int &codPrestatario, Prestamo prestamos[], int &codPrestamos, int codigo){
    cout << "Devolver prestamo" << endl;
    mostrarPrestatarios(prestatarios, codPrestatario);
    cout << "Ingrese el codigo del prestatario (0 para salir): ";
    cin >> codigo;
    
    while(codigo != 0){
        if(existePrestatario(prestatarios, codPrestatario, codigo) == true){
            cout << "Prestamos de: " << prestatarios[codigo].nombre << " " << prestatarios[codigo].apellido << endl;
            for(int i = 0; i < codPrestamos; i++){
                if(prestamos[i].prestatario.codigoPrestatario == codigo){
                    if(prestamos[i].estado == true){
                        cout << "   Categoria: " << prestamos[i].categoria.descripcion << endl;
                        cout << "   Prestamo: " << prestamos[i].descripcion << endl;
                        cout << "   Numero de prestamo: " << i << endl;
                        cout << "*************************" << endl;  
                    }
                }
            }
            cout << "Ingrese el codigo del prestamo a devolver (0 para salir): ";
            int codigoAux;
            cin >> codigoAux;

            while(codigoAux != 0){
                for(int i = 0; i < codPrestamos; i++){
                    if(prestamos[i].prestatario.codigoPrestatario == codigo){
                        if(prestamos[i].estado == true){
                            if(i == codigoAux){
                                prestamos[i].estado = false;
                                cout << "Prestamo devuelto con exito" << endl;
                            }
                        }
                    }
                    else{
                    cout << "El prestamo no existe" << endl;
                    }
                }
                
                cout << "Ingrese el codigo del prestamo a devolver (0 para salir): ";
                cin >> codigoAux;
            }
        }
        else{
            cout << "El prestatario no existe" << endl;
        }
        cout << "Ingrese el codigo del prestatario (0 para salir): ";
        cin >> codigo;
    }
    return 1;
}
    
// *****************************************************************************************************
// *****************************************************************************************************

// Opcion 3 = Consultar Préstamos
//      Funciones secundarias de la opcion 3
int contadorPrestamosPendientes(Prestamo prestamos[], int &codPrestamos){
    int cantObjPen=0;
    for(int j=0; j < codPrestamos; j++){
        if(prestamos[j].estado == true){
            cantObjPen++;
        }
    }
    return cantObjPen;
}
// *****************************************************************************************************
// *****************************************************************************************************

// Opcion 3 = Consultar Préstamos
void cantObjetosPorCategoria(Categoria categorias[], int &codCategoria, Prestamo prestamos[], int &codPrestamos){
    cout << "Cantidad de objetos por categoria" << endl;
    for(int i = 0; i < codCategoria; i++){
        int cant = 0;
        for(int j = 0; j < codPrestamos; j++){
            if(prestamos[j].categoria.codigoCategoria == categorias[i].codigoCategoria){
                cant++;
            }
        }
        cout << "   Categoria: " << categorias[i].descripcion << endl;
        cout << "   Cantidad: " << cant << endl;
        cout << "****************" << endl;
    }
    
    cout << "   Prestamos pendientes totales: "<< contadorPrestamosPendientes(prestamos, codPrestamos) << endl;
    cout << "****************" << endl;

}

// *****************************************************************************************************

int listadoPrestamosPorCategoria(Categoria categorias[], int &codCategoria, Prestatario prestatarios[], int &codPrestatario,Prestamo prestamos[], int &codPrestamos, int codigo){
    cout << "Listado de prestamos pendientes por categoria" << endl;
    cout << "Ingrese el codigo de la categoria(0 para salir): ";
    cin >> codigo;

    while(codigo != 0){
        if(existeCategoria(categorias, codCategoria, codigo) == true){
            for(int i = 0; i < codPrestatario; i++){
                for(int j = 0; j < codPrestamos; j++){
                    if(prestamos[j].prestatario.codigoPrestatario == prestatarios[i].codigoPrestatario && prestamos[j].categoria.codigoCategoria == codigo){
                        cout << "   Prestatario: " << prestatarios[i].nombre << " " << prestatarios[i].apellido << endl;
                        cout << "   Categoria: " << prestamos[j].categoria.descripcion << endl;
                        if(prestamos[j].estado == true){
                            cout << "       Prestamo: " << prestamos[j].descripcion << endl;
                            cout << "****************" << endl;
                        }
                    }
                }
            }
        }
        else{
            cout << "La categoria no existe" << endl;
        }
        cout << "Ingrese el codigo de la categoria(0 para salir): ";
        cin >> codigo;
    }
    return 1;
}

// *****************************************************************************************************
void listadoPrestamosPorPrestatario(Prestamo prestamos[], int &codPrestamos, Prestatario prestatarios[], int &codPrestatario, char opcion, int codigo){
    cout << "Listado de prestamos por prestatario" << endl;
    cout << "   ¿Desea ver el listado por categoria(C) o Prestatario(P)?(X para salir) :";
    cin >> opcion;

    if(opcion == 'C' || opcion == 'c'){
        cout << "Listado de prestamos por categoria" << endl;
        // recorremos el array de prestamos
        // por cada categoria imprimimos el nombre y todos los prestamos de esa categoria
        for(int i = 0; i < codPrestamos; i++){
            cout << "   Categoria: " << prestamos[i].categoria.descripcion << endl;
            for(int j = 0; j < codPrestamos; j++){
                if(prestamos[j].categoria.codigoCategoria == prestamos[i].categoria.codigoCategoria){
                    cout << "       Prestamo: " << prestamos[j].descripcion << endl;
                    cout << "       Prestatario: " << prestamos[j].prestatario.nombre << " " << prestamos[j].prestatario.apellido << endl;
                    cout << "*******************" << endl;
                }
            }
        }
    }
    else if(opcion == 'P' || opcion == 'p'){
        cout << "Listado de prestamos por prestatario" << endl;
        // recorremos el array de prestamos
        // por cada prestatario imprimimos el nombre y todos los prestamos de ese prestatario
        for(int i = 0; i < codPrestamos; i++){
            cout << "   Prestatario: " << prestamos[i].prestatario.nombre << " " << prestamos[i].prestatario.apellido << endl;
            for(int j = 0; j < codPrestamos; j++){
                if(prestamos[j].prestatario.codigoPrestatario == prestamos[i].prestatario.codigoPrestatario){
                    cout << "       Prestamo: " << prestamos[j].descripcion << endl;
                    cout << "       Categoria: " << prestamos[j].categoria.descripcion << endl;
                    cout << "*******************" << endl;
                }
            }
        }
    }
    else if(opcion == 'X' || opcion == 'x'){
        cout << "Saliendo..." << endl;
    }
    else{
        cout << "Opcion incorrecta" << endl;
    }
    
}

// *****************************************************************************************************
int prestatariosConobjetosPrestados(Prestamo prestamos[], int &codPrestamos, Prestatario prestatarios[], int &codPrestatario){
    cout << "Prestatarios con objetos prestados" << endl;
    //muestra los prestatarios que tienen objetos prestados
     for(int i = 0; i < codPrestatario; i++){
        int cant = 0;
        for(int j = 0; j < codPrestamos; j++){
            if(prestamos[j].prestatario.codigoPrestatario == prestatarios[i].codigoPrestatario && prestamos[j].estado == true){
                cant++;
            }
        }
        if(cant > 0){
            cout << "   Nombre: " << prestatarios[i].nombre << endl;
            cout << "   Apellido: " << prestatarios[i].apellido << endl;
            cout << "   Cantidad de prestamos prendientes: " << cant << endl;
            cout << "*****************************" << endl;  
        }
     }
    return 1;
}
//*####################################################################################################

// funcion principal
int main(){
    //Listas
    NodoCategoria* inicioCategoria = nullptr;
    NodoPrestamo * inicioPrestamo = nullptr;
    NodoPrestatario * inicioPrestatario= nullptr;

        do{
            cout << "1. Administrar y consultar Categorías y Prestatarios" << endl;
            cout << "2. Administrar Préstamos" << endl;
            cout << "3. Consultar Préstamos" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcionPrincipal;

            switch (opcionPrincipal)
            {
            case 1:
                do
                {
                    cout << "Administrar y consultar Categorías y Prestatarios" << endl;
                    cout << "   A) Agregar categoría" << endl;
                    cout << "   B) Modificar categoría" << endl;
                    cout << "   C) Eliminar categoría" << endl;
                    cout << "   D) Agregar prestatario" << endl;
                    cout << "   E) Modificar prestatario" << endl;
                    cout << "   F) Eliminar prestatario" << endl;
                    cout << "   X) Salir Al Menú Principal"<< endl;
                    cout << "   ingrese la opcion: ";
                    cin >> opcion;
                    switch (tolower(opcion))
                    {
                    case 'a':
                        inicioCategoria = agregarCategoria(inicioCategoria, codCategoria, descripcion, codCategoria);
                        break;
                    case 'b':
                        inicioCategoria = modificarCategoria(inicioCategoria, codCategoria, descripcion);
                        break;
                    case 'c':
                        inicioCategoria = eliminarCategoria(inicioCategoria, codCategoria, codigo);           
                        break;
                    case 'd':
                        inicioPrestatario = agregarPrestatario(inicioPrestatario, nombre, apellido, codPrestatario);
                        break;
                    case 'e':
                        inicioPrestatario = modificarPrestatario(inicioPrestatario, codigo, nombre, apellido);
                        break;
                    case 'f':
                        inicioPrestatario = eliminarPrestatario(inicioPrestatario, inicioPrestamo, codigo);
                        break;
                    case 'x':
                        break;
                    default:
                        cout << "ELIJA UNA OPCION CORRECTA" << endl;
                        break;
                    }
                } while (opcion != 'a', opcion != 'b', opcion != 'c', opcion != 'd', opcion != 'e', opcion != 'f', opcion!= 'x');
                break;
            case 2:
                do
                {
                    cout << "Administrar Préstamos" << endl;
                    cout << "   A) Agregar préstamo" << endl;
                    cout << "   B) Modificar préstamo" << endl;
                    cout << "   C) Eliminar préstamo" << endl;
                    cout << "   D) Devolver préstamo" << endl;
                    cout << "   X) Salir Al Menú Principal"<< endl;
                    cout << "   ingrese la opcion: ";
                    cin >> opcion;
                    switch (tolower(opcion))
                    {
                    case 'a':
                       inicioPrestamo = agregarPrestamo();                
                        break;
                    case 'b':
                       //modificarPrestamo();
                        break;
                    case 'c':
                        //eliminarPrestamo();
                        break;
                    case 'd':
                       // devolverPrestamo();
                        break;
                    case 'e':
                        break;
                    default:
                        cout << "ELIJA UNA OPCION CORRECTA" << endl;
                        break;
                    }
                } while (opcion != 'a', opcion != 'b', opcion != 'c', opcion != 'd', opcion!='x');
                break;
            case 3:
                do
                {
                    cout << "Consultar Préstamos" << endl;
                    cout << "   A) Cantidad de objetos prestados por categoría" << endl;
                    cout << "   B) Listado de préstamos por categoría" << endl;
                    cout << "   C) Listado de préstamos ordenados por categoría o prestatario" << endl;
                    cout << "   D) Listar todos los prestatarios que tienen al menos un objeto prestado" << endl;
                    cout << "   X) Salir Al Menú Principal"<< endl;
                    cout << "   ingrese la opcion: ";
                    cin >> opcion;
                    switch (tolower(opcion))
                    {
                    case 'a':
                       // cantObjetosPorCategoria();
                        break;
                    case 'b':
                       // listadoPrestamosPorCategoria();
                        break;
                    case 'c':
                       // listadoPrestamosPorPrestatario();
                        break;
                    case 'd':
                       // prestatariosConobjetosPrestados();
                        break;
                    case 'x': 
                        break;
                    default:
                        cout << "ELIJA UNA OPCION CORRECTA" << endl;
                        break;
                    }
                } while (opcion != 'a', opcion != 'b', opcion != 'c', opcion != 'd', opcion !='x');
                break;
            case 254:
                break;
            default:
                cout << "POR FAVOR INGRESE UNA OPCION VALIDA" << endl;
                break;
            }
        } while (opcionPrincipal != 1, opcionPrincipal != 2, opcionPrincipal != 3, opcionPrincipal != 254);
        
    return 0;
}