/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:47:02 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/07 20:37:55 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iterator>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(MutantStack const &other) : std::stack<T, Container>(other) {}
		virtual ~MutantStack(void) {}

		MutantStack &operator=(MutantStack const &other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin(void) { return this->c.begin(); }
		iterator end(void) { return this->c.end(); }
};

#endif
