/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:58:59 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:58:59 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src) {
    *this = src;
}

Intern & Intern::operator=(Intern const & src) {
    (void)src;
    return *this;
}

Intern::~Intern() {}

AForm * Intern::makeShrubbery(std::string const & target) {
    return new ShrubberyCreationForm(target);
}

AForm * Intern::makeRobotomy(std::string const & target) {
    return new RobotomyRequestForm(target);
}

AForm * Intern::makePresidential(std::string const & target) {
    return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm(std::string const & formName, std::string const & target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    typedef AForm * (Intern::*FormMaker)(std::string const &);

    FormMaker makers[] = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*makers[i])(target);
        }
    }

    std::cout << "Intern cannot create " << formName << " because it doesn't exist." << std::endl;
    throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found!";
}
