#include <iostream>
#include <string>
using namespace std;

// *****************************************************************************************************
int dlCategorias = 1;
int dlprestamos = 1;
int dlprestatarios = 1;
const int MAX=15;

//Nodos
// Structs
struct NodoCategoria{
    int codigoCategoria;
    string descripcion;
    NodoCategoria * sigCategoria;
};

struct NodoPrestatario{
    int codigoPrestatario;
    string nombre;
    string apellido;
    NodoPrestatario * sigPrestatario;
};

struct NodoPrestamo{
    string Categoria; 
    string Prestatario;
    string descripcion;
    bool estado;
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
// *****************************************************************************************************
// Opcion 1 = Administrar y consultar Categorías y Prestatarios
// funciones secundarias de la opcion 1
NodoCategoria * guardarCat(NodoCategoria * inicioCategoria, NodoCategoria * nuevo){
    nuevo->sigCategoria=inicioCategoria;
    return nuevo;
}

NodoPrestatario * guardarPrestatario(NodoPrestatario * inicioPrestatario, NodoPrestatario * nuevo){
    nuevo->sigPrestatario=inicioPrestatario;
    return nuevo;
}

NodoPrestamo * guardarPrestamo(NodoPrestamo * inicioPrestamo, NodoPrestamo * nuevo){
    nuevo->sigPrestamo=inicioPrestamo;
    return nuevo;
}

void mostrarCategorias (NodoCategoria * inicioCategoria){
    for (NodoCategoria *i=inicioCategoria; i != nullptr; i = i->sigCategoria){
        cout<<"codigo: "<<i->codigoCategoria<<" - ";
        cout<<"descripcion: "<<i->descripcion<<endl;
    }
}

// void mostrarPrestatarios (NodoPrestatario * inicio){
// 
// }

// void mostrarPrestamos ()

// NodoCategoria * buscarCategoria ()
/*void buscarprestamo(NodoPrestamo*inicioPrestamo){
    for (NodoPrestamo* = i ; i!=nullptr;i=i->sigPrestamo)
    {
        if (i)
        {
            
        }
        
    }
    
}

NodoPrestamo * buscarPrestamo (NodoPrestamo * inicioPrestamo){
    NodoPrestamo * aux=inicioPrestamo;
    while (aux!= nullptr && aux->descripcion != descripcion){
        aux = aux->sigPrestamo;
    }
    return aux;
}

NodoPrestatario * buscarPrestatario (NodoPrestatario * inicioPrestatario, int codigo){
    NodoPrestatario * aux=inicioPrestatario;
    while ( aux !=nullptr && aux->codigoPrestatario != codigoPrestatario){
        aux = aux->sigPrestatario;
    }
    return aux;
}
*/
// *****************************************************************************************************
// *****************************************************************************************************
// Funciones principales de opcion 1

NodoCategoria * agregarCategoria (NodoCategoria * inicioCategoria){
    string desc;
    NodoCategoria * nuevo;
    int codigo = 0;
    cout<<"ingrese la descripcion de la nueva categoria (X para salir): ";
    getline(cin>>ws, desc);   //pido que lo inrgese por teclado

    while(desc != "X"){
        nuevo= new NodoCategoria;
        nuevo -> descripcion=desc;

        nuevo->codigoCategoria=codigo;
        nuevo->sigCategoria=nullptr;

        inicioCategoria=guardarCat(inicioCategoria, nuevo);
        codigo++;

    cout<<"ingrese la descripcion de la nueva categoria (X para salir): ";
    getline(cin>>ws, desc);   //pido que lo inrgese por teclado;
        
    }
    return inicioCategoria;
}
// *****************************************************************************************************
void modificarCategoria(NodoCategoria * inicioCategoria){
    mostrarCategorias(inicioCategoria);
    cout<<"ingrese el codigo de la categoria a modificar: ";
    cin>>codigo;
    string modificado;
    for (NodoCategoria * i = inicioCategoria;i!=nullptr; i= i->sigCategoria){
        if (codigo== i->codigoCategoria){
            cout<<"Ingrese el nuevo nombre de la categoria: "<<endl;
            getline(cin>>ws, modificado);
            i->descripcion=modificado;
        }
        else{
            cout<<"la categoria ingresada no existe"<<endl;
        }
        return;
        
    }
}
// *****************************************************************************************************

// void eliminarCategoria(NodoCategoria *&inicioCategoria, int &dlCategorias, int codigo){//funciona
//     cout << "Eliminar categoria" << endl;
//     cout << "Ingrese el codigo de la categoria a eliminar: ";
//     cin >> codigo;

//     while(codigo != 0){
//         if(inicioCategoria !=nullptr){
//             NodoCategoria *aux_borrar;
//             NodoCategoria *anterior = nullptr;
//             aux_borrar = inicioCategoria;

//             while((aux_borrar != nullptr) && (aux_borrar->categoria.codigoCategoria != codigo)){
//                 anterior = aux_borrar;
//                 aux_borrar = aux_borrar->sigCategoria;
//             }
//             if(aux_borrar == nullptr){
//                 cout << "El elemento no se encuentra en la lista" << endl;
//             }
//             else if(anterior == nullptr){
//                 inicioCategoria = inicioCategoria->sigCategoria;
//                 delete aux_borrar;
//                 cout << "El elemento se ha eliminado de la lista" << endl;
//             }
//             else{
//                 anterior->sigCategoria = aux_borrar->sigCategoria;
//                 delete aux_borrar;
//                 cout << "El elemento se ha eliminado de la lista" << endl;
//             }
//         }
//         else if(inicioCategoria == nullptr){
//             cout << "La lista se encuentra vacia" << endl;
//             break;
//         }
//         else{
//             cout << "La categoria seleccionada no existe" << endl;
//         }
//     }

//     // if(existePrestamo(prestamos, dlprestamos, codigo) == false){
//     //     for(int i = 0; i < dlCategorias; i++){
//     //         if(categorias[i].codigoCategoria == codigo){
//     //             for(int j = i; j < dlCategorias; j++){
//     //                 categorias[j] = categorias[j+1];
//     //             }
//     //             dlCategorias--;
//     //             cout << "Categoria eliminada con exito" << endl;
//     //             break;
//     //         }
//     //     }
//     // }
//     // else{
//     //     cout << "No se puede eliminar la categoria porque tiene prestamos asociados" << endl;
//     // }
//     // return 1;
// }

// // *****************************************************************************************************
// int agregarPrestatario(string nombre, string apellido, string descripcion, int &dlprestatarios, NodoPrestatario *&inicioPrestatario){//revisar
//     cout << "Agregar prestatario" << endl;

//     cout<<"Ingrese el nombre del prestatario(X para salir): ";
//     cin>>nombre;

//     while(nombre != "X" && nombre !="x" && dlprestatarios < MAX){//&& descripcion != "x" iba al medio del while(creo que no hace falta)
//         NodoPrestatario * nuevo = new NodoPrestatario;
//         nuevo->prestatario.codigoPrestatario = dlprestatarios;
//         cout<<"Ingrese el apellido del prestatario: ";
//         cin>>apellido;
//         nuevo->prestatario.apellido = apellido;
//         nuevo->prestatario.nombre = nombre;
//         nuevo->sigPrestatario = nullptr;
//         cout << "Prestatario agregado con exito \nCodigo: " << dlprestatarios << endl;
//         dlprestatarios++;
//         nuevo->prestatario.codigoPrestatario = dlprestatarios;
//     }
//     return dlprestatarios;
// }

// // *****************************************************************************************************
// int modificarPrestatario(bool existe, int codigo, int &dlprestatarios, NodoPrestatario * inicioPrestatario){ //revisar
//     cout << "Modificar prestatario" << endl;
//     NodoPrestatario * nuevo = new NodoPrestatario;
//     string nuevoNombre;
//     string apellidoNuevo;
 
//     cout<<"ingrese el codigo del prestatario a modificar: ";
//     cin>>codigo;

//     while((nuevo != nullptr) && (nuevo->prestatario.codigoPrestatario <= codigo)){
//         if(nuevo->prestatario.codigoPrestatario == codigo){
//             existe = true;
//         }
//         nuevo = nuevo->sigPrestatario;
//     }

//     if (existe == true){
//         cout<<"ingrese el nuevo nombre del prestatario: ";
//         cin>>nuevoNombre;
//         nuevo->prestatario.nombre = nuevoNombre;
//         cout<<"ingrese el nuevo apellido del prestatario: ";
//         cin>>apellidoNuevo;
//         nuevo->prestatario.apellido = apellidoNuevo;
//     }
//     else{
//         cout<<"el prestatario buscado no existe"<<endl;
//     }
//     return 1;
// }

// // for (int i=0; i=dlprestatarios; i++){
// //     if(codigoPrest==dlprestatarios){
// //         cout<<"ingrese el nuevo nombre del prestatario:";
// //         cin>>nuevoNombre;
// //         prestatarios[dlprestatarios].nombre = nuevoNombre;
// //         cout<<"ingrese el nuevo apellido del prestatario:";
// //         cin>>apellidoNuevo;
// //         prestatarios[dlprestatarios].apellido = apellidoNuevo;
// //     }
// //     else{
// //         cout << "no hay ningun prestatario registrado con ese nombre" << endl;
// //     }
// // }
// // return 1;


// // *****************************************************************************************************
// int eliminarPrestatario(Prestatario prestatarios[], int &dlprestatarios, Prestamo prestamos[], int &dlprestamos, int codigo){
//     cout << "Eliminar prestatario" << endl;
//     cout << "Ingrese el codigo del prestatario a eliminar(0 para salir): " << endl;
//     cin >> codigo;
    
//     while(codigo !=0){
//         if(existePrestamo(prestamos, dlprestatarios, codigo) == false){
//             for(int i = 0; i < dlprestatarios; i++){
//                 if(prestatarios[i].codigoPrestatario == codigo){
//                     for(int j = i; j < dlprestatarios; j++){
//                         prestatarios[j] = prestatarios[j+1];
//                     }
//                     dlprestatarios--;
//                     cout << "Prestatario eliminado con exito" << endl;
//                     break;
//                 }
//             }
//         }
//         else{
//             cout << "“El prestatario no puede eliminarse debido a que hay préstamos pendientes" << endl;
//         }
//         cout << "Ingrese el codigo del prestatario a eliminar(0 para salir): " << endl;
//         cin >> codigo;
//     }
//     return 1;
// }

// // *****************************************************************************************************
// // *****************************************************************************************************
// // Opcion 2 = Administrar Préstamos
// // funciones secundarias de opcion 2
// int mostrarCategorias(Categoria categorias[], int &dlCategorias){
//     cout << "Mostrar categorias" << endl;
//     for(int i = 1; i < dlCategorias; i++){
//         cout << "Codigo: " << categorias[i].codigoCategoria << endl;
//         cout << "Descripcion: " << categorias[i].descripcion << endl;
//         cout << "*****************************************" << endl;
//     }
//     return 1;
// }

// bool existeCategoria(Categoria categorias[], int &dlCategorias, int codigoCat){
//     for(int i = 0; i < dlCategorias; i++){
//         if(categorias[i].codigoCategoria == codigoCat){
//             return true;
//         }
//     }
//     return false;
// }

// int mostrarPrestatarios(Prestatario prestatarios[], int &dlprestatarios){
//     cout << "Prestatarios:" << endl;
//     for(int i = 0; i < dlprestatarios; i++){
//         cout << "   Codigo: " << prestatarios[i].codigoPrestatario << endl;
//         cout << "   Nombre: " << prestatarios[i].nombre << endl;
//         cout << "   Apellido: " << prestatarios[i].apellido << endl;
//         cout << "****************" << endl;
//     }
//     return 1;
// }

// bool existePrestatario(Prestatario prestatarios[], int &dlprestatarios, int codigoPrest){
//     for(int i = 1; i < dlprestatarios; i++){
//         if(prestatarios[i].codigoPrestatario == codigoPrest){
//             return true;
//         }
//     }
//     return false;
// }

// void imprimirPrestamo(Prestamo prestamos[], int &dlprestamos){
//     cout << "**********************************" << endl;
//     cout << "Prestamo agregado: " << endl;
//     cout << "   Categoria Codigo: " << prestamos[dlprestamos].categoria.codigoCategoria << endl;
//     cout << "   Categoria Descripcion: " << prestamos[dlprestamos].categoria.descripcion << endl;
//     cout << "   Prestatario Codigo: " << prestamos[dlprestamos].prestatario.codigoPrestatario << endl;
//     cout << "   Prestatario Nombre: " << prestamos[dlprestamos].prestatario.nombre<< endl;
//     cout << "   Prestatario Apellido: " << prestamos[dlprestamos].prestatario.apellido << endl;
//     cout << "   Descripcion: " << prestamos[dlprestamos].descripcion << endl;

// }
// // *****************************************************************************************************
// // *****************************************************************************************************
// // Funciones principales de opcion 2

// int agregarPrestamo(Categoria categorias[], int &dlCategorias, Prestamo prestamos[], int &dlprestamos, Prestatario prestatarios[], int &dlprestatarios, char opcion, int codigo, string descripcion){
//     cout << "Agregar prestamo" << endl;
//     cout << "Desea ver las categorias existentes? (S/N) (X para salir): ";
//     cin >> opcion;

//     switch (tolower(opcion))
//     {
//         case 's':
//             mostrarCategorias(categorias, dlCategorias);
//             cout << "Ingrese el codigo de la categoria(0 para salir): ";
//             cin >> codigo;

//             while(codigo != 0){
//                 if(existeCategoria(categorias, dlCategorias, codigo) == true){
//                     prestamos[dlprestamos].categoria.codigoCategoria = codigo;
//                     for(int i = 1; i < dlCategorias; i++){
//                         if(categorias[i].codigoCategoria == codigo){
//                             prestamos[dlprestamos].categoria.descripcion = categorias[i].descripcion;
//                         }
//                     }
//                     break;
//                 }else{
//                     cout << "No existe la categoria" << endl;
//                 }
//                 cout << "Ingrese el codigo de la categoria(0 para salir): ";
//                 cin >> codigo;  
//             }
//             break;
//         case 'n':
//              while(codigo != 0){
//                 if(existeCategoria(categorias, dlCategorias, codigo) == true){
//                     prestamos[dlprestamos].categoria.codigoCategoria = codigo;
//                     for(int i = 1; i < dlCategorias; i++){
//                         if(categorias[i].codigoCategoria == codigo){
//                             prestamos[dlprestamos].categoria.descripcion = categorias[i].descripcion;
//                         }
//                     }
//                     break;
//                 }else{
//                     cout << "No existe la categoria" << endl;
//                 }
//                 cout << "Ingrese el codigo de la categoria(0 para salir): ";
//                 cin >> codigo;  
//             }
//             break;
//         case 'x':
//             cout << "Saliendo..." << endl;
//             break;

//         default:
//             cout << "Opcion invalida" << endl;
//             break;
//     }
//     // *PRESTATARIO*

//     cout << "¿Desea ver los actuales prestatarios? (S/N) (X para salir): "; 
//     cin >> opcion;

//     switch (tolower(opcion))
//     {

//         case 's':
//         {
//             mostrarPrestatarios(prestatarios, dlprestatarios);
//             cout << "Ingrese el codigo del prestatario(0 para salir): ";
//             cin >> codigo;

//             while(codigo != 0){
//                 if(existePrestatario(prestatarios, dlprestatarios, codigo) == true){
//                     prestamos[dlprestamos].prestatario.codigoPrestatario = codigo;
//                     for(int i = 0; i < dlprestatarios; i++){
//                         if(prestatarios[i].codigoPrestatario == codigo){
//                             prestamos[dlprestamos].prestatario.nombre = prestatarios[i].nombre;
//                             prestamos[dlprestamos].prestatario.apellido = prestatarios[i].apellido;
//                         }
//                     }
//                     cout << "Ingrese la descripcion del prestamo: ";
//                     cin >> descripcion;
//                     prestamos[dlprestamos].descripcion = descripcion;
//                     prestamos[dlprestamos].estado = true;
//                     cout << "Prestamo agregado con exito" << endl;
//                     imprimirPrestamo(prestamos, dlprestamos);
//                     dlprestamos++;
//                     break;
//                 }
//                 else{
//                     cout << "Ingrese un codigo valido" << endl;
//                 }
//                 cout << "Ingrese el codigo del prestatario(0 para salir): ";
//                 cin >> codigo;
//                 }
//             break;
//         }
//         case 'n':
//             {
//             cout << "Ingrese el codigo del prestatario(0 para salir): ";
//             cin >> codigo;

//             while(codigo != 0){
//                 if(existePrestatario(prestatarios, dlprestatarios, codigo) == true){
//                     prestamos[dlprestamos].prestatario.codigoPrestatario = codigo;
//                     for(int i = 0; i < dlprestatarios; i++){
//                         if(prestatarios[i].codigoPrestatario == codigo){
//                             prestamos[dlprestamos].prestatario.nombre = prestatarios[i].nombre;
//                             prestamos[dlprestamos].prestatario.apellido = prestatarios[i].apellido;
//                         }
//                     }
//                     cout << "Ingrese la descripcion del prestamo: ";
//                     cin >> descripcion;
//                     prestamos[dlprestamos].descripcion = descripcion;
//                     prestamos[dlprestamos].estado = true;
//                     cout << "Prestamo agregado con exito" << endl;
//                     imprimirPrestamo(prestamos, dlprestamos);
//                     dlprestamos++;
//                     break;
//                 }
//                 else{
//                     cout << "No existe el prestatario" << endl;
//                 }
//                 cout << "Ingrese el codigo del prestatario(0 para salir): ";
//                 cin >> codigo;
//                 }
//             }
//             break;
//         case 'x':
//         {
//             cout << "Saliendo..." << endl;
//             }
//             break;
//         default:
//             cout << "Opcion invalida" << endl;
//             break;
//         }  
//     return 1;
// }

// // *****************************************************************************************************
// int modificarPrestamo(Prestatario prestatarios[], int &dlprestatarios, Prestamo prestamos[], int &dlprestamos, int codigo, string description){
//     cout << "Modificar prestamo" << endl;
//     mostrarPrestatarios(prestatarios, dlprestatarios);
//     cout << "Ingrese el codigo del prestatario del cual quiere modificar un prestamo (0 para salir): ";
//     cin >> codigo;
    
//     while(codigo != 0){
//         if(existePrestatario(prestatarios, dlprestatarios, codigo) == true){
//             cout << "Prestamos de: " << prestatarios[codigo].nombre << " " << prestatarios[codigo].apellido << endl;
//             for(int i = 0; i < dlprestamos; i++){
//                 if(prestamos[i].prestatario.codigoPrestatario == codigo){
//                     if(prestamos[i].estado == true){
//                         cout << "   Categoria: " << prestamos[i].categoria.descripcion << endl;
//                         cout << "   Prestamo: " << prestamos[i].descripcion << endl;
//                         cout << "   Numero de prestamo: " << i << endl;
//                         cout << "*************************" << endl;  
//                     }
//                 }
//             }
//             cout << "Ingrese el codigo del prestamo a devolver (0 para salir): ";
//             int codigoAux;
//             cin >> codigoAux;

//             while(codigoAux != 0){
//                 for(int i = 0; i < dlprestamos; i++){
//                     if(prestamos[i].prestatario.codigoPrestatario == codigo){
//                         if(prestamos[i].estado == true){
//                             if(i == codigoAux){
//                                 cout << "Ingrese la nueva descripcion del prestamo: ";
//                                 cin >> description;
//                                 prestamos[i].descripcion = description;

//                                 cout << "La nueva descripcion del prestamo es: " << prestamos[i].descripcion << endl;
//                                 cout << "**************************************" << endl;
//                                 cout << "Prestamo modificado con exito" << endl;
//                             }
//                         }
//                     }
//                     else{
//                     cout << "El prestamo no existe" << endl;
//                     }
//                 }
                
//                 cout << "Ingrese el codigo del prestamo a devolver (0 para salir): ";
//                 cin >> codigoAux;
//             }
//         }
//         else{
//             cout << "El prestatario no existe" << endl;
//         }
//         cout << "Ingrese el codigo del prestatario (0 para salir): ";
//         cin >> codigo;
//     }
//     return 1;
// }

// // *****************************************************************************************************
// int eliminarPrestamo(Prestamo prestamos[], int &dlprestamos, Prestatario prestatarios[], int &dlprestatarios, int codigo){
//     cout << "Eliminar prestamo" << endl;
//     mostrarPrestatarios(prestatarios, dlprestatarios);
//     cout << "Ingrese el codigo del prestatario (0 para salir): ";
//     cin >> codigo;
    
//     while(codigo != 0){
//         if(existePrestatario(prestatarios, dlprestatarios, codigo) == true){
//             cout << "Prestamos de: " << prestatarios[codigo].nombre << " " << prestatarios[codigo].apellido << endl;
//             for(int i = 0; i < dlprestamos; i++){
//                 if(prestamos[i].prestatario.codigoPrestatario == codigo){
//                     if(prestamos[i].estado == true){
//                         cout << "   Categoria: " << prestamos[i].categoria.descripcion << endl;
//                         cout << "   Prestamo: " << prestamos[i].descripcion << endl;
//                         cout << "   Numero de prestamo: " << i << endl;
//                         cout << "*************************" << endl;  
//                     }
//                 }
//             }
//             cout << "Ingrese el codigo del prestamo a eliminar (0 para salir): ";
//             int codigoAux;
//             cin >> codigoAux;

//             while(codigoAux != 0){
//                 for(int i = 0; i < dlprestamos; i++){
//                     if(prestamos[i].prestatario.codigoPrestatario == codigo){
//                         if(prestamos[i].estado == true){
//                             if(i == codigoAux){
//                                 for(int j = i; j < dlprestatarios; j++){
//                                     prestatarios[j] = prestatarios[j+1];
//                                 }
//                                 dlprestatarios--;
//                                 cout << "Prestamo eliminado con exito" << endl;
//                             }
//                         }
//                     }
//                     else{
//                     cout << "El prestamo no existe" << endl;
//                     }
//                 }
                
//                 cout << "Ingrese el codigo del prestamo a devolver (0 para salir): ";
//                 cin >> codigoAux;
//             }
//         }
//         else{
//             cout << "El prestatario no existe" << endl;
//         }
//         cout << "Ingrese el codigo del prestatario (0 para salir): ";
//         cin >> codigo;
//     }
//     return 1;
// }


// // *****************************************************************************************************
// int devolverPrestamo(Prestatario prestatarios[], int &dlprestatarios, Prestamo prestamos[], int &dlprestamos, int codigo){
//     cout << "Devolver prestamo" << endl;
//     mostrarPrestatarios(prestatarios, dlprestatarios);
//     cout << "Ingrese el codigo del prestatario (0 para salir): ";
//     cin >> codigo;
    
//     while(codigo != 0){
//         if(existePrestatario(prestatarios, dlprestatarios, codigo) == true){
//             cout << "Prestamos de: " << prestatarios[codigo].nombre << " " << prestatarios[codigo].apellido << endl;
//             for(int i = 0; i < dlprestamos; i++){
//                 if(prestamos[i].prestatario.codigoPrestatario == codigo){
//                     if(prestamos[i].estado == true){
//                         cout << "   Categoria: " << prestamos[i].categoria.descripcion << endl;
//                         cout << "   Prestamo: " << prestamos[i].descripcion << endl;
//                         cout << "   Numero de prestamo: " << i << endl;
//                         cout << "*************************" << endl;  
//                     }
//                 }
//             }
//             cout << "Ingrese el codigo del prestamo a devolver (0 para salir): ";
//             int codigoAux;
//             cin >> codigoAux;

//             while(codigoAux != 0){
//                 for(int i = 0; i < dlprestamos; i++){
//                     if(prestamos[i].prestatario.codigoPrestatario == codigo){
//                         if(prestamos[i].estado == true){
//                             if(i == codigoAux){
//                                 prestamos[i].estado = false;
//                                 cout << "Prestamo devuelto con exito" << endl;
//                             }
//                         }
//                     }
//                     else{
//                     cout << "El prestamo no existe" << endl;
//                     }
//                 }
                
//                 cout << "Ingrese el codigo del prestamo a devolver (0 para salir): ";
//                 cin >> codigoAux;
//             }
//         }
//         else{
//             cout << "El prestatario no existe" << endl;
//         }
//         cout << "Ingrese el codigo del prestatario (0 para salir): ";
//         cin >> codigo;
//     }
//     return 1;
// }
    
// // *****************************************************************************************************
// // *****************************************************************************************************

// // Opcion 3 = Consultar Préstamos
// //      Funciones secundarias de la opcion 3
// int contadorPrestamosPendientes(Prestamo prestamos[], int &dlprestamos){
//     int cantObjPen=0;
//     for(int j=0; j < dlprestamos; j++){
//         if(prestamos[j].estado == true){
//             cantObjPen++;
//         }
//     }
//     return cantObjPen;
// }
// // *****************************************************************************************************
// // *****************************************************************************************************

// // Opcion 3 = Consultar Préstamos
// void cantObjetosPorCategoria(Categoria categorias[], int &dlCategorias, Prestamo prestamos[], int &dlprestamos){
//     cout << "Cantidad de objetos por categoria" << endl;
//     for(int i = 0; i < dlCategorias; i++){
//         int cant = 0;
//         for(int j = 0; j < dlprestamos; j++){
//             if(prestamos[j].categoria.codigoCategoria == categorias[i].codigoCategoria){
//                 cant++;
//             }
//         }
//         cout << "   Categoria: " << categorias[i].descripcion << endl;
//         cout << "   Cantidad: " << cant << endl;
//         cout << "****************" << endl;
//     }
    
//     cout << "   Prestamos pendientes totales: "<< contadorPrestamosPendientes(prestamos, dlprestamos) << endl;
//     cout << "****************" << endl;

// }

// // *****************************************************************************************************

// int listadoPrestamosPorCategoria(Categoria categorias[], int &dlCategorias, Prestatario prestatarios[], int &dlprestatarios,Prestamo prestamos[], int &dlprestamos, int codigo){
//     cout << "Listado de prestamos pendientes por categoria" << endl;
//     cout << "Ingrese el codigo de la categoria(0 para salir): ";
//     cin >> codigo;

//     while(codigo != 0){
//         if(existeCategoria(categorias, dlCategorias, codigo) == true){
//             for(int i = 0; i < dlprestatarios; i++){
//                 for(int j = 0; j < dlprestamos; j++){
//                     if(prestamos[j].prestatario.codigoPrestatario == prestatarios[i].codigoPrestatario && prestamos[j].categoria.codigoCategoria == codigo){
//                         cout << "   Prestatario: " << prestatarios[i].nombre << " " << prestatarios[i].apellido << endl;
//                         cout << "   Categoria: " << prestamos[j].categoria.descripcion << endl;
//                         if(prestamos[j].estado == true){
//                             cout << "       Prestamo: " << prestamos[j].descripcion << endl;
//                             cout << "****************" << endl;
//                         }
//                     }
//                 }
//             }
//         }
//         else{
//             cout << "La categoria no existe" << endl;
//         }
//         cout << "Ingrese el codigo de la categoria(0 para salir): ";
//         cin >> codigo;
//     }
//     return 1;
// }

// // *****************************************************************************************************
// void listadoPrestamosPorPrestatario(Prestamo prestamos[], int &dlprestamos, Prestatario prestatarios[], int &dlprestatarios, char opcion, int codigo){
//     cout << "Listado de prestamos por prestatario" << endl;
//     cout << "   ¿Desea ver el listado por categoria(C) o Prestatario(P)?(X para salir) :";
//     cin >> opcion;

//     if(opcion == 'C' || opcion == 'c'){
//         cout << "Listado de prestamos por categoria" << endl;
//         // recorremos el array de prestamos
//         // por cada categoria imprimimos el nombre y todos los prestamos de esa categoria
//         for(int i = 0; i < dlprestamos; i++){
//             cout << "   Categoria: " << prestamos[i].categoria.descripcion << endl;
//             for(int j = 0; j < dlprestamos; j++){
//                 if(prestamos[j].categoria.codigoCategoria == prestamos[i].categoria.codigoCategoria){
//                     cout << "       Prestamo: " << prestamos[j].descripcion << endl;
//                     cout << "       Prestatario: " << prestamos[j].prestatario.nombre << " " << prestamos[j].prestatario.apellido << endl;
//                     cout << "*******************" << endl;
//                 }
//             }
//         }
//     }
//     else if(opcion == 'P' || opcion == 'p'){
//         cout << "Listado de prestamos por prestatario" << endl;
//         // recorremos el array de prestamos
//         // por cada prestatario imprimimos el nombre y todos los prestamos de ese prestatario
//         for(int i = 0; i < dlprestamos; i++){
//             cout << "   Prestatario: " << prestamos[i].prestatario.nombre << " " << prestamos[i].prestatario.apellido << endl;
//             for(int j = 0; j < dlprestamos; j++){
//                 if(prestamos[j].prestatario.codigoPrestatario == prestamos[i].prestatario.codigoPrestatario){
//                     cout << "       Prestamo: " << prestamos[j].descripcion << endl;
//                     cout << "       Categoria: " << prestamos[j].categoria.descripcion << endl;
//                     cout << "*******************" << endl;
//                 }
//             }
//         }
//     }
//     else if(opcion == 'X' || opcion == 'x'){
//         cout << "Saliendo..." << endl;
//     }
//     else{
//         cout << "Opcion incorrecta" << endl;
//     }
    
// }

// // *****************************************************************************************************
// int prestatariosConobjetosPrestados(Prestamo prestamos[], int &dlprestamos, Prestatario prestatarios[], int &dlprestatarios){
//     cout << "Prestatarios con objetos prestados" << endl;
//     //muestra los prestatarios que tienen objetos prestados
//      for(int i = 0; i < dlprestatarios; i++){
//         int cant = 0;
//         for(int j = 0; j < dlprestamos; j++){
//             if(prestamos[j].prestatario.codigoPrestatario == prestatarios[i].codigoPrestatario && prestamos[j].estado == true){
//                 cant++;
//             }
//         }
//         if(cant > 0){
//             cout << "   Nombre: " << prestatarios[i].nombre << endl;
//             cout << "   Apellido: " << prestatarios[i].apellido << endl;
//             cout << "   Cantidad de prestamos prendientes: " << cant << endl;
//             cout << "*****************************" << endl;  
//         }
//      }
//     return 1;
// }
//*####################################################################################################

// funcion principal
int main(){
    //Listas
    NodoCategoria * inicioCategoria=nullptr;
    NodoPrestamo * inicioPrestamo=nullptr;
    NodoPrestatario * inicioPrestatario=nullptr;

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
                        agregarCategoria(inicioCategoria);
                        break;
                    case 'b':
                        modificarCategoria(inicioCategoria);
                        break;
                    case 'c':
                        //eliminarCategoria();           
                        break;
                    case 'd':
                       // agregarPrestatario();
                        break;
                    case 'e':
                       // modificarPrestatario();
                        break;
                    case 'f':
                       // eliminarPrestatario();
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
                       // agregarPrestamo();                
                        break;
                    case 'b':
                       // modificarPrestamo();
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