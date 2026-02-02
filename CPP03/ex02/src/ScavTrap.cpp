/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 21:15:55 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/01/25 21:15:55 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"
#include <iostream>

// --- CONSTRUCTORES ---

// Constructor por defecto
ScavTrap::ScavTrap() : ClapTrap() {
    // Primero se construye ClapTrap (automáticamente o explícitamente arriba)
    // Luego sobrescribimos los valores para ScavTrap
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Default constructor called." << std::endl;
}

// Constructor con nombre
// Fíjate en ": ClapTrap(name)". Aquí le pasamos el nombre al constructor del PADRE.
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructor called." << std::endl;
}

// Constructor de copia
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "ScavTrap Copy constructor called." << std::endl;
}

// Operador de asignación
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        // Llamamos al operador de asignación del padre para copiar la parte de ClapTrap
        ClapTrap::operator=(other); 
        // Aquí copiaríamos atributos exclusivos de ScavTrap si tuviera
    }
    return *this;
}

// --- DESTRUCTOR ---

ScavTrap::~ScavTrap() {
    // Primero se ejecuta esto, y AUTOMÁTICAMENTE después se llama a ~ClapTrap()
    std::cout << "ScavTrap " << this->_name << " destructor called." << std::endl;
}

// --- MÉTODOS ---

// Sobreescribimos attack para que imprima un mensaje diferente
void ScavTrap::attack(const std::string& target) {
    if (_energyPoints == 0 || _hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " cannot attack." << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " viciously attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
