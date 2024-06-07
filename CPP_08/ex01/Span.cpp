/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:46:12 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/07 16:53:37 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) { return ;}

Span::Span(unsigned int N) : _N(N) { return ;}

Span::Span(Span const &src) : _N(src._N), _numbers(src._numbers) { return ;}

Span::~Span(void) { return ;}

Span &Span::operator=(Span const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_N = rhs._N;
	this->_numbers = rhs._numbers;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_numbers.size() == this->_N)
		throw std::exception();
	this->_numbers.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_numbers.size() + std::distance(begin, end) > this->_N)
		throw std::exception();
	this->_numbers.insert(this->_numbers.end(), begin, end);
}

int		Span::shortestSpan(void)
{
	if (this->_numbers.size() < 2)
		throw std::exception();
	std::vector<int>	tmp(this->_numbers);
	std::sort(tmp.begin(), tmp.end());
	int	span = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < span)
			span = tmp[i + 1] - tmp[i];
	}
	return (span);
}

int		Span::longestSpan(void)
{
	if (this->_numbers.size() < 2)
		throw std::exception();
	std::vector<int>	tmp(this->_numbers);
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

