#include "Sniper.hpp"

void Sniper::attack(vector<vector<Soldier*>> &b, pair<int,int> location){
    int row = b.size();
    int col = b[0].size();
    pair<int,int> spot;
    pair<double, Soldier*> toAttack =make_pair(0, nullptr);
    for(int i= 0; i<row; ++i){
        for(int j= 0; j<col; ++j){
            Soldier* s = b[i][j];
	        if(s != nullptr && s->get_player_number() != player_number){
                double d = s->get_health();//distance(location.first, location.second, i, j);
                if (d > toAttack.first) {
                    toAttack.first = d;
                    toAttack.second = s;
                    spot={i,j};
			    }
            }
        }
    }
    if( toAttack.second != nullptr) {
                int new_health = toAttack.second->get_health() + damage;
                if(new_health <= 0) {
                    printf("I killed: %p\n", toAttack.second);
                    b[spot.first][spot.second]=nullptr;
                    delete toAttack.second;
                    
                }
                else { toAttack.second->set_health(new_health); }
                printf("new_health: %d\n", new_health);
    }
    else {
            printf("There is no one to attack!\n");
    }
}        
