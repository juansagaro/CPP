/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:02:48 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/06 20:53:06 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <cstdlib>
# include <sys/time.h>
# include <algorithm>

class PmergeMe {
private:
    std::vector<int> _vector;
    std::deque<int>  _deque;
    double           _timeVector;
    double           _timeDeque;

    void sortVector();
    void mergeInsertVector(std::vector<int>& arr);
    
    void sortDeque();
    void mergeInsertDeque(std::deque<int>& arr);

    size_t getJacobsthal(size_t n);
    std::vector<size_t> generateJacobsthalSequence(size_t size);

    double getTime() const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& src);
    ~PmergeMe();

    void execute(int argc, char **argv);
};

#endif
