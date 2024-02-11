#include "RPN.hpp"

int main(const int argc, char *argv[])
{
	if (argc == 2)
	{
		try
		{
			RPN data;
			data.operateRPN(argv[1]);
		}
		catch (std::exception& exception)
		{
			std::cout << exception.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Usage: ./RPN \'operations\'" << std::endl;
		return (1);
	}
	return (0);
}
