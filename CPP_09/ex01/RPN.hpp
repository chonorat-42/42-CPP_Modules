#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <sstream>
# include <cstddef>
# include <cstdlib>

class RPN
{
	public:
		RPN();
		~RPN();
		void operateRPN(std::string input);

	private:
		std::stack<std::ptrdiff_t> _stack;
		void operateOnStack(char character);
		void adder();
		void subtractor();
		void multiplicator();
		void divisor();
		void printResult();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		class InvalidFormat : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class CannotOperate : public std::exception
		{
			public:
				CannotOperate(const std::string& operation);
				~CannotOperate() throw();
				const char* what() const throw();
			private:
				std::string _message;
		};
		class StackEmpty : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class ValuesLeft : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class DivisionByZero : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif //RPN_HPP
