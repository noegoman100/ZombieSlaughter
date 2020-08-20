#pragma once
#include <SFML/Graphics.hpp>
#include "Zombie.h"

using namespace sf;

int createBackground(VertexArray& rVA, IntRect);
Zombie* createHorde(int numZombies, IntRect arena);
