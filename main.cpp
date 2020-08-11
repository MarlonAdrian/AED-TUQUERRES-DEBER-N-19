#include <iostream>
#include <fstream>

using namespace std;

void ArchivoPrueba();
void Piramide();

int main()
{
 int op; 
  do 
  {
    cout <<"\n\nEliga el ejercicio\n";
    cout << "\n 1.Ejercicio en Clase\n 2.Piramide invertida\n 3.-Salir" << endl;
    cout << "Numero: ";
    cin >> op;
    cout << "\n";

    switch (op){
        case (1):
            ArchivoPrueba();
        break; 

        case (2):
            Piramide();
        break;

       case (3):
            cout <<"Gracias por su atencion\n";
        break;
        
        default: cout << "¡ERROR! Seleccione correctamente un numero";
    }
  } while ( op != 3);

return 0;
}

void ArchivoPrueba(){
   string nombre;
   string apellido;
   int e;
   char r,aux; //lectura y/o escritura de otro archivo
   ofstream archivoPrueba;
   string nombreArchivo;

   cout << "Ingrese el nombre del archivo: ";
   cin.get(aux);
   getline (cin, nombreArchivo);

   archivoPrueba.open ( nombreArchivo.c_str(), ios::out);

   do
   {
    cout << "\tIngrese el nombre: ";
    getline (cin, nombre);

    cout << "\tIngrese el apellido: ";
    getline (cin, apellido);

    cout << "\tIngrese la edad: ";
    cin >> e;

    archivoPrueba << nombre <<" " << apellido << " " << e <<"\n";

    cout << "Desea agregar mas(s/n): ";
    cin >> r;
    cout << endl ;
    cin.ignore();

   }
   while (r == 's');

   archivoPrueba.close();

   ifstream archivoLectura(nombreArchivo.c_str()/*, ios::in*/ );
   string texto;

    while (!archivoLectura.eof())
    {
     archivoLectura >> nombre >> apellido >> e;
       if (!archivoLectura.eof())
        {
         getline(archivoLectura,texto);
         cout << "**********" << endl;
         cout << "\tNombre es: " << nombre << endl;
         cout << "\tApellido es: " << apellido << endl;
         cout << "\tEdad es: " << e <<endl;
         cout << "**********" << endl;
        }

   }
   archivoLectura.close();
}

void Piramide(){

ofstream Piramide;

Piramide.open ("Piramide.txt");

int x;
cout << "Ingrese el numero de niveles para la piramide: ";
cin >> x;

while (x > 0)
 {  
  for (int i = 1 ; i <= x ; i++ )
  {
    for (int j = 1; j <= x ; j++)
     {
      cout << "*" ;
     }
    cout <<endl;
    x--;
    
    for (int k = 1; k <=x ; k++)
     {
      cout << "-";
     }
    cout <<endl;
  }
 }
}