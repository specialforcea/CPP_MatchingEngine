#include<iostream>
#include"orderbook.h"
#include<vector>
#include<random>
#include <functional>
#include <chrono>

int main(){

    int stock0 = 0;
    int stock1 = 1;

    orderbook OB0 = orderbook(stock0);
    orderbook OB1 = orderbook(stock1);

    int num_of_orders = 1000000;

    auto gen_bool = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    auto gen_bid_float = std::bind(std::uniform_real_distribution<>(70, 100),std::default_random_engine());
    auto gen_offer_float = std::bind(std::uniform_real_distribution<>(20, 50),std::default_random_engine());

    std::vector<OrderEntry> orders;

    float price;

    for (int i=0; i<num_of_orders; i++){
        bool type = gen_bool();
        if(type==OFFER) price = gen_offer_float();
        else  price = gen_bid_float();

        OrderEntry o = OrderEntry(price,type,1,i);
        orders.push_back(o);
    }

    try {OB0.insert_orders(orders);}
    catch(const std::invalid_argument &e) {std::cout<<"Exception: "<<e.what()<<std::endl;}

    std::cout<<orders.size()<<std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << OB0.match()<<std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << duration.count() << std::endl;

    //stock1

    for (int i=0; i<num_of_orders; i++){
        bool type = gen_bool();
        if(type==OFFER) price = gen_offer_float();
        else  price = gen_bid_float();

        OrderEntry o = OrderEntry(price,type,1,i);
        orders[i] = o;
    }

    try {OB1.insert_orders(orders);}
    catch(const std::invalid_argument &e) {std::cout<<"Exception: "<<e.what()<<std::endl;}

    std::cout<<orders.size()<<std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << OB1.match()<<std::endl;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << duration.count() << std::endl;

    return 0;
}