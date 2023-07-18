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
    short cred;
};
struct regTur{
    str20 esp;
    int dia;
    short hora;
    short minu;
    Tur turno;
};
typedef Tur tenTur[nMaxEsp][nMaxTur][dias];

//Medicos
struct regMedicos{
    str20 apeNom;
    short matri;
    str20 esp;
    char turno;
};

// X Obtener_medicos()
void Obtener_medicos(string medicos[36][5])
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

                //cout << palabra << endl; //Borrar en la versi�n final del trabajo
                medicos[contador_medicos][contador_atributos] = palabra;
                palabra.clear();
                contador_atributos++;

            }
            posicion_letra++;
        }
        //cout << palabra << endl << "------------------" << endl; //Borrar en la versi�n final del trabajo
        medicos[contador_medicos][contador_atributos] = palabra;
        contador_atributos = 0;
        contador_medicos++;
    }
    archivo.close();
}

// X Obtener_solicitud_turnos()
void Obtener_solicitud_turnos(string turnos[18][8])
{
    /*
    Pre condici�n: La funci�n recibe un vector de dos dimensiones vacio.
    Post condici�n: El vector se llena con la informaci�n del archivo SolicitudTurnos.txt y la funci�n no devuelve nada.
    */

    // Declaraci�n de variables
    ifstream archivo;
    string linea_archivo;
    int contador_turnos{ 0 };
    int contador_atributos{ 0 };

    // Manipulaci�n del archivo SolicitudTurnos.txt
    archivo.open("SolicitudTurnos.txt");
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

                //cout << palabra << endl; //Borrar en la versi�n final del trabajo
                turnos[contador_turnos][contador_atributos] = palabra;
                palabra.clear();
                contador_atributos++;

            }
            posicion_letra++;
        }
        //cout << palabra << endl << "------------------" << endl; //Borrar en la versi�n final del trabajo
        turnos[contador_turnos][contador_atributos] = palabra;
        contador_atributos = 0;
        contador_turnos++;
    }
    archivo.close();
}

bool LeeEsp(ifstream &fEsp, str20 esp){
/*
 * Lee una especialidad
 * @return
 * true: lectura exitosa
 * false: lectura no exitosa | fin de archivo
 */
    fEsp.get(esp, nChEsp);
    fEsp.ignore();

    return fEsp.good();
}

bool LeeTur(ifstream &fTur, Tur turno){
/*
 * Lee un turno
 * @return
 * true: lectura exitosa
 * false: lectura no exitosa | fin de archivo
 */
    fTur.get(turno.obra, nChObS);
    fTur >> turno.cred;
    fTur.ignore();

    return fTur.good();
}

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

// para testear
void mostrarTensor(tenTur tensor, int caras, int filas, int columnas){
    for(int a = 0; a < caras; a++){
        cout << "CARA " << a << ":" << endl;
        cout << "  |Obra social    |Creden" << endl;
        for(int b = 0; b < filas; b++){
            for(int c = 0; c < columnas; c++){
                cout << tensor[a][b][c].obra << "|";
                cout << tensor[a][b][c].cred << "|";
            }
            cout << endl;
        } cout << endl << endl;
    }
}

void mostrarEsp(Esp vEsp, int carEsp){
    for(int i = 0; i < carEsp; i++){
        cout << vEsp[i] << endl;
    }
}

short cnvHhMm(short hhmm){
/*
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

void IntCmb(str20 esp1, str20 esp2){
    str20 aux;
    strcpy(aux, esp1);
    strcpy(esp1, esp2);
    strcpy(esp2, aux);
}

void OrdxBur(Esp &vEsp, int carEsp){
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

int main() {

    //M�dicos
    const int cantidad_medicos{ 36 };
    const int atributos_medico{ 5 };
    static string medicos[cantidad_medicos][atributos_medico];

    //Turnos
    const int cantidad_turnos{ 18 };
    const int atributos_turnos{ 8 };
    static string turnos[cantidad_turnos][atributos_turnos];

    //Especialidades
    ifstream fEsp("Especialidades.Txt");
    Esp vEsp;
    int carEsp = 0;
    //Turnos
    ifstream fTur("TurnosDiaHora.Txt");
    regTur regTurno;
    tenTur Turnos;
    //int carTur = 0;

    while( LeeEsp(fEsp, vEsp[carEsp]) )
        carEsp++;
    OrdxBur(vEsp, carEsp);

    inicTur(Turnos, nMaxEsp, nMaxTur, dias);
    //while( LeeTur(fTur, regTurno) ){
        // lo dejo amontonado para que se note, aunque no se si lo hace mas o menos intuitivo
      //  strcpy(tenTur[BusBin(regTurno.esp)][cnvHhMm(regTurno.hora*100 + regTurno.minu)][regTurno.dia].obra, regTurno.Tur.obra)
      // carTur++;
    //}

    //mostrarTensor(Turnos, nMaxEsp, nMaxTur, dias);

    fEsp.close();
    //fTur.close();
    Obtener_medicos(medicos);
    cout << "Testeo: " << medicos[3][1] << endl; //Borrar en la versi�n final.
    Obtener_solicitud_turnos(turnos);
    cout << "Testeo: " << turnos[3][3] << endl; //Borrar en la versi�n final.

    return 0;
}
