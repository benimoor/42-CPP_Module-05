#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(/* args */) : _name("NoName"), _grade(150){};

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade()){};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat" << other.getName() << " can't be assigned by operator =" << std::endl;
	return *this;
}
Bureaucrat::Bureaucrat(std::string const name, int const grade) : _name(name), _grade(grade)
{
	if (_grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (_grade > LOWEST_GRADE)
		throw GradeTooLowException();
} 

Bureaucrat::~Bureaucrat(){};

std::string Bureaucrat::getName() const {return _name;}

int			Bureaucrat::getGrade() const {return _grade;}

void		Bureaucrat::upGrade()
{
	_grade--;
	if (_grade < HIGHEST_GRADE)
		throw GradeTooHighException();
}
void		Bureaucrat::downGrade()
{
	_grade++;
	if(_grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& gago)
{
	out <<  gago.getName() << ", bureaucrat grade " << gago.getGrade() << ".";
	return out;
}

void Bureaucrat::signForm(Form& f)
{
	if (f.getSignedOrNot())
		throw Form::AlreadyBeSigned();
	else
		std::cout << this->getName() << " couldn’t sign " << f.getName() << " because he/she hasn't enough grade." << std::endl;
}