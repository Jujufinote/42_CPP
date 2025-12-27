#include "header.hpp"

int	main(void)
{
	/*------------- Tests copies -------------*/

			std::cout << std::endl;

	AMateria* a = new Ice();
	MateriaSource c;
	MateriaSource d;
	d.learnMateria(a);

			std::cout << std::endl;

	c = d;

			std::cout << std::endl;

	AMateria* buf;
	buf = c.createMateria("ice");

			std::cout << std::endl;

	std::cout << "AMateria type " << buf->getType() << std::endl;

			std::cout << std::endl;
	
	Character some("some");
	Character one;
	some.equip(a);

			std::cout << std::endl;

	one = some;

			std::cout << std::endl;

	one.showInventory();

			std::cout << std::endl;

	/*------------ Tests space materiasource ------------*/

			std::cout << std::endl;

	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());	
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;
	src->learnMateria(new Cure()); // no space left

			std::cout << std::endl;
			
	/*--------------- Equipment ---------------*/
	
			std::cout << std::endl;
	
	ICharacter* me = new Character("me");

			std::cout << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << std::endl;
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	std::cout << std::endl;
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("fire"); // no materia called fire, not learned by materiasource

			std::cout << std::endl;

	/*--------------- Battle ---------------*/

			std::cout << std::endl;

	ICharacter* bob = new Character("bob");

			std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob); // no materia equiped at this index

			std::cout << std::endl;

	/*-------------- Unequipment -------------*/

			std::cout << std::endl;

	me->unequip(0);
	me->unequip(1);
	me->unequip(2); // no materia equiped at this index
	me->unequip(4); // out of inventory 

			std::cout << std::endl;

	/*------------- Tests Ground -------------*/

			std::cout << std::endl;

	me->equip(Ground::suppItem("ice"));
	me->equip(Ground::suppItem("cure"));
	me->equip(Ground::suppItem("cure")); // no cure left on ground
			
			std::cout << std::endl;
			
		//to test ground destructor when some items are there
	me->unequip(0);

			std::cout << std::endl;

	/*--------------- Cleaning ---------------*/

			std::cout << std::endl;

	delete bob;
			std::cout << std::endl;
	delete me;
			std::cout << std::endl;
	delete src;
			std::cout << std::endl;
	Ground::destructor();

			std::cout << std::endl;

	return 0;
}
