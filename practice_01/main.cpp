#include "pimpl.h"
#include "Practice_01Config.h"
#include <iostream>

int main()
{
    // Print version info
    std::cout << "Version " << Practice_01_VERSION_MAJOR << "." 
              << Practice_01_VERSION_MINOR << std::endl;
     
    Player p1("Anthony");
    Player p2( "Sabrina" );
    p1.setHealth(10);
    p1.getHealth();

    p2.setHealth(15);
    p1 = p2;
    p1.getHealth();
    std::cin.get();
    
    return 0;
}