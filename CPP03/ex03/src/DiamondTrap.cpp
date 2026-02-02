/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:44:00 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/02 13:11:31 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

// --- CONSTRUCTORES ---

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"), // 1. Construimos al abuelo DIRECTAMENTE
      ScavTrap(name),                // 2. Construimos a los padres (solo para sus partes propias)
      FragTrap(name),
      _name(name)                    // 3. Inicializamos el nombre propio de Diamond
{
    // Configuración de Stats según el enunciado:
    // Hit Points (FragTrap) = 100
    // Energy Points (ScavTrap) = 50
    // Attack Damage (FragTrap) = 30
    
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
        ClapTrap::operator=(other); // Copiamos parte del abuelo
        this->_name = other._name; // Copiamos parte propia
        // ScavTrap y FragTrap no tienen datos propios extra que copiar,
        // pero sus atributos heredados ya están en ClapTrap.
    }
    std::cout << "DiamondTrap Assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
}

// --- FUNCIONES ---

void DiamondTrap::whoAmI() {
    // Aquí accedemos a las dos variables "_name" diferentes.
    
    // 1. La propia de DiamondTrap
    std::cout << "I am DiamondTrap name: " << this->_name << std::endl;
    
    // 2. La del abuelo ClapTrap. Usamos el scope resolution (::) para llegar a ella.
    std::cout << "I am ClapTrap name: " << ClapTrap::_name << std::endl;
}
