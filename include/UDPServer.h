#include <asio.hpp>

class UDPServer
{
public:
    UDPServer(asio::io_context& context, unsigned short port);

    void receive();

private:

    asio::ip::udp::socket socket_;
    asio::ip::udp::endpoint sender_endpoint_;
    enum { max_length = 1024 };
    char data_[max_length];
};