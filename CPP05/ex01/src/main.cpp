/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:34:55 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 17:34:55 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main() {
    std::cout << "--- TEST 1: FORM CREATION BASICS ---" << std::endl;
    try {
        Form tax("Tax Return", 50, 100);
        std::cout << tax << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: FORM CREATION ERRORS ---" << std::endl;
    try {
        Form impossible("Impossible", 0, 100);
    }
    catch (std::exception & e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: SIGNING SUCCESS ---" << std::endl;
    try {
        Bureaucrat hermes("Hermes", 10);
        Form order("Delivery Order", 20, 50);

        std::cout << hermes << std::endl;
        std::cout << order << std::endl;
        
        hermes.signForm(order);
        std::cout << order << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: SIGNING FAILURE (GRADE TOO LOW) ---" << std::endl;
    try {
        Bureaucrat fry("Fry", 100);
        Form constitution("Constitution", 1, 1);

        std::cout << fry << std::endl;
        std::cout << constitution << std::endl;

        fry.signForm(constitution);
    }
    catch (std::exception & e) {
        std::cout << "This should not be printed (exception handles internally): " << e.what() << std::endl;
    }

    return 0;
}
