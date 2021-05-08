#include <iostream>
#include <string>
#include <fstream>

int physical_Memory[65536];
int page_fault_counts = 0;
int tlb_fault_counts = 0;
int page_table[256];

int getPage(std::string address)
{return std::stoi(address)/256;}

int getOffset(std::string address)
{return std::stoi(address)%256;}

int handlePageFault(int page)
{
    page_fault_counts++;
    std::cout<<"Page Fault at: "<<page<<std::endl;
    int new_physical_address = 0;
    return new_physical_address;
}

int main()
{
    std::string address;
    int physical_address;

    std::ifstream inFile("addresses.txt");
    if(!inFile.is_open())
    {
        std::cout<<"Error opening file"<<std::endl;
        exit(0);
    }
    while(!inFile.eof())//for(int i=0; i<5;i++)
    {
        inFile>>address;
        int page = getPage(address);
        int offset = getOffset(address);
        physical_address = page_table[page];
        //page fault
        if(physical_address == -1)
        {
            physical_address = handlePageFault(page);
        }
        physical_address += offset;
        std::cout<<"logical: "<<address<<" (page: "<<page<<", offset: "<<offset<<")"<<std::endl;
        //std::cout<<"physical: "<<physical_address<<" Value: "<<physical_Memory[physical_address]<<std::endl;
    } 

    std::string exit;
    std::cout<<"Enter any character to exit: ";
    std::cin>> exit;
    return 0;
}