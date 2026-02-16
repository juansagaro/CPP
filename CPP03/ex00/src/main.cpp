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
    ClapTrap robot("CL4P-TP");

    robot.attack("Bandit");

    robot.takeDamage(5);

    robot.beRepaired(3);

    robot.takeDamage(10);

    robot.attack("Bandit");
    robot.beRepaired(5);

    return 0;
}
