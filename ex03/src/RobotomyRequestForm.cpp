/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:09:43 by ergrigor          #+#    #+#             */
/*   Updated: 2023/07/27 19:34:46 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45){};

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : AForm("Robotomy", 72, 45), _target(name){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& a) : AForm(a.getName(), a.getMinToSign(), a.getMinToExec()), _target(a.getTarget()) {};
RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& a)
{
	std::cout << "RobotomyRequestForm" << a.getTarget() << " can't be assigned by operator =" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){};


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::srand(time(NULL));
	if (executor.getGrade() > this->getMinToExec())
		throw GradeTooLowException();
	if (std::rand() % 2 == 0)
		std::cout  << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		throw UnsuccessException();
}

std::string RobotomyRequestForm::getTarget(void) const {return _target;}
