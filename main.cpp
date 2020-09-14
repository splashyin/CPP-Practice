#include "pimpl.h"
#include <iostream>

int main()
{
    Player p1( "Anthony" );
    p1.getHealth();
    p1.setHealth(10);
    std::cin.get();
}