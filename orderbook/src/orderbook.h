#include<iostream>
#include <map>
#include <iterator>
#include <vector>

class orderbook{
    private:
        int securityID;
        std::map<int, int> LOB;

    public:
        orderbook(int sid, std::vector<int> prices, std::vector<int> volumes);
        int get_sid();
        std::map<int, int> get_LOB();
};