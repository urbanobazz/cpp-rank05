/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:25:22 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/10 17:35:22 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	BitcoinExchange exchange;
	if (argc != 2) {
		std::cerr << "Usage: ./bitcoin [input_file]" << std::endl;
		return 1;
	}
	(void)argv;
	//exchange.parseInput(argv[1]);
	exchange.parseDataBase("dataBase.csv");
	exchange.processInput(argv[1]);

/* 	std::cout << "Input:" << std::endl;
	for (std::map<std::string, double>::iterator it = exchange._input.begin(); it != exchange._input.end(); it++) {
		std::cout << "Date: "<< it->first << " Amount: " << it->second << std::endl;
	} */

/* 	std::ofstream out;
	out.open("out.txt");
	std::cout << "DataBase:" << std::endl;
	for (std::map<t_date, double>::iterator it = exchange._dataBase.begin(); it != exchange._dataBase.end(); it++) {
		out << "Date: " << it->first << " Value: " << it->second << std::endl;
	} */

	return 0;
}
