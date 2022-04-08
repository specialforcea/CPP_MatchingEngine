#include"LimitPrice.h"

LimitPrice::LimitPrice(float p, bool b)
{
    price = p;
    is_bid_ = b;
}


bool  LimitPrice::is_bid() const {return is_bid_;}

bool  LimitPrice::is_offer() const {return ~is_bid_;}

// bool LimitPrice::operator < (LimitPrice  const &lp) const{
 
//     if (this->is_bid() && lp.is_bid()) return this->get_limitprice()>lp.get_limitprice();
//     else return this->get_limitprice()<lp.get_limitprice();
//     // if (is_bid() && lp.is_bid()) return price>lp.get_limitprice();
//     // else if (is_bid() && lp.is_offer()) return price<lp.get_limitprice();
//     // else if (is_offer() && lp.is_bid()) return price<lp.get_limitprice();
//     // else return price<lp.get_limitprice();
    
// }

float LimitPrice::get_limitprice() const {return price;}

bool operator<(const LimitPrice &lp1, const LimitPrice &lp2){
    if (lp1.is_bid() && lp2.is_bid()) return lp1.get_limitprice()>lp2.get_limitprice();
    else return lp1.get_limitprice()<lp2.get_limitprice();
}