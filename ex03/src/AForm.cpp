#include "AForm.hpp"

AForm::AForm() : _name("NoName"), _signed(false), minToSign(LOWEST_GRADE),  minToExec(LOWEST_GRADE) {}; 

AForm::AForm(const std::string& name, int signLevel, int execLevel) : _name(name), minToSign(signLevel), minToExec(execLevel)
{
	_signed = false;
	if (minToExec < HIGHEST_GRADE || minToSign < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	if (minToExec > LOWEST_GRADE || minToSign > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other.getName()), minToSign(other.getMinToSign()), minToExec(other.getMinToExec()){
	_signed = other.getSignedOrNot();
};

AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "AForm" << other._name << " can't be assigned by operator =" << std::endl;
	return *this;
}

AForm::~AForm(){};

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::AlreadyBeSigned::what() const throw()
{
	return "AForm has already signed";
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return "Form not signed";
}

const char* AForm::UnsuccessException::what() const throw()
{
	return "Unsuccessful attempt at robotization!";
}

void		AForm::beSigned(Bureaucrat& bure)
{
	if (bure.getGrade() > this->getMinToSign())
		throw GradeTooLowException();
	bure.signForm(*this);
	this->_signed = true;
}

std::string AForm::getName() const {return _name;}
std::string AForm::getTarget() const {return "Undefined";}
bool		AForm::getSignedOrNot() const {return _signed;}
int	AForm::getMinToSign() const {return minToSign;}
int	AForm::getMinToExec() const {return minToExec;}

std::ostream& operator<<(std::ostream& out, AForm& f)
{
	out << "AForm Name: " << f.getName();
	out << " Is Signed: " << f.getSignedOrNot();
	out << " Minimum grade for signing: " << f.getMinToSign();
	out << " Minimum grade for exec: " << f.getMinToExec();
	return out;
}