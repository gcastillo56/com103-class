/**
 * filename: noah_queue.cpp
 *
 * In this program we simulate the entrance of Noah's ark
 * and the issues that arise on the first meal of the voyage.
 *
 * @author: gcastillo, 2023
 */

#include <iostream>
#include <queue>
using namespace std;

void display_queue(queue<string>);

int main()
{

    // create a queue of string
    queue<string> animals;

    animals.push("Cat");
    animals.push("Dog");
    animals.push("Fox");
    animals.push("Elephant");
    animals.push("Lion");
    animals.push("Rabbit");
    animals.push("Eagle");

    cout << "Initial Queue: ";
    display_queue(animals);

    // get the element at the front
    string first = animals.front();
    cout << "First animal to eat: " << first << endl;

    // get the element at the back
    string last = animals.back();
    cout << "Last animal to eat: " << last << endl;

    // Cat is gone!
    cout << "The eagle was upset it was the last one and scared the cat!\n";
    animals.pop();

    first = animals.front();
    cout << "New first animal to eat: " << first << endl;

    cout << "Final Queue: ";
    display_queue(animals);

    return 0;
}

// utility function to display queue
void display_queue(queue<string> q)
{
    while (!q.empty())
    {
        cout << q.front() << ", ";
        q.pop();
    }

    cout << endl;
}