#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void	pdf_main(void)
{
	std::cout << "--- PDF main ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	std::cout << "--- PDF main end ---" << std::endl;
}

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

void	deep_copy_test(void)
{
	std::cout << "\n--- Deep copy test ---" << std::endl;
	
	Dog* original_dog = new Dog();
	original_dog->setIdea(0, "I love bones");
	std::cout << "Original dog's first idea: " << original_dog->getIdea(0) << std::endl;

	Dog* copy_dog = new Dog(*original_dog);
	std::cout << "Copied dog's first idea: " << copy_dog->getIdea(0) << std::endl;
	
	std::cout << "--- Changing original dog's idea ---" << std::endl;
	original_dog->setIdea(0, "I love sticks");
	std::cout << "Original dog's new first idea: " << original_dog->getIdea(0) << std::endl;
	std::cout << "Copied dog's first idea (should be unchanged): " << copy_dog->getIdea(0) << std::endl;

	delete original_dog;
	delete copy_dog;

	std::cout << "\n--- Cat assignment test ---" << std::endl;
	Cat cat1;
	cat1.setIdea(0, "I love fish");
	{
		Cat cat2;
		cat2 = cat1;
		cat1.setIdea(0, "I love yarn");
		std::cout << "cat1 idea: " << cat1.getIdea(0) << std::endl;
		std::cout << "cat2 idea: " << cat2.getIdea(0) << std::endl;
	}
	std::cout << "cat1 idea after cat2 is out of scope: " << cat1.getIdea(0) << std::endl;

	std::cout << "--- Deep copy test end ---" << std::endl;
}

int main()
{
	pdf_main();
	array_test();
	deep_copy_test();
	return (0);
}
