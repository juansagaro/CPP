/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:16:20 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:16:20 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain* _brain;

public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &src);
    virtual ~Cat();

    virtual void makeSound() const;

    void compareIdeas(const Cat &other) const;
};

#endif
