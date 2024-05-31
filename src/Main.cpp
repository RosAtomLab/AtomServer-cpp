//#include "Server.hpp"
#include <boost/asio.hpp>
#include "iostream"

int main(){

    boost::asio::io_service io_service;
    
    //  VoxelServer voxel(io_service);
    //io_service.run();
    std::cout << &io_service;
    return 0;
}