/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:57:33 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:57:33 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(Intern const & src);
    ~Intern();

    Intern & operator=(Intern const & src);

    AForm * makeForm(std::string const & formName, std::string const & target);

	class FormNotFoundException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

private:
    AForm * makeShrubbery(std::string const & target);
    AForm * makeRobotomy(std::string const & target);
    AForm * makePresidential(std::string const & target);
};

#endif
