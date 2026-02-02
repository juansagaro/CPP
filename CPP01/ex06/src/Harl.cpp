/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:19:47 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/27 17:19:47 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    int i = 0;

    // 1. Buscamos qué nivel es (convertimos string a int)
    while (i < 4 && levels[i] != level)
        i++;

    // 2. Switch con Fall-through
    switch (i)
    {
        case 0:
            this->debug();
			__attribute__ ((fallthrough));
            // ¡NO hay break! Cae al siguiente
        case 1:
            this->info();
			__attribute__ ((fallthrough));
            // ¡NO hay break! Cae al siguiente
        case 2:
            this->warning();
			__attribute__ ((fallthrough));
            // ¡NO hay break! Cae al siguiente
        case 3:
            this->error();
            break; // Aquí sí paramos
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}