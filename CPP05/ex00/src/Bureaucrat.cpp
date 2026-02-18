/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:23:06 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 13:23:06 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade) {
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade) {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src) {
    if (this != &src) {
        this->_grade = src.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string const & Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i) {
    o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
    return o;
}
