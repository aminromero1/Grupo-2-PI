#include <iostream>
#include <string>
using namespace std;

// ****************************************
int dlCategorias = 0;
int dlprestamos = 0;
int dlprestatarios = 0;
int df=15;
const int MAX=15;

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
    struct Categoria categoria;
    struct Prestatario prestatario;
    string descripcion;
    bool estado;
};
// ***********************************************
// Variables
int opcionPrincipal;
char opcionCase;
string descripcion;
int codigo;

// ***********************************************
Prestatario prestatarios[15];
Prestamo prestamos[15];
Categoria categorias[15]; 

// ***********************************************
// Opcion 1 = Administrar y consultar Categorías y Prestatarios
// ************************************************************************
// ************************************************************************

int agregarCategoria(Categoria categorias[], int &dlCategorias){
    // el codigo de la categoria es el indice del array
    string descripcion;
    categorias[dlCategorias].codigoCategoria = dlCategorias;
    cout<<"Ingrese la descripcion de la categoria(X para salir): ";
    cin>>descripcion;

    while(descripcion != "X" && dlCategorias < MAX){
        categorias[dlCategorias].descripcion = descripcion;
        cout << "Categoria agregada con exito \nodigo: " << dlCategorias << endl;
        dlCategorias++;
        categorias[dlCategorias].codigoCategoria = dlCategorias;
        cout<<"Ingrese la descripcion de la categoria(X para salir): ";
        cin>>descripcion;
    }
    return dlCategorias;
} 

int modificarCategoria(Categoria categorias[], int &dlCategorias){
    int codigo_mod;
    string nueva_desc;
 
    cout<<"ingrese el codigo de la categoria a modificar: ";
    cin>>codigo_mod;
    for (int i=0; i=dlCategorias; i++){
        if(codigo_mod==dlCategorias){
            cout<<"ingrese la nueva descripcion de la categoria:";
            cin>>nueva_desc;
            categorias[dlCategorias].descripcion = nueva_desc;
        }
        else{
            cout<<"la categoria seleccionada no existe"<<endl;
        }
    }
    return 1;
}

// funcion secundaria a EliminarCategoria
bool existePrestamo(Prestamo prestamos[], int &dlprestamos, int codigoCategorias){
    for(int i=0; i < dlprestamos; i++)
        if(prestamos[i].categoria.codigoCategoria == codigoCategorias)
            return true;
    return false;
}
//********************************************************************************


int eliminarCategoria(Categoria categorias[], int &dlCategorias, Prestamo prestamos[], int &dlprestamos, int codigo){
    cout << "Eliminar categoria" << endl;
    cout << "Ingrese el codigo de la categoria a eliminar: ";
    cin >> codigo;

    if(existePrestamo(prestamos, dlprestamos, codigo) == false){
        for(int i = 0; i < dlCategorias; i++){
            if(categorias[i].codigoCategoria == codigo){
                for(int j = i; j < dlCategorias; j++){
                    categorias[j] = categorias[j+1];
                }
                dlCategorias--;
                cout << "Categoria eliminada con exito" << endl;
                break;
            }
        }
    }
    else{
        cout << "No se puede eliminar la categoria porque tiene prestamos asociados" << endl;
    }
    return 1;
}

int agregarPrestatario(Prestatario prestatarios[], int &dlprestatarios){
    cout << "Agregar prestatario" << endl;
    string nombre;
    prestatarios[dlprestatarios].codigoPrestatario = dlprestatarios;

    cout<<"Ingrese el nombre del prestatario(X para salir): ";
    cin>>nombre;
    while(nombre != "X" && dlprestatarios < MAX){
        cout<<"Ingrese el apellido del prestatario: ";
        cin>>prestatarios[dlprestatarios].apellido;
        prestatarios[dlprestatarios].nombre = nombre;
        cout << "Prestatario agregado con exito \n codigo: " << dlprestatarios << endl;
        dlprestatarios++;
        prestatarios[dlprestatarios].codigoPrestatario = dlprestatarios;
        cout<<"Ingrese el nombre del prestatario(X para salir): ";
        cin>>nombre;
    }
    return dlprestatarios;
    
}

int modificarPrestatario(Prestatario prestatarios[], int &dlprestatarios){
    cout << "Modificar prestatario" << endl;
    int codigoPrest;
    string nuevoNombre;
    string apellidoNuevo;
 
    cout<<"ingrese el codigo del prestatario a modificar: ";
    cin>>codigoPrest;
    for (int i=0; i=dlprestatarios; i++){
        if(codigoPrest==dlprestatarios){
            cout<<"ingrese el nuevo nombre del prestatario:";
            cin>>nuevoNombre;
            prestatarios[dlprestatarios].nombre = nuevoNombre;
            cout<<"ingrese el nuevo apellido del prestatario:";
            cin>>apellidoNuevo;
            prestatarios[dlprestatarios].apellido = apellidoNuevo;
        }
        else{
            cout << "no hay ningun prestatario registrado con ese nombre" << endl;
        }
    }
    return 1;
}

// funcion secundaria a EliminarPestatatario
bool existePrestamo(Prestatario prestatarios[], Prestamo prestamos[], int & dlprestatarios, int codigo){
    for(int i=0; i < dlprestatarios; i++)
        if(prestamos[i].prestatario.codigoPrestatario == codigo)
            return true;
    return false;
}

// Opcion 2 = Administrar Préstamos
// ************************************************************************
int eliminarPrestatario(Prestatario prestatarios[], int &dlprestatarios, Prestamo prestamos[], int &dlprestamos, int codigo){
    cout << "Eliminar prestatario" << endl;
    cout << "Ingrese el codigo del prestatario a eliminar: " << endl;
    cin >> codigo;

    bool existe = existePrestamo(prestatarios, prestamos, dlprestatarios, codigo);

    if(existe == false){
        for(int i = 0; i < dlprestatarios; i++){
            if(prestatarios[i].codigoPrestatario == codigo){
                for(int j = i; j < dlprestatarios; j++){
                    prestatarios[j] = prestatarios[j+1];
                }
                dlprestatarios--;
                cout << "Prestatario eliminada con exito" << endl;
                break;
            }
        }
    }
    else{
        cout << "“El prestatario no puede eliminarse debido a que hay préstamos pendientes" << endl;
    }
    return 1;
}

// ************************************************************************
// funciones secundarias a agregarPrestamo
int mostrarCategorias(Categoria categorias[], int &dlCategorias){
    cout << "Mostrar categorias" << endl;
    for(int i = 0; i < dlCategorias; i++){
        cout << "Codigo: " << categorias[i].codigoCategoria << endl;
        cout << "Descripcion: " << categorias[i].descripcion << endl;
        cout << "*****************************************" << endl;
    }
    return 1;
}

bool existeCategoria(Categoria categorias[], int &dlCategorias, int codigoCat){
    for(int i = 0; i < dlCategorias; i++){
        if(categorias[i].codigoCategoria == codigoCat){
            return true;
        }
    }
    return false;
}

int mostrarPrestatarios(Prestatario prestatarios[], int &dlprestatarios){
    cout << "Mostrar prestatarios" << endl;
    for(int i = 0; i < dlprestatarios; i++){
        cout << "Codigo: " << prestatarios[i].codigoPrestatario << endl;
        cout << "Nombre: " << prestatarios[i].nombre << endl;
        cout << "Apellido: " << prestatarios[i].apellido << endl;
        cout << "*****************************************" << endl;
    }
    return 1;
}

bool existePrestatario(Prestatario prestatarios[], int &dlprestatarios, int codigoPrestatario){
    for(int i = 0; i < dlprestatarios; i++){
        if(prestatarios[i].codigoPrestatario == codigoPrestatario){
            return true;
        }
    }
    return false;
}
// *****************************************************************************************************

int agregarPrestamo(Categoria categorias[], int &dlCategorias, Prestamo prestamos[], int &dlprestamos, Prestatario prestatarios[], int &dlprestatarios){
    cout << "Agregar prestamo" << endl;
    int codigoCat;
    int codigoPrest;
    char opcion;
    cout << "Desea ver las categorias existentes? (S/N): ";
    cin >> opcion;
    opcion = toupper(opcion);

    if(opcion == 'S'){
        mostrarCategorias(categorias, dlCategorias);
        cout << "Ingrese el codigo de la categoria: ";
        cin >> codigoCat;
        prestamos[dlprestamos].categoria.codigoCategoria = codigoCat;
        
    }else{
        cout << "Ingrese el codigo de la categoria: ";
        cin >> codigoCat;
        if(existeCategoria(categorias, dlCategorias, codigoCat) == true){
            prestamos[dlprestamos].categoria.codigoCategoria = codigoCat;
            
        }else{
            cout << "No existe la categoria" << endl;
        }
    }

    cout << "¿Desea ver los actuales prestatarios (S/N): ?";
    cin >> opcion;
    if(opcion == 'S'){
        mostrarPrestatarios(prestatarios, dlprestatarios);
        cout << "Ingrese el codigo del prestatario: ";
        cin >> codigoPrest;
        prestamos[dlprestamos].prestatario.codigoPrestatario = codigoPrest;
        
    }else{
        cout << "Ingrese el codigo del prestatario: ";
        cin >> codigoPrest;
        if(existePrestatario(prestatarios, dlprestatarios, codigoPrest) == true){
            prestamos[dlprestamos].prestatario.codigoPrestatario = codigoPrest;
            
        }else{
            cout << "No existe el prestatario" << endl;
        }
    }
    
    cout << "Ingrese la descripcion del prestamo: ";
    cin >> prestamos[dlprestamos].descripcion;
    prestamos[dlprestamos].estado = true;
    cout << "Prestamo agregado con exito" << endl;
    dlprestamos++;
    return 1;
}
// *****************************************************************************************************
// *****************************************************************************************************


int modificarPrestamo(Prestamo prestamos[], int &dlprestamos){
    int codigo_modPr;
    string nueva_descPr;

    cout<<"ingrese el codigo del prestamo a modificar: ";
    cin>>codigo_modPr;
    for (int i=0; i=dlprestamos; i++){
        if(codigo_modPr==dlprestamos){
            cout<<"ingrese la nueva descripcion de la categoria:";
            cin>>nueva_descPr;
            prestamos[dlprestamos].descripcion = nueva_descPr;
            }
            else{
                cout<<"el prestamo seleccionado no existe"<<endl;
            }
        }
    return 1;
}

void eliminarPrestamo(){
    cout << "Eliminar prestamo" << endl;
}
// Funcion secundaria a devolver prestamo


// **************************************************************************
void devolverPrestamo(Prestatario prestatarios[], int &dlprestatarios, Prestamo prestamos[], int &dlprestamos){
    cout << "Devolver prestamo" << endl;
    mostrarPrestatarios(prestatarios, dlprestatarios);
    int codigoPrestatario;
    cout << "Ingrese el codigo del prestatario: ";
    cin >> codigoPrestatario;
    // mostrar prestamos del prestatario
    for(int i = 0; i < dlprestamos; i++){
        if(prestamos[i].prestatario.codigoPrestatario == codigoPrestatario){
            // cambiar estado a false
            prestamos[i].estado = false;
        }
    }
}
// ************************************************************************


// Opcion 3 = Consultar Préstamos
// ************************************************************************
// ************************************************************************

void cantObjetosPorCategoria(){
    cout << "Cantidad de objetos por categoria" << endl;
    //muestra muestra todos los objetos existentes en cada categoria
}

void listadoPrestamosPorCategoria(){
    cout << "Listado de prestamos por categoria" << endl;
    //muestra el listado de objetos por categoria
}

void listadoPrestamosPorPrestatario(){
    cout << "Listado de prestamos por prestatario" << endl;
    //muestra el listado de prestamos por prestatario
}

void prestatariosConobjetosPrestados(){
    cout << "Prestatarios con objetos prestados" << endl;
    //muestra un listado de prestatarios que tengan uno o mas objetos prestados
}

//***############################################################################################################################################

// funcion principal
int main(){
        do{
            cout << "1. Administrar y consultar Categorías y Prestatarios" << endl;
            cout << "2. Administrar Préstamos" << endl;
            cout << "3. Consultar Préstamos" << endl;
            cout << "ingrese una opcion: ";
            cin >> opcionPrincipal;

            switch (opcionPrincipal)
            {
            case 1:
                do
                {
                    cout << "Administrar y consultar Categorías y Prestatarios" << endl;
                    cout << "  A) Agregar categoría" << endl;
                    cout << "  B) Modificar categoría" << endl;
                    cout << "  C) Eliminar categoría" << endl;
                    cout << "  D) Agregar prestatario" << endl;
                    cout << "  E) Modificar prestatario" << endl;
                    cout << "  F) Eliminar prestatario" << endl;
                    cout << "ingrese la opcion: ";
                    cin >> opcionCase;
                    switch (tolower((opcionCase)))
                    {
                    case 'a':
                        agregarCategoria(categorias, dlCategorias);
                        break;
                    case 'b':
                        modificarCategoria(categorias, dlCategorias);
                        break;
                    case 'c':
                        eliminarCategoria(categorias, dlCategorias, prestamos, dlprestamos, codigo);           
                        break;
                    case 'd':
                        agregarPrestatario(prestatarios, dlprestatarios);
                        break;
                    case 'e':
                        modificarPrestatario(prestatarios, dlprestatarios);
                        break;
                    case 'f':
                        eliminarPrestatario(prestatarios, dlprestatarios, prestamos, dlprestamos, codigo);
                        break;
                    default:
                        cout << "ELIJA UNA OPCION CORRECTA" << endl;
                        break;
                    }
                } while (opcionCase != 'a', opcionCase != 'b', opcionCase != 'c', opcionCase != 'd', opcionCase != 'e', opcionCase != 'f');
                break;
            case 2:
                do
                {
                    cout << "  Administrar Préstamos" << endl;
                    cout << "  A) Agregar préstamo" << endl;
                    cout << "  B) Modificar préstamo" << endl;
                    cout << "  C) Eliminar préstamo" << endl;
                    cout << "  D) Devolver préstamo" << endl;
                    cout << "ingrese la opcion: ";
                    cin >> opcionCase;
                    switch (tolower((opcionCase)))
                    {
                    case 'a':
                        agregarPrestamo(categorias, dlCategorias, prestamos, dlprestamos, prestatarios, dlprestatarios);                
                        break;
                    case 'b':
                        modificarPrestamo(prestamos, dlprestamos);
                        break;
                    case 'c':
                        eliminarPrestamo();
                        break;
                    case 'd':
                        devolverPrestamo(prestatarios, dlprestatarios, prestamos, dlprestamos);
                        break;
                    default:
                        cout << "ELIJA UNA OPCION CORRECTA" << endl;
                        break;
                    }
                } while (opcionCase != 'a', opcionCase != 'b', opcionCase != 'c', opcionCase != 'd');
                break;
            case 3:
                do
                {
                    cout << "Consultar Préstamos" << endl;
                    cout << "  A) Cantidad de objetos prestados por categoría" << endl;
                    cout << "  B) Listado de préstamos por categoría" << endl;
                    cout << "  C) Listado de préstamos ordenados por categoría o prestatario" << endl;
                    cout << "  D) Listar todos los prestatarios que tienen al menos un objeto prestado" << endl;
                    cout << "ingrese la opcion: ";
                    cin >> opcionCase;
                    switch (tolower((opcionCase)))
                    {
                    case 'a':
                        cantObjetosPorCategoria();
                        break;
                    case 'b':
                        listadoPrestamosPorCategoria();
                        break;
                    case 'c':
                        listadoPrestamosPorPrestatario();
                        break;
                    case 'd':
                        prestatariosConobjetosPrestados();
                        break;
                    default:
                        cout << "ELIJA UNA OPCION CORRECTA" << endl;
                        break;
                    }
                } while (opcionCase != 'a', opcionCase != 'b', opcionCase != 'c', opcionCase != 'd');
                    break;
            default:
                cout << "POR FAVOR INGRESE UNA OPCION VALIDA" << endl;
                break;
            }
        } while (opcionPrincipal != 1, opcionPrincipal != 2, opcionPrincipal != 3);
        
    return 0;
}