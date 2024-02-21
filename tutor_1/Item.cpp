#include "Item.hpp"

using namespace std;

int Item::totalRevenue = 0;
int Item::totalItems = 0;

Item::Item() : serialNum(totalItems+1){
    stock = 0;
    price = 0;
    sold = 0;
    totalItems++;
}

Item::Item(int stock, int price) : serialNum(totalItems+1){
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems++;
}

Item::Item(const Item& other) : stock(other.stock), price(other.price), sold(other.sold), serialNum(totalItems+1){
    totalItems++;
}

Item::~Item(){
}

int Item::getSerialNum() const{
    return this->serialNum;
}

int Item::getSold() const{
    return this->sold;
}

int Item::getPrice() const{
    return this->price;
}

void Item::addStock(int addedStock){
    if(addedStock > 0){
        this->stock += addedStock;
    }
}

void Item::sell(int soldStock){
    int itemSold;
    if(soldStock > this->stock){
        itemSold = this->stock;
    } else {
        itemSold = soldStock;
    }
    totalRevenue += itemSold * this->price;
    this->sold += itemSold;
    this->stock -= itemSold;
}

void Item::setPrice(int newPrice){
    this->price = newPrice;
}
