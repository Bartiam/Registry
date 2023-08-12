#include <iostream>
#include <string>
#include <map>

bool is_correct_surname(const std::string& info)
{
	for (int i = 1; i < info.length(); ++i)
	{
		if (info[0] < 'A' || info[0] > 'Z' ||
			info[i] < 'a' || info[i] > 'z')
		{
			return false;
		}
	}
	return true;
}

void add(std::map<std::string, std::string>& queue, std::string& info)
{
	int i = 0;
	std::map<std::string, std::string>::iterator it = queue.find(info + std::to_string(i));
	for (; it != queue.end(); ++it)
	{
		++i;
		it = queue.find(info + std::to_string(i));
		if (it == queue.end()) break;
	}
	if (it == queue.end())
	{
		queue.emplace(info + std::to_string(i), info);
		return;
	}
}

void next(std::map<std::string, std::string>& queue)
{
	std::map<std::string, std::string>::iterator it = queue.begin();
	if (it == queue.end())
	{
		std::cerr << "There is no queue. " << std::endl;
		return;
	}
	std::cout << "Your turn: " << it->second << std::endl;
	queue.erase(it);
}

int main()
{
	std::string surname;
	std::map<std::string, std::string> queue;

	while (true)
	{
		std::cout << "Enter the surname(X for output): " << std::endl;
		std::getline(std::cin, surname);

		if (surname == "X" || surname == "x")
			return 0;

		if (surname == "Next" || surname == "next")
			next(queue);
		else if (is_correct_surname(surname))
			add(queue, surname);
		else
			std::cerr << "Error! Incorrect input data. Try again. " << std::endl;
	}



	return 0;
}
