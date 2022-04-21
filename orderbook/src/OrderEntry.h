
class OrderEntry{
    private:
        long orderID;
        long orderStatus;
        long quantity;
        long submittedTime;
        float price;
        bool type;
    
    public:
        OrderEntry();
        OrderEntry(float p, bool b, long q, long t);

        void set_orderID(long _ID_);
        long get_orderID();

        void set_orderStatus(long status);
        long get_orderStatus();

        void set_orderQuantity(long quantity_);
        long get_orderQuantity();

        void set_submittedTime(long submittedTime_);
        long get_submittedTime();

        void set_LimitPrice(float price_);
        float get_LimitPrice();

        void set_orderType(bool type_);
        bool get_orderType();

        bool operator< (OrderEntry& o);

};