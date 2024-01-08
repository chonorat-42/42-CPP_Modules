

#include "Harl.hpp"

Harl::Harl()
{
	map["info"] = &Harl::info;
	map["debug"] = &Harl::debug;
	map["warning"] = &Harl::warning;
	map["error"] = &Harl::error;
}

void	Harl::complain(std::string level)
{
	const std::map<std::string, void(Harl::*)()>::iterator it = map.find(level);
	if (it != map.end())
		(this->*(it->second))();
}

void	Harl::debug() {std::cout << "debug" << std::endl;}
void	Harl::info() {std::cout << "info" << std::endl;}
void	Harl::warning() {std::cout << "warning" << std::endl;}
void	Harl::error() {std::cout << "error" << std::endl;}
