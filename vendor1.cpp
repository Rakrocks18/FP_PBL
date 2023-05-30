#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> d1 = {{"Sweet chilli chicken wrap", 80},
                                 {"salad wrap", 70},
                                 {"chicken caesar wrap", 80},
                                 {"chicken mayo wrap", 90},
                                 {"chicken salad wrap", 90},
                                 {"mexican wrap", 90},
                                 {"chicken barbeque wrap", 100}};

unordered_map<string, int> d2 = {{"salad bread roll", 50},
                                 {"egg and lettuce", 60},
                                 {"chicken and mayo bread roll", 60},
                                 {"hot and spicy chicken schnitzel bread roll", 70},
                                 {"hot chicken gravy bread roll", 70}};

unordered_map<string, int> d3 = {{"cheese and tomato sandwich", 40},
                                 {"chicken and cheese", 50},
                                 {"tuna sandwich", 60},
                                 {"chicken lettuce and mayo sandwich", 60},
                                 {"chicken caesar sandwich", 70},
                                 {"vegan sandwich", 55}};

unordered_map<string, int> d4 = {{"Chicken Burger", 120},
                                 {"Veg Burger", 100},
                                 {"Fries", 60},
                                 {"Aloo Tikki Burger", 90},
                                 {"Spicy Chicken Burger", 130},
                                 {"Spicy Veg Burger", 110}};

unordered_map<string, int> d5 = {{"Butter Chicken Rice", 150},
                                 {"Pasta Red Sauce", 140},
                                 {"Pasta White Sauce", 140},
                                 {"Roasted Veggies Pasta", 120},
                                 {"Fried Rice", 90},
                                 {"Veg Kebab", 70},
                                 {"Harabhara Kebab", 80}};

unordered_map<string, int> d6 = {{"Fruit Bowl", 40},
                                 {"Muffins", 30},
                                 {"Chicken Wrap", 80},
                                 {"Veg Wrap", 70},
                                 {"Veg Club Sandwich", 40}};

vector<string> l1 = {"Sweet chilli chicken wrap", "salad wrap", "chicken caesar wrap",
                     "chicken mayo wrap", "chicken salad wrap", "mexican wrap", "chicken barbeque wrap"};

vector<string> l2 = {"salad bread roll", "egg and lettuce", "chicken and mayo bread roll",
                     "hot and spicy chicken schnitzel bread roll", "hot chicken gravy bread roll"};

vector<string> l3 = {"cheese and tomato sandwich", "chicken and cheese", "tuna sandwich",
                     "chicken lettuce and mayo sandwich", "chicken caesar sandwich", "vegan sandwich"};

vector<string> l4 = {"Chicken Burger", "Veg Burger", "Fries", "Aloo Tikki Burger",
                     "Spicy Chicken Burger", "Spicy Veg Burger"};

vector<string> l5 = {"Butter Chicken Rice", "Pasta Red Sauce", "Pasta White Sauce",
                     "Roasted Veggies Pasta", "Fried Rice", "Veg Kebab", "Harabhara Kebab"};

vector<string> l6 = {"Fruit Bowl", "Muffins", "Chicken Wrap", "Veg Wrap", "Veg Club Sandwich"};

class Canteen {
private:
    static int t2;
    static int t4;
    static int t6;
    static int t8;

public:
    static void getSeating() {
        int s2, s4, s6, s8;
        cout << "Enter the number of available 2-seater tables: ";
        cin >> s2;
        t2 = s2;

        cout << "Enter the number of available 4-seater tables: ";
        cin >> s4;
        t4 = s4;

        cout << "Enter the number of available 6-seater tables: ";
        cin >> s6;
        t6 = s6;

        cout << "Enter the number of available 8-seater tables: ";
        cin >> s8;
        t8 = s8;
    }

    static void menu() {
        cout << "Menu for the canteen: " << endl;
        cout << "1. Wraps" << endl;
        cout << "2. Bread Rolls" << endl;
        cout << "3. Sandwiches" << endl;
        cout << "4. Burgers" << endl;
        cout << "5. Rice and Pasta" << endl;
        cout << "6. Snacks" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                orderItems("wraps", l1, d1);
                break;
            case 2:
                orderItems("bread rolls", l2, d2);
                break;
            case 3:
                orderItems("sandwiches", l3, d3);
                break;
            case 4:
                orderItems("burgers", l4, d4);
                break;
            case 5:
                orderItems("rice and pasta", l5, d5);
                break;
            case 6:
                orderItems("snacks", l6, d6);
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }

    static void orderItems(const string& category, const vector<string>& items, const unordered_map<string, int>& prices) {
        cout << "Items available in the " << category << " category: " << endl;
        for (int i = 0; i < items.size(); ++i) {
            cout << i + 1 << ". " << items[i] << " - " << prices.at(items[i]) << endl;
        }

        int total_sum = 0;
        vector<string> orders;

        int num_items;
        cout << "Enter the number of items you want to order: ";
        cin >> num_items;

        while (num_items > 0) {
            int n;
            cout << "Enter the item index you want to order: ";
            cin >> n;

            if (n >= 1 && n <= items.size()) {
                n -= 1;
                num_items -= 1;
                cout << "Your chosen item is " << items[n] << " with price " << prices.at(items[n]) << endl;
                orders.push_back(items[n]);
                total_sum += prices.at(items[n]);
            } else {
                cout << "Invalid item index." << endl;
            }
        }

        cout << "The total cost of the order is " << total_sum << endl;
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
