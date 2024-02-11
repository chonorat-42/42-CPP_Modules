#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN()
{

}

void RPN::adder()
{
	if (this->_stack.size() >= 2)
	{
		const std::ptrdiff_t nbr1 = this->_stack.top();
		this->_stack.pop();
		const std::ptrdiff_t nbr2 = this->_stack.top();
		this->_stack.pop();
		this->_stack.push(nbr2 + nbr1);
	}
	else
		throw CannotOperate("+");
}

void RPN::subtractor()
{
	if (this->_stack.size() >= 2)
	{
		const std::ptrdiff_t nbr1 = this->_stack.top();
		this->_stack.pop();
		const std::ptrdiff_t nbr2 = this->_stack.top();
		this->_stack.pop();
		this->_stack.push(nbr2 - nbr1);
	}
	else
		throw CannotOperate("-");
}

void RPN::multiplicator()
{
	if (this->_stack.size() >= 2)
	{
		const std::ptrdiff_t nbr1 = this->_stack.top();
		this->_stack.pop();
		const std::ptrdiff_t nbr2 = this->_stack.top();
		this->_stack.pop();
		this->_stack.push(nbr2 * nbr1);
	}
	else
		throw CannotOperate("*");
}

void RPN::divisor()
{
	if (this->_stack.size() >= 2)
	{
		const std::ptrdiff_t nbr1 = this->_stack.top();
		this->_stack.pop();
		const std::ptrdiff_t nbr2 = this->_stack.top();
		this->_stack.pop();
		this->_stack.push(nbr2 / nbr1);
	}
	else
		throw CannotOperate("/");
}

void RPN::operateOnStack(const char character)
{
	if (character == '+')
		adder();
	else if (character == '-')
		subtractor();
	else if (character == '*')
		multiplicator();
	else if (character == '/')
		divisor();
	else
		throw InvalidFormat();
}

void RPN::printResult()
{
	if (this->_stack.size() == 1)
		std::cout << this->_stack.top() << std::endl;
	else if (this->_stack.empty())
		throw StackEmpty();
	else
		throw ValuesLeft();
}

void RPN::operateRPN(std::string input)
{
	if (!input.empty())
	{
		std::string value;
		std::istringstream iss(input);
		while (std::getline(iss, value, ' '))
		{
			if (value.length() > 1)
				throw InvalidFormat();
			if (isdigit(value[0]))
				this->_stack.push(atoi(value.c_str()));
			else
				operateOnStack(value[0]);
		}
		printResult();
	}
}

const char* RPN::InvalidFormat::what() const throw()
{
	return ("Error: invalid format");
}

RPN::CannotOperate::CannotOperate(const std::string &operation) : _message("Error: cannot operate on " + operation) {}

RPN::CannotOperate::~CannotOperate() throw() {}

const char *RPN::CannotOperate::what() const throw()
{
	return (this->_message.c_str());
}

const char* RPN::StackEmpty::what() const throw()
{
	return ("Error: stack is empty");
}

const char* RPN::ValuesLeft::what() const throw()
{
	return ("Error: values left in stack");
}