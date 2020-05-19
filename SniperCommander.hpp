#pragma once

#include "Soldier.hpp"

class SniperCommander : public Soldier {

public:
        SniperCommander(int pn): Soldier(pn, 120, 100) {}

        void attack();
};