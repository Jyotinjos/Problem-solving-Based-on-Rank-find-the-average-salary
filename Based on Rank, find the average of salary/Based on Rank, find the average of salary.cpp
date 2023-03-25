#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Employee {
    string name;
    int number;
    int rank;
    int salary;

public:
    Employee(string n, int num, int r, int s) : name(n), number(num), rank(r), salary(s) {}

    int get_rank() const {
        return rank;
    }

    int get_salary() const {
        return salary;
    }

    const string get_name() const {
        return name;
    }
};

int main() {
    vector<Employee> v{
        Employee { "Charlie", 1, 1, 10000 },
        Employee { "Jim", 2, 2, 8000 },
        Employee { "Jam", 3, 1, 11000 }
    };

    sort(v.begin(), v.end(), [](const Employee& e1, const Employee& e2) {
        return e1.get_rank() < e2.get_rank();
        });

    for (const auto& x : v) {
        std::cout << "Rank- " << x.get_rank() << " : " << x.get_name() << ": " << x.get_salary() << std::endl;
    }

    auto itr = v.begin();
    int sum_avg = itr->get_salary();
    int count = 1;
    int prev_rank = itr->get_rank();

    while (itr != v.end()) {
        ++itr;
        if (itr != v.end() && itr->get_rank() == prev_rank) {
            sum_avg += itr->get_salary();
            ++count;
        }
        else {
            std::cout << "Rank: " << prev_rank << " Average salary: " << sum_avg / count << std::endl;
            if (itr != v.end()) {
                sum_avg = itr->get_salary();
                count = 1;
                prev_rank = itr->get_rank();
            }
        }
    }

    return 0;
}
