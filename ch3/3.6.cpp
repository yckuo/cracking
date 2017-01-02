/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
using namespace std;

class Animal {
public:
    Animal(string name, int timestamp) : name(name), timestamp(timestamp) {
    }
    string getName() {
        return this->name;
    }
    int getTimeStamp() {
        return this->timestamp;
    }
    bool isOlderThan(Animal a) {
        return this->timestamp < a.getTimeStamp();
    }
protected:
    string name;
    int timestamp;
};

class Dog : public Animal {
public:
    Dog(string name, int timestamp) : Animal(name, timestamp) {
    }
};

class Cat : public Animal {
public:
    Cat(string name, int timestamp) : Animal(name, timestamp) {
    }
};

class AnimalQueue {
public:
    AnimalQueue() : timestamp(0) {
    }

    void Enqueue(string name, bool isDog) {
        if (isDog) dogs.push_back(Dog(name, timestamp));
        else cats.push_back(Cat(name, timestamp));
        timestamp++;
    }

    string DequeueAny() {
        if (dogs.empty() && cats.empty()) return "#";
        string ret = "#";
        if (dogs.empty()) {
            ret = cats.front().getName();
            cats.pop_front();
        } else if (cats.empty()) {
            ret = dogs.front().getName();
            dogs.pop_front();
        } else {
            Dog dog = dogs.front();
            Cat cat = cats.front();
            if (dog.isOlderThan(cat)) {
                ret = dogs.front().getName();
                dogs.pop_front();
            } else {
                ret = cats.front().getName();
                cats.pop_front();
            }
        }
        return ret;
    }

    string DequeueDog() {
        if (dogs.empty()) return "#";
        Dog dog = dogs.front();
        dogs.pop_front();
        return dog.getName();
    }

    string DequeueCat() {
        if (cats.empty()) return "#";
        Cat cat = cats.front();
        cats.pop_front();
        return cat.getName();
    }

private:
    list<Dog> dogs;
    list<Cat> cats;
    int timestamp;
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        AnimalQueue q;
        string token, name;
        int dogOrCat;
        while (iss >> token) {
            if (token == "e") {
                iss >> name >> dogOrCat;
                q.Enqueue(name, dogOrCat == 1);
                cout << "enqueued";
            } else if (token == "a") {
                cout << q.DequeueAny();
            } else if (token == "d") {
                cout << q.DequeueDog();
            } else if (token == "c") {
                cout << q.DequeueCat();
            }
            cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}

