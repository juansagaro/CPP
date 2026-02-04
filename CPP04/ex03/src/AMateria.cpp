/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:32:21 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/04 20:32:21 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp" // Aquí sí necesitamos la definición completa

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &src) {
    *this = src;
}

AMateria &AMateria::operator=(const AMateria &src) {
    (void)src; // No copiamos el tipo, se mantiene el que ya tenía
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return this->_type;
}

void AMateria::use(ICharacter& target) {
    // Implementación base por defecto (puede estar vacía)
    (void)target;
}
