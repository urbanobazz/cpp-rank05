/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:39:44 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/11 19:44:50 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe	pmm;

	if (ac < 2)
	{
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	pmm.parseInput(av);
	pmm.sortVector();
	pmm.sortList();
	pmm.printResult();
	return 0;
}

/* Mac random test */
/* ARG=$(jot -r 3000 1 1000 | tr '\n' ' ') ; ./PmergeMe "$ARG" */
/* Linux random test */
/* ARG=$(shuf -i 1-1000 -n 3000 | tr '\n' ' ') ; ./PmergeMe "$ARG" */
