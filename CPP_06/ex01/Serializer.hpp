/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:21:41 by ubazzane          #+#    #+#             */
/*   Updated: 2024/06/05 18:22:58 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <stdint.h>

struct Data {
	int x;
	int y;
};

class Serializer {
	private:
		Serializer(void);
		Serializer(Serializer const &other);
		~Serializer(void);
		Serializer &operator=(Serializer const &other);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
