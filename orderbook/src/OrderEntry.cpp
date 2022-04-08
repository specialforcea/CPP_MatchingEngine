#include<iostream>
#include"OrderEntry.h"

OrderEntry::OrderEntry(float p, bool b, long q, long t){
    orderID = 0;
    orderStatus = 0;
    quantity = q;
    submittedTime = t;
    price = p;
    side = b;
}

long OrderEntry::get_orderID(){
    return orderID;
}

void OrderEntry::set_orderID(long _ID_){
    orderID = _ID_;
}


void OrderEntry::set_orderStatus(long status){
    orderStatus = status;
}

long OrderEntry::get_orderStatus(){
    return orderStatus;
}

void OrderEntry::set_orderQuantity(long quantity_){
    quantity = quantity_;
}

long OrderEntry::get_orderQuantity(){
    return quantity;
}

void OrderEntry::set_submittedTime(long submittedTime_){
    submittedTime = submittedTime_;
}

long OrderEntry::get_submittedTime(){
    return submittedTime;
}

void OrderEntry::set_LimitPrice(float price_){
    price = price_;
}

float OrderEntry::get_LimitPrice(){
    return price;

}

void OrderEntry::set_orderSide(bool side_){
    side = side_;
}

bool OrderEntry::get_orderSide(){
    return side;
}

bool OrderEntry::operator< (OrderEntry& o){
    if (submittedTime<o.get_submittedTime()) return true;
    
    else return false;
}