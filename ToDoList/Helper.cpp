#include <bits/stdc++.h>
#include "DataStructure.cpp"
using namespace std;

vector<DataStructure> store;

void print(DataStructure &it)
{
    string Mark = it.flag ? "Done" : "Not Done";
    cout << "------------------------------------" << endl;
    cout << "Name : " << it.name << endl;
    cout << "Done : " << Mark << endl;
    cout << "StartTime : " << it.startTime << endl;
    cout << "EndTime : " << it.endTime << endl;
}
void newTask(string name, string startTime, string endTime)
{
    DataStructure Node;
    Node.name = name;
    Node.flag = false;
    Node.startTime = startTime;
    Node.endTime = endTime;
    store.push_back(Node);
}
void markDone(string name)
{
    for (auto &it : store)
    {
        if (it.name == name)
        {
            it.flag = true;
        }
    }
}
void Display()
{
    for (auto &it : store)
    {
        print(it);
    }
}
void displayByName(string name)
{
    vector<DataStructure> temp;
    for (auto &it : store)
    {
        if (it.name == name)
        {
            temp.push_back(it);
        }
    }
    if (temp.empty())
        cout << "Not Found" << endl;
    for (auto &it : temp)
    {
        print(it);
    }
}

void deleteTask(string name)
{
    int pos;
    int n = store.size();
    for (int i = 0; i < n; i++)
    {
        if (store[i].name == name)
        {
            store.erase(store.begin() + i);
        }
    }
}
void EraseAllTask()
{
    store.clear();
}

void updateTask(string oldName, string name, string startTime, string endTime)
{

    for (auto &it : store)
    {
        if (it.name == oldName)
        {
            DataStructure Node = it;
            if (name != "")
            {
                it.name = name;
            }
             if (startTime != "")
            {
                it.startTime = startTime;
            }
            if (endTime != "")
            {
                it.endTime = endTime;
            }
        }
    }
}

vector<DataStructure> filterTask(bool flag, string name)
{
    vector<DataStructure> temp;
    for (auto &it : store)
    {
        if (name != "")
        {
            if (it.name == name)
                temp.push_back(it);
        }
        else
        {
            if (it.flag == flag)
                temp.push_back(it);
        }
    }
    return temp;
}
bool checkDoneTask(string name)
{
    for (auto &it : store)
    {
        if (it.name == name && it.flag == true)
        {
            return true;
        }
    }
    return false;
}

vector<int> count()
{
    int cntDone = 0;
    int total = store.size();
    for (auto &it : store)
    {
        if (it.flag)
        {
            cntDone++;
        }
    }
    return {cntDone, total - cntDone, total};
}
