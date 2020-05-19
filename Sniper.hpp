#pragma once

#include "Soldier.hpp"

class Sniper : public Soldier {

public:
        Sniper(int pn): Soldier(pn, 100, 50) {}

        void attack();
};