#include "orderbook.h"

orderbook::orderbook(int sid){
    set_sid(sid);
    // BID_OrderMap = OrderMap(BID);
    // OFFER_OrderMap = OrderMap(OFFER);
}

void orderbook::set_sid(int sid){
    securityID = sid;
}

int orderbook::get_sid(){
    return securityID;
}

void orderbook::insert_order(OrderEntry &oe){
    bool type = oe.get_orderType();
    if (type==BID) BID_OrderMap.insert_OrderEntry(oe);
    else OFFER_OrderMap.insert_OrderEntry(oe);
}

void orderbook::insert_orders(std::vector<OrderEntry> &vec_oe){
    for (auto oe : vec_oe){
        insert_order(oe);
    }
}

float orderbook::get_BestBidPrice(){
    return BID_OrderMap.get_BestLimitPrice();
}
        
float orderbook::get_BestOfferPrice(){
    return OFFER_OrderMap.get_BestLimitPrice();
}

long orderbook::get_TotalBidVolume(){
    return BID_OrderMap.get_TotalVolume();
}

long orderbook::get_TotalOfferVolume(){
    return OFFER_OrderMap.get_TotalVolume();
}