#include "SniperCommander.hpp"
#include <iostream>
#include "Sniper.hpp"

void SniperCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location){
    int row = b.size();
    int col = b[0].size();
    pair<double, Soldier*> toAttack =make_pair(MAXFLOAT, nullptr);
    for(int i= 0; i<row; ++i){
        for(int j= 0; j<col; ++j){
            Soldier* s = b[i][j];
            if(s != nullptr) {        
                if(s->get_player_number() != player_number){
                    double d = s->get_health();//distance(location.first, location.second, i, j);
                    if (d < toAttack.first) {
                        toAttack.first = d;
                        toAttack.second = s;
                    }
                }
            	else {
                    if(Sniper* ps=dynamic_cast<Sniper*>(s)){
						cout<< "I found a soldier of my in: " << i << " " << j <<endl;
				    	ps->attack(b, {i,j});
					}
            	}
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
