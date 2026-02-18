/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:55:45 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:55:45 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const & target);
    RobotomyRequestForm(RobotomyRequestForm const & src);
    ~RobotomyRequestForm();

    RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

    void execute(Bureaucrat const & executor) const;
};

#endif
