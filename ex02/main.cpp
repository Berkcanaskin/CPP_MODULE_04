#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void	array_test(void)
{
	std::cout << "\n--- Array test ---" << std::endl;
	const int animal_count = 4;
	Animal* animals[animal_count];

	for (int i = 0; i < animal_count / 2; i++)
	{
		animals[i] = new Dog();
	}
	for (int i = animal_count / 2; i < animal_count; i++)
	{
		animals[i] = new Cat();
	}

	std::cout << "\n--- Deleting array ---" << std::endl;
	for (int i = 0; i < animal_count; i++)
	{
		delete animals[i];
	}
	std::cout << "--- Array test end ---" << std::endl;
}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	delete j;
	delete i;

	array_test();

	return (0);
}
