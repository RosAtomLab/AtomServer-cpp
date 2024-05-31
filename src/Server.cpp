#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "Server.hpp"

using boost::asio::ip::udp;


VoxelServer::VoxelServer(boost::asio::io_service& io_service) : _socket(io_service, udp::endpoint(udp::v4(), 1111)){
    startReceive();
}

void VoxelServer::startReceive(){
        std::cout << "start receiving";
        _socket.async_receive_from(
            boost::asio::buffer(_recvBuffer), _remoteEndpoint,
            boost::bind(&VoxelServer::handleReceive, this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
}
void VoxelServer::handleReceive(const boost::system::error_code& error,
                       std::size_t bytes_transferred) {
        if (!error || error == boost::asio::error::message_size) {

            auto message = std::make_shared<std::string>("Hello, World\n");

            _socket.async_send_to(boost::asio::buffer(*message), _remoteEndpoint,
                boost::bind(&VoxelServer::handleSend, this, message,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
        }
 }

void VoxelServer::handleSend(std::shared_ptr<std::string> message,
                    const boost::system::error_code& ec,
                    std::size_t bytes_transferred) {
        startReceive();
}