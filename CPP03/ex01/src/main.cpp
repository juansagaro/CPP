/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:50:54 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/01/25 14:50:54 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

int main() {
    std::cout << "--- CREANDO SCAVTRAP ---" << std::endl;
    ScavTrap robot("Guardian");

    std::cout << "\n--- PROBANDO ATAQUE (Debe ser mensaje nuevo) ---" << std::endl;
    robot.attack("Intruder"); // Debería hacer 20 de daño

    std::cout << "\n--- PROBANDO GUARD GATE ---" << std::endl;
    robot.guardGate();

    std::cout << "\n--- PROBANDO HERENCIA (Métodos de ClapTrap) ---" << std::endl;
    robot.takeDamage(10); // Heredado
    robot.beRepaired(10); // Heredado

    std::cout << "\n--- DESTRUYENDO (Orden inverso) ---" << std::endl;
    // Al salir del scope, verás primero el destructor de ScavTrap, luego ClapTrap
    return 0;
}