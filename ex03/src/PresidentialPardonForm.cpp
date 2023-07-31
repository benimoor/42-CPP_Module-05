/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:09:43 by ergrigor          #+#    #+#             */
/*   Updated: 2023/07/31 18:42:14 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("NoName"){};

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : AForm("Presidential", 25, 5),  _target(name){};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignedOrNot() == false)
		throw AForm::UnsignedFormException();
	if  (executor.getGrade() > this->getMinToExec())
		throw AForm::GradeTooLowException();
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm(){};

std::string PresidentialPardonForm::getTarget(void) const {return _target;}