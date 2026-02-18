/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:25:06 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:25:06 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(std::string const & name, int gradeToSign, int gradeToExec) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) 
    : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {}

AForm & AForm::operator=(AForm const & src) {
    if (this != &src) {
        this->_isSigned = src._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string const & AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExec() const { return _gradeToExec; }

void AForm::beSigned(Bureaucrat const & bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

void AForm::checkExecution(Bureaucrat const & executor) const {
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExec)
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() { return "Grade is too high"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Grade is too low"; }
const char* AForm::FormNotSignedException::what() const throw() { return "Form is not signed"; }

std::ostream & operator<<(std::ostream & o, AForm const & i) {
    o << "Form [" << i.getName() << "] | Signed: " << (i.getIsSigned() ? "Yes" : "No")
		<< " | Sign Grade: " << i.getGradeToSign() << " | Exec Grade: " << i.getGradeToExec();
    return o;
}
