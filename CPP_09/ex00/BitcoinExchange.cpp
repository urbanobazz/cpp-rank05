/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:25:14 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/10 16:21:38 by ubazzane         ###   ########.fr       */
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
	}
	return *this;
}

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
		t_date					date = stringToDate(line.substr(0, pos));
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

t_date BitcoinExchange::stringToDate(std::string const &str)
{
	t_date	date;
	std::string::size_type	pos = str.find('-');

	date.year = toInt(str.substr(0, pos));
	date.month = toInt(str.substr(pos + 1, str.find('-', pos + 1) - pos - 1));
	date.day = toInt(str.substr(str.find('-', pos + 1) + 1));
	return date;
}

bool BitcoinExchange::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool BitcoinExchange::isValidDate(std::string const &str) {
	t_date	date = stringToDate(str);

	if (date.year < 0 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31) {
		std::cerr << "Error: invalid date." << std::endl;
		return false;
	}
	if (date.month == 2) {
		if (isLeapYear(date.year) && date.day > 29) {
			std::cerr << "Error: invalid date." << std::endl;
			return false;
		}
		if (!isLeapYear(date.year) && date.day > 28) {
			std::cerr << "Error: invalid date." << std::endl;
			return false;
		}
	}
	if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30) {
		std::cerr << "Error: invalid date." << std::endl;
		return false;
	}
	return true;
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










// s_date fucntions
bool s_date::operator<(s_date const &other) const
{
	return (this->year < other.year) ? true :
		(this->year == other.year && this->month < other.month) ? true :
		(this->year == other.year && this->month == other.month && this->day < other.day) ? true : false;
}

bool s_date::operator==(s_date const &other) const
{
	return (this->year == other.year && this->month == other.month && this->day == other.day) ? true : false;
}

std::ostream& operator<<(std::ostream& os, const s_date& dt)
{
	os << dt.year << "-" << dt.month << "-" << dt.day;
	return os;
}
