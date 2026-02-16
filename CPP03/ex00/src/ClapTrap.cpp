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

ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap " << _name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap() 
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap Default has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    *this = other;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
        return;
    }

    _energyPoints--;
    
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }

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
