/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:33:20 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/04 20:33:20 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cure.cpp
#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &src) : AMateria(src) {}

Cure &Cure::operator=(const Cure &src) {
    if (this != &src)
        AMateria::operator=(src);
    return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
