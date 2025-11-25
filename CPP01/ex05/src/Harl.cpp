/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:18:30 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/25 21:48:44 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    // 1. Array de los niveles (strings)
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    // 2. Array de punteros a funciones miembro
    // Sintaxis: void (Clase::*nombre)(parametros)
    void (Harl::*ptr_complain[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // 3. Iteramos para buscar la coincidencia
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            // Llamada a la función miembro.
            // (this->*ptr)(): Necesitamos 'this' porque estamos dentro de la clase.
            (this->*ptr_complain[i])();
            return;
        }
    }
    // Opcional: Si no encuentra el nivel, simplemente no hace nada o imprime error.
}