#pragma once

#include "Soldier.hpp"

using namespace std;

class Sniper : public Soldier {

public:
        Sniper(int pn): Soldier(pn, 100, -50) {}

        void attack(vector<vector<Soldier*>> &b, pair<int,int> location);      
};