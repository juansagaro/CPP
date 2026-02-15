/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceString.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:18:30 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/15 19:42:39 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sedIsForLosers.hpp"

void replaceString(std::string& content, const std::string& s1, const std::string& s2) {
    if (s1.empty()) {
        return;
    }

    size_t pos = 0;
    
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        
        content.erase(pos, s1.length());
        
        content.insert(pos, s2);
        
        pos += s2.length();
    }
}