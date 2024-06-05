/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:22:17 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/05 19:59:13 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <exception>

static Base *generate(void) {
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

static void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "By pointer: A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "By pointer: B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "By pointer: C" << std::endl;
	}
}

static void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "By reference: A" << std::endl;
	}
	catch (...) {}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "By reference: B" << std::endl;
	}
	catch (...) {}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "By reference: C" << std::endl;
	}
	catch (...) {}
}

int main(void) {
	srand(time(NULL));

	Base *base = generate();

	identify(base);
	identify(*base);

	delete base;

	return (0);
}
