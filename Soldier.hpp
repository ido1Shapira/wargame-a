#pragma once

class Soldier {
        
protected:
        uint player_number;
        uint health;
        uint damage;

public:
        Soldier(uint p, uint h, int d) : player_number(p), health(h), damage(d) { }
        virtual void attack() = 0;
        uint get_player_number() { return player_number;}
        uint get_health() { return health;}
        uint get_damage() { return damage;}
};