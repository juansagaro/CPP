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

#include "../inc/ClapTrap.hpp"

int main() {
    // Crear instancia (Llama al Constructor automáticamente)
    ClapTrap robot("CL4P-TP");

    // Probar ataque
    robot.attack("Bandit");
    
    // Probar recibir daño
    robot.takeDamage(5);
    
    // Probar repararse
    robot.beRepaired(3);

    // Probar recibir daño letal
    robot.takeDamage(10);
    
    // Intentar actuar estando muerto (debería fallar)
    robot.attack("Bandit");
    robot.beRepaired(5);

    // El Destructor se llama automáticamente aquí al salir del scope
    return 0;
}
