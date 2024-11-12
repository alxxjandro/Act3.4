#include <iostream>
#include "tools.h"
#include "Node.h"
#include "BST.h"
#include <vector>
using namespace std;

//Eliel Mejia A01563697
//Alonso Alarcon A01563388
//Myriam Muruato A01569121

int main() {
    vector<string> documento;
    tools::guardarIPs("../bitacora-3.4.txt",documento);

    BST<string> arbolDeIPs;
    for (string linea : documento) {
        arbolDeIPs.insertNode(linea);
    }

    vector<pair<string,int>> almacen;
    arbolDeIPs.preordenDos(arbolDeIPs.getRoot(),&almacen);
    tools::quickSort(almacen, 0, almacen.size() - 1);
    for (int i = 0; i < 5; ++i) {
        cout << almacen[i].first << ' ' << almacen[i].second << endl;
    }

    return 0;
}
