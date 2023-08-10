
/*
    Programa Fuente: TP1V1K1045G4-apellido_nombre.cpp
    Fecha Entrega: 14/8/2023
    Nro. version: V1
    Objetivo: Asignacion de turnos por servicios medicos segun especialidad, dia y turno (mangana, tarde, noche),
      de acuerdo a la solicitud de quien requiere el servicio.
    Curso: K1045
        Dias: Lunes, turno tarde.
    Grupo Nro.: 4
    Integrantes: (Apellido, Nombre).
*/

#include <fstream.h>
#include <string.h>
#include <iomanip.h>

using namespace std;

// Especialidades
const nMaxEsp = 20,
      nChEsp = 20;
typedef char str20[nChEsp+1];
typedef str20 vecEsp[nMaxEsp];

//Medicos
const nMaxMed = 60;
struct regMed{
    str20 apeNom,
          esp;
    char turno;
};
typedef regMed vecMed[nMaxMed];

//Turnos
const nMaxSes = 24,
      nMaxDias = 31,
      nChObS = 15;
typedef char str15[nChObS+1];
struct Tur{
    str15 obra;
    int cred;
};
typedef Tur tenTur[nMaxEsp][nMaxSes][nMaxDias];

//Turnos Previos
struct regTur{
    str20 esp;
    int dia,
        hora,
        minu;
    Tur turno;
};

//Turnos Actuales
struct regSlc{
    str20 apeNom,
          esp;
    int dia;
    char chTur;
    Tur turno;
};

//Hora
const nChTur = 5;
typedef char str5[nChTur+1];

//Titulo
const nChTit = 11;
typedef char str11[nChTit+1];

bool LeeMed(ifstream &fMed, regMed &rMed){
/**
 * Descarga un registro de Medicos en rMed
 * @return
 * true = {lectura exitosa}
 * false = {lectura no exitosa | fin de archivo}
 */

    fMed.get(rMed.apeNom, nChEsp+1);
    fMed.ignore();
    fMed.get(rMed.esp, 6+1); // ignora matricula
    fMed.ignore();
    fMed.get(rMed.esp, nChEsp+1);
    fMed.ignore();
    fMed >> rMed.turno;
    fMed.ignore();

    return fMed.good();
}
void procMedicos(ifstream &fMed, vecMed vMed, int *carMed){
    regMed rMed;

    *carMed = 0;
    while(LeeMed(fMed, rMed)){
        strcpy(vMed[(*carMed)].apeNom, rMed.apeNom);
        strcpy(vMed[(*carMed)].esp, rMed.esp);
        vMed[(*carMed)].turno = rMed.turno;
        (*carMed)++;
    }
}

void IntCmb(str20 esp1, str20 esp2){
    str20 aux;
    strcpy(aux, esp1);
    strcpy(esp1, esp2);
    strcpy(esp2, aux);
}
void OrdxBur(vecEsp vEsp, int carEsp){
    int k = 0;
    bool ordenado;

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
bool LeeEsp(ifstream &fEsp, str20 esp){
/**
 * Descarga un registro de Especialidades en esp
 * @return
 * true = {lectura exitosa}
 * false = {lectura no exitosa | fin de archivo}
 */
    fEsp.get(esp, nChEsp+1);
    fEsp.ignore();

    return fEsp.good();
}
void procEspecialidad(ifstream &fEsp, vecEsp vEsp, int *carEsp){
    *carEsp = 0;
    while( LeeEsp(fEsp, vEsp[*carEsp]) )
        (*carEsp)++;
    OrdxBur(vEsp, *carEsp);
}

void inicTur(tenTur &tTurnos, int nMaxEsp, int nMaxSes, int nMaxDias){
    for(int e = 0; e < nMaxEsp; e++)
        for(int t = 0; t < nMaxSes; t++)
            for(int d = 0; d < nMaxDias; d++){
                strcpy(tTurnos[e][t][d].obra, "*");
                tTurnos[e][t][d].cred = 0;
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
busBin(vecEsp vEsp, str20 eClv, int ult){
    int pri = 0,
        med;

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
short cnvHhMm(short hhmm){
/**
 * @return posicion de hora sesion en funcion de hora en formato hhmm
 */
    const short hIni = 800;
    short pos = -1,
          i = hIni;

    while(hhmm != i)
        i = ++pos % 2 ? i + 70 : i + 30;

    return ++pos;
}
void procTurnos(ifstream &fTur, tenTur &tTur, int *carTur, vecEsp vEsp, int carEsp){
    *carTur = 0;
    regTur rTur;

    inicTur(tTur, nMaxEsp, nMaxSes, nMaxDias);
    while(LeeTur(fTur, rTur)){
        strcpy(tTur[busBin(vEsp, rTur.esp, carEsp)][cnvHhMm(rTur.hora*100 + rTur.minu)][rTur.dia-1].obra, rTur.turno.obra);
        tTur[busBin(vEsp, rTur.esp, carEsp)][cnvHhMm(rTur.hora*100 + rTur.minu)][rTur.dia-1].cred = rTur.turno.cred;
        (*carTur)++;
    }
}

void tstMostrarTensor(tenTur tensor, vecEsp vEsp){
    for(int a = 0; a < nMaxEsp; a++){
        cout << "ESPECIALIDAD[" << a << "]: " << vEsp[a] << endl;
        cout << "  |Obra social    |Creden" << endl;
        for(int b = 0; b < nMaxSes; b++){
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
void tstMostrarEsp(vecEsp vEsp, int carEsp){
    for(int i = 0; i < carEsp; i++){
        cout << "[" << i << "] " << vEsp[i]<< "|" << endl;
    }
    cout << "carEsp = " << carEsp << endl;
}

void cnvPosHhMm(str5 &res, int n){
    switch(n){
        case 0: strcpy(res, " 8:00"); break;
        case 1: strcpy(res, " 8:30"); break;
        case 2: strcpy(res, " 9:00"); break;
        case 3: strcpy(res, " 9:30"); break;
        case 4: strcpy(res, "10:00"); break;
        case 5: strcpy(res, "10:30"); break;
        case 6: strcpy(res, "11:00"); break;
        case 7: strcpy(res, "11:30"); break;
        case 8: strcpy(res, "12:00"); break;
        case 9: strcpy(res, "12:30"); break;
        case 10: strcpy(res,"13:00"); break;
        case 11: strcpy(res,"13:30"); break;
        case 12: strcpy(res,"14:00"); break;
        case 13: strcpy(res,"14:30"); break;
        case 14: strcpy(res,"15:00"); break;
        case 15: strcpy(res,"15:30"); break;
        case 16: strcpy(res,"16:00"); break;
        case 17: strcpy(res,"16:30"); break;
        case 18: strcpy(res,"17:00"); break;
        case 19: strcpy(res,"17:30"); break;
        case 20: strcpy(res,"18:00"); break;
        case 21: strcpy(res,"18:30"); break;
        case 22: strcpy(res,"19:00"); break;
        case 23: strcpy(res,"19:30"); break;
    }
}
void impTurno(ofstream &fLst, str20 esp, int dia, int posHor, str15 obra, int cred){
    str5 hora;
    cnvPosHhMm(hora, posHor);
    fLst << esp << " ";
    fLst << setw(2) << dia << "  ";
    fLst << hora << "  ";
    fLst << obra << "  ";
    fLst << setw(6) << cred;
    fLst << endl;
}
void lstTurnos(ofstream &fLst, tenTur tTur, int carTur, vecEsp vEsp, str11 titulo){
    int i,j,k;

    i = j = k = 0;

    fLst << "Listado de turnos " << titulo << " orden Espec.+Dia+Turno" << endl;
    fLst << "Especialidad        Dia Horario Obr. Soc.       Nro.Cred." << endl;

    while(carTur){
        if(strcmp(tTur[i][j][k].obra, "*")){
            impTurno(fLst, vEsp[i], k+1, j, tTur[i][j][k].obra, tTur[i][j][k].cred);
            carTur--;
        }
        k = ++j % nMaxSes ? k : ++k;
        j %= nMaxSes;
        i = k / nMaxDias ? ++i : i;
        k %= nMaxDias;
    }

    fLst << endl;
}

bool LeeSlc(ifstream &fSlc, regSlc &rSlc){
/**
 * Descarga un registro de TurnosActuales en rSlc
 * @return
 * true = {lectura exitosa}
 * false = {lectura no exitosa | fin de archivo}
 */

    fSlc.get(rSlc.apeNom, nChEsp+1);
    fSlc.ignore();
    fSlc.get(rSlc.turno.obra, 2+1); // ignorando la edad
    fSlc.ignore();
    fSlc.get(rSlc.turno.obra, nChObS+1);
    fSlc.ignore();
    fSlc >> rSlc.turno.cred;
    fSlc.ignore();
    fSlc.get(rSlc.esp, nChEsp+1);
    fSlc.ignore();
    fSlc >> rSlc.dia;
    fSlc.ignore();
    fSlc.get(rSlc.chTur);
    fSlc.ignore();

    return fSlc.good();
}

void procSolicitud(ifstream &fSlc, tenTur &tTur, int *carTur, vecEsp vEsp, int carEsp, ofstream &fLst){
    regSlc rSlc;
    short posHor;
    str5 hora;

    fLst << "Listado de Solicitudes Actuales orden Cronologico" << endl;
    fLst << "Apellido Nombre      Nom.Obr. Soc.   Nro.Cred. Especialidad        Dia Turno Medico/a" << endl;

    while(LeeSlc(fSlc, rSlc)){
        switch(rSlc.chTur){
            case 'M': posHor = 0; break;
            case 'T': posHor = 8; break;
            case 'N': posHor = 16; break;
        }

        while(strcmp(tTur[busBin(vEsp, rSlc.esp, carEsp)][posHor][rSlc.dia-1].obra, "*"))
            posHor++;
        strcpy(tTur[busBin(vEsp, rSlc.esp, carEsp)][posHor][rSlc.dia-1].obra, rSlc.turno.obra);
        tTur[busBin(vEsp, rSlc.esp, carEsp)][posHor][rSlc.dia-1].cred = rSlc.turno.cred;
        (*carTur)++;

        cnvPosHhMm(hora, posHor);
        fLst << rSlc.apeNom << " ";
        fLst << rSlc.turno.obra << "  ";
        fLst << rSlc.turno.cred << "   ";
        fLst << rSlc.esp << " ";
        fLst << setw(2) << rSlc.dia << " ";
        fLst << hora << " ";
        fLst << "Med(esp, turno)" << endl; // falta la funcion que devuelve el nombre del medico en funcion de la especialidad y el turno
    }

    fLst << endl;
}

main() {

//Declarar las variables utilizadas en el bloque main().
    vecEsp vEsp;
    regTur rTur;
    tenTur tTur;
    vecMed vMed;
    int *carEsp,
        *carTur,
        *carMed;

//Abrir todos los archivos
    ifstream fMed("Medicos.Txt"),
             fEsp("Especialidades.Txt"),
             fTur("TurnosDiaHora.Txt"),
             fSlc("SolicitudTurnos.Txt");
    ofstream fLst("Listadox3.Txt");

    //procMedicos(fMed, vMed, carMed);
    procEspecialidad(fEsp, vEsp, carEsp);
    procTurnos(fTur, tTur, carTur, vEsp, *carEsp);
    lstTurnos(fLst, tTur, *carTur, vEsp, "INICIAL");
    procSolicitud(fSlc, tTur, carTur, vEsp, *carEsp, fLst);
    lstTurnos(fLst, tTur, *carTur, vEsp, "ACTUALIZADO");

//cerrar todos los archivos
    fMed.close();
    fEsp.close();
    fTur.close();
    fSlc.close();
    fLst.close();

    return 0;
}
