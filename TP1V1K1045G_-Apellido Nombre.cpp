#include <fstream.h>

using namespace std;

const int nMaxEsp = 20;
const int nChEsp = 20;

typedef char str20[nChEsp+1];
typedef str20 Esp[nMaxEsp];

/*
 * Lee una especialidad
 * @return
 * true: lectura exitosa
 * false: lectura no exitosa | fin de archivo
 */
bool LeeEsp(ifstream &fEsp, str20 esp){
    fEsp.get(esp, nChEsp);
    fEsp.ignore();

    return fEsp.good();
}

main() {

    Esp vEsp;
    ifstream fEsp("Especialidades.Txt");
    int carEsp = 0;

    while( LeeEsp(fEsp, vEsp[carEsp]) )
        carEsp++;

    cout << "Imprimiendo vector" << endl;
    for(int i = 0; i < carEsp; i++){ //ciclaria de mas si pongo nMaxEsp
        cout << i+1 << ". " << vEsp[i] << endl;
    }

    return 0;
}
