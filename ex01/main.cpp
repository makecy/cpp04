#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	const int arraySize = 6;
	const Animal *animals[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Creating animal at index: " << i << std::endl;
		if (i < arraySize / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "---------------------------------" << std::endl;

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Animal at index: " << i << std::endl;
		animals[i]->makeSound();
	}

	std::cout << "---------------------------------" << std::endl;

	for (int i = 0; i <arraySize; i++)
	{
		std::cout << "Deleting animal at index: " << i << std::endl;
		delete animals[i];
	}

	std::cout << "---------------------------------" << std::endl;
	std::cout << "Testing deep copy with Dog" << std::endl;

	Dog dogA;
	{
		Dog dogB(dogA); // Copy constructor
		std::cout << "dogB is going out of scope." << std::endl;
	}

	std::cout << "dogA still in scope, testing its sound:" << std::endl;
	dogA.makeSound();

	std::cout << "---------------------------------" << std::endl;
	std::cout << "Testing deep copy with Cat" << std::endl;

	Cat* catOriginal = new Cat();
	Cat* catCopy = new Cat(*catOriginal); // Copy constructor

	std::cout << "Deleting original cat." << std::endl;
	delete catOriginal;

	std::cout << "catCopy still in scope, testing its sound:" << std::endl;
	catCopy->makeSound();

	delete catCopy;

	std::cout << "---------------------------------" << std::endl;
	return 0;
}