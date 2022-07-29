#include <iostream>
#include "orderbook.h"
#include <vector>
#include <random>
#include <functional>
#include <chrono>
#include <thread>
// #include <pthread.h>

void execute_match(orderbook ob)
{
    std::cout << "Matched: " << ob.match() << std::endl;
}

std::vector<OrderEntry> generate_random_orders(int num)
{

    float price;
    std::vector<OrderEntry> orders;

    auto gen_bool = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
    auto gen_bid_float = std::bind(std::uniform_real_distribution<>(70, 100), std::default_random_engine());
    auto gen_offer_float = std::bind(std::uniform_real_distribution<>(20, 50), std::default_random_engine());

    for (int i = 0; i < num; i++)
    {
        bool type = gen_bool();
        if (type == OFFER)
            price = gen_offer_float();
        else
            price = gen_bid_float();

        OrderEntry o = OrderEntry(price, type, 1, i);
        orders.push_back(o);
    }

    return orders;
}

int main()
{

    int num_ordertype = 4;
    int num_of_orders = 1000000;

    std::vector<orderbook> OBs;

    for (int i = 0; i < num_ordertype; i++)
    {
        orderbook temp_ob = orderbook(i);
        std::vector<OrderEntry> temp_orders = generate_random_orders(num_of_orders);
        try
        {
            temp_ob.insert_orders(temp_orders);
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        OBs.push_back(temp_ob);
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::thread worker1(execute_match, OBs[0]);
    std::thread worker2(execute_match, OBs[1]);
    std::thread worker3(execute_match, OBs[2]);
    std::thread worker4(execute_match, OBs[3]);
    worker1.join();
    worker2.join();
    worker3.join();
    worker4.join();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "duration: " << duration.count() << std::endl;

    return 0;
}