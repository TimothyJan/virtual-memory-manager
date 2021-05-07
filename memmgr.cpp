#include <iostream>
#include <string>
#include <fstream>

using BYTE = uint8_t;
using SBYTE = int8_t;

int getPage(std::string address)
{return std::stoi(address)/256;}

int getOffset(std::string address)
{return std::stoi(address)%256;}

int main()
{
    std::string address;
    std::ifstream inFile("addresses.txt");
    if(!inFile.is_open())
    {
        std::cout<<"Error opening file"<<std::endl;
        exit(0);
    }
    //while(!inFile.eof())
    for(int i=0; i<5;i++)
    {
        inFile>>address;
        int page = getPage(address);
        int offset = getOffset(address);
        std::cout<<"logical: "<<address<<" (page: "<<page<<", offset: "<<offset<<")"<<std::endl;
    } 

    std::string exit;
    std::cout<<"Enter any character to exit: ";
    std::cin>> exit;
    return 0;
}