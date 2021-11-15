/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCE-5-1-rtype-antonin.fille
** File description:
** ServerPlayer
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "ServerBullet.hpp"
#include "ServerRoom.hpp"
#include <asio.hpp>
#include <time.h>

class ServerRoom;

class ServerPlayer :  public ServerEntity, std::enable_shared_from_this<ServerPlayer> {
    public:
        ServerPlayer(const CustomRect &rect, asio::io_context &io_context, ServerRoom &roomRef, int port);
        ~ServerPlayer();

        void update() override;
        void setUsername(const std::string &username);

        std::string getUsername() const;
        int getPort() const;
        asio::ip::udp::socket &getSocket();
        void startUDP();
        bool isReady() const;
        void setIsReady(bool isReady);
        void sendData(const std::string &code, const std::string &msg);
        void broadcastUDPNotSelf();
        void handleReceive(const asio::error_code &error);
        void closeUDP();
        void movePlayer(const std::string &direction);
        std::vector<std::shared_ptr<IEntity>> getAmmo();
        void shoot();
        void openRead(const asio::error_code &error);
        bool _canShoot;

    protected:
    private:
        std::string _userName;
        asio::ip::udp::socket _socketR;
        asio::ip::udp::socket _socketW;
        asio::io_context &_io_context;
        asio::ip::udp::endpoint _receiverEndpointR;
        asio::ip::udp::endpoint _receiverEndpointW;
        ServerRoom *_roomRef;
        std::vector<std::shared_ptr<IEntity>> _ammo;
        bool _isReady;
        char _buffer[1024];
        int _port;

};

#endif /* !PLAYER_HPP_ */
