/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:46:12 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/07 18:01:11 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) { return ;}

Span::Span(unsigned int N) : _N(N) { return ;}

Span::Span(Span const &other) : _N(other._N), _numbers(other._numbers) { return ;}

Span::~Span(void) { return ;}

Span &Span::operator=(Span const &other)
{
	if (this == &other)
		return (*this);
	this->_N = other._N;
	this->_numbers = other._numbers;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_numbers.size() == this->_N)
		throw std::runtime_error("Array has reached max capacity");
	this->_numbers.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_numbers.size() + std::distance(begin, end) > this->_N)
		throw std::runtime_error("Array has reached max capacity");
	this->_numbers.insert(this->_numbers.end(), begin, end);
}

int		Span::shortestSpan(void)
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers stored!");
	std::vector<int>	tmp(this->_numbers);
	std::sort(tmp.begin(), tmp.end());
	int	span = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < span)
			span = tmp[i] - tmp[i - 1];
	}
	return (span);
}

int		Span::longestSpan(void)
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers stored!");
	std::vector<int>	tmp(this->_numbers);
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

