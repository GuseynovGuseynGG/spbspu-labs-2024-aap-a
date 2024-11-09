#include <iostream>
#include <ios>
#include <cstddef>
#include <fstream>
#include "functions.hpp"

int main()
{
	size_t memory = 10;
	char* str = reinterpret_cast< char* >(malloc((memory + 1) * sizeof(char)));
	if (str == nullptr)
	{
		std::cerr << "Malloc error!\n";
		free(str);
		return 1;
	}

	size_t current_size = 0;
	char c = '\n';

	std::noskipws(std::cin);
	while ((std::cin >> c) && (c != '\n'))
	{
		if (current_size == memory)
		{
			constexpr size_t multiplier = 2;
			memory *= multiplier;
			char* new_str = shramko::createBiggerStrMemory(memory, str);
			if (new_str == nullptr)
			{
				return 1;
			}
			free(str);
			str = new_str;
			free(new_str);
		}
		str[current_size++] = c;
	}
	std::skipws(std::cin);

	if (current_size == 0)
	{
		std::cerr << "Nothing in string\n";
		free(str);
		return 1;
	}

	std::cout << shramko::countConsecutiveIdenticalSymbols(str) << '\n';
	free(str);
}
