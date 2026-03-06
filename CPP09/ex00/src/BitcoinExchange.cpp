/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:10:34 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/06 17:05:34 by jsagaro-         ###   ########.fr       */
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
    std::getline(file, line);

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

static std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            std::string trimmed = trim(line);
            if (trimmed == "date | value" || trimmed == "date|value")
                continue;
        }
        processLine(line);
    }
    file.close();
}

void BitcoinExchange::processLine(const std::string& line) {
    std::string trimmedLine = trim(line);

    if (trimmedLine.empty()) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    size_t pipePos = trimmedLine.find('|');

    if (pipePos == std::string::npos) {
        std::cerr << "Error: bad input => " << trimmedLine << std::endl;
        return;
    }

    if (trimmedLine.find('|', pipePos + 1) != std::string::npos) {
        std::cerr << "Error: bad input => " << trimmedLine << std::endl;
        return;
    }

    std::string date = trim(trimmedLine.substr(0, pipePos));
    std::string valueStr = trim(trimmedLine.substr(pipePos + 1));
    float value;

    if (date.empty() || !isValidDate(date)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    if (valueStr.empty()) {
        std::cerr << "Error: bad input => " << trimmedLine << std::endl;
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

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1)
        return false;

    struct tm timeinfo;
    
    timeinfo.tm_sec = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_hour = 12;
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
    if (valueStr.empty()) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    size_t i = 0;
    if (valueStr[0] == '+' || valueStr[0] == '-') {
        if (valueStr[0] == '-') {
            std::cerr << "Error: not a positive number." << std::endl;
            return false;
        }
        i = 1;
    }

    if (i >= valueStr.length()) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    bool hasDot = false;
    bool hasDigit = false;
    for (; i < valueStr.length(); i++) {
        if (valueStr[i] == '.') {
            if (hasDot) {
                std::cerr << "Error: not a positive number." << std::endl;
                return false;
            }
            hasDot = true;
        } else if (std::isdigit(valueStr[i])) {
            hasDigit = true;
        } else {
            std::cerr << "Error: not a positive number." << std::endl;
            return false;
        }
    }

    if (!hasDigit) {
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
