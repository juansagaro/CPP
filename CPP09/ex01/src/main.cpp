/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:15:25 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/06 17:17:30 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Try: ./rpn \"expression\"" << std::endl;
        std::cerr << "Example: ./rpn \"3 4 + 2 *\"" << std::endl;
        return 1;
    }

    RPN rpn;
    rpn.calculate(argv[1]);

    return 0;
}
