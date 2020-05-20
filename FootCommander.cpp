#include "FootCommander.hpp"
#include "FootSoldier.hpp"
void FootCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location) {
        int row = b.size();
        int col = b[0].size();
        pair<double, Soldier*> toAttack =make_pair(distance(0, 0, row-1, col-1) + 1, nullptr);
        for(int i= 0; i<row; ++i){
                for(int j= 0; j<col; ++j){
                        Soldier* s = b[i][j];
                        if(s != nullptr) {        
                                if(s->get_player_number() != player_number){
                                        double d = distance(location.first, location.second, i, j);
                                        if (d < toAttack.first) {
                                                toAttack.first = d;
                                                toAttack.second = s;
                                        }
                                }
                                else {
                                        FootSoldier* ps;
                                        if(ps=dynamic_cast<FootSoldier*> (s))
                                                ps->attack(b, {i,j});
                                }
                }
        }
        int new_health = toAttack.second->get_health() + damage;
        if(new_health <= 0) { delete toAttack.second; toAttack.second = nullptr;}
        else { toAttack.second->set_health(new_health); }
}