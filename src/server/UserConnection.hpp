/*
** EPITECH PROJECT, 2021
** Asio
** File description:
** connection singeltone
*/

#ifndef TCPCONNECTION_HPP
#define TCPCONNECTION_HPP

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <asio.hpp>
#include "AsioTcpServ.hpp"
#include "SEPParsor.hpp"

class AsioTcpServ;
class UserConnection;

typedef std::shared_ptr<UserConnection> userConnectionPointer;

class UserConnection : public std::enable_shared_from_this<UserConnection>
{
public:

    /**
     * @brief Creates a new user (TCP only)
     * 
     * @param io_context Context of the server (asio)
     * @param servRef Reference of the parent class.
     * @param id New id of the user
     * @param debug is in debug mode
     * @return new pointer to the new user
     */
    static userConnectionPointer create(asio::io_context &io_context, AsioTcpServ &servRef, int id, bool debug) {
        return userConnectionPointer(new UserConnection(io_context, servRef, id, debug));
    }

    /**
     * @brief Get the Socket object
     *
     * @return asio::ip::tcp::socket&
     */
    asio::ip::tcp::socket &getSocket();

    /**
     * @brief Get the Id object
     *
     * @return int id
     */
    int getId() const;

    /**
     * @brief Start listening on the user's TCP socket.
     *
     */
    void startCommunication();


protected:
private:
    UserConnection(asio::io_context &io_context, AsioTcpServ &servRef, int id, bool debug);
    typedef void (UserConnection::*factoryF)(const std::vector<std::string> &arg);

    void handleWrite(const asio::error_code &err, size_t size);
    void handleRead(const asio::error_code &error, size_t size);
    void sendError(int code, const std::string &msg);
    void broadcastTCP(const std::string &msg) const;
    void broadcastTCPNotUser(const std::string &msg) const;
    void checkDisconnection() const;
    bool isUsernameAvailable(const std::string &username) const;

    std::string getUsername() const;

    ///////////////////////////////////////////////////////////////
    //-----------------------CMD_RESPONSES-----------------------//
    ///////////////////////////////////////////////////////////////

    void cmdConnection(const std::vector<std::string> &arg);
    void cmdCreateRoom(const std::vector<std::string> &arg);
    void cmdJoinRoom(const std::vector<std::string> &arg);
    void cmdQuitRoom(const std::vector<std::string> &arg);
    void cmdDeleteRoom(const std::vector<std::string> &arg);

    std::map<int, factoryF> _cmd;

    asio::ip::tcp::socket _socket;
    asio::streambuf _message;
    std::string _finalMessage;

    int _id;
    std::string _userName;
    bool _isUDPOn;
    bool _debug;
    int _roomId;
    AsioTcpServ *_servRef;
};

#endif /* !TCPCONNECTION_HPP */