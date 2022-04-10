#include"ordermap.h"

class orderbook{
    private:
        int securityID;
        OrderMap BID_OrderMap = OrderMap(BID);
        OrderMap OFFER_OrderMap = OrderMap(OFFER);

    public:
        orderbook(int sid);
        void set_sid(int sid);
        int get_sid();
        void insert_order(OrderEntry &oe);
        void insert_orders(std::vector<OrderEntry> &vec_oe);
        float get_BestBidPrice();
        float get_BestOfferPrice();
        long get_TotalBidVolume();
        long get_TotalOfferVolume();

};