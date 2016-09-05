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
  getline(input, curr); //consume the newline character for the first line.
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
		  if (ss.fail() || skyline[x] != NULL || x<0 || x> constructionspots || y<1) 
		  {
			  output << "Error - incorrect command BUILD" << endl;
			  			  //ss.clear(); - try with and without
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
		  if (ss.fail() || skyline[x] == NULL)
		   {
			  output << "Error - incorrect command extend" << endl;
			  			  ss.clear(); //- try with and without
		  	}
		  	else
		  	{
		  		
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
		  if (ss.fail() || skyline[x] == NULL)
		   {
			  output << "Error - incorrect command DEMOLISH" << endl;
			  			  //ss.clear(); - try with and without
		  }
		  else
		  	{
		  		buildingheights[x] = 0;
		  		delete [] skyline[x];
		  		skyline[x] = NULL;

		  	}

	  }
	  else if (curr == "SKYLINE") 
	  {
	  	  int y;
		  ss >> y;
		  if (ss.fail() || y<1) 
		  {
			  output << "Error - incorrect command sky" << endl;
			  			  //ss.clear(); - try with and without
		  }
		  else
		  	{
		  		for(int i = 0; i< constructionspots; i++)
		  		{
		  			if(buildingheights[i]>=y)
		  			{
		  				output<<skyline[i][y-1]<<" ";
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
	  	output << "Error - incorrect command none" << endl;
	  }
  }
  for(int i = 0; i<constructionspots; i++)
  {
  	delete [] skyline[i];
  }
  delete [] skyline;
  delete [] buildingheights;
  return 0;
}
