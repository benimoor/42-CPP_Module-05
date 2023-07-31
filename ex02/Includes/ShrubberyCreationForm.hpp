/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:53:10 by ergrigor          #+#    #+#             */
/*   Updated: 2023/07/31 18:42:53 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Bureaucrat.hpp"
# include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	/* data */
public:
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
	ShrubberyCreationForm(const std::string&);
	ShrubberyCreationForm(/* args */);
	~ShrubberyCreationForm();
	
	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
};

#endif
