#include "Board.hpp"

using namespace std;

namespace WarGame {

class Board {
  private:
    vector<vector<Soldier*>> board;
  public:
    enum MoveDIR { Up, Down, Right, Left };
    
    Board(uint numRows, uint numCols) : 
    	board(numRows, vector<Soldier*>(numCols, nullptr)) {}

    // operator for putting soldiers on the game-board during initialization.
    Soldier*& operator[](pair<int,int> location) {
    	return board[location.first][location.second];
    }
    
    // operator for reading which soldiers are on the game-board.
    Soldier* operator[](pair<int,int> location) const {
    	return board[location.first][location.second];
    }
    
    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
    void move(uint player_number, pair<int,int> source, MoveDIR direction) {
		Soldier* s = (*this)[source];
		if(s==nullptr || s->get_player_number() != player_number)
			throw invalid_argument("Illegal argument");
		pair<int, int> target;
		switch (direction)
		{
		case Up:
			target= make_pair(source.first-1, source.second);
			break;
		case Down:
			target= make_pair(source.first+1, source.second);
			break;
		case Left:
			target= make_pair(source.first, source.second-1);
			break;
		case Right:
			target= make_pair(source.first, source.second+1);
			break;
		}
		if(target.first >= board.size() || target.first < 0 || target.second >= board.size() || target.second < 0) 
			throw invalid_argument("Out size of the board");
		
		if((*this)[target] != nullptr)
			throw invalid_argument("Target is not null");
		
		(*this)[source] = nullptr;
		(*this)[target] = s;
		s->attack();
    }

    // returns true iff the board contains one or more soldiers of the given player.
    bool has_soldiers(uint player_number) const {
		for(int i= 0; i< board.size(); ++i){
			for(int j=0; j< board[i].size(); ++j) {
				Soldier* s = (*this)[{i, j}];
				if (s != nullptr && s->get_player_number() == player_number)
					return true;
			}
		}
		return false;
    }
};

}