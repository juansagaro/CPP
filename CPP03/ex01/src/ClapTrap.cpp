/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:50:24 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/01/25 14:50:24 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

// --- CONSTRUCTORES Y DESTRUCTOR ---

// Constructor principal
ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap " << _name << " has been constructed!" << std::endl;
}

// Constructor por defecto (necesario para OCF, aunque no se use mucho aquí)
ClapTrap::ClapTrap() 
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap Default has been constructed!" << std::endl;
}

// Constructor de copia: Crea un objeto nuevo idéntico a 'other'
ClapTrap::ClapTrap(const ClapTrap &other) {
    *this = other;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

// Operador de asignación: Copia datos de 'other' a un objeto ya existente
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor: Se llama al final de la vida del objeto
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

// --- MÉTODOS DE ACCIÓN ---

void ClapTrap::attack(const std::string& target) {
    // Regla del ejercicio: No puede hacer nada si no tiene HP o Energía
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
        return;
    }

    // Coste de acción
    _energyPoints--;
    
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }

    // Protección para que no baje de 0 (unsigned int no tiene negativos)
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;

    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " points of damage! HP is now " << _hitPoints << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy left to repair!" << std::endl;
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << std::endl;
        return;
    }

    _energyPoints--;
    _hitPoints += amount;

    std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount 
              << " hit points! HP is now " << _hitPoints << "." << std::endl;
}
