#define BID true
#define OFFER false
class LimitPrice
{
private:
    float price;
    bool type;

public:
    LimitPrice(float p, bool b);
    bool  is_bid() const;
    bool  is_offer() const;
    float get_limitprice() const;
};

bool operator<(const LimitPrice &lp1, const LimitPrice &lp2);
