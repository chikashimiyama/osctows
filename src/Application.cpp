#include <cstdlib>
#include <iostream>
#include "asio.hpp"

using asio::ip::udp;

class UdpServer
{
public:
    UdpServer(asio::io_context& io_context, unsigned short port)
            : socket_(io_context, udp::endpoint(udp::v4(), port))
    {
        receive();
    }

    void receive()
    {
        socket_.async_receive_from(
                asio::buffer(data_, max_length), sender_endpoint_,
                [this](std::error_code ec, std::size_t bytes_recvd)
                {
                    if (!ec && bytes_recvd > 0)
                    {
                        std::cout << "received" << std::endl;
                    }

                    receive();
                });
    }



private:
    udp::socket socket_;
    udp::endpoint sender_endpoint_;
    enum { max_length = 1024 };
    char data_[max_length];
};

int main(int argc, char* argv[])
{

    asio::io_context io_context;

    UdpServer s(io_context, 5000);

    io_context.run();

    return 0;
}