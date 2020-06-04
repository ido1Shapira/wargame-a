#pragma once

#include <stdexcept>
#include <math.h>
#include <vector>

using namespace std;
class Soldier {
        
protected:
        int player_number;
        int max_health;
        int health;
        int damage;
        
        double distance(int x_s, int y_s, int x_t, int y_t){
                return sqrt(pow(x_s - x_t,2) + pow(y_s - y_t,2));}

public:
        Soldier(int p, int h, int d) : player_number(p), max_health(h), health(h), damage(d) { }
        virtual ~Soldier() {}

        virtual void attack (std::vector<std::vector<Soldier*>> &b, pair<int,int> location)= 0;
        int get_player_number() { return player_number;}
        int get_health() { return health;}
        int get_max_health() { return max_health;}
        void set_health(int h) { health = min(h,max_health);}
        int get_damage() { return damage;}
};
