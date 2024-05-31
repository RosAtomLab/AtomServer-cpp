#pragma once

using boost::asio::ip::udp;

class VoxelServer{
    
public:

    VoxelServer(boost::asio::io_service& io_service) : _socket(io_service, udp::endpoint(udp::v4(), 1111)){};


    void startReceive();
    void handleReceive(const boost::system::error_code& error,
                       std::size_t bytes_transferred);
    void handleSend(std::shared_ptr<std::string> message,
                    const boost::system::error_code& ec,
                    std::size_t bytes_transferred);

    udp::socket _socket;
    udp::endpoint _remoteEndpoint;
    std::array<char, 1024> _recvBuffer;

};