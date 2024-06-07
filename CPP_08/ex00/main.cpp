/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:45:02 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/07 16:27:37 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main(void)
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
	}
	std::cout << "=============== Value found test ==================" << std::endl;
	try
	{
		std::cout << "Vector: " << *easyfind(vec, 5) << std::endl;
		std::cout << "List: " << *easyfind(lst, 5) << std::endl;
		std::cout << "Deque: " << *easyfind(deq, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	std::cout << "============ Index out of bounds test =============" << std::endl;
	try
	{
		std::cout << "Vector: " << *easyfind(vec, 10) << std::endl;
		std::cout << "List: " << *easyfind(lst, 10) << std::endl;
		std::cout << "Deque: " << *easyfind(deq, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	return (0);
}
