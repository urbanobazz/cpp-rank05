/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:26:40 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/11 13:41:52 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(std::string expression) : _expression(expression) {}

RPN::RPN(RPN const &other) : _expression(other._expression) {}

RPN::~RPN(void) {}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
		this->_expression = other._expression;
	return (*this);
}

void	RPN::calculateExpression(void)
{
	std::string		token;
	std::istringstream	iss(this->_expression);

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
			executeOperation(token);
		else if (token >= "0" && token <= "9")
			pushOperand(token);
		else {
			std::cout << "Error: invalid token \" " << token << " \"" << std::endl;
			exit(1);
		}
	}
	std::cout << this->_stack.top() << std::endl;
}

void RPN::executeOperation(std::string token)
{
	if (this->_stack.size() < 2)
	{
		std::cout << "Error: not enough operands" << std::endl;
		exit(1);
	}
	int op2 = this->_stack.top();
	this->_stack.pop();
	int op1 = this->_stack.top();
	this->_stack.pop();
	switch (token[0])
	{
		case '+':
			this->_stack.push(op1 + op2);
			break;
		case '-':
			this->_stack.push(op1 - op2);
			break;
		case '*':
			this->_stack.push(op1 * op2);
			break;
		case '/':
			if (op2 == 0)
			{
				std::cout << "Error: division by zero" << std::endl;
				exit(1);
			}
			this->_stack.push(op1 / op2);
			break;
		default:
			std::cout << "Error: invalid token \"" << token << "\"" << std::endl;
			exit(1);
	}
}

void	RPN::pushOperand(std::string operand)
{
	std::istringstream	iss(operand);
	int			value;

	iss >> value;
	if (iss.fail())
	{
		std::cout << "Error: not an integer \" " << operand << " \"" << std::endl;
		exit(1);
	}
	else if (value < 0 || value > 9)
	{
		std::cout << "Error: invalid integer \" " << operand << " \"" << std::endl;
		exit(1);
	}
	else
		this->_stack.push(value);
}
