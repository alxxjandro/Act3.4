#ifndef ACT3_4_TOOLS_H
#define ACT3_4_TOOLS_H
#include <vector>
#include <iostream>
using namespace std;

class tools {
public:
    static void swapNumbers(string& a, string& b);
    static string tokenizarIP(string &linea);
    static int devolverIndexToken(string &linea);
    static void guardarIPs(string rutaDocumento, vector<string> &vectorAlmacen);
    static void quickSort(vector<pair<string, int>>& almacen, int low, int high);
    static int partition(vector<pair<string, int>>& almacen, int low, int high);
};



#endif
