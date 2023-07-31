#include "./Intern.hpp"
#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this != &other) {}
	return *this;
}

Intern::~Intern() {};

const char	*Intern::InternException::what() const throw() { return "Form not found"; }

AForm	*Intern::makeForm(const std::string& formName, const std::string& formTarget) const
{
	AForm *(Intern::*ptr_member_func[3])(const std::string& target) const = {&Intern::PresidentMake, &Intern::RobotomyMake, &Intern::ShrubberyMake};
	std::string	request[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(request[i]) == 0)
		{
			std::cout << "Intern creates " << formName << std::endl;;
			return ((this->*ptr_member_func[i])(formTarget));
		}
	}
	throw InternException();
}

AForm	*Intern::PresidentMake(const std::string& target) const { return new PresidentialPardonForm(target); }
AForm	*Intern::RobotomyMake(const std::string& target) const { return new RobotomyRequestForm(target); }
AForm	*Intern::ShrubberyMake(const std::string& target) const { return new ShrubberyCreationForm(target); }