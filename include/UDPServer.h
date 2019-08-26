#include <asio.hpp>

namespace ds
{
    class UDPServer
    {
    public:
        UDPServer(asio::io_context& io_context, unsigned short port);

        void receive();

    private:
        asio::ip::udp::socket socket_;
        asio::ip::udp::endpoint sender_endpoint_;
        enum
        {
            max_length = 2048
        };
        char data_[max_length];
    };
}