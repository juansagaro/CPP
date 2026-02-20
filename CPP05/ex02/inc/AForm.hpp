/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:19:20 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:19:20 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
private:
    std::string const _name;
    bool _isSigned;
    int const _gradeToSign;
    int const _gradeToExec;

protected:
    void checkExecution(Bureaucrat const & executor) const;

public:
    AForm();
    AForm(std::string const & name, int gradeToSign, int gradeToExec);
    AForm(AForm const & src);
    virtual ~AForm();

    AForm & operator=(AForm const & src);

    std::string const & getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    void beSigned(Bureaucrat const & bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, AForm const & i);

#endif
