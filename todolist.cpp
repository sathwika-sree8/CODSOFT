#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void TaskMenu() {
    cout << "\n To-Do List Manager \n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<string> taskDescriptions;       
    vector<bool> taskCompletionStatus;     
    int choice;

    while (true) {
        TaskMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        if (choice == 1) {
            string description;
            cout << "Enter task description: ";
            cin.ignore(); 
            getline(cin, description);
            taskDescriptions.push_back(description);
            taskCompletionStatus.push_back(false); 
            cout << "Task added successfully!\n";
        } 
        else if (choice == 2) {
            if (taskDescriptions.empty()) {
                cout << "No tasks to view\n";
            } else {
                cout << "\nTask List\n";
                for (int i = 0; i < taskDescriptions.size(); i++) {
                    cout << i + 1 << ". " << taskDescriptions[i]
                         << " [" << (taskCompletionStatus[i] ? "Completed" : "Pending") << "]\n";
                }
            }
        } 
        else if (choice == 3) {
            if (taskDescriptions.empty()) {
                cout << "No tasks to mark as completed.\n";
                continue;
            }
            int taskIndex;
            cout << "Enter the task number to mark as completed: ";
            cin >> taskIndex;

            if (cin.fail() || taskIndex < 1 || taskIndex > static_cast<int>(taskDescriptions.size())) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid task number.\n";
            } else {
                taskCompletionStatus[taskIndex - 1] = true;
                cout << "Task marked as completed.\n";
            }
        } 
        else if (choice == 4) {
            if (taskDescriptions.empty()) {
                cout << "No tasks to remove.\n";
                continue;
            }
            int taskIndex;
            cout << "Enter the task number to remove: ";
            cin >> taskIndex;

            if (cin.fail() || taskIndex < 1 || taskIndex > static_cast<int>(taskDescriptions.size())) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid task number.\n";
            } else {
                taskDescriptions.erase(taskDescriptions.begin() + taskIndex - 1);
                taskCompletionStatus.erase(taskCompletionStatus.begin() + taskIndex - 1);
                cout << "Task removed successfully.\n";
            }
        } 
        else if (choice == 5) {
            // Exit
            cout << "Exiting program...\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
