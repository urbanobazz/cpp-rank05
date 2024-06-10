/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:25:14 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/10 15:05:44 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const &other) {
	if (this != &other) {
		this->_dataBase = other._dataBase;
		this->_input = other._input;
	}
	return *this;
}

/* void	BitcoinExchange::parseInput(std::string const &fileName) { //make a new data structure to store the input
	std::ifstream	file(fileName);
	std::string		line;

	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << fileName << std::endl;
		exit(1);
	}
	while (std::getline(file, line)) {
		std::string::size_type	pos = line.find(' ');
		std::string			date = line.substr(0, pos);
		double				amount = std::strtod(line.substr(pos + 2).c_str(), NULL); // make my own conversion fucntion and check for errors

		this->_input[date] = amount;
	}
	file.close();
} */

void	BitcoinExchange::parseDataBase(std::string const &fileName) {
	std::ifstream	file(fileName);
	std::string		line;

	if (strncmp(fileName.c_str() + fileName.length() - 4, ".csv", 4) != 0) {
		std::cerr << "Error: file " << fileName << " is not a CSV file" << std::endl;
		exit(1);
	}
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file " << fileName << std::endl;
		exit(1);
	}
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		std::cerr << "Error: invalid database file format" << std::endl;
		exit(1);
	}
	while (std::getline(file, line)) {
		std::string::size_type	pos = line.find(',');
		std::string				date = line.substr(0, pos);
		double					rate = toDouble(line.substr(pos + 1));

		this->_dataBase.insert(std::make_pair(date, rate));
	}
	file.close();
}

int	BitcoinExchange::toInt(std::string const &str) {
	std::istringstream	iss(str);
	int					n;

	iss >> n;
	if (iss.fail() || !iss.eof()) {
		std::cerr << "Error: invalid input (not an Int)." << std::endl;
		return -1;
	}
	return n;
}

double	BitcoinExchange::toDouble(std::string const &str) {
	std::istringstream	iss(str);
	double				n;

	iss >> n;
	if (iss.fail() || !iss.eof()) {
		std::cerr << "Error: invalid input (not a Double)." << std::endl;
		return -1;
	}
	return n;
}


