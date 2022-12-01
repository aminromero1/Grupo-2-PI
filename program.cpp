#include <iostream>
#include <string>
using namespace std;

// *****************************************************************************************************
int codCategoria = 1;
int codPrestatario = 1;

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
    nuevo->sigPrestamo = inicioPrestamo;
    return nuevo;
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
        if(aux->prestamo.categoria.codigoCategoria == codigo){
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

NodoCategoria * agregarCategoria (NodoCategoria * inicioCategoria, int codigo, string descripcion, int &codCategoria){
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
            if(inicioCategoria->categoria.codigoCategoria == codigo){
                cout << "ingrese la nueva descripcion de la categoria: ";
                cin >> descripcion;
                inicioCategoria->categoria.descripcion = descripcion;
                cout << "Categoria modificada: " << endl;
                cout << "   Codigo: " << inicioCategoria->categoria.codigoCategoria << endl;
                cout << "   Descripcion: " << inicioCategoria->categoria.descripcion << endl;
            }
            else{
                NodoCategoria * aux = inicioCategoria;
                while(aux->sigCategoria != nullptr && aux->sigCategoria->categoria.codigoCategoria != codigo){
                    aux = aux->sigCategoria;
                }
                if(aux->sigCategoria != nullptr){
                    cout << "ingrese la nueva descripcion de la categoria: ";
                    cin >> descripcion;
                    aux->sigCategoria->categoria.descripcion = descripcion;
                    cout << "Categoria modificada: " << endl;
                    cout << "   Codigo: " << aux->sigCategoria->categoria.codigoCategoria << endl;
                    cout << "   Descripcion: " << aux->sigCategoria->categoria.descripcion << endl;
                }
                else{
                    cout << "No existe la categoria con el codigo ingresado" << endl;
                    break;
                }
            }
            cout << "ingrese el codigo de la categoria a modificar(0 para salir): ";
            cin >> codigo;   
        }
    }
    return inicioCategoria;  
}
// *****************************************************************************************************

NodoCategoria * eliminarCategoria(NodoCategoria *&inicioCategoria, NodoPrestamo * inicioPrestamo, int codigo){
    cout << "Eliminar categoria" << endl;
    mostrarCategorias(inicioCategoria);
    cout << "Ingrese el codigo de la categoria a eliminar(0 para salir): ";
    cin >> codigo;

    while(codigo != 0){
        NodoCategoria *aux = inicioCategoria;
        NodoCategoria *aEliminar;

        while(aux != nullptr){
            if (existePrestamo(inicioPrestamo, codigo) == false){
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
NodoPrestatario * agregarPrestatario(NodoPrestatario *&inicioPrestatario, string nombre, string apellido, int &codPrestatario){
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
                if(inicioPrestatario->prestatario.codigoPrestatario == codigo){
                    cout << "Ingrese el nuevo nombre del prestatario: ";
                    cin >> nombre;
                    inicioPrestatario->prestatario.nombre = nombre;
                    cout << "Ingrese el nuevo apellido del prestatario: ";
                    cin >> apellido;
                    inicioPrestatario->prestatario.apellido = apellido;
                    cout << "Prestatario modificado: " << endl;
                    cout << "   Codigo: " << inicioPrestatario->prestatario.codigoPrestatario << endl;
                    cout << "   Nombre: " << inicioPrestatario->prestatario.nombre << " " << inicioPrestatario->prestatario.apellido << endl;
                }
                else{
                    NodoPrestatario * aux = inicioPrestatario;
                    while(aux->sigPrestatario != nullptr && aux->sigPrestatario->prestatario.codigoPrestatario != codigo){
                        aux = aux->sigPrestatario;
                    }
                    if(aux->sigPrestatario != nullptr){
                        cout << "Ingrese el nuevo nombre del prestatario: ";
                        cin >> nombre;
                        aux->sigPrestatario->prestatario.nombre = nombre;
                        cout << "Ingrese el nuevo apellido del prestatario: ";
                        cin >> apellido;
                        aux->sigPrestatario->prestatario.apellido = apellido;
                        cout << "Prestatario modificado: " << endl;
                        cout << "   Codigo: " << aux->sigPrestatario->prestatario.codigoPrestatario << endl;
                        cout << "   Nombre: " << aux->sigPrestatario->prestatario.nombre << endl;
                        cout << "   Apellido: " << aux->sigPrestatario->prestatario.apellido << endl;
                    }
                }
            }          
            cout << "ingrese el codigo del prestatario a modificar(0 para salir): ";
            cin >> codigo;
        }
    }
    return inicioPrestatario;
}

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
        cout << "   Apellido: " << i->prestatario.apellido << endl;
        cout << "****************" << endl;
    }
}

void imprimirPrestamo(NodoPrestamo * nuevo){
    cout << "**********************************" << endl;
    cout << "Prestamo agregado: " << endl;
    cout << "   Categoria Codigo: " << nuevo->prestamo.categoria.codigoCategoria << endl;
    cout << "   Categoria Descripcion: " << nuevo->prestamo.categoria.descripcion << endl;
    cout << "   Prestatario Codigo: " << nuevo->prestamo.prestatario.codigoPrestatario << endl;
    cout << "   Prestatario Nombre: " << nuevo->prestamo.prestatario.nombre << endl;
    cout << "   Prestatario Apellido: " << nuevo->prestamo.prestatario.apellido << endl;
    cout << "   Descripcion del prestamo: " << nuevo->prestamo.descripcion << endl;
}

void mostrarPrestamos(NodoPrestamo * inicioPrestamo, int codigo){
    cout << "Prestamos pendientes:" << endl;
    int j = 1;
    for(NodoPrestamo * i = inicioPrestamo; i != nullptr; i = i->sigPrestamo){
        if(i->prestamo.prestatario.codigoPrestatario == codigo){
            if(i->prestamo.estado == true){
                cout << "   Categoria: " << i->prestamo.categoria.descripcion << endl;
                cout << "   Prestamo: " << i->prestamo.descripcion << endl;
                cout << "   Numero de prestamo: " << j << endl;
                cout << "****************" << endl;
                j++;
            }
            else{
                cout << "El prestatario no tiene prestamos prendientes" << endl;
            }
        }
        
    }
}

void mostrarPrestamosFinalizados(NodoPrestamo * inicioPrestamo, int codigo){
    cout << "Prestamos finalizados:" << endl;
    int j = 1;
    for(NodoPrestamo * i = inicioPrestamo; i != nullptr; i = i->sigPrestamo){
        if(i->prestamo.prestatario.codigoPrestatario == codigo){
            if(i->prestamo.estado == false){
                cout << "   Categoria: " << i->prestamo.categoria.descripcion << endl;
                cout << "   Prestamo: " << i->prestamo.descripcion << endl;
                cout << "   Numero de prestamo: " << j << endl;
                cout << "****************" << endl;
                j++;
            }
            else{
                cout << "El prestatario no tiene prestamos finalizados" << endl;
            }
        }     
    }
}

// *****************************************************************************************************
// *****************************************************************************************************
// Funciones principales de opcion 2

NodoPrestamo * agregarPrestamo(NodoPrestamo * inicioPrestamo, NodoCategoria * inicioCategoria, NodoPrestatario * inicioPrestatario, char opcion, int codigo, string descripcion){
    cout << "Agregar prestamo" << endl;
    cout << "Desea ver las categorias existentes? (S/N) (X para salir): ";
    cin >> opcion;

    NodoPrestamo * nuevo;
    nuevo = new NodoPrestamo;
    
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
                    break;
                }else{
                    cout << "No existe la categoria" << endl;
                    break;
                }
                cout << "Ingrese el codigo de la categoria(0 para salir): ";
                cin >> codigo;  
            }
            break;
        case 'n':
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
                if(existePrestatario(inicioPrestatario, codigo) == true){
                    nuevo->prestamo.prestatario.codigoPrestatario = codigo;
                    for(NodoPrestatario * i = inicioPrestatario; i != nullptr; i = i->sigPrestatario){
                        if(i->prestatario.codigoPrestatario == codigo){
                            nuevo->prestamo.prestatario.nombre = i->prestatario.nombre;
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
                    inicioPrestamo=guardarPrestamo(inicioPrestamo, nuevo);
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
                if(existePrestatario(inicioPrestatario, codigo) == true){
                    nuevo->prestamo.prestatario.codigoPrestatario = codigo;
                    for(NodoPrestatario * i = inicioPrestatario; i != nullptr; i = i->sigPrestatario){
                        if(i->prestatario.codigoPrestatario == codigo){
                            nuevo->prestamo.prestatario.nombre = i->prestatario.nombre;
                            nuevo->prestamo.prestatario.apellido = i->prestatario.apellido;
                        }
                    }
                    cout << "Ingrese la descripcion del prestamo: ";
                    cin >> descripcion;
                    nuevo->prestamo.descripcion = descripcion;
                    nuevo->prestamo.estado = true;
                    
                    cout << "Prestamo agregado con exito" << endl;

                    imprimirPrestamo(nuevo);
                    inicioPrestamo=guardarPrestamo(inicioPrestamo, nuevo);
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
    
    }
    return inicioPrestamo;
}

// *****************************************************************************************************
NodoPrestamo * modificarPrestamo(NodoPrestatario * inicioPrestatario, NodoPrestamo * inicioPrestamo, int codigo, string descripcion){
    cout << "Modificar prestamo" << endl;
    mostrarPrestatarios(inicioPrestatario);

    cout << "Ingrese el codigo del prestatario del cual quiere modificar un prestamo (0 para salir): ";
    cin >> codigo;
    
    while(codigo != 0){
        if(existePrestatario(inicioPrestatario, codigo) == true){
            mostrarPrestamos(inicioPrestamo, codigo);
            
            cout << "Ingrese el codigo del prestamo a modificar(0 para salir): ";
            int codigoAux;
            cin >> codigoAux;

            while(codigoAux != 0){
                int j = 1;
                for(NodoPrestamo * i = inicioPrestamo; i != nullptr; i = i->sigPrestamo){
                    if(i->prestamo.prestatario.codigoPrestatario == codigo){
                        if(i->prestamo.estado == true){
                            if(j == codigoAux){
                                cout << "Ingrese la nueva descripcion del prestamo: ";
                                cin >> descripcion;
                                i->prestamo.descripcion = descripcion;

                                cout << "   La nueva descripcion del prestamo es: " << i->prestamo.descripcion << endl;
                                cout << "   **************************************" << endl;
                                cout << "   Prestamo modificado con exito" << endl;
                            }
                            else{
                                j++;
                            }
                        }
                        else{
                            cout << "El prestatario no tiene prestamos prendientes" << endl;
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
    return inicioPrestamo;
}

// *****************************************************************************************************
NodoPrestamo * eliminarPrestamo(NodoPrestamo * inicioPrestamo, NodoPrestatario * inicioPrestatario, int codigo){
    cout << "Eliminar prestamo" << endl;
    mostrarPrestatarios(inicioPrestatario);
    cout << "Ingrese el codigo del prestatario (0 para salir): ";
    cin >> codigo;
    
    while(codigo != 0){
        if(existePrestatario(inicioPrestatario, codigo) == true){
            mostrarPrestamosFinalizados(inicioPrestamo, codigo);
            
            cout << "Ingrese el codigo del prestamo a eliminar(0 para salir): ";
            int codigoAux;
            cin >> codigoAux;

            while(codigoAux != 0){
                NodoPrestamo * aux = inicioPrestamo;
                NodoPrestamo * aEliminar;
                int j = 1;
                while(aux !=nullptr){
                    for(NodoPrestamo * i = inicioPrestamo; i != nullptr; i = i->sigPrestamo){
                        if(i->prestamo.prestatario.codigoPrestatario == codigo){//*************************
                            if(i->prestamo.estado == false){
                                if(j == codigoAux){
                                    aEliminar = i;
                                    aux->sigPrestamo = i->sigPrestamo;
                                    delete aEliminar;
                                    cout << "Prestamo eliminado con exito" << endl;
                                }
                                else{
                                    j++;
                                }
                            }
                            else{
                                cout << "El prestatario no tiene prestamos prendientes" << endl;
                            }
                        }
                        else{
                        cout << "El prestamo no existe" << endl;
                        }
                    }
                }
            }
        }
        else{
            cout << "El prestatario no existe" << endl;
        }
        cout << "Ingrese el codigo del prestatario (0 para salir): ";
        cin >> codigo;
    }
    return inicioPrestamo;
}

// *****************************************************************************************************
NodoPrestamo * devolverPrestamo(NodoPrestamo * inicioPrestamo, NodoPrestatario * inicioPrestatario, int codigo){
    cout << "Devolver prestamo" << endl;
    mostrarPrestatarios(inicioPrestatario);
    cout << "Ingrese el codigo del prestatario (0 para salir): ";
    cin >> codigo;
    
    while(codigo != 0){
        if(existePrestatario(inicioPrestatario, codigo) == true){
            mostrarPrestamos(inicioPrestamo, codigo);
            
            cout << "Ingrese el codigo del prestamo a devolver(0 para salir): ";
            int codigoAux;
            cin >> codigoAux;

            while(codigoAux != 0){
                int j = 1;
                for(NodoPrestamo * i = inicioPrestamo; i != nullptr; i = i->sigPrestamo){
                    if(i->prestamo.prestatario.codigoPrestatario == codigo){
                        if(i->prestamo.estado == true){
                            if(j == codigoAux){
                                i->prestamo.estado = false;
                                cout << "   Prestamo devuelto con exito" << endl;
                                cout << "   **************************************" << endl;  
                                break;                             
                            }
                            else{
                                j++;
                            }
                        }
                        else{
                            cout << "El prestatario no tiene prestamos pendientes" << endl;
                            break;
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
    return inicioPrestamo;
}
    
// *****************************************************************************************************
// *****************************************************************************************************

// Opcion 3 = Consultar Préstamos
// Funciones secundarias de la opcion 3
int contadorPrestamosPendientes( NodoPrestamo * inicioPrestamo){
    int cantObjPen=0;
    for(NodoPrestamo * i = inicioPrestamo; i != nullptr; i = i->sigPrestamo){
        if(i->prestamo.estado == true){
            cantObjPen++;
        }
    }
    return cantObjPen;
}

// *****************************************************************************************************
// *****************************************************************************************************
// Opcion 3 = Consultar Préstamos
void cantObjetosPorCategoria(NodoCategoria * inicioCategoria, NodoPrestamo * inicioPrestamo){
    cout << "Cantidad de objetos por categoria" << endl;
    for(NodoCategoria * i = inicioCategoria; i != nullptr; i = i->sigCategoria){
        int cant = 0;
        for(NodoPrestamo * j = inicioPrestamo; j != nullptr; j = j->sigPrestamo){
            if(j->prestamo.categoria.codigoCategoria == i->categoria.codigoCategoria){
                cant++;
            }
        }
        cout << "   Categoria: " << i->categoria.descripcion << endl;
        cout << "   Cantidad: " << cant << endl;
        cout << "****************" << endl;
    
    
    cout << "   Prestamos pendientes totales: "<< contadorPrestamosPendientes(inicioPrestamo) << endl;
    cout << "****************" << endl;
    }
}
// *****************************************************************************************************

void listadoPrestamosPorCategoria(NodoCategoria * inicioCategoria,NodoPrestatario * inicioPrestatario, NodoPrestamo * inicioPrestamo, int codigo){
    cout << "Listado de prestamos pendientes por categoria" << endl;
    mostrarCategorias(inicioCategoria);
    cout << "*****************" << endl;
    cout << "Ingrese el codigo de la categoria(0 para salir): ";
    cin >> codigo;

    while(codigo != 0){
        if(existeCategoria(inicioCategoria, codigo) == true){
            for(NodoPrestatario * aux = inicioPrestatario; aux != nullptr; aux = aux->sigPrestatario){
                for(NodoPrestamo * i = inicioPrestamo; i != nullptr; i = i->sigPrestamo){
                    if(i->prestamo.prestatario.codigoPrestatario == aux->prestatario.codigoPrestatario){
                        if(i->prestamo.categoria.codigoCategoria == codigo){
                            cout << "   Prestatario: " << i->prestamo.prestatario.nombre << " " << i->prestamo.prestatario.apellido << endl;
                            cout << "   Categoria: " << i->prestamo.categoria.descripcion << endl;
                            if(i->prestamo.estado == true){
                                cout << "   Prestamo: " << i->prestamo.descripcion << endl;
                                cout << "****************" << endl;
                            }
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
}

// *****************************************************************************************************
void listadoPrestamosPorPrestatario(NodoCategoria * inicioCategoria,NodoPrestatario * inicioPrestatario, NodoPrestamo * inicioPrestamo, char opcion, int codigo){
    cout << "Listado de prestamos por prestatario" << endl;
    cout << "   ¿Desea ver el listado por categoria(C) o Prestatario(P)?(X para salir) :";
    cin >> opcion;
    opcion = toupper(opcion);
    if(opcion == 'C'){
        cout << "Listado de prestamos por categoria" << endl;
        // recorremos el array de prestamos
        // por cada categoria imprimimos el nombre y todos los prestamos de esa categoria
        for(NodoCategoria * i = inicioCategoria; i != nullptr; i = i->sigCategoria){
            cout << "   Categoria: " << i->categoria.descripcion << endl;
            for(NodoPrestamo * j = inicioPrestamo; j != nullptr; j = j->sigPrestamo){
                if(j->prestamo.categoria.codigoCategoria == i->categoria.codigoCategoria){
                    cout << "   Prestamo: " << j->prestamo.descripcion << endl;
                    cout << "   Prestatario: " << j->prestamo.prestatario.nombre << " " << j->prestamo.prestatario.apellido << endl;
                    cout << "****************" << endl;
                }
            }
        }
    }
    else if(opcion == 'P'){
        cout << "Listado de prestamos por prestatario" << endl;
        // recorremos el array de prestamos
        // por cada prestatario imprimimos el nombre y todos los prestamos de ese prestatario
        for(NodoPrestatario * i = inicioPrestatario; i != nullptr; i = i->sigPrestatario){
            cout << "   Prestatario: " << i->prestatario.nombre << " " << i->prestatario.apellido << endl;
            for(NodoPrestamo * j = inicioPrestamo; j != nullptr; j = j->sigPrestamo){
                if(j->prestamo.prestatario.codigoPrestatario == i->prestatario.codigoPrestatario){
                    cout << "   Prestamo: " << j->prestamo.descripcion << endl;
                    cout << "   Categoria: " << j->prestamo.categoria.descripcion << endl;
                    cout << "****************" << endl;
                }
            }
        }
    }
    else if(opcion == 'X'){
        cout << "Saliendo..." << endl;
    }
    else{
        cout << "Opcion incorrecta" << endl;
    }
}

// *****************************************************************************************************
void prestatariosConobjetosPrestados(NodoPrestamo * inicioPrestamo,NodoPrestatario * inicioPrestatario){
    cout << "Prestatarios con objetos prestados" << endl;
    //muestra los prestatarios que tienen objetos prestados
    for(NodoPrestatario * aux = inicioPrestatario; aux != nullptr; aux = aux->sigPrestatario){
        int cant = 0;
        for(NodoPrestamo * aux2 = inicioPrestamo; aux2 != nullptr; aux2 = aux2->sigPrestamo){
            if(aux2->prestamo.prestatario.codigoPrestatario == aux->prestatario.codigoPrestatario && aux2->prestamo.estado == true){
                cant++;
            }
        }
        if(cant > 0){
            cout << "   Prestatario: " << aux->prestatario.nombre << " " << aux->prestatario.apellido << endl;
            cout << "   Cantidad de prestamos: " << cant << endl;
            cout << "****************" << endl;
        }
    }
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
                        inicioCategoria = eliminarCategoria(inicioCategoria, inicioPrestamo, codigo);           
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
                        inicioPrestamo = agregarPrestamo(inicioPrestamo, inicioCategoria, inicioPrestatario, opcion, codigo, descripcion);                
                        break;
                    case 'b':
                        inicioPrestamo = modificarPrestamo(inicioPrestatario, inicioPrestamo, codigo, descripcion);
                        break;
                    case 'c':
                        inicioPrestamo = eliminarPrestamo(inicioPrestamo, inicioPrestatario, codigo);
                        break;
                    case 'd':
                        inicioPrestamo = devolverPrestamo(inicioPrestamo, inicioPrestatario, codigo);
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
                        cantObjetosPorCategoria(inicioCategoria, inicioPrestamo);
                        break;
                    case 'b':
                        listadoPrestamosPorCategoria(inicioCategoria, inicioPrestatario, inicioPrestamo, codigo);
                        break;
                    case 'c':
                        listadoPrestamosPorPrestatario(inicioCategoria, inicioPrestatario, inicioPrestamo, opcion,codigo);
                        break;
                    case 'd':
                        prestatariosConobjetosPrestados(inicioPrestamo, inicioPrestatario);
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