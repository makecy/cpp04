#include "Character.hpp"

Character::Character() : _name("default")
{
	std::cout << "Character default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	std::cout << "Character constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called." << std::endl;
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment operator called." << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i] != NULL)
				delete this->_materia[i];
			if (other._materia[i] != NULL)
				this->_materia[i] = other._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			std::cout << "Materia equipped at index " << i << std::endl;
			return;
		}
	}
	std::cout << "No more space for new materia." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->_materia[idx] == NULL)
	{
		std::cout << "Invalid index or no materia at this index " << idx << std::endl;
		return;
	}
	this->_materia[idx] = NULL;
	std::cout << "Materia unequipped at index " << idx << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || this->_materia[idx] == NULL)
	{
		std::cout << "Invalid index or no materia at this index " << idx << std::endl;
		return;
	}
	this->_materia[idx]->use(target);
	std::cout << "Materia at index " << idx << " used on target " << target.getName() << std::endl;
}