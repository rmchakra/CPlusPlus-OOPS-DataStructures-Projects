#include <string>
#include <map>
#include <vector>
#include <set>

#include "Move.h"
#include "Dictionary.h"
#include "Board.h"
#include "Player.h"
#include "AbstractAI.h"
#include <iostream>

using std::string;
using std::set;
using std::cout;
using std::endl;
using std::vector;

//take in a constructor with the appropriate name to determine which type of AI to create

class AI_Base: public AbstractAI
{
 public:
  virtual std::string getName()
  {
    return name;
  }
  // returns the name by which the AI would like to be called
 virtual void  initialize (Dictionary* dict)
  {//this just adds all the prefixes to the words
    set <string> all_words = dict->allWords ();
    
       for (std::set<string>::iterator it=all_words.begin(); it!=all_words.end(); ++it)
      {
          string prefix_of_curr_word = "";
          string curr_word = *it;
          for (int j = 0; j < (int)curr_word.size() - 1; ++j)
          {
            prefix_of_curr_word+=curr_word[j];
            //here remember to add curr_word[j] to the set containing each 
            prefixes.insert(prefix_of_curr_word);
          }
      }
  }

  void all_perms( string tiles, string res, int num, int& counter, vector <string> &all_perms_tiles);
/*

  have a for loop that goes through each of the spots. Another for within  where after the first iteration horizontal is false
  and second is true
  Within this have a function call for the permutations of letters and trying to place them at the given spot.
  for the move exceptions use 



  catch (const MoveException& m)



  if the last member of the words from get words is not a word, then check if its not a prefix. If not a prefix then return

  Have a move vector which stores all of the possible moves and have a virtual determine move function which determines the move for each of the different AIs
  Have all_perms take in a vector by reference that places every move in



  For each res cout which is a move of placing that specific permutation of tiles
  propose a move (create the move) of placing one tile (that specific res), and see what words are formed by that move
  . (baord.getwords(move, score_var)) which returns a vector of strings
   Place the get words inside a try block. if a move exception is thrown. If catch is of MoveException type and message
  is occupied then move to next square. Move exception message is out of bounds then treat it same as not a prefix i.e. return and stop that recurtsion of
  increasingly adding tiles 
  Apart from those exceptions if its an exception and is not nowords then then simply ityerate to the next  to the spot
  run a for loop checking if each of those words except the last is a word (part of the dictionary)
  Also check if last member of returned words is a word each time. If it is a word, then create a move and store that move and score
  Also check if last member of returned words is a prefix each time if not then return as has been done
  COORDINATES OF THE PLACEMENET OF THE MOVE BEGIN FROM 1 AND NOT 0 SO BE CAREFUL




  For ? tile iterate through letters from bag usaing initial tile count for all thje possible letters


   Our Board class returns the formed words as a vector, and always puts the 
  "main" word last in the vector, so you can distinguish the crosswords 
  (which must be correct as is) from the main word (which you may add more letters to).

*/


  //PASS IN RES HAVING THE LETTERS TO THE TOP/LEFT BASED ON DIRECTION
    //Each time I recurse is when I'm adding new letters to the string of prefixes
    //INCREMENT THE BOARD POSITION HORIZONTALLY OR VERTICALLY AND HAVE A WHILE THAT KEEPS ADDING LETTERS AT THE BOARD SPOT AS LONG AS
    //THE SPOT IS OCCUPIED.
    //IF THE SPOT IS OFF THE BOARD (>ROWS OR COLUMNS) THEN ALSO RETURN AS NO FURTHER PLACEMENT POSSIBLE 
    //FOR INCREASED LETTERS OF THE STRING
    //IN THE IF INSTEAD OF COUT PUSH BACK INTO THE VECTOR

     
  





  /* you can use this function to do pre-processing, such as 
     constructing maps for fast lookup.
     We will call initilalize on your AI before asking it for its first move. 


//prefixes of all the words in the dictionary. Add to a set



     */

  virtual Move getMove (const Board & board, const Player & player, std::map<char, int> initialTileCount)
  {
    Move m;
    return m;
  }
  /* This will be the main function doing the work.
     You will get the board and player, and have hopefully stored the dictionary.
     You also get a map giving you the initial number of each type of tiles in the bag.
     (The board class allows you to find out how many of each type have been placed.)
     You should return a Move object describing the move your AI wants to make.




     for()//each row
  */

   protected:
    string name;
    set <string> prefixes;
};
