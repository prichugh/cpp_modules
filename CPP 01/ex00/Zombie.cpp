#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
void Zombie::nameZombie(std::string name)
{
	this->name = name;
}
Zombie::~Zombie()
{
	std::cout << name << " is dead\n";
}

Zombie::Zombie(std::string name)
{
	nameZombie(name);
	announce();
}
