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
#include <cstdlib> // Para std::atoi

int main(int argc, char* argv[])
{
    // 1. Validación de argumentos: Ahora esperamos 3 (Ejecutable, Nombre, Cantidad)
    if (argc != 3) {
        std::cerr << "Uso correcto: ./moar_brainz <nombre_zombie> <cantidad>" << std::endl;
        std::cerr << "Ejemplo: ./moar_brainz Walker 5" << std::endl;
        return 1;
    }

    // 2. Extracción de argumentos
    // argv[1] es ahora el nombre (std::string se construye automáticamente desde char*)
    std::string name = argv[1];
    
    // argv[2] es ahora la cantidad (convertimos de string a int)
    int N = std::atoi(argv[2]);

    // 3. Validaciones de seguridad para el número
    if (N <= 0) {
        std::cerr << "Error: La cantidad de zombies debe ser mayor a 0." << std::endl;
        return 1;
    }
    
    // Límite opcional por seguridad (para no colgar tu PC si pones 2 millones)
    if (N > 100000) {
        std::cout << "Advertencia: Demasiados zombies. Limitando a 10 para evitar crasheos." << std::endl;
        N = 10;
    }

    std::cout << "--- Generando horda de " << N << " zombies llamados '" << name << "' ---" << std::endl;

    // 4. Llamada a la función (Recuerda: el prototipo es (int N, string name))
    Zombie* horda = zombieHorde(N, name);

    // Verificación de fallo de memoria (buena práctica)
    if (horda == NULL) {
        std::cerr << "Error fatal: No se pudo reservar memoria." << std::endl;
        return 1;
    }

    // 5. Prueba: Hacemos que todos se anuncien
    for (int i = 0; i < N; i++) {
        // Imprimimos el índice para verificar que son objetos distintos
        std::cout << "[" << i + 1 << "] "; 
        horda[i].announce();
    }

    // 6. LIBERACIÓN DE MEMORIA (¡IMPORTANTE!)
    delete[] horda;
    
    std::cout << "--- Horda eliminada. Memoria limpia. ---" << std::endl;

    return 0;
}