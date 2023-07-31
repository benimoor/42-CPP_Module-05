/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:09:43 by ergrigor          #+#    #+#             */
/*   Updated: 2023/07/31 20:38:23 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("NoName"){};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : AForm("Shrubbery", 145, 137), _target(name){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& a) : AForm(a.getName(), a.getMinToSign(), a.getMinToExec()), _target(a.getTarget()) {};
ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& a)
{
	std::cout << "ShrubberyCreationForm" << a.getTarget() << " can't be assigned by operator =" << std::endl;
	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm(){};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getMinToExec())
		throw GradeTooLowException();
	else if (this->getSignedOrNot() == false)
		throw UnsignedFormException();
	std::ofstream f(this->getTarget().append("_shrubbery"));
	if (!f)
	{
		std::cerr << "Error creating the file." << std::endl;
		return ;
	}
	std::string asciiArt =
       "      ccee88oo\n"
       " C8O8O8Q8PoOb o8oo\n"
       " dOB69QO8PdUOpugoO9bD\n"
       "CgggbU8OU qOp qOdoUOdcb\n"
       "    6OuU  /p u gcoUodpP\n"
       "      \\|//  /douUP\n"
       "        \\\\//\n"
       "         |||\n"
       "         |||\n"
       "         |||\n";
	f << asciiArt;
	f.close();
	std::cout << "Shrubbery tree created in file '" << this->getTarget().append("_shrubbery") << "'." << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const {return _target;}
