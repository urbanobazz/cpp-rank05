/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:25:14 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/12 11:33:01 by ubazzane         ###   ########.fr       */
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
	std::ifstream	file(fileName.c_str());
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
		float					rate = toFloat(line.substr(pos + 1));

		this->_dataBase.insert(std::make_pair(date, rate));
	}
	file.close();
}

int	BitcoinExchange::toInt(std::string const &str) {
	std::istringstream	iss(str);
	int					n;

	iss >> n;
	if (iss.fail() || !iss.eof()) {
		return -1;
	}
	return n;
}

double	BitcoinExchange::toFloat(std::string const &str) {
	std::istringstream	iss(str);
	float				n;

	iss >> n;
	if (iss.fail() || !iss.eof())
		return -1;
	if (n < 0)
		return -2;
	return n;
}

t_date BitcoinExchange::stringToDate(std::string const &str)
{
	t_date	date;
	std::istringstream	iss(str);
	char delimiter1, delimiter2;

	iss >> date.year >> delimiter1 >> date.month >> delimiter2 >> date.day;
	if (iss.fail() || delimiter1 != '-' || delimiter2 != '-')
		date.year = -1, date.month = -1, date.day = -1;
	return date;
}

bool BitcoinExchange::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool BitcoinExchange::isValidDate(t_date const &date) {
	if (date.year < 0 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31)
		return false;
	if (date.month == 2)
	if (isLeapYear(date.year) && date.day > 29)
		return false;
	if (!isLeapYear(date.year) && date.day > 28)
		return false;
	if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30)
		return false;
	return true;
}

void	BitcoinExchange::processInput(std::string const &fileName) {
	std::ifstream	file(fileName.c_str());
	std::string		line;

	if (!file.is_open()) {
		std::cerr << "Error: could not open input file " << fileName << std::endl;
		exit(1);
	}
	int flag = 0;
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		else if (flag == 0 && line != "date | value") {
			std::cerr << "Error: invalid file format[input]" << std::endl;
			exit(1);
		}
		else if (flag == 0)
		{
			flag = 1;
			continue;
		}
		std::string::size_type	pos = line.find('|');
		t_date					date = stringToDate(line.substr(0, pos));
		float					value = toFloat(line.substr(pos + 1));

		if (!isValidDate(date))
			std::cerr << "Error: invalid date => " << line.substr(0, pos) << std::endl;
		else if (value == -1)
			std::cerr << "Error: invalid value [ " << line.substr(pos + 1) << "]" << std::endl;
		else if (value == -2)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cerr << "Error: value too high." << std::endl;
		else
			calculateValue(value, date);
	}
}

void	BitcoinExchange::calculateValue(float amount, t_date const &date) {
	std::map<t_date, double>::iterator	it = this->_dataBase.lower_bound(date);

	if (it == this->_dataBase.begin())
	{
		if (it->first == date)
			std::cout << date << " => " << amount << " = " << amount * it->second << std::endl;
		else
		std::cout << " No match found to this date." << std::endl;
		return;
	}
	if (it == this->_dataBase.end() || !(it->first == date))
		--it;
	std::cout << date << " => " << amount << " = " << amount * it->second << std::endl;
}


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
