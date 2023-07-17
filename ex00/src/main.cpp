#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat	davo("davo", 3);

		davo.upGrade();
		davo.upGrade();
		std::cout << davo << std::endl;

		davo.downGrade();
		davo.upGrade();
		std::cout << davo << std::endl;

		davo.upGrade();
		davo.upGrade();
		std::cout << davo << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	ashot("ashot", 149);

		ashot.downGrade();
		std::cout << ashot << std::endl;

		ashot.downGrade();
		std::cout << ashot << std::endl;

		ashot.downGrade();
		std::cout << ashot << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}