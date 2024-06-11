/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:26:27 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/11 13:08:36 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <exception>
# include <cstdlib>

class RPN
{
	public:
		RPN(std::string expression);
		RPN(RPN const &other);
		~RPN(void);

		RPN &operator=(RPN const &other);

		void	calculateExpression(void);
		void	executeOperation(std::string token);
		void	pushOperand(std::string operand);

	private:
		RPN(void);
		std::string		_expression;
		std::stack<int>	_stack;
};

#endif
