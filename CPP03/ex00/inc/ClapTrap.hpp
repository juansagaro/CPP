/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:49:33 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/01/25 14:49:33 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
// PRIVATE: Datos internos. En C serían los campos de tu struct.
private:
    std::string     _name;
    unsigned int    _hitPoints;
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;

// PUBLIC: La interfaz. Lo que el usuario puede usar.
public:
    // Constructor con parámetro (lo que pide el ejercicio)
    ClapTrap(std::string name);

    // Forma Canónica Ortodoxa (Buenas prácticas en 42)
    ClapTrap(); // Constructor por defecto
    ClapTrap(const ClapTrap &other); // Constructor de copia
    ClapTrap &operator=(const ClapTrap &other); // Operador de asignación
    ~ClapTrap(); // Destructor

    // Funciones miembro (Métodos)
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif