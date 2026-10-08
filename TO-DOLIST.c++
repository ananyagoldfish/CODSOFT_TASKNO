#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a single task
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void addTask(vector<Task>& todoList);
void viewTasks(const vector<Task>& todoList);
void markTaskCompleted(vector<Task>& todoList);
void removeTask(vector<Task>& todoList);

int main() {
    vector<Task> todoList;
    int choice;

    do {
        cout << "\n===============================\n";
        cout << "       TO-DO LIST MANAGER      \n";
        cout << "===============================\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Clear input buffer
        cin.ignore();

        switch (choice) {
            case 1:
                addTask(todoList);
                break;

            case 2:
                viewTasks(todoList);
                break;

            case 3:
                markTaskCompleted(todoList);
                break;

            case 4:
                removeTask(todoList);
                break;

            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

// Function to add a task
void addTask(vector<Task>& todoList) {
    Task newTask;

    cout << "Enter the task description: ";
    getline(cin, newTask.description);

    newTask.completed = false;

    todoList.push_back(newTask);

    cout << "Task added successfully!\n";
}

// Function to display tasks
void viewTasks(const vector<Task>& todoList) {
    if (todoList.empty()) {
        cout << "Your to-do list is empty.\n";
        return;
    }

    cout << "\n--- Your Tasks ---\n";

    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". ["
             << (todoList[i].completed ? "Completed" : "Pending")
             << "] "
             << todoList[i].description << "\n";
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& todoList) {
    if (todoList.empty()) {
        cout << "No tasks available to mark as completed.\n";
        return;
    }

    viewTasks(todoList);

    int taskNumber;

    cout << "Enter the number of the task to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 &&
        static_cast<size_t>(taskNumber) <= todoList.size()) {

        todoList[taskNumber - 1].completed = true;

        cout << "Task marked as completed!\n";
    }
    else {
        cout << "Invalid task number!\n";
    }
}

// Function to remove a task
void removeTask(vector<Task>& todoList) {
    if (todoList.empty()) {
        cout << "No tasks available to remove.\n";
        return;
    }

    viewTasks(todoList);

    int taskNumber;

    cout << "Enter the number of the task to remove: ";
    cin >> taskNumber;

    if (taskNumber > 0 &&
        static_cast<size_t>(taskNumber) <= todoList.size()) {

        todoList.erase(todoList.begin() + (taskNumber - 1));

        cout << "Task removed successfully!\n";
    }
    else {
        cout << "Invalid task number!\n";
    }
}