#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
        Bureaucrat      ob("ash", 145);
        ShrubberyCreationForm           *f = new(ShrubberyCreationForm);
        Intern  inter;
        AForm   *ptr;

        std::cout << ob;
        try{
                ob.downGrade();
        }
        catch(const std::exception &o)
        {
                std::cout << o.what() << std::endl;
        }

        std::cout << ob;
        try{
                ob.upGrade();
        }
        catch(const std::exception &o)
        {
                std::cout << o.what() << std::endl;
        }
        std::cout << ob;
        ob.signForm(*f);
        f->beSigned(ob);
        try{
                f->execute(ob);
        }
        catch(std::exception &o)
        {
                std::cout << o.what()<< std::endl;
        }
        ptr = inter.makeForm("RobotomyRequestForm", "davo");
        delete f;
        delete ptr;
}