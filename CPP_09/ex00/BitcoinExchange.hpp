/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:25:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/10 17:35:04 by ubazzane         ###   ########.fr       */
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

class BitcoinExchange;

typedef struct	s_date {
	int			year;
	int			month;
	int			day;

	bool operator<(s_date const &other) const;
	bool operator==(s_date const &other) const;

}	t_date;

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange(void);

		BitcoinExchange &	operator=(BitcoinExchange const &other);

		void				parseDataBase(std::string const &fileName);
		int					toInt(std::string const &str);
		double				toFloat(std::string const &str);
		t_date 				stringToDate(std::string const &str);
		bool				isValidDate(t_date const &date);
		bool				isLeapYear(int year);
		void				processInput(std::string const &fileName);
		void				calculateValue(float amount, t_date const &date);

	private:
		std::map<t_date, double>	_dataBase; // put back to private!!
};

std::ostream& operator<<(std::ostream& os, const s_date& dt);

#endif
