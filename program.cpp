#include <iostream>
#include<string>
using namespace std;

int main(){
int opcionprincipal;//variable que almacena el numero de la opción del menu principal
char opcioncase1;
char opcioncase2;
char opcioncase3;
const int cantclientes=10;//dimensión fisica
int Codigo=cantclientes;//la cantidad de código de prestatario es la misma que la cantidad de prestatarios
char Categorias;
string NombreyApellido;
char Prestamo;
char Prestatario[cantclientes]; //sacar de main y   poner dentro de una función asi no ocupa espacio
    do{
        cout<<"1.Administrar y consultar Categorías y Prestatarios"<<endl;
        cout<<"2. Administrar Préstamos"<<endl;
        cout<<"3. Consultar Préstamos"<<endl;
        cout<<"ingrese una opcion: ";
        cin>>opcionprincipal;
        switch (opcionprincipal)
        {
            case 1: do{
                        cout<<"Administrar y consultar Categorías y Prestatarios"<<endl;
                        cout<<"  i) Agregar categoría"<<endl;
                        cout<<"  ii) Modificar categoría"<<endl;
                        cout<<"  iii) Eliminar categoría"<<endl;
                        cout<<"  iv) Agregar prestatario"<<endl;
                        cout<<"  v) Modificar prestatario"<<endl;
                        cout<<"  vi) Eliminar prestatario"<<endl;
                        cout<<"ingrese la opcion: ";
                        cin>>opcioncase1;
                        switch (tolower((opcioncase1))){
                                case 'i':cout<<"usted eligio la op 1"<<endl; //sacar los cout y poner las funciones
                                    break;
                                case 'ii':cout<<"usted eligio la op 2"<<endl;
                                    break;
                                case 'iii':cout<<"usted eligio la op 3"<<endl;
                                    break;
                                case 'iv':cout<<"usted eligio la op 4"<<endl;
                                    break;
                                case 'v':cout<<"usted eligio la op 5"<<endl;
                                    break;
                                case 'vi':cout<<"usted eligio la op 6";
                                 break;
                        
                                default:cout<<"ELIJA UNA OPCION CORRECTA"<<endl;
                                    break;}

                    }while(opcioncase1!='i' , opcioncase1!='ii', opcioncase1!='iii', opcioncase1!='iv',opcioncase1!='v',opcioncase1!='vi' );
                break;
            case 2: do{
                        cout<<"Administrar Préstamos"<<endl; //AGREAGAR SWITCH ctrl c + ctrl v
                        cout<<"  i) Agregar préstamo"<<endl;
                        cout<<"  ii) Modificar préstamo"<<endl;
                        cout<<"  iii) Eliminar préstamo"<<endl;
                        cout<<"  iv) Devolver préstamo"<<endl;
                    switch (tolower((opcioncase2))){
                            case 'i':cout<<"usted eligio la op 1"<<endl; //sacar los cout y poner las funciones
                                break;
                            case 'ii':cout<<"encontraste el secreto"<<endl;
                                break;
                            case 'iii':cout<<"usted eligio la op 3"<<endl;
                             break;
                            case 'iv':cout<<"usted eligio la op 4"<<endl;
                             break;
                
                            default:cout<<"ELIJA UNA OPCION CORRECTA"<<endl; 
                            break;}

                    }while(opcioncase2!='i' , opcioncase2!='ii', opcioncase2!='iii', opcioncase2!='iv');
                break;
            case 3: do{
                        cout<<"Consultar Préstamos"<<endl; //AGREAGAR SWITCH ctrl c + ctrl v
                        cout<<"  i) Cantidad de objetos prestados por categoría"<<endl;
                        cout<<"  ii) Listado de préstamos por categoría"<<endl;
                        cout<<"  iii) Listado de préstamos ordenados por categoría o prestatario"<<endl;
                        cout<<"  iv) Listar todos los prestatarios que tienen al menos un objeto prestado"<<endl;
                        switch (tolower((opcioncase3))){
                            case 'i':cout<<"usted eligio la op 1"<<endl; //sacar los cout y poner las funciones
                                break;
                            case 'ii':cout<<"usted eligio la op 2"<<endl;
                                break;
                            case 'iii':cout<<"usted eligio la op 3"<<endl;
                             break;
                            case 'iv':cout<<"usted eligio la op 4"<<endl;
                             break;
                
                            default:cout<<"ELIJA UNA OPCION CORRECTA"<<endl;
                            break;}

                    }while(opcioncase3!='i' , opcioncase3!='ii', opcioncase3!='iii', opcioncase3!='iv');
                break;
            default:cout<<"POR FAVOR INGRESE UNA OPCION VALIDA"<<endl;
                break;
        }}while(opcionprincipal<1 or opcionprincipal>3); 

return 0;
}
//CORREGIR LOS CASE "vi" XQ TOMAN EL ULTIMO DIGITO