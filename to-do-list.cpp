#include <iostream>
#include <string>
using namespace std;

void displayTask(string tasks[], int count)
{
    system("clear");
    cout << "<<< - To Do List - >>>" << endl;
    cout << "----------------------" << endl;
    for(int i=0; i<count; i++)
    {
        cout << "Task ID -> " << i << " | " << tasks[i] << endl;
        cout << "----------------------" << endl;
    }
}

int main ()
{
    int del = 0 ;
    int choice;
    int count = 0;
    string tasks[15] = {""} ;
    do {
        cout << "<<< --- TO DO LIST --- >>>" << endl;
        cout << "1 - Add a New To Do" << endl;
        cout << "2 - View To Do List " << endl;
        cout << "3 - Delete Completed Tasks" << endl;
        cout << "4 - Exit " << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: 
                cout << "<<< --- Add a New To Do  --- >>>" << endl;
                {
                    if(count > 15)
                    {
                        cout << "<<< To Do List is FULL Please delete completed tasks. >>> " << endl;
                    }
                    else
                    {
                        cout << "Enter a new To Do : ";
                        cin.ignore();
                        getline(cin,tasks[count]);
                        count++;
                        system("clear");
                        cout << "New to do has been added.\n" << endl;
                    }
                }
                break;
            case 2:
                displayTask(tasks,count);
                break;
            case 3:
                system("clear");
                displayTask(tasks,count);
                cout << "<<< --- Delete  --- >>>\n"<< endl;
                cout << "Enter the ID of the item you want to delete (0 - 15): ";
                cin >> del;
                if (del<0 || del>15)
                {
                    cout << "You entered INVALID Task ID" << endl;
                    break;
                }
                for (int i = del; i<count; i++ )
                {
                    tasks[i] = tasks[i+1];

                }
                count--;
                break;
            case 4:
                system("clear");
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Please enter a correct choice " << endl;
                break;
        }
    } while(choice != 4);
    
    return 0;
}