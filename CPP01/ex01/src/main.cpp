/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:36:44 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/24 18:36:44 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Uso correcto: ./moar_brainz <nombre_zombie> <cantidad>" << std::endl;
        std::cerr << "Ejemplo: ./moar_brainz Walker 5" << std::endl;
        return 1;
    }

    std::string name = argv[1];
    
    int N = std::atoi(argv[2]);

    if (N <= 0) {
        std::cerr << "Error: La cantidad de zombies debe ser mayor a 0." << std::endl;
        return 1;
    }
    
    if (N > 100000) {
        std::cout << "Advertencia: Demasiados zombies. Limitando a 10 para evitar crasheos." << std::endl;
        N = 10;
    }

    std::cout << "--- Generando horda de " << N << " zombies llamados '" << name << "' ---" << std::endl;

    Zombie* horda = zombieHorde(N, name);

    if (horda == NULL) {
        std::cerr << "Error fatal: No se pudo reservar memoria." << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        std::cout << "[" << i + 1 << "] "; 
        horda[i].announce();
    }

    delete[] horda;
    
    std::cout << "--- Horda eliminada. Memoria limpia. ---" << std::endl;

    return 0;
}