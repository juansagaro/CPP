/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:44:00 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/16 11:54:43 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

// --- CONSTRUCTORES ---

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name),
      FragTrap(name),
      _name(name)
{
    this->_hitPoints = FragTrap::_hitPoints; 
    this->_energyPoints = ScavTrap::_energyPoints; 
    this->_attackDamage = FragTrap::_attackDamage;
    
    std::cout << "DiamondTrap " << _name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap() 
    : ClapTrap("Default_clap_name"), 
      ScavTrap(), 
      FragTrap(), 
      _name("Default") 
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap Default constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
    : ClapTrap(other), ScavTrap(other), FragTrap(other) 
{
    *this = other;
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "DiamondTrap Assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap name: " << this->_name << std::endl;

    std::cout << "I am ClapTrap name: " << ClapTrap::_name << std::endl;
}
