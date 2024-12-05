/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:06 by tecker            #+#    #+#             */
/*   Updated: 2024/12/03 19:22:16 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Base_HPP
#define Base_HPP

#include <iostream>
#include <ctime>

class Base
{
	public:
		virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif