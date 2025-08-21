#include <iostream>
#include <memory>
#include <string>
#include <vector>

constexpr int MAX_STUDENTS = 100;

class Student final {
public:
    explicit Student(std::string name, int age) noexcept
        : name_(std::move(name)), age_(age) {}

    std::string GetName() const noexcept { return name_; }
    int GetAge() const noexcept { return age_; }

    void PrintDetails() const {
        std::cout << "Name: " << name_ << ", Age: " << age_ << std::endl;
    }

private:
    std::string name_;
    int age_;
};

void PrintAllStudents(const std::vector<std::unique_ptr<Student>>& students) {
    for (const auto& s : students) {
        if (s != nullptr) {
            s->PrintDetails();
        }
    }
}

int main() {
    std::vector<std::unique_ptr<Student>> students;
    students.reserve(3);

    students.emplace_back(std::make_unique<Student>("Alice", 21));
    students.emplace_back(std::make_unique<Student>("Bob", 22));
    students.emplace_back(st_
