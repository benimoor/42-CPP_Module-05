/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:09:43 by ergrigor          #+#    #+#             */
/*   Updated: 2023/07/31 20:38:40 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("NoName"){};

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : AForm("Presidential", 25, 5),  _target(name){};


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& a) : AForm(a.getName(), a.getMinToSign(), a.getMinToExec()), _target(a.getTarget()) {};
PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& a)
{
	std::cout << "PresidentialPardonForm" << a.getTarget() << " can't be assigned by operator =" << std::endl;
	return *this;
}



PresidentialPardonForm::~PresidentialPardonForm(){};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignedOrNot() == false)
		throw AForm::UnsignedFormException();
	if  (executor.getGrade() > this->getMinToExec())
		throw AForm::GradeTooLowException();
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const {return _target;}