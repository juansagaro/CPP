/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:08:22 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/19 10:08:22 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}
