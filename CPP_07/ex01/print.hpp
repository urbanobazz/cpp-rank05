/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:28:27 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/06 15:37:05 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HPP
# define PRINT_HPP

# include <iostream>

template <typename T>
void	print(T const &elem)
{
	std::cout << elem << std::endl;
}

#endif
