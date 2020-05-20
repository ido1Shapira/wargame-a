#pragma once

#include "Soldier.hpp"

class Paramedic : public Soldier {

public:
        Paramedic(int pn): Soldier(pn, 100, 50) {}

        void attack(vector<vector<Soldier*>> &b, pair<int,int> location);        

};