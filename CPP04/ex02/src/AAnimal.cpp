/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:17:24 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:17:24 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* AAnimal.cpp */
#include "../inc/AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
    *this = src;
    std::cout << "AAnimal copy constructed" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src) {
    if (this != &src)
        this->type = src.type;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destroyed" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}
// NOTA: makeSound() ha desaparecido del .cpp
