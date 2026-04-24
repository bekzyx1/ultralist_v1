#include <iostream>
#include <curl/curl.h>
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

string url;
string server_output;

std::vector<string> v = {"1", "2", "3"};

fstream file("data_base.txt");

// brute function without wordlist
void brute_force()
{
}

// Show All menu
void allT()
{
    for (string i : v)
    {
        std::cout << i << endl;
    }
}

// Menu---s11
void menu()
{
    std::cout << "+===================+" << endl;
    std::cout << "|                   |" << endl;
    std::cout << "|  1.Add task       |" << endl;
    std::cout << "|  2.Remove task    |" << endl;
    std::cout << "|  3.edit task      |" << endl;
    std::cout << "|  4.show all tasks |" << endl;
    std::cout << "|                   |" << endl;
    std::cout << "+===================+" << endl;
}

int main()
{

    int chose;
    int remove_task;
    int ed_task;
    int red_task;
    string new_task;

    // Menu---s11
    menu();

    std::cout << "chose: ";
    cin >> chose;

    // " a13 "  =  is input for create new choose
    // " s11 "  =  is function for show Menu of choose

    while (chose)
    {

        switch (chose)
        {
        case 1:
            std::cout << chose << endl;
            std::cout << "---Add Task---" << endl;
            std::cout << "new task: ";
            cin >> new_task;
            v.push_back(new_task);
            std::cout << "Task added!" << endl;
            std::cout << "  " << endl;

            // Menu---s11
            menu();

            std::cout << "chose: ";
            cin >> chose; // a13
            break;
        case 2:
            std::cout << "---Remove Task---" << endl;

            allT();
            std::cout << "chose removing num: ";
            cin >> remove_task;

            if (remove_task >= 0 && remove_task < v.size())
            {
                v.erase(v.begin() + remove_task);
            }
            else
            {
                cout << "no this task: " << remove_task << endl;
            }

            std::cout << " " << endl;

            // Menu---s11
            menu();

            std::cout << "chose: ";
            cin >> chose; // a13
            break;
        case 3: // Edit task
            std::cout << "---Edit task---" << endl;
            std::cout << "editing task: ";
            cin >> ed_task; // choose task
            cout << "how to write now: ";
            cin >> new_task; // new task

            v[ed_task] = new_task;

            std::cout << " " << endl;

            // Menu---s11
            menu();

            std::cout << "chose: ";
            cin >> chose; // a13
            break;
        case 4:
            std::cout << "---Show All Task---" << endl;
            allT();
            std::cout << " " << endl;

            // Menu---s11
            menu();

            std::cout << "chose: ";
            cin >> chose; // a13
            break;
        case 0:
            break;
        default:
            std::cout << "[error] chose correct num! " << endl;
            std::cout << "chose: ";
            cin >> chose;
        }
    }

    // allT().f_value(string/int/double/etc)

    for (string fw : v)
    {
        file << fw << endl;
    };

    //  allT();

    std::cout << "\n=== End of Demo ===\n";

    return 0;
}
