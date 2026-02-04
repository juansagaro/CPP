/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:20:37 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:20:37 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    // Constructores y Destructor (OCF)
    WrongCat();
    WrongCat(const WrongCat &src);
    WrongCat &operator=(const WrongCat &src);
    ~WrongCat();

    // Intentamos sobrescribir la función, pero sin virtual en el padre,
    // esto es solo "shadowing" (ocultación), no "overriding" (sobrescritura).
    void makeSound() const;
};

#endif
