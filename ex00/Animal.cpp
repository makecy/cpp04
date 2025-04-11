#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}