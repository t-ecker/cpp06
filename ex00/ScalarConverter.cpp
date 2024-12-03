/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:02 by tecker            #+#    #+#             */
/*   Updated: 2024/12/03 15:26:40 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum values
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

int	get_type(const std::string str)
{
	size_t pos = 0;

	if (str.empty() || str[0] == '\0')
		return (-1);
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (FLOAT);
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (DOUBLE);
	if (isalpha(str[0]))
	{
		if (str.length() == 1)
			return (CHAR);
		else
			return (-1);
	}
	try
	{
        std::stoi(str, &pos);
        if (pos == str.length())
            return INT;
    }
    catch (const std::invalid_argument &e) {}
    catch (const std::out_of_range &e)
	{
		std::cout << "input is int out of range\nInput a valid Int" << std::endl;
		return (-1);
	}

    try
	{
		if (str.back() != 'f')
			throw std::invalid_argument("no f a the end");
		std::string modified_str = str;
		modified_str.pop_back();
		std::stof(modified_str, &pos);
		if (pos == modified_str.length())
			return FLOAT;
    }
    catch (const std::invalid_argument &e) {}
    catch (const std::out_of_range &e) {
		std::cout << "jj" << std::endl;
	}

    try
	{
        std::stod(str, &pos);
        if (pos == str.length())
        	return DOUBLE;
    }
    catch (const std::invalid_argument &e) {}
    catch (const std::out_of_range &e) {
		std::cout << "pp" << std::endl;
	}

    return (-1);
}

void handle_char(const std::string str)
{
	char c = str[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " <<  std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void handle_int(const std::string str)
{
	int i = stoi(str);
	if (i > 32 && i < 127)
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "char: char not printable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << 'f' << std::endl;
	std::cout << "double: " <<  std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void handle_float(const std::string str)
{
	float f = stof(str);
	if (f > 32.0 && f < 127.0)
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: char not printable" << std::endl;
	if (!isnan(f) && !isinf(f))
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << f << 'f' << std::endl;
	std::cout << "double: " <<  std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void handle_double(const std::string str)
{
	double d = stod(str);
	if (d > 32.0 && d < 127.0)
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: char not printable" << std::endl;
	if (!isnan(d) && !isinf(d))
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << 'f' << std::endl;
	std::cout << "double: " <<  std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	int type = get_type(str);
	switch(type)
	{
		case CHAR:
			std::cout << "input type: char\n" << std::endl;;
			handle_char(str);
			break;
		case INT:
			std::cout << "input type: int\n" << std::endl;;
			handle_int(str);
			break;
		case FLOAT:
			std::cout << "input type: float\n" << std::endl;;
			handle_float(str);
			break;
		case DOUBLE:
			std::cout << "input type: double\n" << std::endl;;
			handle_double(str);
			break;
		default:
			std::cerr << "Wrong Input" << std::endl;;
	}
}