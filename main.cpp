#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
#include "iomanip"

using namespace std;


int main()
{
    string inputFileName = "data.txt";
    double S = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double V = 0;

    if (!ImportData(inputFileName, S, n, w, r))
    {
        cerr<< "Errore nell'apertura del file"<< endl;
        return -1;
    }
    else
        cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << "\nw = " << ArrayToString(n, w) << "\nr = " << ArrayToString(n, r) << endl;

    double rateofreturn = Rateofreturn(n, w, r, V, S);
    cout <<fixed << setprecision(4) << "Rate of return of the portfolio: "<< rateofreturn << "\nV: " << setprecision(2) << V << endl;

    string outputFileName = "result.txt";
    if (!ExportResult(outputFileName, n, w, r, rateofreturn, S, V))
    {
        cerr<< "Errore nella scrittura del file"<< endl;
        return -1;
    }
    

    delete[] w;
    delete[] r;

    return 0;
}