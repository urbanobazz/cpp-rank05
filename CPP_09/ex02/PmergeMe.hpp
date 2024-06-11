/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:40:12 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/11 19:33:20 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <algorithm>
# include <list>
# include <iterator>
# include <sys/time.h>
# include <cstdlib>
# include <iomanip>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &other);

		void		parseInput(char **av);
		void		parseInputString(std::string &str);
		int			stringToInt(const std::string &str);
		void		push_back(const std::list<int> &lst);
		void		push_back(const std::vector<int> &vec);

		void		sortVector();
		void		sortList();
		void		printResult();
		double		calculateTime(struct timeval &start, struct timeval &end);

		template <typename T>
		void		splitSequence(T &lower, T &upper, T &sequence);
		template <typename T>
		void		insertionSort(T &sequence);
		template <typename T>
		void		merge(T &lower, T &upper, T &sorted);

	private:
		std::vector<int>	_vector;
		std::vector<int>	_vectorSorted;
		double				_timeVector;
		std::list<int>		_list;
		std::list<int>		_listSorted;
		double				_timeList;
};

template <typename T>
void PmergeMe::splitSequence(T &lower, T &upper, T &sequence)
{
	typename T::iterator it = sequence.begin();
	while (it != sequence.end())
	{
		typename T::iterator next_it = std::next(it, 1);
		if (next_it != sequence.end())
		{
			if (*it < *next_it)
			{
				lower.push_back(*it);
				upper.push_back(*next_it);
			}
			else
			{
				lower.push_back(*next_it);
				upper.push_back(*it);
			}
			it = std::next(next_it, 1);
		}
		else
		{
			lower.push_back(*it);
			it = next_it;
		}
	}
}

template <typename T>
void	PmergeMe::insertionSort(T &sequence)
{
	for (typename T::iterator it = sequence.begin(); it != sequence.end(); it++)
	{
		typename T::iterator it2 = it;
		while (it2 != sequence.begin() && *it2 < *std::prev(it2))
		{
			std::iter_swap(it2, std::prev(it2));
			it2 = std::prev(it2);
		}
	}
}

template <typename T>
void	PmergeMe::merge(T &lower, T &upper, T &sorted)
{
	typename T::iterator itLower = lower.begin();
	typename T::iterator itUpper = upper.begin();

	while (itLower != lower.end() && itUpper != upper.end())
	{
		if (*itLower < *itUpper)
		{
			sorted.push_back(*itLower);
			itLower++;
		}
		else
		{
			sorted.push_back(*itUpper);
			itUpper++;
		}
	}
	while (itLower != lower.end())
	{
		sorted.push_back(*itLower);
		itLower++;
	}
	while (itUpper != upper.end())
	{
		sorted.push_back(*itUpper);
		itUpper++;
	}
}

#endif
