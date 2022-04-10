#include<iostream>
#include"orderbook.h"
// #include"OrderEntry.h"
// #include"ordermap.h"
#include<vector>
#include<map>
#include <algorithm> 


int main(){

    // for (auto i: a){
    //     std::cout<< i.first<<' '<<i.second <<std::endl;
    // }
    // std::vector<int> p = {5,3,7,4,8};
    // std::vector<int> v = {10,50,30,20,40};

    // orderbook test_ob = orderbook(3, p, v);

    // std::map<int, int> test_LOB = test_ob.get_LOB();

    // std::map<int, int>::iterator itr;

    // std::cout << "\nThe LOB is : \n";
    // std::cout << "\tKEY\tELEMENT\n";
    // for (itr = test_LOB.begin(); itr != test_LOB.end(); ++itr) {
    //     std::cout << '\t' << itr->first << '\t' << itr->second
    //          << '\n';
    // }
    // std::cout << std::endl;      

    int stock = 0;

    orderbook OB = orderbook(stock);

    bool T = BID;

    std::vector<OrderEntry> orderlist = {
        OrderEntry(6,BID,1,5),
        OrderEntry(20,BID,1,3),
        OrderEntry(20,BID,4,1),
        OrderEntry(10,BID,1,7),
        OrderEntry(10,BID,1,4),
        OrderEntry(10,BID,1,2),
        OrderEntry(50,BID,1,4),
        OrderEntry(50,BID,6,7),
        OrderEntry(50,BID,1,5),
        OrderEntry(80,OFFER,4,1),
        OrderEntry(80,OFFER,1,7),
        OrderEntry(60,OFFER,1,4),
        OrderEntry(40,OFFER,1,2),
        OrderEntry(40,OFFER,1,4),
        OrderEntry(40,OFFER,6,7),
        OrderEntry(40,OFFER,1,5),
    };
    // pbqt
    
    try {OB.insert_orders(orderlist);}
    catch(const std::invalid_argument &e) {std::cout<<"Exception: "<<e.what()<<std::endl;}
    
    std::cout << OB.get_BestBidPrice() <<' '<<OB.get_BestOfferPrice()<<' '<<std::endl;
    std::cout << OB.get_TotalBidVolume() <<' '<<OB.get_TotalOfferVolume()<<' '<<std::endl;
    // for (auto x : orderlist){
    //     try {OM.insert_OrderEntry(x);}
    //     catch(const std::invalid_argument &e) {std::cout<<"Exception: "<<e.what()<<std::endl;}
    // }
        

    // std::map<float, std::vector<OrderEntry>> ordermap = OM.get_ordermap();
    // std::map<float, std::vector<OrderEntry>>::iterator itr;

    // for (itr = ordermap.begin(); itr != ordermap.end(); ++itr) {
    //     std::cout << '\t' << itr->first << '\n';
    // }
    // std::cout<<OM.get_BestLimitPrice()<<std::endl;
    // std::cout<<OM.get_BestLimitPrice()<<' '<<OM.get_TotalVolume()<<std::endl;

    // std::sort(orderlist.begin(), orderlist.end());
 
    // std::cout << "Sorted \n";
    // for (auto x : orderlist)
    //     std::cout << x.get_submittedTime() << " ";
    // std::cout << std::endl;

    // std::map<LimitPrice, int> a;

    // a.insert({LimitPrice(2, OFFER), 5});
    // a.insert({LimitPrice(4, OFFER), 6});

    // LimitPrice lp = LimitPrice(2, OFFER);

    // bool R = ~(lp < LimitPrice(2, OFFER) || LimitPrice(2, OFFER)<lp);
    // std::cout<<a[lp]<<std::endl;

}