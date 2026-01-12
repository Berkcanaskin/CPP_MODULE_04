#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	pdf_main(void)
{
	std::cout << "--- PDF main ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	std::cout << "--- PDF main end ---" << std::endl;
}

void	wrong_main(void)
{
	std::cout << "\n--- Wrong main ---" << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	std::cout << "--- Wrong main end ---" << std::endl;
}

int main()
{
	pdf_main();
	wrong_main();

	std::cout << "\n--- My tests ---" << std::endl;

	std::cout << "\n--- Dog copy test ---" << std::endl;
	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog(*dog1);
	delete dog1;
	dog2->makeSound();
	delete dog2;
	std::cout << "--- Dog copy test end ---" << std::endl;

	std::cout << "\n--- Cat copy test ---" << std::endl;
	Cat cat1;
	Cat cat2;
	cat2 = cat1;
	cat2.makeSound();
	std::cout << "--- Cat copy test end ---" << std::endl;

	return (0);
}
