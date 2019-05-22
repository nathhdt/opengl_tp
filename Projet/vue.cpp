#include "vue.h"
#include <cstdlib>
#include <iostream>


Vue::Vue(const std::string& _titre)
	:titre(_titre)
{
}

void Vue::clear() const
{
	system("CLS");
}

void Vue::afficher() const
{
	std::cout << titre << std::endl << std::endl;
}