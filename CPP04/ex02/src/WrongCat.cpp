/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:20:54 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:20:54 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

// --- OCF ---
WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
    *this = src;
    std::cout << "WrongCat copy constructed" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
    if (this != &src)
        WrongAnimal::operator=(src);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

// --- Métodos ---
void WrongCat::makeSound() const {
    std::cout << "WrongCat: Meow! (But you might not hear this...)" << std::endl;
}
