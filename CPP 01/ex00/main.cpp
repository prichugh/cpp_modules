#include "Zombie.hpp"

int	main(void)
{

	//creating a new zombie on the heap
	Zombie *heapZombie = newZombie("jimmy");
	delete heapZombie;

	//creating a new zombie on the stack
	randomChump("fredd");

	return (0);
}
