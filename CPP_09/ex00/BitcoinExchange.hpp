/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:25:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/10 14:42:49 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <cstring>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange(void);

		BitcoinExchange &	operator=(BitcoinExchange const &other);

		// void				parseInput(std::string const &fileName);
		void				parseDataBase(std::string const &fileName);
		int					toInt(std::string const &str);
		double				toDouble(std::string const &str);
		//void				calculateOutput(void);

			std::map<std::string, double>	_dataBase;
			std::map<std::string, double>	_input;
		private:
};

#endif
