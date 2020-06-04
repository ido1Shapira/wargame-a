#include "Board.hpp"
#include "FootSoldier.hpp"
#include <typeinfo>

void FootSoldier::attack(vector<vector<Soldier*>> &b, pair<int,int> location){
        int row = b.size();
        int col = b[0].size();
        // if(b[6][0] != nullptr){
        //         printf("Board[6,0]: player_number: %d, player_health: %d, max_health: %d, damage: %d\n", b[6][0]->get_player_number(), b[6][0]->get_health(), b[6][0]->get_max_health(), b[6][0]->get_damage());
        // }
        pair<double, Soldier*> toAttack =make_pair(distance(0, 0, row-1, col-1) + 1, nullptr);
        pair<int, int> toAttack_index = make_pair(0,0);
        for(int i= 0; i<row; ++i){
                for(int j= 0; j<col; ++j){
                        Soldier* s = b[i][j];
                        if(s != nullptr && s->get_player_number() != player_number){
                                double d = distance(location.first, location.second, i, j);
                                if (d < toAttack.first) {
                                        toAttack.first = d;
                                        toAttack.second = s;
                                        toAttack_index.first = i;
                                        toAttack_index.second = j;
                                        printf("i: %d, j: %d\n", i,j);
                                        printf("toAttack 1: first: %f, second: %p, player_number: %d, player_health: %d, max_health: %d, damage: %d\n", toAttack.first, toAttack.second, toAttack.second->get_player_number(), toAttack.second->get_health(), toAttack.second->get_max_health(), toAttack.second->get_damage());
                                }
                        }
                }
        }
        if(toAttack.second->get_player_number() > 2) {
                toAttack.second = nullptr;
        }
        printf("toAttack: first 2: %f, second: %p, player_number: %d, player_health: %d, max_health: %d, damage: %d\n", toAttack.first, toAttack.second, toAttack.second->get_player_number(), toAttack.second->get_health(), toAttack.second->get_max_health(), toAttack.second->get_damage());
        // printf("type: %s\n", typeid(*(toAttack.second)).name());
        if(toAttack.second != nullptr) {
                printf("1\n");
                int new_health = toAttack.second->get_health() + damage;
                printf("2\nnew_health: %d\n", new_health);
                if(new_health <= 0) {
                        printf("2.5\n");
                        delete toAttack.second;
                        b[toAttack_index.first][toAttack_index.second] = nullptr;
                        printf("3\n");
                }
                else { 
                        toAttack.second->set_health(new_health); 
                        printf("4\n");
                }
        }
        else {
                printf("There is no one to attack!\n");
        }
}