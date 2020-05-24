#include "doctest.h"
#include "Soldier.hpp"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include <string>
using namespace std;
//using namespace WarGame;



namespace WarGame {
	

   Board b(20,20);
   


TEST_CASE("Test replacement of p, f and b") {


   CHECK(!b.has_soldiers(1));
   CHECK(!b.has_soldiers(2));
   for (int i = 0; i < 20; i++) {
     
     b[{5,i}] = new FootSoldier(1);
   //   CHECK_NOTHROW( b[{0,i}] = new FootSoldier(1));
   CHECK(true);
   }
   CHECK(b.has_soldiers(1));
   CHECK(!b.has_soldiers(2));
   for (int i = 0; i < 20; i++) {
     
     b[{15,i}] = new FootSoldier(2);
   //   CHECK_NOTHROW( b[{0,i}] = new FootSoldier(1));
   CHECK(true);
   }
   CHECK(b.has_soldiers(1));
   CHECK(b.has_soldiers(2));

   for (int i = 0; i < 20; i++) {
     b[{0,i}] = new FootSoldier(1);
   //   CHECK_NOTHROW( b[{0,i}] = new FootSoldier(1));
   CHECK(true);
   }
   

   for (int i = 0; i < 20; i++) {
     b[{19,i}] = new FootCommander(2);
   //  b[{16,i}] = new SniperCommander(2);
   //   CHECK_NOTHROW( b[{0,i}] = new FootSoldier(1));
   CHECK(true);
   }
  // printf("IM ok\n");
  // CHECK_NOTHROW(b.move(1, {0,15}, Board::MoveDIR::Up));
   for (int i = 0; i < 15; i++)
   {
    //  printf("%d\n", i);
      if(b.has_soldiers(2) &&b.has_soldiers(1)){
        CHECK_NOTHROW(b.move(1, {0,i}, Board::MoveDIR::Up));

        CHECK_NOTHROW(b.move(2, {15,i}, Board::MoveDIR::Down));
      }
   }
   
   /*
 //  for (int  i = 0; i < 20; i++)
  // {
    //  printf("%d\n", i);
 //     if(b[{0,i}]!=nullptr){
 //        printf("%d and not null", i);
 //       CHECK_NOTHROW(b.move(1, {0,i}, Board::MoveDIR::Up));
      }
      else
      {
         CHECK_THROWS(b.move(1, {0,i}, Board::MoveDIR::Up));
      }
      printf("%d\n", i);
      //}
      if(b[{18,i}]!=nullptr)
         CHECK_NOTHROW(b.move(2, {18,i}, Board::MoveDIR::Down));
      else
      {
         CHECK_THROWS(b.move(2, {18,i}, Board::MoveDIR::Down));
      }
         
   }
   */
   


}

}









// Id of collaborators 208825539 207950577


   
  // Board b(20,20);

   // CHECK(find(text, "haffy") == string("happy"));
//}
