#include "AI_Base.h"




  void AI_Base::all_perms( string tiles, string res, int num, int& counter, vector <string> &all_perms_tiles) 
{
  if(prefixes.find(res) == prefixes.end()) return; //will not recurse further down that prefix check for prefix, but before that check if it is a word also for letters in the middle of the word on the bpard and letters after he placed tile remember to add it to the word search
  
      if(res.size()>0)
     { cout << res <<num<<"Counter is :" << counter<<endl; counter++;}
  
  

  for( int i = 0; i < (int)tiles.length(); i++ )
     {all_perms( string(tiles).erase(i,1), res + tiles[i], i, counter, all_perms_tiles );}
}