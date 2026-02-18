/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:56:24 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:56:24 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) 
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    this->checkExecution(executor);

    std::ofstream outfile((this->_target + "_shrubbery").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }
    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;
    outfile.close();
}
