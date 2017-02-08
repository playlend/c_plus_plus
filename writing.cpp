// Taras yakovchuk-besarab | writing and reading to a file
#include <iostream>
#include <string>
#include <fstream>

const int SIZE = 60;


int main()
{
	using namespace std;

	
	char fileName[SIZE];
	char txt[SIZE] = ".txt";	
	string text;

	cout << "Please, enter the name of the file you want to create: ";
	cin.getline(fileName, SIZE);
	

  

  ofstream myfile (fileName);
  if (myfile.is_open())
    {
      cout << "Success! File " << fileName << " was created!" << endl;

      cout << "Please, enter the text you want to write to " << fileName << ": ";
      getline(cin, text);

      myfile << text;

      cout << "'" << text << "'" << " was saved to " << fileName << "." << endl;

      myfile.close();

    }
    else
    {
      cout << "Error. File couldn't be open.";

    }

//

  cout << "Please, enter yes if you want to read from the "<< fileName << " file, and no if you don't: ";
  string answer;
  string content;
  cin >> answer;
    if (answer == "Yes" || answer == "yes" || answer == "YES")
      {
        ifstream theFile (fileName);
        if (theFile.is_open())
          {

              while (getline(theFile, content)) {
                cout << content << endl;
        }
            theFile.close();
          }
        else
        {
          cout << "Error. File couldn't be open.";
        }

      }


    else {
      cout << "Thank you!" << endl;

    }








return 0;
}
