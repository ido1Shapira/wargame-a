#pragma once

#include "Soldier.hpp"

using namespace std;

class FootSoldier : public Soldier {

public:
        FootSoldier(int pn): Soldier(pn, 100, -10) {}

        void attack(WarGame::Board& b, pair<int,int> location);
};