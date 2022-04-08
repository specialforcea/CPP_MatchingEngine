#include<iostream>
#include"orderbook.h"
// #include"OrderEntry.h"
#include"ordermap.h"
#include<vector>
#include<map>
#include <algorithm> 


int main(){

    // std::map<int, int> a;

    // a[3] = 4;
    // a[4] = 5;

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

    std::vector<OrderEntry> orderlist = {
        OrderEntry(6,1,1,5),
        OrderEntry(20,1,1,3),
        OrderEntry(20,1,4,1),
        OrderEntry(10,1,1,7),
        OrderEntry(10,1,1,4),
        OrderEntry(10,1,1,2),
        OrderEntry(50,1,1,4),
        OrderEntry(50,1,6,7),
        OrderEntry(50,1,1,5),
    };
    // pbqt

    OrderMap OM = OrderMap(1);

    for (auto x : orderlist)
        OM.insert_OrderEntry(x);

    // std::map<float, std::vector<OrderEntry>> ordermap = OM.get_ordermap();
    // std::map<float, std::vector<OrderEntry>>::iterator itr;

    // for (itr = ordermap.begin(); itr != ordermap.end(); ++itr) {
    //     std::cout << '\t' << itr->first << '\n';
    // }
    std::cout<<OM.get_BestLimitPrice()<<std::endl;
    // std::cout<<OM.get_BestLimitPrice()<<' '<<OM.get_TotalVolume()<<std::endl;

    // std::sort(orderlist.begin(), orderlist.end());
 
    // std::cout << "Sorted \n";
    // for (auto x : orderlist)
    //     std::cout << x.get_submittedTime() << " ";
    // std::cout << std::endl;
}