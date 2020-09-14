/*
PImpl AKA "Pointer to implementation" is a c++ programming technique
that removes implementation details of a class from its object representation
by placing them in a separate class, accessible from an opaque pointer
*/

#include "pimpl.h"
#include <iostream>

struct Player::Impl
{
    Impl(std::string i_name)
        : name( i_name ){};

    ~Impl() = default;

    void Greeting()
    {
        std::cout << "Hi, I'm " << name << "!" << std::endl;
    }

    std::string name;
    int health = 1;
};

// Constructor connected with the Impl structure
Player::Player( std::string i_name ) : pimpl( new Impl( i_name ) )
{
    pimpl->Greeting();
}

// Default destructor
Player::~Player() = default;

// Assignment operator and copy operator
Player::Player( const Player& i_other ) : pimpl( new Impl( *i_other.pimpl ) )
{
}

Player& Player::operator=( Player i_rhs )
{
    std::swap( pimpl, i_rhs.pimpl );
    return *this;
}

int Player::getHealth()
{
    std::cout << "Player health is " << pimpl->health << "!" << std::endl;
    return pimpl->health;
}

void Player::setHealth( int i_health )
{
    pimpl->health = i_health;
    std::cout << "Player health is set to " << i_health << std::endl;
}