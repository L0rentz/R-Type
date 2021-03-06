/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCE-5-1-rtype-antonin.fille
** File description:
** main
*/

#include <iostream>
#include "RtypeException.hpp"
#include "AsioTcpServ.hpp"
#include "ValidateIp.hpp"
#include "ServerPlayer.hpp"

int threadCount = 0;

int arg_check(int ac, char *argv[])
{
    ValidateIp validator;
    if (ac < 2)
        throw rtype::RtypeException("./rtype_server port");
    if (std::atoi(argv[1]) < 1 || std::atoi(argv[1]) > 65535)
        throw rtype::RtypeException("Please provide a valid port (1025 to 65535).");
    return (0);
}

int main(int ac, char **av)
{
    bool multi_threading = true;
    srand(time(nullptr));
    bool debug = false;
    try {
        asio::io_context io_context;
        arg_check(ac, av);
        if (ac >= 3) {
            if (std::strcmp(av[2], "debug") == 0) {
                debug = true;
            }
        }

        AsioTcpServ server(io_context, std::atoi(av[1]), debug);

        if (multi_threading) {
            // std::thread shell(AsioTcpServ::shell_send);
        }
        io_context.run();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}