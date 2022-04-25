#include"ordermap.h"


OrderMap::OrderMap(bool T){
    type = T;
    std::map<LimitPrice, std::multimap<long, OrderEntry>> ordermap;
    std::map<LimitPrice, int> price_volume;
    TotalVolume = 0;

}

void OrderMap::insert_OrderEntry(OrderEntry o){

    if (type!=o.get_orderType()) {throw std::invalid_argument("Order type does not match order map.");}

    float p = o.get_LimitPrice();
    long q = o.get_orderQuantity();
    long t = o.get_submittedTime();

    LimitPrice limitprice = LimitPrice(p, type);

    if (ordermap.count(limitprice)>0){
        ordermap[limitprice].insert({t, o});
        price_volume[limitprice] += q;
    }
    else{
        ordermap[limitprice] = {{t, o}};
        price_volume[limitprice] = q;
    }

    TotalVolume += q;

}

float OrderMap::get_BestLimitPrice(){
    
    if (ordermap.size()==0) return -1;

    LimitPrice lp = ordermap.begin()->first;
    
    return lp.get_limitprice();

}

long OrderMap::get_TotalVolume(){
    return TotalVolume;
}


std::map<LimitPrice, std::multimap<long, OrderEntry>> OrderMap::get_ordermap(){
    return ordermap;
}


void OrderMap::remove_price(float r_p){
    long quantity = 0;

    LimitPrice limit_r_p = LimitPrice(r_p, type);

    if (ordermap.count(limit_r_p) && price_volume.count(limit_r_p)){
        
        quantity = price_volume[limit_r_p];
        TotalVolume -= quantity;
        ordermap.erase(limit_r_p);
        price_volume.erase(limit_r_p);
    }    
    
}

long OrderMap::remove_quantity_in_price(float r_p, long r_q){
    
    long q_toRemove = r_q;

    LimitPrice limit_r_p = LimitPrice(r_p, type);

    while(q_toRemove>0){

        if (ordermap.count(limit_r_p)==0) break;

        if (ordermap[limit_r_p].size()>0){

            long cur_q = ordermap[limit_r_p].begin()->second.get_orderQuantity();

            if (cur_q>q_toRemove){
                ordermap[limit_r_p].begin()->second.set_orderQuantity(cur_q - q_toRemove);
                price_volume[limit_r_p] -= q_toRemove;
                q_toRemove = 0;
            }
            else{
                q_toRemove -= cur_q;
                ordermap[limit_r_p].erase(ordermap[limit_r_p].begin());
                price_volume[limit_r_p] -= cur_q;
            }
        }
        else break;
        
    }

    if (ordermap[limit_r_p].size()==0) {
        ordermap.erase(limit_r_p);
        price_volume.erase(limit_r_p);
    } 

    TotalVolume -= (r_q - q_toRemove);

    return r_q - q_toRemove;

}

long OrderMap::remove_quantity(long r_q){
    long quantity = r_q;

    while (quantity>0){

        float best_price = get_BestLimitPrice();
        if (best_price<0) break;
        
        quantity -= remove_quantity_in_price(best_price, quantity);
        
    }

    return r_q - quantity;
}

long OrderMap::get_BestPriceQuantity(){

    float best_price = get_BestLimitPrice();
    
    if (best_price<0) return 0;

    LimitPrice BestLimitPrice = LimitPrice(best_price, type);

    return price_volume[BestLimitPrice];
}