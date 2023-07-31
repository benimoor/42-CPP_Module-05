/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:53:10 by ergrigor          #+#    #+#             */
/*   Updated: 2023/07/31 18:47:12 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Bureaucrat.hpp"
# include <fstream>
#include <cstdlib>


class AForm;

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	/* data */
public:
	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	RobotomyRequestForm(const std::string&);
	RobotomyRequestForm(/* args */);
	~RobotomyRequestForm();
	
	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
};

#endif
