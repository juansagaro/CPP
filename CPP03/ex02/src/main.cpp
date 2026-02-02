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

#include "../inc/FragTrap.hpp"

int main() {
    std::cout << "--- CREANDO FRAGTRAP ---" << std::endl;
    FragTrap robot("Clappy");

    std::cout << "\n--- PROBANDO ATAQUE HEREDADO ---" << std::endl;
    // Usará el mensaje de "ClapTrap::attack" porque no lo sobrescribimos,
    // PERO hará 30 de daño porque cambiamos la variable _attackDamage.
    robot.attack("TargetDummy"); 

    std::cout << "\n--- PROBANDO HABILIDAD ESPECIAL ---" << std::endl;
    robot.highFivesGuys();

    std::cout << "\n--- DESTRUYENDO ---" << std::endl;
    return 0;
}
