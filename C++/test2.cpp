#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<char> leerArchivo(const string& nombreBase){
    string nombreArchivo = nombreBase + ".txt";
    vector<char> instrucciones;
    string funciones = "UDNS";
    char caracter;
    ifstream archivo(nombreArchivo);
    if(!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        instrucciones = {'E', 'R', 'R', 'O', 'R'};
    }else{
        while (archivo.get(caracter)) {
            if (funciones.find(caracter) != funciones.npos) {
                instrucciones.push_back(caracter);
            } else {
                cout << "Error en las instrucciones, funcion no definida: '" << caracter << "'" << endl;
            }
        }
        archivo.close();
    }
    return instrucciones;
}

void ejecutarInstrucciones(const vector<char>& instrucciones){
    vector<int> memoria;
    int puntero = 0;  
    memoria.push_back(0);
    for(char instruccion : instrucciones){
        switch (instruccion) {
            case 'U':
                if(memoria[puntero] == 9){
                    memoria[puntero] = 0;
                    break;
                }else{              
                    memoria[puntero] = memoria[puntero] + 1;
                    break;
                }
            case 'D':
                if(memoria[puntero] == 0){
                    memoria[puntero] = 9;
                    break;
                }else{
                    memoria[puntero] = memoria[puntero] - 1;
                    break;
                }
            case 'N':
                puntero = puntero + 1;
                memoria.push_back(0);
                break;
            case 'S':
                for(int memo : memoria){
                    cout << memo;
                }
                puntero = puntero + 1;
                memoria.clear();
                break;
        }
    }
}

int main(int argc, char* argv[]){
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <nombreArchivo>" << endl;
        return 1;
    }
    vector<char> instrucciones = leerArchivo(argv[1]);
    cout << "Instrucciones: " << endl;
    for(char instruccion : instrucciones){
        cout << instruccion;
    }
    cout << endl;
    ejecutarInstrucciones(instrucciones);
    return 0;
}