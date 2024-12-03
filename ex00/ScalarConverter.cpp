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
    catch (const std::out_of_range &e) {
		std::cout << "kk\n";
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
    catch (const std::out_of_range &e) {}

    try
	{
        std::stod(str, &pos);
        if (pos == str.length())
        	return DOUBLE;
    }
    catch (const std::invalid_argument &e) {}
    catch (const std::out_of_range &e) {}

    return (-1);
}

void ScalarConverter::convert(std::string str)
{
	int type = get_type(str);
	switch(type)
	{
		case CHAR:
			std::cout << "char" << std::endl;;
			// handle_char(str);
			break;
		case INT:
			std::cout << "int" << std::endl;;
			// handle_int(str);
			break;
		case FLOAT:
			std::cout << "float" << std::endl;;
			// handle_float(str);
			break;
		case DOUBLE:
			std::cout << "double" << std::endl;
			// handle_double(str);
			break;
		default:
			std::cerr << "Wrong Input" << std::endl;;
	}
}