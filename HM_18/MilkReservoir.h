#pragma once
#include <iostream>
class MilkReservoir
{
    //TODO HW: Need to implement MilkReservoir logic to be able to prepare Cappuccino
    //See WaterReservoir for reference, the logic here will be very similar
public:
    void showOperations();
    void receiveInput();
    void update();

    void fill(float newVolume) { m_volume = std::min(newVolume, MaxVolume); };
    void useMilk(float volume) { m_volume -= volume; }; //== useWater

    void empty() { m_volume = 0.0f; };
    float getVolume() const { return m_volume; }


    //TODO HW ADDITIONAL: implement milk freshness logic
    //E.g.: start new timer after every empty/fill operation
    //and once this specified time is passed(in seconds/minutes for simplicity to test - mark that milk as gone bad and you can't prepare new Milk-required drinks
    //until the MilkReservoir is emptied and filled once again

private:
    int m_operation = -1;

    float m_volume = 0.0f;
    const float MaxVolume = 1.5f;
};
