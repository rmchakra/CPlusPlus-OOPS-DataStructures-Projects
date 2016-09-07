#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }

  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int constructionspots;
  int *buildingheights;
  string **skyline;
  string curr;

  input >> constructionspots;
  getline(input, curr); 
  //consume the newline character for the first line.
  skyline = new string*[constructionspots];

  //you will need to keep track of the height of each building
  buildingheights = new int[constructionspots];

  for (int i = 0; i < constructionspots; i++) 
  {
     buildingheights[i] = 0;
     skyline[i] = NULL;
  }
  while(getline(input, curr)) 
  {
     stringstream ss;
     ss << curr;
     ss >> curr;
     if (curr == "BUILD") 
     {
        int x,y;
        string c;
        ss >> x;
        ss >> y;
        ss >> c;

        char extra_arg_checker;//checks for extra arguments in line
        if(x<0 || x>= constructionspots || ss.fail())
        {//invalid spot position for the command was made a
          //separate if for each command since 
           //skyline[x] would cause an error in these cases
           //since stream shouldnt fail for everything except extra arguments 
           //(in which case it should fail)
           //fail condition was checked before checking 
          for positive failure of extra arguments
           output << "Error - incorrect command" << endl;
        }
        else if ( ss>>extra_arg_checker|| y<1 || skyline[x] != NULL) 
        {
           output << "Error - incorrect command" << endl;
        }
        else {
                 buildingheights[x]=y;
                 skyline[x] = new string [y];
                 for(int i = 0; i<y; i++)
                 {
                    skyline[x][i] = c;
                 }
              }
     }
     else if (curr == "EXTEND") {
        int x,y;
        string c;
        ss >> x;
        ss >> y;
        ss >> c;

        char extra_arg_checker;

        if(x<0 || x> constructionspots || ss.fail())
        {
           output << "Error - incorrect command" << endl;
        }
        else if (ss>>extra_arg_checker || skyline[x] == NULL || y<1)
        {
           output << "Error - incorrect command" << endl;
        }
        else
        {
           //temp stores coloring scheme of already
           // built floors since the array would be deleted
           //to reallocate memory during extension of the building
           string* temp = new string [buildingheights[x]];
           for(int i = 0; i<buildingheights[x]; i++)
           {
              temp[i] = skyline[x][i];
           }
           delete [] skyline[x];//delete former colors
           buildingheights[x]+=y;//changing to new height
           skyline[x] = new string [buildingheights[x]];
           for(int i=0; i<(buildingheights[x]-y); i++)//copying old floors back
         {
            skyline[x][i] = temp[i];
         }
         for(int i = buildingheights[x]-y ; i< buildingheights[x]; i++)
         {
            skyline[x][i] = c;
         }
            delete [] temp;
        }



     }
     else if (curr == "DEMOLISH") {

          int x;
        ss >> x;
        char extra_arg_checker;

         if(x<0 || x> constructionspots || ss.fail())
        {
           output << "Error - incorrect command" << endl;
        }

        else if ( ss>> extra_arg_checker || skyline[x] == NULL)
         {
           output << "Error - incorrect command" << endl;
        }
        else
           {
              buildingheights[x] = 0;
              delete [] skyline[x];
              skyline[x] = NULL;
              //deleting former floors and then setting it to
              //NULL to prevent bad memory access

           }

     }
     else if (curr == "SKYLINE") 
     {
          int y;
        ss >> y;
        char extra_arg_checker;
        if (ss.fail() || y<1) 
        {//skyline cant be found below the first floor
           output << "Error - incorrect command" << endl;
        }
        else if(ss>> extra_arg_checker)
        {
            output << "Error - incorrect command" << endl;
        }
        else
           {
              for(int i = 0; i< constructionspots; i++)
              {
                 if(buildingheights[i]>=y)
                 {
                    output<<skyline[i][y-1]<<" ";
                    //for skyline at a spot i and height y, 
                    //since array for colors would start from
                    //0, position in y axis would be y - 1
                 }
                 else
                 {
                    output<<"SKY"<<" ";
                 }

              }
              output <<endl;
           }

     }
     else 
     {
        output << "Error - incorrect command" << endl;
     }
  }
  for(int i = 0; i<constructionspots; i++)
  {//freeing allocated data
     delete [] skyline[i];
  }
  delete [] skyline;
  delete [] buildingheights;
  return 0;
}
