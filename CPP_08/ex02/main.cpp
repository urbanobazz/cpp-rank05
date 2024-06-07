/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:46:34 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/07 21:16:06 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include "MutantStack.hpp"

int main()
{
	std::cout << "===================== MutantStack ===================" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "----------- Increment/Decrement test ----------------" << std::endl;

	std::cout << "Iterator value before incrementing: " << *it << std::endl;
	++it;
	std::cout << "Iterator value after incrementing: " << *it << std::endl;
	--it;
	std::cout << "Iterator value after decrementing: " << *it << std::endl;

	std::cout << "----------- print stack ----------------" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "===================== std::list ===================" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << "Top: " << list.back() << std::endl;

	list.pop_back();

	std::cout << "Size: " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();

	std::cout << "----------- Increment/Decrement test ----------------" << std::endl;

	std::cout << "Iterator value before incrementing: " << *it2 << std::endl;
	++it2;
	std::cout << "Iterator value after incrementing: " << *it2 << std::endl;
	--it2;
	std::cout << "Iterator value after decrementing: " << *it2 << std::endl;

	std::cout << "----------- print stack ----------------" << std::endl;
	while (it2 != ite2) {
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> l(list);

	std::cout << "===================== std::vector ===================" << std::endl;
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(17);

	std::cout << "Top: " << vec.back() << std::endl;

	vec.pop_back();

	std::cout << "Size: " << vec.size() << std::endl;

	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	vec.push_back(0);

	std::vector<int>::iterator it3 = vec.begin();
	std::vector<int>::iterator ite3 = vec.end();

	std::cout << "----------- Increment/Decrement test ----------------" << std::endl;

	std::cout << "Iterator value before incrementing: " << *it3 << std::endl;
	++it3;
	std::cout << "Iterator value after incrementing: " << *it3 << std::endl;
	--it3;
	std::cout << "Iterator value after decrementing: " << *it3 << std::endl;

	std::cout << "----------- print stack ----------------" << std::endl;
	while (it3 != ite3) {
		std::cout << *it3 << std::endl;
		++it3;
	}
	std::vector<int> v(vec);

	std::cout << "======================== END ========================" << std::endl;
	return 0;
}
