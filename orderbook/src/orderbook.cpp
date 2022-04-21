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

long orderbook::remove_BIDQuantity(long q){
    return BID_OrderMap.remove_quantity(q);
}

long orderbook::remove_OFFERQuantity(long q){
    return OFFER_OrderMap.remove_quantity(q);
}

long orderbook::match(){

    float best_bid, best_offer;
    long executed_quantity = 0;
    long best_bid_quantity, best_offer_quantity;
    long quantity_toRemove;

    while(true){
        best_bid = get_BestBidPrice();
        best_offer = get_BestOfferPrice();
        if (best_bid<0 || best_offer<0 || best_bid<best_offer) break;

        best_bid_quantity = BID_OrderMap.get_BestPriceQuantity();
        best_offer_quantity = OFFER_OrderMap.get_BestPriceQuantity();

        quantity_toRemove = std::min(best_bid_quantity, best_offer_quantity);

        OFFER_OrderMap.remove_quantity(quantity_toRemove);
        BID_OrderMap.remove_quantity(quantity_toRemove);
        
        executed_quantity += quantity_toRemove;
    }

    return executed_quantity * 2;
}