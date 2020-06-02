#include "Paramedic.hpp"

void Paramedic::attack(vector<vector<Soldier*>> &b, pair<int,int> location){
    int i=location.first;
    int j= location.second;
    

    if( i>0 && b[i-1][j] != nullptr){
        if(b[i-1][j]->get_player_number()== player_number ) 
            b[i-1][j]->set_health(b[i-1][j]->get_max_health());
    }
    
    if( j<b[0].size()-1 && b[i][j+1] != nullptr){
        if(b[i][j+1]->get_player_number()== player_number ) 
            b[i][j+1]->set_health(b[i][j+1]->get_max_health());
    }
   if(j>0 && b[i][j-1] != nullptr){
       if(b[i][j-1]->get_player_number()== player_number ) 
            b[i][j-1]->set_health(b[i][j-1]->get_max_health());
    }
    if(i<b[0].size() && b[i+1][j] != nullptr){
        if(b[i+1][j]->get_player_number()== player_number ) 
            b[i+1][j]->set_health(b[i+1][j]->get_max_health());
    }
    try{
        if(b[i+1][j+1] != nullptr){
        if(b[i+1][j+1]->get_player_number()== player_number ) 
            b[i+1][j+1]->set_health(b[i+1][j+1]->get_max_health());
            }
    }
    catch(exception &e){}

    try{
        if(b[i-1][j-1] != nullptr){
        if(b[i-1][j-1]->get_player_number()== player_number ) 
            b[i-1][j-1]->set_health(b[i-1][j-1]->get_max_health());
            }
    }
    catch(exception &e){}

    try{
        if(b[i+1][j-1] != nullptr){
        if(b[i+1][j-1]->get_player_number()== player_number ) 
            b[i+1][j-1]->set_health(b[i+1][j-1]->get_max_health());
            }
    }
    catch(exception &e){}

    try{
        if(b[i-1][j+1] != nullptr){
        if(b[i-1][j+1]->get_player_number()== player_number ) 
            b[i-1][j+1]->set_health(b[i-1][j+1]->get_max_health());
            }
    }
    catch(exception &e){}
    
}      
