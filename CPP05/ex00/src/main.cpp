/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:26:47 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 13:26:47 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main() {
    std::cout << "--- TEST 1: COMPORTAMIENTO ESTANDAR ---" << std::endl;
    try {
        Bureaucrat hermes("Hermes Conrad", 34);
        std::cout << "Created: " << hermes << std::endl;
        
        hermes.incrementGrade();
        std::cout << "After increment (promotion): " << hermes << std::endl;

        hermes.decrementGrade();
        std::cout << "After decrement (demotion): " << hermes << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: ERRORES EN EL CONSTRUCTOR (LIMITES) ---" << std::endl;
    
    std::cout << "[Testing Grade 151]..." << std::endl;
    try {
        Bureaucrat fry("Fry", 151);
        std::cout << "Error: Fry should not be created." << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Exception caught successfully: " << e.what() << std::endl;
    }

    std::cout << "[Testing Grade 0]..." << std::endl;
    try {
        Bureaucrat god("God", 0);
        std::cout << "Error: God should not be created." << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Exception caught successfully: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: ERRORES EN INCREMENTO/DECREMENTO ---" << std::endl;

    std::cout << "[Testing Increment on Grade 1]..." << std::endl;
    try {
        Bureaucrat boss("Number 1.0", 1);
        std::cout << boss << std::endl;
        boss.incrementGrade();
        std::cout << "Error: Boss grade should not become 0." << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "[Testing Decrement on Grade 150]..." << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;
        intern.decrementGrade();
        std::cout << "Error: Intern grade should not become 151." << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- END OF TESTS ---" << std::endl;

    return 0;
}
