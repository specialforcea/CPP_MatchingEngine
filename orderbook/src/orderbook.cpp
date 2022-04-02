#include "orderbook.h"

orderbook::orderbook(int sid, std::vector<int> prices, std::vector<int> volumes){
    securityID = sid;

    std::vector<int>::iterator iter_prices = prices.begin();
    std::vector<int>::iterator iter_volumes = volumes.begin();

    while(iter_prices != prices.end()){
        LOB.insert(std::pair<int, int>(*iter_prices, *iter_volumes));
        iter_prices++;
        iter_volumes++;
    }

}

int orderbook::get_sid(){
    return securityID;
}

std::map<int, int> orderbook::get_LOB(){
    return LOB;
}