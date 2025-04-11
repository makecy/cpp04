#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

void	testEquippingMoreThanFourMaterias()
{
	std::cout << "\n--- Test equipping more than 4 materias ---\n" << std::endl;

	IMateriaSource *source = new MateriaSource();
	source->learnMateria(new Ice());

	ICharacter *character = new Character("Me");

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Equipping materia #" << i + 1 << std::endl;
		AMateria *materia = source->createMateria("ice");
		if (materia)
			character->equip(materia);
		else
			std::cout << "Failed to create materia." << std::endl;
	}

	std::cout << "\n--- End of equipping test ---\n" << std::endl;

	delete character;
	delete source;
}

void	testUsingNonExistentMateria()
{
	std::cout << "\n--- Test using a non-existent materia ---\n" << std::endl;

	ICharacter *you = new Character("You");
	ICharacter *me = new Character("Me");

	int	invalidIndex = 4;
	std::cout << "Character 'me' tries to use materia at invalid index: " << invalidIndex << std::endl;
	me->use(invalidIndex, *you);

	std::cout << "\n--- End of non-exitant materia test ---\n" << std::endl;

	delete you;
	delete me;
}

void	testUnequipping()
{
	std::cout << "\n--- Test unequipping ---\n" << std::endl;

	IMateriaSource *source = new MateriaSource();
	source->learnMateria(new Ice());

	ICharacter *me = new Character("Me");
	AMateria *iceMateria = source->createMateria("ice");

	me->equip(iceMateria);
	me->unequip(0);

	me->use(0, *me);

	delete me;
	delete source;
}

void	testDeepCopyOfCharacter()
{
	std::cout << "\n--- Test deep copy of Character ---\n" << std::endl;

	IMateriaSource *source = new MateriaSource();
	source->learnMateria(new Ice());

	Character *original = new Character("Original");
	original->equip(source->createMateria("ice"));

	Character *copy = new Character(*original);

	original->unequip(0);

	Character tempTarget("Target");
	copy->use(0, tempTarget);

	delete original;
	delete copy;
	delete source;
}

void	testMateriaSource()
{
	std::cout << "\n--- Test MateriaSource ---\n" << std::endl;

	MateriaSource *source = new MateriaSource();
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	for (int i = 0; i < 5; i++)
	{
		if (i < 4)
		{
			if (i % 2 == 0)
				source->learnMateria(ice);
			else
				source->learnMateria(cure);
		}
		else
			source->learnMateria(new Ice());
	}
	delete ice;
	delete cure;
	delete source;
}

int main()
{
	std::cout << "\n--- Basic Tests ---\n" << std::endl;

	std::cout << "\n--- Test MateriaSource ---\n" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n--- Testing Character Creation ---\n" << std::endl;
	ICharacter* me = new Character("me");

	std::cout << "\n--- Testing Materia Creation ---\n" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n--- Testing Materia use ---\n" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "-----------------------------------------" << std::endl;
	delete bob;
	delete me;
	delete src;
	std::cout << "-----------------------------------------" << std::endl;
	// testEquippingMoreThanFourMaterias();
	// testUsingNonExistentMateria();
	// testUnequipping();
	// testDeepCopyOfCharacter();
	// testMateriaSource();
	return 0;
}