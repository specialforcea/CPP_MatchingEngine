#include"ordermap.h"


OrderMap::OrderMap(bool T){
    type = T;
    std::map<LimitPrice, std::multimap<long, OrderEntry>> ordermap;
    TotalVolume = 0;

}

void OrderMap::insert_OrderEntry(OrderEntry o){

    float p = o.get_LimitPrice();
    long q = o.get_orderQuantity();
    long t = o.get_submittedTime();

    LimitPrice limitprice = LimitPrice(p, type);

    if (ordermap.count(limitprice)>0){
        ordermap[limitprice].insert({t, o});
    }
    else{
        ordermap[limitprice] = {{t, o}};
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

    if (ordermap.count(limit_r_p)){
        for(auto o : ordermap[limit_r_p]){
            quantity += o.second.get_orderQuantity();
        }
        TotalVolume -= quantity;
        ordermap.erase(limit_r_p);
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
                q_toRemove = 0;
            }
            else{
                q_toRemove -= cur_q;
                ordermap[limit_r_p].erase(ordermap[limit_r_p].begin());
            }
        }
        else break;
        
    }

    if (ordermap[limit_r_p].size()==0)  ordermap.erase(limit_r_p);

    TotalVolume -= (r_q - q_toRemove);

    return r_q - q_toRemove;

}