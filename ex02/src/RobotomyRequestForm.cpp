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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getMinToExec())
		throw GradeTooLowException();
	else if (this->getSignedOrNot() == false)
		throw UnsignedFormException();
	if (std::rand() % 2 == 0)
	{
		std::cout << "Vrrrrrrrrr... Vrrrrrrrrr... Vrrrrrrrrr..." << std::endl;
		std::cout << this->getName() << "' has been robotomized successfully 50% of the time" << std::endl;
	}
	else
		throw UnsuccessException();
}
RobotomyRequestForm::~RobotomyRequestForm(){};

std::string RobotomyRequestForm::getTarget(void) const {return _target;}
