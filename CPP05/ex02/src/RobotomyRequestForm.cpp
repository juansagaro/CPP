/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:26:30 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:26:30 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) 
    : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) 
    : AForm(src), _target(src._target) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    this->checkExecution(executor);

    std::cout << "* DRRRRRRRRRRRRR... Drilling noises * " << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->_target << "." << std::endl;
}
