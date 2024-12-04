/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:11 by tecker            #+#    #+#             */
/*   Updated: 2024/12/04 19:16:36 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.text = "Hello World!";
	std::cout << "Data address: " << &data << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Raw pointer value: " << raw << std::endl;
	std::cout << "Deserialized adress: " << Serializer::deserialize(raw) << "\ndeserialized text: " << Serializer::deserialize(raw)->text << std::endl;
	return (0);
}