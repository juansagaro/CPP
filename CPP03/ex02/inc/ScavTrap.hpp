/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 21:15:28 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/01/25 21:15:28 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// ScavTrap hereda de ClapTrap
class ScavTrap : public ClapTrap {

public:
    // Constructores y Destructor (Ortodoxo)
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    // Métodos propios o sobreescritos
    void attack(const std::string& target); // Sobreescribimos attack()
    void guardGate(); // Nueva funcionalidad exclusiva de ScavTrap
};

#endif
