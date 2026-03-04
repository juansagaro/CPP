/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:10:34 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/04 19:21:42 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _database(src._database) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
    if (this != &src) {
        _database = src._database;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line); // Saltamos la cabecera "date,exchange_rate"

    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            float rate = std::atof(line.substr(commaPos + 1).c_str());
            _database[date] = rate;
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl; // Error exacto del subject
        return;
    }

    std::string line;
    std::getline(file, line); // Leemos la cabecera "date | value"

    while (std::getline(file, line)) {
        processLine(line);
    }
    file.close();
}

void BitcoinExchange::processLine(const std::string& line) {
    size_t pipePos = line.find(" | ");
    
    if (pipePos == std::string::npos) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date = line.substr(0, pipePos);
    std::string valueStr = line.substr(pipePos + 3);
    float value;

    if (!isValidDate(date)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    if (!isValidValue(valueStr, value)) {
        return;
    }

    std::map<std::string, float>::iterator it = _database.lower_bound(date);

    if (it == _database.end() || it->first != date) {
        if (it == _database.begin()) {
            std::cerr << "Error: date is prior to database records." << std::endl;
            return;
        }
        --it;
    }

    std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    struct tm timeinfo;
    
    timeinfo.tm_sec = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_hour = 0;
    timeinfo.tm_isdst = -1; 
    
    timeinfo.tm_year = year - 1900; 
    timeinfo.tm_mon = month - 1;    
    timeinfo.tm_mday = day;

    std::mktime(&timeinfo);

    if (timeinfo.tm_year != (year - 1900) || 
        timeinfo.tm_mon != (month - 1) || 
        timeinfo.tm_mday != day) {
        return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    if (valueStr.empty() || valueStr.find_first_not_of("0123456789.-+") != std::string::npos) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    value = std::atof(valueStr.c_str());

    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}
