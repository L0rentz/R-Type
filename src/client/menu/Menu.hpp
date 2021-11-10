/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCE-5-1-rtype-antonin.fille
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Graphics.hpp>
#include <boost/asio.hpp>

#include "WarningBox.hpp"
#include "Connection.hpp"
#include "RoomsList.hpp"
#include "Room.hpp"

class Menu {
    public:
        Menu();
        ~Menu();

        void create(const sf::RenderWindow &window, char *buf);
        void draw(sf::RenderWindow &window) const;
        void event(const sf::Event &event, const sf::RenderWindow &window, boost::asio::ip::tcp::endpoint &endpoint, boost::asio::ip::tcp::socket &socket);
        void update();
        void setAlert();

    protected:
    private:
        void connect(const sf::Event &event, const sf::RenderWindow &window);
        void getDefaultInput();
        void joinRoom();
        void openAlert();
        void leaveRoom();

        sf::RectangleShape _background;
        WarningBox _alert;
        Connection _connection;
        RoomsList _rooms;
        bool _connected;
        bool _inRoom;
        sf::Texture _logoTexture;
        sf::Sprite _logo;
        char *_buf;
        Room _room;
};

#endif /* !MENU_HPP_ */
