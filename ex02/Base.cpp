/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:02 by tecker            #+#    #+#             */
/*   Updated: 2024/12/04 00:39:55 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base * generate(void)
{
	std::srand(std::time(nullptr));
	int values[] = {0, 1, 2};

	switch (values[std::rand() % 3])
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	default:
		return (nullptr);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "type is A!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type is B!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type is C!" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "type is A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "type is B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "type is C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
}
	