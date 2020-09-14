#pragma once

#include <memory>
#include <string>

class Player
{
public:
    // Dtor
    ~Player();

    // Ctor
    Player( std::string i_name );

    // Asssignment operator and copy operator
    Player( const Player& i_other );

    Player& operator=( Player i_rhs );

    // Getter
    int getHealth();

    // Setter
    void setHealth( int i_health );

private:
    // Implmentation class (internal)
    class Impl;
    
    // Pointer to the internal implementation
    std::unique_ptr< Impl > pimpl;
};