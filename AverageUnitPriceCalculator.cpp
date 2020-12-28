#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/*
 * Create file "transaction_log.txt" in same directory as .exe
 * Specify the units and purchase price (space separated) for each transaction in a new line
 */


int main()
{
    std::cout << "\t---------------------------" << std::endl;
    std::cout << "\tAverage Unit Price Calculator" << std::endl;
    std::cout << "\t---------------------------" << std::endl << std::endl;

    std::string transactionLine("");
    double units(0.0), price(0.0), value(0.0);
    double total_units(0.0), sum_value(0.0);
    std::ifstream myFile;

    myFile.open("transaction_log.txt");

    if (myFile.is_open())
    {
        std::cout << "\tunits" << "\t  price" << "\t  value" << std::endl;
        std::cout << "\t---------------------------" << std::endl;
        while (getline(myFile, transactionLine))
        {
            std::istringstream ss(transactionLine);
            ss >> units >> price;
            total_units += units;
            value = units * price;
            sum_value += value;

            std::cout << "\t" << units << "\tx " << price << "\t= " << value << std::endl;
        }
        std::cout << "\t---------------------------" << std::endl;
        std::cout << "\t" << total_units << "\t  " << "\t  " << sum_value << std::endl;
        std::cout << "\t" << "average unit price: " << sum_value / total_units << std::endl;
    }

    myFile.close();

    return 0;
}




