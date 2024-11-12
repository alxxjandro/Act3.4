#include "tools.h"
#include <fstream>

void tools::swapNumbers(std::string &a, std::string &b) {
    string temp = a;
    a = b;
    b = temp;
}

void tools::guardarIPs(string rutaDocumento, vector<string> &vectorAlmacen) {
    ifstream archivo(rutaDocumento);
    string linea;
    while(getline(archivo,linea)){
        vectorAlmacen.push_back(tokenizarIP(linea));
    }
    archivo.close();
}

//recotar los espacios hasta llegar a la IP
string tools::tokenizarIP(string &linea) {
    char *ptrAux = &linea[0];
    int contador = 0;
    string lineaTemp;

    for (int i = 0; i < linea.length(); ++i) {
        if (*ptrAux == ' '){
            contador++;
            if (contador == 3){
                lineaTemp = linea.substr(i+1);
                break;
            }
        }
        ptrAux++;
    }
    //devolver la IP pelona
    return lineaTemp.substr(0, tools::devolverIndexToken(lineaTemp));
}

int tools::devolverIndexToken(string &linea) {
    char *ptrAux = &linea[0];
    for (int i = 0; i < linea.length(); ++i) {
        if (*ptrAux == ':'){
            return i;
        }
        ptrAux++;
    }
    return -1;
}


void tools::quickSort(vector<pair<string, int>>& almacen, int low, int high) {
    if (low < high) {
        int pi = partition(almacen, low, high);

        quickSort(almacen, low, pi - 1);
        quickSort(almacen, pi + 1, high);
    }
}

int tools::partition(vector<pair<string, int>>& almacen, int low, int high) {
    int pivot = almacen[high].second;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (almacen[j].second >= pivot) {
            i++;
            swap(almacen[i], almacen[j]);
        }
    }
    swap(almacen[i + 1], almacen[high]);
    return (i + 1);
}
