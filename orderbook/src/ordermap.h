#include"OrderEntry.h"
#include"LimitPrice.h"
#include<map>
#include<vector>

class OrderMap {
    private:
        bool type;
        std::map<LimitPrice, std::multimap<long, OrderEntry>> ordermap;
        long TotalVolume;
    
    public:
        OrderMap(bool T);
        float get_BestLimitPrice();
        long get_TotalVolume();
        void insert_OrderEntry(OrderEntry o);
        std::map<LimitPrice, std::multimap<long, OrderEntry>> get_ordermap();
        long remove_quantity_in_price(float r_p, long r_q);
        void remove_price(float r_p);
        

};