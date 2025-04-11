#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "---------------------------------" << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	std::cout << "---------------------------------" << std::endl;
	return (0);
}