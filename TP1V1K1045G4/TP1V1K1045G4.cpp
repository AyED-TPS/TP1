#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Obtener_medicos(string medicos[37][5])
{
    /*
    Pre condici�n: La funci�n recibe un vector de dos dimensiones vacio.
    Post condici�n: El vector se llena con la informaci�n del archivo Medicos.txt y la funci�n no devuelve nada.
    */

    // Declaraci�n de variables
    ifstream archivo;
    string linea_archivo;
    int contador_medicos{ 0 };
    int contador_atributos{ 0 };

    // Manipulaci�n del archivo Medicos.txt
    archivo.open("Medicos.txt");
    while (archivo.good())
    {
        //Declaraci�n de variables dentro del ciclo while.
        getline(archivo, linea_archivo);
        char separador{ ' ' };
        int posicion_letra{ 0 };
        string palabra;
        int tama�o_linea = linea_archivo.size();

        while (linea_archivo[posicion_letra] != '\0') //  '\0.' es el caracter nulo en la tabla ASCII.
        {
            if (linea_archivo[posicion_letra] != separador)
            {
                palabra += linea_archivo[posicion_letra];
            }
            else
            {
                while (linea_archivo[posicion_letra + 1] == ' ')
                    posicion_letra++;

                cout << palabra << endl;
                medicos[contador_medicos][contador_atributos] = palabra;
                palabra.clear();
                contador_atributos++;

            }
            posicion_letra++;
        }
        cout << palabra << endl;
        medicos[contador_medicos][contador_atributos] = palabra;
        contador_atributos = 0;
        contador_medicos++;
    }
    archivo.close();
}

int main()
{
    // 1)Declaraci�n e inicilizaci�n de variables:
    const int cantidad_medicos{ 37 };
    const int atributos_medico{ 5 };
    static string medicos[cantidad_medicos][atributos_medico];
    
    
    // 2)Funciones del main():

    Obtener_medicos(medicos);
    cout << "Testeo: " << medicos[3][1]; //Borrar en la versi�n final.
    /*
    ProcMedicos();      -->  Descarga archivo M�dicos.
    ProcEspecialidad(); -->  Descarga archivo Especialidades
    ProcTurnos();       -->  Descarga archivo TurnosDiaHora
    LstTurnos();        -->  Lista ordenada por Especialidades, D�as y Turnos del vuelco del archivo  TurnosDiasHora.
    ProcTurnos();       -->  Descarga archivo SolicitudesTurnos y lista lineas  de las solicitudes.
    LstTurnos();        -->  Lista ordenada por Especialidades, D�as y Turnos actualizado con las SolicitudesTurnos.
    */
    


    return 0;
}

