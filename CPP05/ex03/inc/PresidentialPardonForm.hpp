/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:55:36 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/18 18:55:36 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string _target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const & target);
    PresidentialPardonForm(PresidentialPardonForm const & src);
    ~PresidentialPardonForm();

    PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

    void execute(Bureaucrat const & executor) const;
};

#endif
