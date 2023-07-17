#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	/* data */
	const std::string _name;
	bool	_signed; 
	const int minToSign;
	const int minToExec;
public:
	Form(/* args */);
	Form(const std::string& name, int signLevel, int execLevel);
	Form(const Form&);
	Form& operator=(const Form&);
	virtual ~Form();
	class GradeTooHighException : std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class AleadyBeSigned: public std::exception
	{
		virtual const char* what() const throw();
	};

	void	beSigned(Bureaucrat& bure);
	std::string getName() const;
	bool	getSignedOrNot() const;
	int	getMinToSign() const;
	int	getMinToExec() const;
};

std::ostream& operator<<(std::ostream&, Form&);


#endif