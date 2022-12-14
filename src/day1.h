// Liz Arcorium

#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Result
{
	uint64_t Elf;
	uint64_t TotalCallories;
	std::vector<uint64_t> Callories;

	void Show()
	{
		std::cout << "Elf: " << Elf << std::endl;
		std::cout << "Callories: " << TotalCallories << std::endl;

		std::cout << "Input: " << std::endl;
		for (auto& call : Callories)
		{
			std::cout << call << std::endl;
		}
	}
};

class Day1
{
public:
	Day1(const std::string& input_) : m_input{input_} {}

	Result Solve()
	{

		uint64_t start = 0;
		uint64_t end;
		uint64_t elfIndex = 0;
		uint64_t highestElfIndex = 0;
		uint64_t highestTotalCallories = 0;
		uint64_t currentTotalCallories = 0;
		std::vector<uint64_t> highestCallories{};
		std::vector<uint64_t> currentCallories{};

		while((end = m_input.find('\n', start)) != std::string::npos)
		{

			if (start != end)
			{
				std::string line = m_input.substr(start, end - start);

				const auto number = std::stoul(line);

				currentTotalCallories += number;
				currentCallories.push_back(number);
			}
			else
			{
				if (highestTotalCallories < currentTotalCallories)
				{
					highestTotalCallories = currentTotalCallories;
					highestElfIndex = elfIndex;
					highestCallories = currentCallories;
				}

				// reset
				currentCallories.clear();
				currentTotalCallories = 0;
				++elfIndex;
			}
			start = end + 1;
		}

		return {highestElfIndex, highestTotalCallories, highestCallories};
	}

private:
	std::string m_input;
};
