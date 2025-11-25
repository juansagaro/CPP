/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:47:55 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/24 18:47:55 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		HumanB(const std::string name);
		~HumanB();

		void setWeapon(Weapon& weapon);
		void attack() const;
};

#endif