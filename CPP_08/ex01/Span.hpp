/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:46:05 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/07 16:53:35 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>

class	Span
{
	public:
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);

		Span &operator=(Span const &rhs);

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);

	private:
		Span(void);

		unsigned int	_N;
		std::vector<int>	_numbers;
};

#endif
