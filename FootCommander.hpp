#pragma once

#include "Soldier.hpp"

using namespace std;

class FootCommander : public Soldier {

public:
        FootCommander(int pn): Soldier(pn, 150, -20) {}

        void attack(vector<vector<Soldier*>> &b, pair<int,int> location);        
};