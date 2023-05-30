#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Seating {
private:
    map<int, int> v2;
    map<int, int> v4;
    map<int, int> v6;
    map<int, int> v8;
    int token_no;

public:
    Seating(int t2, int t4, int t6, int t8) : token_no(0) {
        for (int tables = 0; tables < t2; tables++) {
            v2[tables] = 2;
        }
        for (int tables = 0; tables < t4; tables++) {
            v4[tables] = 4;
        }
        for (int tables = 0; tables < t6; tables++) {
            v6[tables] = 6;
        }
        for (int tables = 0; tables < t8; tables++) {
            v8[tables] = 8;
        }
    }

    int assignTables(int t2, int t4, int t6, int t8, int numpeople) {
        vector<int> vacancy_checker;
        for (const auto& pair : v2) {
            vacancy_checker.push_back(pair.second);
        }
        for (const auto& pair : v4) {
            vacancy_checker.push_back(pair.second);
        }
        for (const auto& pair : v6) {
            vacancy_checker.push_back(pair.second);
        }
        for (const auto& pair : v8) {
            vacancy_checker.push_back(pair.second);
        }

        if (*max_element(vacancy_checker.begin(), vacancy_checker.end()) == 0) {
            return 0;
        }

        if (numpeople <= *max_element(v2.begin(), v2.end(), [](const auto& p1, const auto& p2) {
            return p1.second < p2.second;
        })->second) {
            auto table = find_if(v2.begin(), v2.end(), [](const auto& p) {
                return p.second == *max_element(v2.begin(), v2.end(), [](const auto& p1, const auto& p2) {
                    return p1.second < p2.second;
                })->second;
            });
            table->second -= numpeople;
            int table_number = distance(v2.begin(), table) + 1;
            return table_number;
        }

        if (numpeople <= *max_element(v4.begin(), v4.end(), [](const auto& p1, const auto& p2) {
            return p1.second < p2.second;
        })->second) {
            auto table = find_if(v4.begin(), v4.end(), [](const auto& p) {
                return p.second == *max_element(v4.begin(), v4.end(), [](const auto& p1, const auto& p2) {
                    return p1.second < p2.second;
                })->second;
            });
            table->second -= numpeople;
            int table_number = distance(v4.begin(), table) + 1 + t2;
            return table_number;
        }

        if (numpeople <= *max_element(v6.begin(), v6.end(), [](const auto& p1, const auto& p2) {
            return p1.second < p2.second;
        })->second) {
            auto table = find_if(v6.begin(), v6.end(), [](const auto& p) {
                return p.second == *max_element(v6.begin(), v6.end(), [](const auto& p1, const auto& p2) {
                    return p1.second < p2.second;
                })->second;
            });
            table->second -= numpeople;
            int table_number = distance(v6.begin(), table) + 1 + t4 + t2;
            return table_number;
        }

        if (numpeople <= *max_element(v8.begin(), v8.end(), [](const auto& p1, const auto& p2) {
            return p1.second < p2.second;
        })->second) {
            auto table = find_if(v8.begin(), v8.end(), [](const auto& p) {
                return p.second == *max_element(v8.begin(), v8.end(), [](const auto& p1, const auto& p2) {
                    return p1.second < p2.second;
                })->second;
            });
            table->second -= numpeople;
            int table_number = distance(v8.begin(), table) + 1 + t2 + t4 + t6;
            return table_number;
        }

        return 0;
    }

    int getToken() {
        return ++token_no;
    }
};

class Canteen {
private:
    static int t2;
    static int t4;
    static int t6;
    static int t8;

public:
    static void getSeating() {
        cout << "Enter the number of 2 people sittings: ";
        cin >> t2;
        cout << "Enter the number of 4 people sittings: ";
        cin >> t4;
        cout << "Enter the number of 6 people sittings: ";
        cin >> t6;
        cout << "Enter the number of 8 people sittings: ";
        cin >> t8;
    }

    static void menu() {
        map<int, string> ind = {
            {1, "9:00"},
            {2, "9:45"},
            {3, "10:30"},
            {4, "11:15"},
            {5, "12:00"},
            {6, "12:45"},
            {7, "1:30"},
            {8, "2:15"},
            {9, "3:00"},
            {10, "3:45"},
            {11, "4:30"},
            {12, "5:15"}
        };

        vector<Seating> seats_at_slot;
        for (int slots = 0; slots < ind.size(); slots++) {
            seats_at_slot.emplace_back(Seating(t2, t4, t6, t8));
        }

        while (true) {
            string day;
            cout << "Enter the day: ";
            cin >> day;

            cout << "Enter the time slot among the following by index: " << endl;
            for (const auto& pair : ind) {
                cout << pair.first << ": " << pair.second << endl;
            }
            int time_slot;
            cin >> time_slot;

            string name;
            cout << "Enter your name: ";
            cin >> name;

            int nos_people;
            cout << "Enter the number of customers: ";
            cin >> nos_people;

            int tableState = seats_at_slot[time_slot - 1].assignTables(t2, t4, t6, t8, nos_people);
            if (tableState != 0) {
                vector<string> data_read;
                data_read.push_back(name);
                data_read.push_back(to_string(nos_people));
                data_read.push_back(to_string(tableState));
                data_read.push_back(ind[time_slot]);
                data_read.push_back(to_string(seats_at_slot[time_slot - 1].getToken()));

                vector<string> order_data = takeOrder(day);
                data_read.insert(data_read.end(), order_data.begin(), order_data.end());

                ofstream fname("orders.txt", ios::app);
                if (fname.is_open()) {
                    for (const auto& item : data_read) {
                        fname << item << " ";
                    }
                    fname << endl;
                    fname.close();
                }
                else {
                    cout << "Unable to open file." << endl;
                }
            }
            else {
                cout << "The tables for the timeslot are full." << endl;
            }

            for (const auto& item : data_read) {
                cout << item << " ";
            }
            cout << endl;
        }
    }

    static vector<string> takeOrder(const string& day) {
        int total_sum = 0;
        vector<string> orders;
        if (day == "monday") {
            cout << l1 << endl;
            int num_items;
            cout << "Enter the number of items you want to order: ";
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n < l1.size()) {
                    n -= 1;
                    num_items -= 1;
                    cout << "Your chosen item is " << l1[n] << " with price " << d1[l1[n]] << endl;
                    orders.push_back(l1[n]);
                    total_sum += d1[l1[n]];
                }
                else {
                    cout << "Your input exceeds the number of items." << endl;
                }
            }
        }
        else if (day == "tuesday") {
            cout << l2 << endl;
            int num_items;
            cout << "Enter the number of items you want to order: ";
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n < l2.size()) {
                    n -= 1;
                    num_items -= 1;
                    cout << "Your chosen item is " << l2[n] << " with price " << d2[l2[n]] << endl;
                    orders.push_back(l2[n]);
                    total_sum += d2[l2[n]];
                }
                else {
                    cout << "Your input exceeds the number of items." << endl;
                }
            }
        }
        else if (day == "wednesday") {
            cout << l3 << endl;
            int num_items;
            cout << "Enter the number of items you want to order: ";
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n < l3.size()) {
                    n -= 1;
                    num_items -= 1;
                    cout << "Your chosen item is " << l3[n] << " with price " << d3[l3[n]] << endl;
                    orders.push_back(l3[n]);
                    total_sum += d3[l3[n]];
                }
                else {
                    cout << "Your input exceeds the number of items." << endl;
                }
            }
        }
        else if (day == "thursday") {
            cout << l4 << endl;
            int num_items;
            cout << "Enter the number of items you want to order: ";
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n < l4.size()) {
                    n -= 1;
                    num_items -= 1;
                    cout << "Your chosen item is " << l4[n] << " with price " << d4[l4[n]] << endl;
                    orders.push_back(l4[n]);
                    total_sum += d4[l4[n]];
                }
                else {
                    cout << "Your input exceeds the number of items." << endl;
                }
            }
        }
        else if (day == "friday") {
            cout << l5 << endl;
            int num_items;
            cout << "Enter the number of items you want to order: ";
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n < l5.size()) {
                    n -= 1;
                    num_items -= 1;
                    cout << "Your chosen item is " << l5[n] << " with price " << d5[l5[n]] << endl;
                    orders.push_back(l5[n]);
                    total_sum += d5[l5[n]];
                }
                else {
                    cout << "Your input exceeds the number of items." << endl;
                }
            }
        }

        cout << "The total cost of the order is " << total_sum << endl;
        return orders;
    }
};

int Canteen::t2 = 0;
int Canteen::t4 = 0;
int Canteen::t6 = 0;
int Canteen::t8 = 0;

int main() {
    Canteen::getSeating();
    Canteen::menu();
    return 0;
}
