// ToDo list | a program that enables to create and modify to do lists
// Taras Yakovchuk-Besarab, 20 May 2016
// CISP 360

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>



using namespace std;




// welcome bonus
void welcome();
// instructions bonus
void instructions();
// main menu bonus
void Menu();

// prompt for task
void Task(string &line, vector <string> &tasks, int &index);

// bonus creating a file for browser output
void CretingFile(int index, vector <string> tasks, int index1, vector <string> tasks1);

// print list
void PrintList(int index, vector <string> tasks);

// bonus mark task as a completed 
void MarkCompleted(int &index, vector <string> &tasks, int &index1, vector <string> &tasks1);



int main()
{
	welcome();
	instructions();
	// vars required for program
	int answer = 0;
	string line;
	string readingTasks;
	string readingTasks1;
  	vector <string> tasks;
	int index = 0;
	
	vector <string> tasks1;	
	int index1 = 0;

// reading first vector
	ifstream myfile ("data.txt");
  	if (myfile.is_open())
 	{
   		 while (getline (myfile,readingTasks) )
    		{
    			tasks.push_back(readingTasks);  
   		}
			index = tasks.size();
   	 	myfile.close();
 	}


// reading second vector
	ifstream myfile1 ("data1.txt");
  	if (myfile1.is_open())
 	{
   		 while (getline (myfile1,readingTasks1) )
    		{
    			tasks1.push_back(readingTasks1);  
   		}
			index1 = tasks1.size();
   	 	myfile1.close();
 	}


//reading

	// go to
	menu:	
	Menu();
	cout << "Please, enter your selection: ";
	cin >> answer;
	cin.clear();
        cin.get(); 
	// main menu
	switch (answer)
	{
		//exit
		case 0:
			break;
		//create a task		
		case 1:
			Task(line, tasks, index);
			
			cout << "Success! The list of tasks was created!";
			cout << endl;
			goto menu;
			break;
		//mark task as completed
		case 2:	
			if (index != 0 )
			{
				PrintList(index, tasks);
				MarkCompleted(index, tasks, index1, tasks1);
				
				cout << "Success!" << endl;
				goto menu;
			}
			else
			{
				cout << "There is no lists! You need to create one before editing or viewing." << endl;
				goto menu;
			}
				
			break;
		// output in the browser
		case 3:
			CretingFile(index, tasks, index1, tasks1);
			system("firefox tasks.html");
			break;
		// output in terminal
		case 4:
		
			system("clear");
			cout << "List of tasks: " << endl;
			PrintList(index, tasks);
			cout << endl;
			cout << "Completed tasks: "<< endl;
			PrintList(index1, tasks1);
			



			goto menu;
			break;
		default:
			cout << "Good Bye!" << endl; 
			break;
	

	}

	
		
		
	
	
	
	//write vector 1
		ofstream theFile("data.txt");
		if (theFile.is_open())
		{
			for(vector<string>::const_iterator i = tasks.begin(); i != tasks.end(); ++i) 
			{
	    		theFile << *i << '\n';
			}
			theFile.close();	
		}
	//write	vector 2
		ofstream theFile1("data1.txt");
		if (theFile1.is_open())
		{
			for(vector<string>::const_iterator i = tasks1.begin(); i != tasks1.end(); ++i) 
			{
	    		theFile1 << *i << '\n';
			}
			theFile1.close();	
		}

	

	// write	
		
	
	
		

cout << endl;	
return 0;
}

// welcome bonus
void welcome()
{
	cout << "Welcome to the program that manages your tasks!" << endl;

}
// instructions bonus
void instructions()
{

	cout << "In order to finish when creating task/s, you have to enter a blank line." << endl;
	cout << "In order to finish when marking task/s completed, you have to enter 0." << endl;
	cout << "Enjoy!" << endl;

}



// main manu bonus
void Menu()
{
	
	cout << endl;	
	cout << "Menu options: " << endl;
	cout << "0. Exit" << endl;
	cout << "1. Create task/s" << endl;
	cout << "2. Mark task/s as completed" << endl;
	cout << "3. View the list in browser" << endl;
	cout << "4. View the list in terminal" << endl;
	cout << endl;

}
// a function for entering tasks
void Task(string &line, vector <string> &tasks, int &index)
{

	cout << "Please, enter a task #" << index+1 << ": ";
	getline(cin,line);
	
	while (!line.empty())
	{
		index++;
		tasks.push_back(line);
		cout << "Please, enter a task #" << index+1 << ": ";
		getline(cin,line);
		
			
	}
	
}
// bonus output in the browser
void CretingFile(int index, vector <string> tasks, int index1, vector <string> tasks1)
{
	ofstream myfile ("tasks.html");
	if (myfile.is_open())
	{
		// html skeleton
		myfile << "<!DOCTYPE html>";
		myfile << "<html>";
		myfile << "<head>";
		myfile << "<title>List of tasks</title>";	
		myfile << "</head>";	
		myfile << "<body style='text-align: left;'>";
		
		// *content	
			myfile << "<h2>List of tasks: </h2>";
			myfile << "<ul>";
			for (int i=0; i<=index-1; i++)
			{		
				myfile << "<li>";
					myfile << tasks[i];
				myfile << "</li>";
			} 
			myfile <<"</ul>";
		// *content	
		// *content	
			myfile << "</ br>";			
			myfile << "<h2>Completed tasks: </h2>";
			myfile << "<ul>";
			for (int i=0; i<=index1-1; i++)
			{		
				myfile << "<li>";
					myfile << tasks1[i];
				myfile << "</li>";
			} 
			myfile <<"</ul>";
		// *content	


		// end html	   
		myfile << "</body>";
		myfile << "</html>";	
		// close the file
	        myfile.close();

    	}
    	
	else
   	{
      
		cout << "Error. File couldn't be open.";

    	}
	

}

// printing results
void PrintList(int index, vector <string> tasks)
{
	for (int i=0; i<=index-1; i++)
	{		
	
	cout << "Task #" << i+1 << ": " << tasks[i] << endl;
	
	}

}

// bonus mark items completed and create separate lists
void MarkCompleted(int &index, vector <string> &tasks, int &index1, vector <string> &tasks1)
{
	int number;	
	int counter;
	
	
	cout << "Please, enter the number of task to mark it completed(enter 0 to finish): ";
	cin >> number;
	while(number != 0)
	{
		
		counter = number - 1;
		
		tasks1.push_back(tasks[counter]);
		index1++;
		tasks.erase(tasks.begin() + counter);
		index--;
		PrintList(index, tasks);
		cout << "Please, enter the number of task to mark it completed(enter 0 to finish): ";
		cin >> number;	
		
	}
}



