/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:18:01 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/25 21:19:45 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sedIsForLosers.hpp"

int main(int argc, char* argv[]) {
    // 1. Validación de argumentos
    if (argc != 4) {
        std::cerr << "Error: Uso incorrecto." << std::endl;
        std::cerr << "Uso: ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // 2. Abrir archivo de entrada (Lectura)
    // .c_str() es necesario en C++98 para los constructores de fstream
    std::ifstream inFile(filename.c_str());
    
    if (!inFile.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo de entrada '" << filename << "'" << std::endl;
        return 1;
    }

    // 3. Leer todo el contenido del archivo
    // Hay muchas formas, esta es una forma robusta usando un buffer temporal
    std::string content;
    std::string line;
    
    // Leemos línea a línea y las unimos (getline descarta el \n, hay que volver a ponerlo)
    // Nota: Esta técnica puede fallar si el archivo no termina en \n, pero es estándar para ejercicios simples.
    while (std::getline(inFile, line)) {
        content += line;
        if (!inFile.eof()) // Si no es la última línea, añadimos el salto de línea que getline quitó
            content += "\n";
    }
    
    // Cerramos el archivo de entrada, ya tenemos el contenido en memoria
    inFile.close();

    // 4. Aplicar la lógica de reemplazo
    replaceString(content, s1, s2);

    // 5. Crear archivo de salida (Escritura)
    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());

    if (!outFile.is_open()) {
        std::cerr << "Error: No se pudo crear el archivo de salida." << std::endl;
        return 1;
    }

    // 6. Escribir el resultado
    outFile << content;
    
    outFile.close();

    return 0;
}