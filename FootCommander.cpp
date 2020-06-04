#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include <iostream>

void FootCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location) {
    int row = b.size();
    int col = b[0].size();
    // if(b[6][0] != nullptr){
    //             printf("from Commander 1: Board[6,0]: player_number: %d, player_health: %d, max_health: %d, damage: %d\n", b[6][0]->get_player_number(), b[6][0]->get_health(), b[6][0]->get_max_health(), b[6][0]->get_damage());
    //     }
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
                	if(FootSoldier* ps=dynamic_cast<FootSoldier*>(s)){
						cout<< "I found a soldier of my in: " << i << " " << j <<endl;
                        // if(b[6][0] != nullptr){
                        //     printf("from Commander 2: Board[6,0]: player_number: %d, player_health: %d, max_health: %d, damage: %d\n", b[6][0]->get_player_number(), b[6][0]->get_health(), b[6][0]->get_max_health(), b[6][0]->get_damage());
                        // }
				    	ps->attack(b, {i,j});
					}
            	}
                printf("i: %d, j: %d, player_number: %d\n", i,j,s->get_player_number());
        	}
		}
	}
    if( toAttack.second != nullptr) {
                int new_health = toAttack.second->get_health() + damage;
                if(new_health <= 0) { delete toAttack.second; toAttack.second = nullptr;}
                else { toAttack.second->set_health(new_health); }
    }
    else {
            printf("There is no one to attack!\n");
    }
}