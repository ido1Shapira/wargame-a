#pragma once

#include "Soldier.hpp"

class FootSoldier : public Soldier {

public:
        FootSoldier(int pn): Soldier(pn, 100, 10) {}

        void attack();
};