#include "UDPServer.h"

using asio::ip::udp;

int main(int argc, char* argv[])
{
    asio::io_context io_context;

    ds::UDPServer s(io_context, 5000);

    io_context.run();

    return 0;
}