#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

// Load names from a file into a queue
void loadQueueFromFile(const string &filename, queue<string> &q) {
    ifstream file(filename);
    string name;
    while (getline(file, name)) {
        if (!name.empty()) {
            q.push(name);
        }
    }
    file.close();
}

// Process queues in cycles of 3 priority / 1 regular, 30 names per day
void processAllQueues(queue<string> priorityq, queue<string> regularq) {
    int day = 1;

    while (!priorityq.empty() || !regularq.empty()) {
        queue<string> tomorrowq;
        int processedCount = 0;

        cout << "Day " << day << " processing:\n";

        // Process up to 30 names per day
        while (processedCount < 30 && (!priorityq.empty() || !regularq.empty())) {
            int pCount = 0, rCount = 0;

            // Process a cycle of 3 priority + 1 regular
            while ((pCount < 3 && !priorityq.empty()) || (rCount < 1 && !regularq.empty())) {
                if (pCount < 3 && !priorityq.empty()) {
                    cout << priorityq.front() << " (priorityq)" << endl;
                    priorityq.pop();
                    pCount++;
                    processedCount++;
                }
                if (rCount < 1 && !regularq.empty()) {
                    cout << regularq.front() << " (regularq)" << endl;
                    regularq.pop();
                    rCount++;
                    processedCount++;
                }
                if (processedCount >= 30) break;
            }
        }

        // Move remaining names to tomorrowq
        while (!priorityq.empty()) { tomorrowq.push(priorityq.front()); priorityq.pop(); }
        while (!regularq.empty()) { tomorrowq.push(regularq.front()); regularq.pop(); }

        // Next day uses tomorrowq
        priorityq = tomorrowq;
        regularq = queue<string>(); // reset regularq
        day++;
        cout << "-------------------------\n";
    }
}

int main() {
    queue<string> priorityq, regularq;

    // Load files
    loadQueueFromFile("priority.txt", priorityq);
    loadQueueFromFile("regular.txt", regularq);

    // Process all queues
    processAllQueues(priorityq, regularq);

    return 0;
}
