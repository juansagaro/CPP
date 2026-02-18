/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:56:08 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:56:08 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"

int main() {
    Intern  someRandomIntern;
    AForm* rrf = NULL;

    std::cout << "--- TEST 1: ROBOTOMY REQUEST (Valid) ---" << std::endl;
    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        
        delete rrf; 
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: SHRUBBERY CREATION (Valid) ---" << std::endl;
    try {
        rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        
        Bureaucrat gardener("Gardener", 137);
        gardener.signForm(*rrf);
        gardener.executeForm(*rrf);
        
        delete rrf;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: INVALID FORM ---" << std::endl;
    try {
        rrf = someRandomIntern.makeForm("coffee request", "Boss");

        if (rrf)
            delete rrf;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught successfully: " << e.what() << std::endl;
    }

    return 0;
}
