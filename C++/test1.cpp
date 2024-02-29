#include <iostream>
#include <vector>


std::string decodificarInstrucciones(const std::string& instrucciones) {
    std::vector<int> memoria(1, 0);  // Inicializar memoria con un slot y valor 0
    int puntero = 0;  // Inicializar puntero en el slot inicial

    for (char instruccion : instrucciones) {
        switch (instruccion) {
            case 'U':
                memoria[puntero] = (memoria[puntero] + 1) % 10;
                break;
            case 'D':
                memoria[puntero] = (memoria[puntero] + 9) % 10;
                break;
            case 'N':
                puntero = (puntero + 1) % memoria.size();
                break;
            case 'S':
                // Mostrar en pantalla y reiniciar
                for (int valor : memoria) {
                    std::cout << (char)('A' + valor - 1);
                }
                memoria.push_back(0);  // Agregar un nuevo slot con valor 0
                puntero = 0;  // Reiniciar el puntero
                break;
        }
    }

    return "";  // Devolver cadena vacía, ya que estamos mostrando en pantalla en lugar de devolver una cadena
}

int main() {
    std::string instrucciones = "UNDDNNUUNNNUNUUUUUNNUNUUUUNNUUNUUUUUNNUUNNNSDDNNUUNNNUNDNNSUNUUUNNUNUUUUNNUNNNUUNUUUNNDDDNNUUUUUUNNDDDNNUUNUUUUUUNNUNNNUNDNNUUUUUUNNS";

    // Decodificar instrucciones y mostrar la última frase
    std::string resultado = decodificarInstrucciones(instrucciones);

    return 0;
}
