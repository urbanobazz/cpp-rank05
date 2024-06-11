/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:26:00 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/11 11:46:05 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN <expression>" << std::endl;
		return (1);
	}
	RPN rpn(av[1]);
	rpn.calculateExpression();
	return (0);
}
