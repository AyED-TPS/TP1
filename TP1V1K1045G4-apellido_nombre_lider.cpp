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
const int nMaxDias = 31;
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
typedef Tur tenTur[nMaxEsp][nMaxTur][nMaxDias];

//Turnos Slc
struct regSlc{
    str20 apeNom;
    str20 esp;
    int dia;
    char chTur;
    Tur turno;
};

//Medicos
const int nMaxMed = 60;
struct regMed{
    str20 apeNom;
    short matri;
    str20 esp;
    char turno;
};
typedef regMed Med[nMaxMed];

bool LeeMed(ifstream &fMed, regMed rMed){
/*
    //Pre condicion: La funcion recibe un vector de dos dimensiones vacio. // un registro de medico
    //Post condicion: El vector se llena con la informacion del archivo Medicos.txt y la funcion no devuelve nada.// vuelva un registro del archivo al registro de Medico y devuelve true si la lectura fue exitosa


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
    archivo.close();*/

    return fMed.good();
}

bool LeeSlc(ifstream &fSlc, Tur turnos){
/*
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
*/

    return fSlc.good();
}


void inicTur(tenTur &tTurnos, int nMaxEsp, int nMaxTur, int nMaxDias){
    for(int e = 0; e < nMaxEsp; e++){
        for(int t = 0; t < nMaxTur; t++){
            for(int d = 0; d < nMaxDias; d++){
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
void mostrarTensor(tenTur tensor, Esp vEsp){
    for(int a = 0; a < nMaxEsp; a++){
        cout << "ESPECIALIDAD[" << a << "]: " << vEsp[a] << endl;
        cout << "  |Obra social    |Creden" << endl;
        for(int b = 0; b < nMaxTur; b++){
            if(b < 10) cout << " ";
            cout << b;
            for(int c = 0; c < nMaxDias; c++){
                cout << "|" << tensor[a][b][c].obra << "|";
                cout << tensor[a][b][c].cred;
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
    const short hIni = 800,
                hFin = 1930;
    short pos = -1,
          i = hIni;

    while(i <= hFin && hhmm != i)
        i = ++pos % 2 ? i + 70 : i + 30;

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
    int k;
    bool ordenado;

    k = 0;
    do{
        k++;
        ordenado = true;

        for(int i = 0; i <= carEsp-k-1; i++){
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
void procTurnos(ifstream &fTur, tenTur &tTur, regTur rTur, Esp vEsp, int carEsp, int *carTur){
    *carTur = 0;
    inicTur(tTur, nMaxEsp, nMaxTur, nMaxDias); // acceso a variables globales, es error?
    while( LeeTur(fTur, rTur)){
        strcpy(tTur[busBin(vEsp, rTur.esp, carEsp)][cnvHhMm(rTur.hora*100 + rTur.minu)][rTur.dia-1].obra, rTur.turno.obra);
        tTur[busBin(vEsp, rTur.esp, carEsp)][cnvHhMm(rTur.hora*100 + rTur.minu)][rTur.dia-1].cred = rTur.turno.cred;
        (*carTur)++;
    }
}

void procMedicos(ifstream &fMed, Med vMed, int *carMed){
//    *carMed = 0;
//    while(LeeMed(fMed, vMed[*carMed])){
//        (*carMed)++;
//    }
}

// void OrdxBur(tid tbl, tid card), ordena tbl PerMed por NomEsp+Turno.

const nChTur = 5;
typedef char str5[nChTur+1];

void impEsp(ofstream &arch, short num){
    if(num < 10) arch << " " << num;
    else arch << num;
}

void impCred(ofstream &arch, short cred){
    div_t cred_d;
    cred_d = div((float)cred, 100.0);

    arch << cred_d.quot << "." << cred_d.rem;
}

void cnvPosHhMm(str5 &res, int n){

    switch(n){
        case 0: strcpy(res, "08:00");
        case 1: strcpy(res, "08:30");
        case 2: strcpy(res, "09:00");
        case 3: strcpy(res, "09:30");
        case 4: strcpy(res, "10:00");
        case 5: strcpy(res, "10:30");
        case 6: strcpy(res, "11:00");
        case 7: strcpy(res, "11:30");
        case 8: strcpy(res, "12:00");
        case 9: strcpy(res, "12:30");
        case 10: strcpy(res,"13:00");
        case 11: strcpy(res,"13:30");
        case 12: strcpy(res,"14:00");
        case 13: strcpy(res,"14:30");
        case 14: strcpy(res,"15:00");
        case 15: strcpy(res,"15:30");
        case 16: strcpy(res,"16:00");
        case 17: strcpy(res,"16:30");
        case 18: strcpy(res,"17:00");
        case 19: strcpy(res,"17:30");
        case 20: strcpy(res,"18:00");
        case 21: strcpy(res,"18:30");
        case 22: strcpy(res,"19:00");
        case 23: strcpy(res,"19:30");
    }
}

void lstTurnos(ofstream &fLst, tenTur tTur, int carTur, Esp vEsp){

    // asignacion de turnos
    // imprimirlo

    int posEsp,
        posTur,
        posDia;

    str5 cad;

    fLst << "Listado de turnos INICIAL orden Espec.+Dia+Turno" << endl;
    fLst << "Especialidad        Dia Horario Obr. Soc.       Nro. Cred." << endl;

    posEsp = posTur = posDia = 0;
    while(tTur[posEsp][posTur][posDia].cred == 0){
        posTur++;
        if(posTur >= 24){
            posDia++;
            posTur = 0;
        }
    }
    fLst << vEsp[posEsp] << " ";
    impEsp(fLst, posDia+1);
    fLst << "  ";
    cnvPosHhMm(cad, posTur);
    fLst << cad << "  ";
//    fLst << posTur << "  ";
    fLst << tTur[posEsp][posTur][posDia].obra << "  ";
    fLst << tTur[posEsp][posTur][posDia].cred << endl;
//    //fLst << posTur;
//    posTur %= 24;
//    cout << "posTur: " << posTur;

}

main() {

//Declarar las variables utilizadas en el bloque main().

    //Especialidades
    Esp vEsp;
    int *carEsp;

    //Turnos
    regTur rTur;
    tenTur tTur;
    int *carTur;

    //Medicos
    Med vMed;
    int *carMed;

//Abrir todos los archivos
    ifstream fEsp("Especialidades.Txt");
    ifstream fTur("TurnosDiaHora.Txt");
    ifstream fMed("Medicos.Txt");
    ofstream fLst("Listadox3.Txt");

    procMedicos(fMed, vMed, carMed);
    procEspecialidad(fEsp, vEsp, carEsp);
    procTurnos(fTur, tTur, rTur, vEsp, *carEsp, carTur);
    lstTurnos(fLst, tTur, *carTur, vEsp);
    //mostrarTensor(tTur, vEsp);
    //procTurnos();
    //lstTurnos();

//cerrar todos los archivos
    fEsp.close();
    fTur.close();
    fMed.close();

//    Medicos
//    const int cantidad_medicos = 36;
//    const int atributos_medico = 5;
//    static string medicos[cantidad_medicos][atributos_medico];

//    Turnos
//    const int cantidad_turnos = 18;
//    const int atributos_turnos = 8;
//    static string turnos[cantidad_turnos][atributos_turnos];

//    LeeSlc(turnos); // ERROR retorno de programa distinto de cero
//    cout << "Testeo: " << turnos[3][3] << endl; //Borrar en la version final.
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
