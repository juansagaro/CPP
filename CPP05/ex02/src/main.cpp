/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:24:01 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:24:01 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    std::cout << "--- TEST 1: SHRUBBERY (Low Level) ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");
        
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;

        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: ROBOTOMY (Mid Level) ---" << std::endl;
    try {
        Bureaucrat doctor("Dr. House", 45);
        RobotomyRequestForm robot("Bender");

        doctor.signForm(robot);
        doctor.executeForm(robot);
        doctor.executeForm(robot);
        doctor.executeForm(robot);
    }
    catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: PRESIDENTIAL (High Level & Errors) ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 140);
        Bureaucrat president("Zaphod", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        intern.signForm(pardon);
        
        president.signForm(pardon);

        intern.executeForm(pardon);

        president.executeForm(pardon);
    }
    catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
