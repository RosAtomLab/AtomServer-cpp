#include "Server.hpp"
#include <boost/asio.hpp>

int main(){

    boost::asio::io_service io_service;
    VoxelServer voxel(io_service);

    io_service.run();

    return 0;
}