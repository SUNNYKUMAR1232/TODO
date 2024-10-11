#include <bits/stdc++.h>
#include "Helper.cpp"
using namespace std;


int main()
{
    /*     newTask("sunny", "10-10-2024", "12");
        newTask("sunnya", "10-10-2024", "12");
        newTask("sunnys", "10-10-2024", "12");
        newTask("sunnyy", "10-10-2024", "12");
        Display();
        displayByName("sunny");
        deleteTask("sunny");
        displayByName("sunny");
        updateTask("sunnya", "sunny", "", "");
        markDone("sunny");
        displayByName("sunny");
        cout<<checkDoneTask("sunny")<<endl;
        cout<<"Total Number of Done Task : "<<count()[0]<<endl;
        cout<<"Total Number of Not Done Task : "<<count()[1]<<endl;
        cout<<"Total Number of Task : "<<count()[2]<<endl;
        cout<<filterTask(true,"")[0].name<<endl;
     */
    int j;
    vector<string> functionName = {"Add Task", "Update Task", "Display Task", "Display Task By Name", "Delete Task By Name", "Erase All Task", "Mark Task Done", "Check Task Done Or Not", "Count Total Number Of Task(done,not,total)", "Filter Task"};
    cout << "========== Welcome To TODO APP ============" << endl;
    for (int i = 0; i < functionName.size(); i++)
    {
        cout << i << ". " << functionName[i] << " : " << endl;
    }

    while (true)
    {
        cout << "Enter the number corresponding to the function you want to execute (or -1 to exit): ";
        cin >> j;
        if (j == -1)
            break;

        switch (j)
        {
        case 0:
        {
            string name, startdate, enddate;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter task satrtdate (dd-mm-yyyy): ";
            getline(cin, startdate);
            cout << "Enter task satrtdate (dd-mm-yyyy): ";
            getline(cin, enddate);
            newTask(name, startdate, enddate);
            break;
        }
        case 1:
        {
            string oldName, newName, startdate, enddate;
            cout << "Enter old task name: ";
            cin >> oldName;
            cout << "Enter new task name (leave blank if no change): ";
            cin.ignore();
            getline(cin, newName);
            cout << "Enter new task startdate (leave blank if no change): ";
            getline(cin, startdate);
            cout << "Enter new task priority (leave blank if no change): ";
            getline(cin, enddate);
            updateTask(oldName, newName, startdate, enddate);
            break;
        }
        case 2:
        {
            Display();
            break;
        }
        case 3:
        {
            string name;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, name);
            displayByName(name);
            break;
        }
        case 4:
        {
            string name;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, name);
            deleteTask(name);
            break;
        }
        case 5:
        {
            EraseAllTask();
            break;
        }
        case 6:
        {
            string name;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, name);
            markDone(name);
            break;
        }
        case 7:
        {
            string name;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, name);
            cout << (checkDoneTask(name) ? "Task is done" : "Task is not done") << endl;
            break;
        }
        case 8:
        {
            cout << "Total Number of Done Tasks: " << count()[0] << endl;
            cout << "Total Number of Not Done Tasks: " << count()[1] << endl;
            cout << "Total Number of Tasks: " << count()[2] << endl;
            break;
        }
        case 9:
        {
            bool done;
            cout << "Enter 1 to filter done tasks, 0 for not done tasks: ";
            cin >> done;
            vector<DataStructure> filteredTasks = filterTask(done, "");
            for (const auto &task : filteredTasks)
            {
                cout << task.name << " " << task.startTime << " " << task.endTime << endl;
            }
            break;
        }
        default:
        {
            cout << "Invalid option. Please try again." << endl;
            break;
        }
        }
    }
}