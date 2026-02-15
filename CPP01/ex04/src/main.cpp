/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:18:01 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/15 19:42:09 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sedIsForLosers.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Error: Uso incorrecto." << std::endl;
        std::cerr << "Uso: ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inFile(filename.c_str());
    
    if (!inFile.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo de entrada '" << filename << "'" << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    
    while (std::getline(inFile, line)) {
        content += line;
        if (!inFile.eof())
            content += "\n";
    }
    inFile.close();

    replaceString(content, s1, s2);

    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());

    if (!outFile.is_open()) {
        std::cerr << "Error: No se pudo crear el archivo de salida." << std::endl;
        return 1;
    }

    outFile << content;
    
    outFile.close();

    return 0;
}