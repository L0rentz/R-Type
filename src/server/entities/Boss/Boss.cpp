/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** ServerBasicMob1
*/

#include "Boss.hpp"

#if defined(__linux__) || defined(__APPLE__)
extern "C" IEntity *allocator()
{
    return new Boss;
}
#endif

// #ifdef WIN32
// extern "C"
// {
// 	__declspec (dllexport) ServerBasicMob1 *allocator()
// 	{
// 		return new ServerBasicMob1();
// 	}

// 	__declspec (dllexport) void deleter(ServerBasicMob1 *ptr)
// 	{
// 		delete ptr;
// 	}
// }
// #endif

Boss::Boss()
    : ServerEntity(CustomRect(512 * 4 / 8, 132 * 4))
{
    int x = std::rand() % 200 + 2000;
    int y = 300;
    setPosition(x, y);
    _speed = -10;
    _type = "Boss";
}

Boss::~Boss()
{
}

void Boss::update()
{
    if (getPosition().first > 1700) {
        setPosition(getPosition().first + _speed, getPosition().second);
    } else {
        if (getPosition().second > 500 || getPosition().second < 50) {
            _speed *= -1;
        }
        setPosition(getPosition().first, getPosition().second + _speed);
    }
}