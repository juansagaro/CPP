/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 21:33:45 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/01/25 21:33:45 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap Copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->_name << " destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void) {
    if (_hitPoints <= 0) {
        std::cout << "FragTrap " << _name << " is dead and cannot high five :(" << std::endl;
        return; 
    }
    std::cout << "FragTrap " << _name << " requests a positive high five! ✋" << std::endl;
}
