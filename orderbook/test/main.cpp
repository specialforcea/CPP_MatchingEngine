#include<iostream>
#include"orderbook.h"
#include<vector>
#include<map>


int main(){

    std::vector<int> p = {5,3,7,4,8};
    std::vector<int> v = {10,50,30,20,40};

    orderbook test_ob = orderbook(3, p, v);

    std::map<int, int> test_LOB = test_ob.get_LOB();

    std::map<int, int>::iterator itr;

    std::cout << "\nThe LOB is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (itr = test_LOB.begin(); itr != test_LOB.end(); ++itr) {
        std::cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    std::cout << std::endl;      
}