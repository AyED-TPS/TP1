#include <fstream.h>
#include <string.h>

using namespace std;

// Especialidades
const int nMaxEsp = 20;
const int nChEsp = 20;
typedef char str20[nChEsp+1];
typedef str20 Esp[nMaxEsp];

//Turnos
const int nMaxTur = 24; // 24 turnos por dia cada especialidad
const int dias = 31;
const nChObS = 15;
typedef char str15[nChObS+1];
struct Tur{
    str15 obra;
    int cred;
};
struct regTur{
    str20 esp;
    int dia;
    int hora;
    int minu;
    Tur turno;
};
typedef Tur tenTur[nMaxEsp][nMaxTur][dias];

//Medicos
const int nMaxMed = 60;
struct regMedicos{
    str20 apeNom;
    short matri;
    str20 esp;
    char turno;
};
typedef regMedicos Med[nMaxMed];

/*
bool LeeMed(ifstream &fMed, Med medicos){

    //Pre condicion: La funcion recibe un vector de dos dimensiones vacio.
    //Post condicion: El vector se llena con la informacion del archivo Medicos.txt y la funcion no devuelve nada.


    // Declaracion de iables
    ifstream archivo;
    string linea_archivo;
    int contador_medicos = 0;
    int contador_atributos = 0;

    // Manipulacion del archivo Medicos.txt
    archivo.open("Medicos.txt");
    while (archivo.good())
    {
        //Declaracion de iables dentro del ciclo while.
        getline(archivo, linea_archivo);
        char separador;
        int posicion_letra = 0;
        string palabra;
        int tamanio_linea = linea_archivo.size();

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

                //cout << palabra << endl; //Borrar en la version final del trabajo
                medicos[contador_medicos][contador_atributos] = palabra;
                palabra.clear();
                contador_atributos++;

            }
            posicion_letra++;
        }
        //cout << palabra << endl << "------------------" << endl; //Borrar en la version final del trabajo
        medicos[contador_medicos][contador_atributos] = palabra;
        contador_atributos = 0;
        contador_medicos++;
    }
    archivo.close();
}

bool LeeTur2(ifstream &fTur, Tur turnos){

    //Pre condicion: La funcion recibe un vector de dos dimensiones vacio.
    //Post condicion: El vector se llena con la informacion del archivo SolicitudTurnos.txt y la funcion no devuelve nada.

    // Declaracion de iables
    ifstream archivo;
    string linea_archivo;
    int contador_turnos = 0;
    int contador_atributos = 0;

    // Manipulacion del archivo SolicitudTurnos.txt
    archivo.open("SolicitudTurnos.txt");
    while (archivo.good())
    {
        //Declaracion de iables dentro del ciclo while.
        getline(archivo, linea_archivo);
        char separador;
        int posicion_letra = 0;
        string palabra;
        int tamanio_linea = linea_archivo.size();

        while (linea_archivo[posicion_letra] != '\0') //  '\0.' es el caracter nulo en la tabla ASCII.
        {
            if (linea_archivo[posicion_letra] != separador)
            {
                palabra += linea_archivo[posicion_letra];
            }
            else
            {
                //Checkear el if si funciona correctamente.
                if (contador_atributos == 3 && linea_archivo[posicion_letra + 1] != ' ')
                {
                    palabra += linea_archivo[posicion_letra];
                    posicion_letra++;
                    while (linea_archivo[posicion_letra] != ' ')
                    {
                        palabra += linea_archivo[posicion_letra];
                        posicion_letra++;
                    }
                }
                if (contador_atributos == 5 && linea_archivo[posicion_letra + 1] != ' ')
                {
                    palabra += linea_archivo[posicion_letra];
                    posicion_letra++;
                    while (linea_archivo[posicion_letra] != ' ')
                    {
                        palabra += linea_archivo[posicion_letra];
                        posicion_letra++;
                    }
                }
                while (linea_archivo[posicion_letra + 1] == ' ')
                    posicion_letra++;

                turnos[contador_turnos][contador_atributos] = palabra;
                palabra.clear();
                contador_atributos++;

            }
            posicion_letra++;
        }
        //cout << palabra << endl << "------------------" << endl; //Borrar en la version final del trabajo
        turnos[contador_turnos][contador_atributos] = palabra;
        contador_atributos = 0;
        contador_turnos++;
    }
    archivo.close();
}
*/

void inicTur(tenTur &tTurnos, int nMaxEsp, int nMaxTur, int dias){
    for(int e = 0; e < nMaxEsp; e++){
        for(int t = 0; t < nMaxTur; t++){
            for(int d = 0; d < dias; d++){
                strcpy(tTurnos[e][t][d].obra, "*");
                tTurnos[e][t][d].cred = 0;
            }
        }
    }
}
bool LeeTur(ifstream &fTur, regTur &turno){
/**
 * Lee un turno
 * @return
 * true: lectura exitosa
 * false: lectura no exitosa | fin de archivo
 */

    fTur.get(turno.esp, nChEsp+1);
    fTur.ignore();
    fTur >> turno.dia >> turno.hora >> turno.minu;
    fTur.ignore();
    fTur.get(turno.turno.obra, nChObS+1);
    fTur.ignore();
    fTur >> turno.turno.cred;
    fTur.ignore();

    return fTur.good();
}
void mostrarTensor(tenTur tensor, int caras, int filas, int columnas){
    for(int a = 0; a < caras; a++){
        cout << "CARA " << a << ":" << endl;
        cout << "  |Obra social    |Creden" << endl;
        for(int b = 0; b < filas; b++){
            cout << b;
            for(int c = 0; c < columnas; c++){
                cout << "|" << tensor[a][b][c].obra << "|";
                cout << tensor[a][b][c].cred << "|";
            }
            cout << endl;
        } cout << endl << endl;
    }
}
void mostrarRegTur(regTur rTur){
    cout << rTur.esp << " ";
    cout << rTur.dia << " ";
    cout << rTur.hora << " ";
    cout << rTur.minu << " ";
    cout << rTur.turno.obra << " ";
    cout << rTur.turno.cred << " ";
    cout << endl;
}

short cnvHhMm(short hhmm){
/**
 * dada la hora en formato hhmm, devuelve la posicion del tensor de los turnos
 */
    const short hIni = 800;
    const short hFin = 1930;
    short pos = -1;
    short i = hIni;

    while(i <= hFin && hhmm != i){
        i = ++pos % 2 ? i + 70 : i + 30;
    }

    return ++pos;
}

bool LeeEsp(ifstream &fEsp, str20 esp){
/**
 * Lee una especialidad
 * @return
 * true: lectura exitosa
 * false: lectura no exitosa | fin de archivo
 */
    fEsp.get(esp, nChEsp+1);
    fEsp.ignore();

    return fEsp.good();
}
void IntCmb(str20 esp1, str20 esp2){
    str20 aux;
    strcpy(aux, esp1);
    strcpy(esp1, esp2);
    strcpy(esp2, aux);
}
void OrdxBur(Esp vEsp, int carEsp){
    int k = 0;
    bool ordenado;
    do{
        k++;
        ordenado = true;

        for(int i = 0; i < carEsp-k; i++){
            if(strcmp(vEsp[i], vEsp[i+1]) > 0){
                ordenado = false;
                IntCmb(vEsp[i], vEsp[i+1]);
            }
        }
    } while(!ordenado);
}
void procEspecialidad(ifstream &fEsp, Esp vEsp, int *carEsp){
    *carEsp = 0;
    while( LeeEsp(fEsp, vEsp[*carEsp]) )
        (*carEsp)++;
    OrdxBur(vEsp, *carEsp);
}
void mostrarEsp(Esp vEsp, int carEsp){
    for(int i = 0; i < carEsp; i++){
        cout << "[" << i << "] " << vEsp[i]<< "|" << endl;
    }
    cout << "carEsp = " << carEsp << endl;
}
int busBin(Esp vEsp, str20 eClv, int ult){
    int pri, med;

    pri = 0;
    while(pri <= ult){
        med = (pri + ult) / 2;
        if(strcmp(eClv, vEsp[med]) == 0)
            return med;
        else if(strcmp(eClv, vEsp[med]) > 0)
            pri = med + 1;
        else ult = med - 1;
    }
    return -1;
}

main() {

//Declarar las variables utilizadas en el bloque main().
    //Especialidades
    Esp vEsp;
    int *carEsp;

    //Turnos
    regTur rTur;
    tenTur tTur;
    int carTur = 0;

    //Medicos
    const int cantidad_medicos = 36;
    const int atributos_medico = 5;
    static string medicos[cantidad_medicos][atributos_medico];

//    const int cantidad_turnos = 18;
//    const int atributos_turnos = 8;
//    static string turnos[cantidad_turnos][atributos_turnos];

//Abrir todos los archivos
    ifstream fEsp("Especialidades.Txt");
    ifstream fTur("TurnosDiaHora.Txt");

    procEspecialidad(fEsp, vEsp, carEsp);
    mostrarEsp(vEsp, *carEsp);

    int posEsp;
    int posHora;    int hhmm;

    inicTur(tTur, nMaxEsp, nMaxTur, dias);
    while( LeeTur(fTur, rTur)){
        posEsp = busBin(vEsp, rTur.esp, *carEsp);
        //hhmm = rTur.hora*100 + rTur.minu;
        //posHora = cnvHhMm(hhmm);
        cout << "[" << posEsp << "]";
        cout << rTur.esp << endl;
//          cout << "[" << posHora << "]";
//        cout << "[" << rTur.dia-1 << "]" << endl;
    //    strcpy(tTur[posEsp][posHora][rTur.dia-1].obra, rTur.turno.obra);
    //    tTur[posEsp][posHora][rTur.dia-1].cred = rTur.turno.cred;
        carTur++;
    }
    //mostrarTensor(tTur, nMaxEsp, nMaxTur, dias);

//cerrar todos los archivos
    fEsp.close();
    fTur.close();

    //LeeTur(turnos); // ERROR retorno de programa distinto de cero
    //cout << "Testeo: " << turnos[3][3] << endl; //Borrar en la version final.

//    LeeMed(medicos);
//    cout << "Medicos: " << endl;
//    for(int i = 0; i < 36; i++){
//        for(int j = 0; j < 5; j++){
//            cout << medicos[i][j];
//        }
//        cout << endl;
//    }
    return 0;
}
