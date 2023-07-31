/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:54:06 by ergrigor          #+#    #+#             */
/*   Updated: 2023/07/31 18:54:43 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern
{
	AForm	*PresidentMake(const std::string& target) const;
	AForm	*RobotomyMake(const std::string& target) const;
	AForm	*ShrubberyMake(const std::string& target) const;

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator = (const Intern& other);
	~Intern();
	
	class InternException : public std::exception
	{
		const char	*what() const throw();
	};
	
	AForm	*makeForm(const std::string& formName, const std::string& formTarget) const;
};

#endif