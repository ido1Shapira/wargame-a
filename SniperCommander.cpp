#include "SniperCommander.hpp"
#include <iostream>
#include "Sniper.hpp"

void SniperCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location){
    int row = b.size();
    int col = b[0].size();
    pair<double, Soldier*> toAttack =make_pair(0, nullptr);
    pair<int, int> toAttack_index = make_pair(-1,-1);
    for(int i= 0; i<row; ++i){
        for(int j= 0; j<col; ++j){
            Soldier* s = b[i][j];
            if(s != nullptr) {        
                if(s->get_player_number() != player_number){
                    double d = s->get_health();//distance(location.first, location.second, i, j);
                    if (d > toAttack.first) {
                        toAttack.first = d;
                        toAttack.second = s;
                        toAttack_index.first = i;
                        toAttack_index.second = j;
                    }
                }
            	
           	}
        }
	}
    if( toAttack.second != nullptr) {
                int new_health = toAttack.second->get_health() + damage;
                if(new_health <= 0) { 
                    // delete toAttack.second; 
                    printf("Sniper Commander killed: %p\n", toAttack.second);
                    b[toAttack_index.first][toAttack_index.second] = nullptr;
                }
                else { 
                    printf("Sniper Commander attacking [%d,%d], new heath: %d\n", toAttack_index.first, toAttack_index.second, new_health);
                    b[toAttack_index.first][toAttack_index.second]->set_health(new_health); 
                }
                for(int i= 0; i<row; ++i){
                    for(int j= 0; j<col; ++j){
                        Soldier* s = b[i][j];
                        if(s != nullptr) {        
                            if(s->get_player_number()== player_number){
                                if(Sniper* ps=dynamic_cast<Sniper*>(s)){
						            cout<< "I found a sniper of my in: " << i << " " << j <<endl;
				    	            ps->attack(b, {i,j});
					            }
            	            }
                        }
		            }
	            }
    }
    else {
            printf("There is no one to attack!\n");
    }

 
}
