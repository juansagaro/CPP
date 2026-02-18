/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:26:39 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:26:39 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon Form", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) 
    : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) 
    : AForm(src), _target(src._target) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    this->checkExecution(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
