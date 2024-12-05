/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:02 by tecker            #+#    #+#             */
/*   Updated: 2024/12/05 13:21:26 by tecker           ###   ########.fr       */
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

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	if(this != &src)
		*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if(this != &src)
		*this = src;
	return *this;
}

int	get_precision(const std::string str, int type)
{
	int res = str.length() - str.find('.') - 1;
	if (type == FLOAT)
		return (std::min(res, FLT_DIG));
	else
		return (std::min(res, DBL_DIG));
}

int	get_type(const std::string str)
{
	size_t pos = 0;

	if (str.empty() || str[0] == '\0')
		return (-1);
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (FLOAT);
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (DOUBLE);
	if (!isdigit(str[0]) && str.length() == 1)
		return (CHAR);
	if (str.find('.') != std::string::npos && str.back() != '.')
	{
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
		catch (const std::out_of_range &e)
		{
			std::cout << "input is out of range of a float\n->try with a valid float" << std::endl;
			return (-1);
		}
		try
		{
			std::stod(str, &pos);
			if (pos == str.length())
				return DOUBLE;
		}
		catch (const std::invalid_argument &e) {}
		catch (const std::out_of_range &e)
		{
			std::cout << "input is out of range of a double\n->try with a valid double" << std::endl;
			return (-1);
		}
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
		std::cout << "input is out of range of an int\n->try with a valid int" << std::endl;
		return (-1);
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
	if (f > INT_MAX || f < INT_MIN || std::isnan(f))
		std::cout << "int: float out of range of int" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(get_precision(str, FLOAT) - 1) << f << 'f' << std::endl;
	std::cout << "double: " <<  std::fixed << std::setprecision(get_precision(str, DOUBLE) - 1) << static_cast<double>(f) << std::endl;
}

void handle_double(const std::string str)
{
	double d = stod(str);
	if (d > 32.0 && d < 127.0)
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: char not printable" << std::endl;
	if (d > INT_MAX || d < INT_MIN || std::isnan(d))
		std::cout << "int: double out of range of int" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if ((d > FLT_MAX || d < -FLT_MAX) && !std::isinf(d))
		std::cout << "float: double out of range of float" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(get_precision(str, FLOAT)) << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " <<  std::fixed << std::setprecision(get_precision(str, DOUBLE)) << d << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	int type = get_type(str);
	switch(type)
	{
		case CHAR:
			handle_char(str);
			break;
		case INT:
			handle_int(str);
			break;
		case FLOAT:
			handle_float(str);
			break;
		case DOUBLE:
			handle_double(str);
			break;
		default:
			std::cerr << "Wrong Input" << std::endl;;
	}
}