/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:38:00 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/08/30 19:37:03 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void    put_str_upper(char *s)
{
    int     i;
    char    c;

    i = -1;
    while (s[++i])
    {
        c = std::toupper(s[i]);
        std::cout << c;
    }
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    i = 0;
    while (++i < argc)
    {
        put_str_upper(argv[i]);
        if (i + 1 < argc)
            std::cout << ' ';
    }
    std::cout << std::endl;
    return (0);
}
