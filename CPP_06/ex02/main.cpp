/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:22:17 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/05 19:26:53 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

Base *generate(void) {
	int random = rand() % 3;

	if (random == 0) {
		std::cout << "Generated A" << std::endl;
		return (new A());
	}
	else if (random == 1) {
		std::cout << "Generated B" << std::endl;
		return (new B());
	}
	else {
		std::cout << "Generated C" << std::endl;
		return (new C());
	}
}

void identify_from_pointer(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}

void identify_from_reference(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::bad_cast &e) {
	}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	} catch (std::bad_cast &e) {
	}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	} catch (std::bad_cast &e) {
	}
}

int main(void) {
	srand(time(NULL));

	Base *base = generate();

	identify_from_pointer(base);
	identify_from_reference(*base);

	delete base;

	return (0);
}
