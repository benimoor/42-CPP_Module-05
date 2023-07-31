#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "___________________ START ORIGINAL OPERATOR '<<' ___________________" << std::endl << std::endl;
	Form	balance;

	std::cout << "Form:\t\t" << balance.getName() << std::endl;
	std::cout << "Is signed:\t" << balance.getSignedOrNot() << std::endl;
	std::cout << "Sign grade:\t" << balance.getMinToSign() << std::endl;
	std::cout << "Execute grade:\t" << balance.getMinToExec() << std::endl << std::endl;
	
	Form	balance_1("balance_1", 50, 140);

	std::cout << "Form:\t\t" << balance_1.getName() << std::endl;
	std::cout << "Is signed:\t" << balance_1.getSignedOrNot() << std::endl;
	std::cout << "Sign grade:\t" << balance_1.getMinToSign() << std::endl;
	std::cout << "Execute grade:\t" << balance_1.getMinToExec() << std::endl << std::endl;

	Form	balance_2("balance_2", 1, 85);

	std::cout << "Form:\t\t" << balance_2.getName() << std::endl;
	std::cout << "Is signed:\t" << balance_2.getSignedOrNot() << std::endl;
	std::cout << "Sign grade:\t" << balance_2.getMinToSign() << std::endl;
	std::cout << "Execute grade:\t" << balance_2.getMinToExec() << std::endl << std::endl;

	std::cout << "___________________ END ORIGINAL OPERATOR '<<' ___________________" << std::endl << std::endl;
	
	std::cout << "___________________ START OVERLOAD OPERATOR '<<' ___________________" << std::endl << std::endl;
	std::cout << balance << std::endl;
	std::cout << balance_1 << std::endl;
	std::cout << balance_2 << std::endl << std::endl;
	std::cout << "___________________ END OVERLOAD OPERATOR '<<' ___________________" << std::endl << std::endl;
	
	std::cout << "___________________ START try and catch ___________________" << std::endl << std::endl;
	
	try
	{
		Form balance_3("balance_3", 151, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Form balance_4("balance_4", 7, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Form balance_5("balance_5", 0, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Form balance_6("balance_6", 40, -4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n___________________ END try and catch ___________________" << std::endl << std::endl;
	
	std::cout << "___________________ START TEST beSigned(Bureaucrat& brt) func ___________________" << std::endl << std::endl;
	
	try{
	Bureaucrat Davit("Davit", 90);

	Form balance_7("balance_7", 100, 80);
	balance_7.beSigned(Davit);

	std::cout << std::endl;

	Form balance_8("balance_8", 150, 10);
	balance_8.beSigned(Davit);

	std::cout << std::endl;

	Form balance_9("balance_9", 20, 10);
	balance_9.beSigned(Davit);

	std::cout << std::endl;

	Form balance_10("balance_10", 20, 91);
	balance_10.beSigned(Davit);

	std::cout << "\n___________________ END TEST beSigned(Bureaucrat& brt) func ___________________" << std::endl << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}