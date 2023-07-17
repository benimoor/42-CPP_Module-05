/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:36:23 by kali              #+#    #+#             */
/*   Updated: 2023/07/17 11:15:51 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

#define  HIGHEST_GRADE 1
#define  LOWEST_GRADE 150

class Form;

class Bureaucrat
{
private:
	std::string const _name;
	int				_grade;
public:
	Bureaucrat(/* args */);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);
	Bureaucrat(std::string const, int const);
	virtual ~Bureaucrat();
public:
	std::string getName() const;
	int			getGrade() const;
	void		upGrade();
	void		downGrade();
	void		signForm(Form&);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream&, Bureaucrat&);

#endif