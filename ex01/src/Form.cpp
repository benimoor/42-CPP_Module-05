#include "Form.hpp"

Form::Form() : _name("NoName"), _signed(false), minToSign(LOWEST_GRADE),  minToExec(LOWEST_GRADE) {}; 

Form::Form(const std::string& name, int signLevel, int execLevel) : _name(name), minToSign(signLevel), minToExec(execLevel)
{
	_signed = false;
	if (minToExec < HIGHEST_GRADE || minToSign < HIGHEST_GRADE)
	{
		throw Form::GradeTooHighException();

	}
	else if (minToExec > LOWEST_GRADE || minToSign > LOWEST_GRADE)
	{	throw Form::GradeTooLowException();
}}

Form::Form(const Form& other) : _name(other.getName()), minToSign(other.getMinToSign()), minToExec(other.getMinToExec()){
	_signed = other.getSignedOrNot();
};

Form&	Form::operator=(const Form& other)
{
	std::cout << "Form" << other._name << " can't be assigned by operator =" << std::endl;
	return *this;
}

Form::~Form(){};

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* Form::AlreadyBeSigned::what() const throw()
{
	return "Form has aleady signed";
}

void		Form::beSigned(Bureaucrat& bure)
{
	if (bure.getGrade() > this->getMinToSign())
		throw GradeTooLowException();
	_signed = true;
	bure.signForm(*this);
}

std::string Form::getName() const {return _name;}
bool		Form::getSignedOrNot() const {return _signed;}
int	Form::getMinToSign() const {return minToSign;}
int	Form::getMinToExec() const {return minToExec;}

std::ostream& operator<<(std::ostream& out, Form& f)
{
	out << "Form Name: " << f.getName();
	out << " Is Signed: " << f.getSignedOrNot();
	out << " Minimum grade for signing: " << f.getMinToSign();
	out << " Minimum grade for exec: " << f.getMinToExec();
	return out;
}