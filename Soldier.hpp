#pragma once

#include <stdexcept>
#include <math.h>
#include <vector>

using namespace std;
class Soldier {
        
protected:
        uint player_number;
        uint max_health;
        uint health;
        uint damage;
        
        double distance(uint x_s, uint y_s, uint x_t, uint y_t){
                return sqrt(pow(x_s - x_t,2) + pow(y_s - y_t,2));}

public:
        Soldier(uint p, uint h, int d) : player_number(p), max_health(h), health(h), damage(d) { }
        virtual ~Soldier() {}

        virtual void attack (std::vector<std::vector<Soldier*>> &b, pair<int,int> location) = 0;
        uint get_player_number() { return player_number;}
        uint get_health() { return health;}
        void set_health(uint h) { health = h;}
        uint get_damage() { return damage;}
};