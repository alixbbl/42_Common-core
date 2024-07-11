/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:34:04 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 11:04:25 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define GRADE_MAX 1
#define GRADE_MIN 150

void	ShrubberyCreationForm_working()
{
	Bureaucrat Sylvie("Sylvie", 1);
	ShrubberyCreationForm taff("taff");
	try {
		Sylvie.signForm(taff); }
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl; }
	try {
		Sylvie.executeForm(taff); }
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl; }
}

void	ShrubberyCreationForm_notworking()
{
	Bureaucrat Sylvie("Sylvie", 138);
	ShrubberyCreationForm taff("taff");
	try {
		Sylvie.signForm(taff); }
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl; }
	try {
		Sylvie.executeForm(taff); }
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl; }
}

void	RobotomyRequestForm_working()
{
	Bureaucrat Sylvie("Sylvie", 72);
	Bureaucrat Bernard("Bernard", 45);
	RobotomyRequestForm form("random");
	try {
		Sylvie.signForm(form); }
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl; }
	try {
		Sylvie.executeForm(form); }
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl; }
    try {
		Bernard.signForm(form); }
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl; }
	try {
		Bernard.executeForm(form); }
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl; }
}

void	RobotomyRequestForm_notworking()
{
	Bureaucrat Sylvie("Sylvie", 148);
	RobotomyRequestForm taff("taff");
	try {
		Sylvie.signForm(taff); }
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl; }
	try {
		Sylvie.executeForm(taff); }
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl; }
}

void	PresidentialPardonForm_working()
{
	Bureaucrat Sylvie("Sylvie", 5);
	PresidentialPardonForm taff("Target 51");
	try {
		Sylvie.signForm(taff); }
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl; }
	try {
		Sylvie.executeForm(taff); }
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl; }
}

int main()
{
	std::cout << "-------------- TEST 1 --------------" << std::endl;
	ShrubberyCreationForm_working();
	std::cout << std::endl;
	std::cout << "-------------- TEST 2 --------------" << std::endl;
	ShrubberyCreationForm_notworking();
	std::cout << std::endl;
	std::cout << "-------------- TEST 3 --------------" << std::endl;
	RobotomyRequestForm_working();
	std::cout << std::endl;
	std::cout << "-------------- TEST 4 --------------" << std::endl;
	RobotomyRequestForm_notworking();
	std::cout << std::endl;
	std::cout << "-------------- TEST 5 --------------" << std::endl;
	PresidentialPardonForm_working();
}
