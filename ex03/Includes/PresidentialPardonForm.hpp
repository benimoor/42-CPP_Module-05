/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:53:10 by ergrigor          #+#    #+#             */
/*   Updated: 2023/07/31 18:42:39 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Bureaucrat.hpp"
# include <fstream>

class AForm;

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	/* data */
public:
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
	PresidentialPardonForm(const std::string&);
	PresidentialPardonForm(/* args */);
	~PresidentialPardonForm();
	
	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
};

#endif
