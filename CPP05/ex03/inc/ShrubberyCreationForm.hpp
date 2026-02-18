/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:55:51 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:55:51 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(ShrubberyCreationForm const & src);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

    void execute(Bureaucrat const & executor) const;
};

#endif
