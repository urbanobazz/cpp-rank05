/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:39:58 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/11 19:50:23 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {*this = src;}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_list = other._list;
	}
	return *this;
}

int	PmergeMe::stringToInt(const std::string &str)
{
	std::istringstream	iss(str);
	int					n;

	iss >> n;
	if (iss.fail())
	{
		std::cout << "Error: Invalid input \" " << str << " \"" << std::endl;
		exit(1);
	}
	else if (n < 0)
	{
		std::cout << "Error: Negative number \" " << str << " \"" << std::endl;
		exit(1);
	}
	else
		return n;
}

void	PmergeMe::parseInput(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		std::string str = av[i];
		if (str.find(' ') != std::string::npos)
			parseInputString(str);
		else
		{
			int n = stringToInt(str);
			this->_vector.push_back(n);
			this->_list.push_back(n);
		}
	}
}

void	PmergeMe::parseInputString(std::string &str)
{
	std::string				tmp;
	std::string::size_type	start = 0;
	std::string::size_type	end = 0;

	while (end != std::string::npos)
	{
		end = str.find(' ', start);
		tmp = str.substr(start, end - start);
		if (tmp.size() > 0)
		{
			int n = stringToInt(tmp);
			this->_vector.push_back(n);
			this->_list.push_back(n);
		}
		start = end + 1;
	}
}

void	PmergeMe::push_back(const std::list<int> &lst)
{
	this->_list.insert(this->_list.end(), lst.begin(), lst.end());
}

void	PmergeMe::push_back(const std::vector<int> &vec)
{
	this->_vector.insert(this->_vector.end(), vec.begin(), vec.end());
}

void PmergeMe::sortVector() {
	std::vector<int> lowerHalf;
	std::vector<int> upperHalf;

	timeval start, end;
	gettimeofday(&start, NULL);

	splitSequence(lowerHalf, upperHalf, this->_vector);
	insertionSort(lowerHalf);
	insertionSort(upperHalf);
	merge(lowerHalf, upperHalf, this->_vectorSorted);

	gettimeofday(&end, NULL);
	this->_timeVector = calculateTime(start, end);
}

void PmergeMe::sortList() {
	std::list<int> lowerHalf;
	std::list<int> upperHalf;

	timeval start, end;
	gettimeofday(&start, NULL);

	splitSequence(lowerHalf, upperHalf, this->_list);
	insertionSort(lowerHalf);
	insertionSort(upperHalf);
	merge(lowerHalf, upperHalf, this->_listSorted);

	gettimeofday(&end, NULL);
	this->_timeList = calculateTime(start, end);
}

void	PmergeMe::printResult()
{
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.begin() + 5; it++)
		std::cout << *it << " ";
	if (this->_vector.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;


	std::cout << "Vector after: ";
	for (std::vector<int>::iterator it = this->_vectorSorted.begin(); it != this->_vectorSorted.begin() + 5; it++)
		std::cout << *it << " ";
	if (this->_vectorSorted.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;

	std::cout << "List after: ";
	std::list<int>::iterator it = this->_listSorted.begin();
	std::advance(it, 5);
	for (std::list<int>::iterator it2 = this->_listSorted.begin(); it2 != it; it2++)
		std::cout << *it2 << " ";
	if (this->_listSorted.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;

	std::cout << "Time to preccess a range of " << _vectorSorted.size() << " elements with std::vector: "
	<< std::fixed << std::setprecision(4) << this->_timeVector << " ms." << std::endl;
	std::cout << "Time to preccess a range of " << _listSorted.size() << " elements with std::list: "
	<< std::fixed << std::setprecision(4) << this->_timeList << " ms." << std::endl;
}

double	PmergeMe::calculateTime(struct timeval &start, struct timeval &end)
{
	double microseconds = end.tv_usec - start.tv_usec;
	double seconds = end.tv_sec - start.tv_sec;
	double milliseconds = seconds * 1000.0 + microseconds / 1000.0;
	return milliseconds;
}
