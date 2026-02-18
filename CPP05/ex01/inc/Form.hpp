/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:30:21 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 17:30:21 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {
private:
    std::string const _name;
    bool _isSigned;
    int const _gradeToSign;
    int const _gradeToExec;

public:
    Form();
    Form(std::string const & name, int gradeToSign, int gradeToExec);
    Form(Form const & src);
    ~Form();

    Form & operator=(Form const & src);

    std::string const & getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    void beSigned(Bureaucrat const & bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif
