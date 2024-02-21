#include "SpacingGuildShip.hpp"

int SpacingGuildShip::producedShips = 0;
float SpacingGuildShip::totalGuildTravel = 0;

SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), guildNavigatorCount(3), serialNum(producedShips+1){
    passengerCount = 0;
    operatingGuildNavigator = 3;
    spiceStock = 50;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(producedShips+1){
    passengerCount = 0;
    operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& s) : maxPassengerCap(s.maxPassengerCap), guildNavigatorCount(s.guildNavigatorCount), serialNum(producedShips+1){
    passengerCount = s.passengerCount;
    operatingGuildNavigator = s.operatingGuildNavigator;
    spiceStock = s.spiceStock;
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip(){
}

int SpacingGuildShip::getShipSerialNum() const{
    return serialNum;
}

int SpacingGuildShip::getPassengerCount() const{
    return passengerCount;
}

void SpacingGuildShip::travel(float distance){
    if(operatingGuildNavigator > 0){
        totalGuildTravel += distance / (E*E*operatingGuildNavigator);
        operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers){
    if(passengerCount + addedPassengers > maxPassengerCap){
        passengerCount = maxPassengerCap;
    } else {
        passengerCount += addedPassengers;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers){
    if(passengerCount - droppedPassengers < 0){
        passengerCount = 0;
    } else {
        passengerCount -= droppedPassengers;
    }
}

void SpacingGuildShip::refreshNavigator(int n){
    if(spiceStock - n*GUILD_NAVIGATOR_SPICE_DOSE >= 0){
        operatingGuildNavigator += n;
        spiceStock -= n*GUILD_NAVIGATOR_SPICE_DOSE;
    } else {
        operatingGuildNavigator += spiceStock/GUILD_NAVIGATOR_SPICE_DOSE;
        spiceStock = spiceStock % GUILD_NAVIGATOR_SPICE_DOSE;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice){
    spiceStock += addedSpice;
}