#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	/* data */
	const std::string _name;
	bool	_signed; 
	const int minToSign;
	const int minToExec;
public:
	AForm(/* args */);
	AForm(const std::string& name, int signLevel, int execLevel);
	AForm(const AForm&);
	AForm& operator=(const AForm&);
	virtual ~AForm();
	class GradeTooHighException :public std::exception
	{
		 const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		 const char* what() const throw();
	};
	class AlreadyBeSigned : public std::exception
	{
		 const char* what() const throw();
	};
	class UnsignedFormException : public std::exception
	{
		 const char* what() const throw();
	};
	class UnsuccessException : public std::exception
	{
		 const char* what() const throw();
	};
	
	void	beSigned(Bureaucrat& bure);
	std::string getName() const;
	bool	getSignedOrNot() const;
	int	getMinToSign() const;
	int	getMinToExec() const;
	virtual std::string getTarget() const;
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream&, AForm&);


#endif