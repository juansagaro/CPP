/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:04:05 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/12 20:06:36 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No numbers provided." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <number1> <number2> ..." << std::endl;
        return 1;
    }

    PmergeMe sorter;
    sorter.execute(argc, argv);

    return 0;
}
