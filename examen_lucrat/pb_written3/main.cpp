#include <iostream>
#include <utility>
#include <vector>

template<typename T>
class ToDo {
private:
    std::vector<T> v;
public:
    ToDo() = default;
    void operator+=(const T& obj){
        v.insert(v.begin(), obj);
    }
    auto begin(){
        return v.begin();
    }
    auto end(){
        return v.end();
    }
    void reversePrint(std::ostream &os){
        for(int i = v.size() - 1; i >= 0; i--) {
            os << v[i] << "\n";
        }
    }
};

class Activity {
private:
    std::string description;
    std::string time;
public:
    Activity(std::string description, std::string time) : description(std::move(description)), time(std::move(time)) {}

    friend std::ostream &operator<<(std::ostream &os, const Activity &activity) {
        os << "Activity " << activity.description << " will take place at " << activity.time;
        return os;
    }
};

void ToDoList() {
    ToDo<Activity> todo{};
    Activity tiff{"go to TIFF movie", "20:00"};
    todo += tiff;
    Activity project{"present project assignment", "09.20"};
    todo += project;

    // iterates through the activities and prints them as follows:
    // Activity present project assignment will take place at 09.20.
    // Activity go to TIFF movie will take place at 20.00.
    for (auto a : todo)
        std::cout << a << '\n';

    // Prints the activities as follows:
    // Activity go to TIFF movie will take place at 20.00.
    // Activity present project assignment will take place at 09.20.
    todo.reversePrint(std::cout);
}

int main() {
    ToDoList();
    return 0;
}
