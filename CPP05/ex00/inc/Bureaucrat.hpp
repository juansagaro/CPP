/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:17:54 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 13:17:54 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
private:
    std::string const _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const &src);
    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &src);

    std::string const &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
