/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:02:48 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/12 19:50:20 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <sys/time.h>
#include <algorithm>

// ═══════════════════════════════════════════════════════════════════════════
// ANSI Color Codes
// ═══════════════════════════════════════════════════════════════════════════
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// ═══════════════════════════════════════════════════════════════════════════
// Configuration
// ═══════════════════════════════════════════════════════════════════════════
#define MAX_DISPLAY 10

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& src);
    ~PmergeMe();

    void execute(int argc, char** argv);

private:
    // ─── Data ───────────────────────────────────────────────────────────────
    std::vector<int> _vec;
    std::deque<int>  _deq;
    double           _timeVec;
    double           _timeDeq;

    // ─── Sorting ────────────────────────────────────────────────────────────
    void fordJohnson(std::vector<int>& arr);
    void fordJohnson(std::deque<int>& arr);

    // ─── Jacobsthal ─────────────────────────────────────────────────────────
    static size_t              jacobsthal(size_t n);
    static std::vector<size_t> jacobsthalSequence(size_t size);
    static std::vector<size_t> buildInsertionOrder(size_t pendSize);

    // ─── Utils ──────────────────────────────────────────────────────────────
    static double now();
    static int    parseNumber(const std::string& arg);
    static void   printSequence(const std::string& label, 
                                const std::vector<int>& arr, 
                                const std::string& color);
};
