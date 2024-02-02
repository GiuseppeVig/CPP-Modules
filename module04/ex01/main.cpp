#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal** meta = new Animal*[10];
	int i = 0;
	while (i < 5)
		meta[i++] = new Dog();
	while (i < 10)
		meta[i++] = new Cat();
	for (int i = 0; i < 10; i++)
		meta[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete meta[i];
	delete[] meta;
	return 0;
}