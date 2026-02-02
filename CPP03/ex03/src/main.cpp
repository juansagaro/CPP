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

#include "../inc/DiamondTrap.hpp"

int main() {
    std::cout << "--- CONSTRUCCIÓN ---" << std::endl;
    DiamondTrap monster("Monster");

    std::cout << "\n--- DATOS DEL MONSTRUO ---" << std::endl;
    // HP hereda de FragTrap (100)
    // Energy hereda de ScavTrap (50)
    // Attack hereda de FragTrap (30)
    monster.whoAmI();

    std::cout << "\n--- ACCIONES ---" << std::endl;
    monster.attack("Victim"); // Debería usar ScavTrap::attack
    monster.highFivesGuys();  // De FragTrap
    monster.guardGate();      // De ScavTrap

    std::cout << "\n--- DESTRUCCIÓN ---" << std::endl;
    return 0;
}
