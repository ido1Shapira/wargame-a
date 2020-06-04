#include "Board.hpp"
#include "FootSoldier.hpp"
#include <typeinfo>

void FootSoldier::attack(vector<vector<Soldier*>> &b, pair<int,int> location){
        int row = b.size();
        int col = b[0].size();
        pair<double, Soldier*> toAttack =make_pair(distance(0, 0, row-1, col-1) + 1, nullptr);
        pair<int, int> toAttack_index = make_pair(-1,-1);
        for(int i= 0; i<row; ++i){
                for(int j= 0; j<col; ++j){
                        Soldier* s = b[i][j];
                        if(s != nullptr && s->get_player_number() != player_number){
                                double d = distance(location.first, location.second, i, j);
                                if (d <= toAttack.first) {
                                        toAttack.first = d;
                                        toAttack.second = s;
                                        toAttack_index.first = i;
                                        toAttack_index.second = j;
                                }
                        }
                }
        }
        if(toAttack.second != nullptr) {
                int new_health = toAttack.second->get_health() + damage;
                if(new_health <= 0) {
                        printf("Foot Soldier killed: %p\n", toAttack.second);
                        b[toAttack_index.first][toAttack_index.second] = nullptr;
                       // delete toAttack.second;
                }
                else { 
                        printf("Foot Soldier [%d,%d], new heath: %d\n", toAttack_index.first, toAttack_index.second, new_health);
                        b[toAttack_index.first][toAttack_index.second]->set_health(new_health); 
                }
        }
        else {
                printf("There is no one to attack!\n");
        }
}