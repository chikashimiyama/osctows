#include "UDPServer.h"
#include <iostream>
using asio::ip::udp;

namespace ds
{

    UDPServer::UDPServer(asio::io_context& io_context, unsigned short port) :
            socket_(io_context, udp::endpoint(udp::v4(), port))
    {
        receive();
    }

    void UDPServer::receive()
    {
        socket_.async_receive_from(
            asio::buffer(data_, max_length), sender_endpoint_,
                [this](std::error_code ec, std::size_t bytes_recvd)
                {
                    if (!ec && bytes_recvd > 0)
                    {
                        std::cout << "test" << std::endl;
                    }
                    receive();
                });
    }
}