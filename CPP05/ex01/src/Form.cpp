/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:31:45 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 17:31:45 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}


Form::Form(std::string const & name, int gradeToSign, int gradeToExec) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    
    if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const & src) 
    : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
}

Form & Form::operator=(Form const & src) {
    if (this != &src) {
        this->_isSigned = src._isSigned;
    }
    return *this;
}

Form::~Form() {}

std::string const & Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExec() const {
    return this->_gradeToExec;
}

void Form::beSigned(Bureaucrat const & bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream & operator<<(std::ostream & o, Form const & i) {
    o << "Form [" << i.getName() << "] | Signed: " << (i.getIsSigned() ? "Yes" : "No")
    	<< " | Grade to Sign: " << i.getGradeToSign()
    	<< " | Grade to Exec: " << i.getGradeToExec();
    return o;
}
