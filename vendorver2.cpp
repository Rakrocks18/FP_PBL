#include <iostream> // input/output input-output stream
#include <vector>   //python lists/dynamic arrays
#include <unordered_map> //C++ Dictionaries
#include <string>   //c++ string operations (strcpy,strcat)
#include <fstream>  //file operations, full form - file stream
#include <algorithm>    //basic algorithms maximum or minimum element, sorting algorithms, searching algorithms

using namespace std;

unordered_map<string, int> d1 = {{"Sweet chilli chicken wrap", 80},
                                 {"Salad wrap", 70},
                                 {"Chicken caesar wrap", 80},
                                 {"Chicken mayo wrap", 90},
                                 {"Chicken salad wrap", 90},
                                 {"Mexican wrap", 90},
                                 {"Chicken Wrap", 80},
                                 {"Veg Wrap", 70},
                                 {"Chicken barbeque wrap", 100},
                                 {"Veg Kebab", 70},
                                 {"Harabhara Kebab", 80}};

unordered_map<string, int> d2 = {{"Salad bread roll", 50},
                                 {"Egg and lettuce roll", 60},
                                 {"Chicken and mayo bread roll", 60},
                                 {"Hot and spicy chicken schnitzel bread roll", 70},
                                 {"Hot chicken gravy bread roll", 70}};

unordered_map<string, int> d3 = {{"Cheese and tomato sandwich", 40},
                                 {"Chicken and cheese", 50},
                                 {"Tuna sandwich", 60},
                                 {"Chicken lettuce and mayo sandwich", 60},
                                 {"Chicken caesar sandwich", 70},
                                 {"Vegan sandwich", 55},
                                 {"Veg Club Sandwich", 40}};

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
                                 {"Fried Rice", 90}
                                 };

unordered_map<string, int> d6 = {{"Fruit Bowl", 40},
                                 {"Muffins", 30},
                                 {"Pastry", 30}
                                 };

vector<string> l1;
vector<string> l2;
vector<string> l3;
vector<string> l4;
vector<string> l5;
vector<string> l6;

class Seating {
private:
    unordered_map<int, int> v2; //.first , .second
    unordered_map<int, int> v4;
    unordered_map<int, int> v6;
    unordered_map<int, int> v8;
    
public:
    int token_no;
    Seating(int t2, int t4, int t6, int t8) {
        for (int tables = 0; tables < t2; tables++) {
            v2[tables] = 2;
        } //{{0,2},{1,2},{2,2}}
        for (int tables = 0; tables < t4; tables++) {
            v4[tables] = 4;
        }
        for (int tables = 0; tables < t6; tables++) {
            v6[tables] = 6;
        }
        for (int tables = 0; tables < t8; tables++) {
            v8[tables] = 8;
        }
        token_no = 0;
    }

    int assignTables(int t2, int t4, int t6, int t8, int numpeople) {
        vector<int> vacancy_checker;
        for (auto& kv : v2) {
            vacancy_checker.push_back(kv.second); //vacany_checker = {2,2,2}
        }
        for (auto& kv : v4) {
            vacancy_checker.push_back(kv.second); //vacany_checker = {2,2,2,4,4,4}
        }
        for (auto& kv : v6) {
            vacancy_checker.push_back(kv.second);
        }
        for (auto& kv : v8) {
            vacancy_checker.push_back(kv.second);
        }

        if (*max_element(vacancy_checker.begin(), vacancy_checker.end()) == 0) { //no seats are free , canteen is full
            return 0;
        }

        //assigns table in ascending order based on the number of people who have come

        if (numpeople <= max_element(v2.begin(), v2.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second) 
        {
            auto it = max_element(v2.begin(), v2.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
            int table = it->first;
            if((numpeople < v2[table])&& (numpeople >= min_element(v2.begin(), v2.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second))
            {
                it = min_element(v2.begin(), v2.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
                table = it->first;
            }
            v2[table] -= numpeople;
            int table_number = table + 1;
            return table_number;
        }

        if (numpeople <= max_element(v4.begin(), v4.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second) 
        {
            auto it = max_element(v4.begin(), v4.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
            int table = it->first;
            if((numpeople < v4[table])&& (numpeople >= min_element(v4.begin(), v4.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second))
            {
                it = min_element(v4.begin(), v4.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
                table = it->first;
            }
            v4[table] -= numpeople;
            int table_number = table + 1 + t2;
            return table_number;
        }

        if (numpeople <= max_element(v6.begin(), v6.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second) 
        {
            auto it = max_element(v6.begin(), v6.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
            int table = it->first;
            if((numpeople < v6[table])&& (numpeople >= min_element(v6.begin(), v6.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second))
            {
                it = min_element(v6.begin(), v6.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
                table = it->first;
            }
            v6[table] -= numpeople;
            int table_number = table + 1 + t4 + t2;
            return table_number;
        }

        if (numpeople <= max_element(v8.begin(), v8.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second) 
        {
            auto it = max_element(v8.begin(), v8.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
            int table = it->first;
            if((numpeople < v8[table])&& (numpeople >= min_element(v8.begin(), v8.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second))
            {
                it = min_element(v8.begin(), v8.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
                table = it->first;
            }
            v8[table] -= numpeople;
            int table_number = table + 1 + t2 + t4 + t6;
            return table_number;
        }

        return 0;
    }

    int get_token() {
        token_no++;
        return token_no;
    }
};

class Canteen{
    
public:
    int t2, t4, t6, t8;
    Canteen() {
            cout << "Enter the number of 2 people sittings: ";
        cin >> t2;
        cout << "Enter the number of 4 people sittings: ";
        cin >> t4;
        cout << "Enter the number of 6 people sittings: ";
        cin >> t6;
        cout << "Enter the number of 8 people sittings: ";
        cin >> t8;
    }



   


    vector<string> takeOrder(const string& cuisine) {
        vector<string> orders;
        int total_sum = 0;

        if (cuisine == "wraps" || cuisine == "Wraps" || cuisine == "1") {
            for (int i = 0; i < l1.size(); i++) {
                cout << i + 1 << ". " << l1[i] << endl;
            }
            cout << "Enter the number of items you want to order: ";
            int num_items;
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n <= l1.size()) {
                    n--;
                    num_items--;
                    cout << "Your chosen item is " << l1[n] << " with price " << d1[l1[n]] << endl;
                    orders.push_back(l1[n]);
                    total_sum += d1[l1[n]];
                }
                else {
                    cout << "Your input exceeds the number of items" << endl;
                }
            }
        }
        else if (cuisine == "rolls" || cuisine == "Rolls" || cuisine == "2") {
            for (int i = 0; i < l2.size(); i++) {
                cout << i + 1 << ". " << l2[i] << endl;
            }
            cout << "Enter the number of items you want to order: ";
            int num_items;
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n <= l2.size()) {
                    n--;
                    num_items--;
                    cout << "Your chosen item is " << l2[n] << " with price " << d2[l2[n]] << endl;
                    orders.push_back(l2[n]);
                    total_sum += d2[l2[n]];
                }
                else {
                    cout << "Your input exceeds the number of items" << endl;
                }
            }
        }
        else if (cuisine == "sandwiches" || cuisine == "Sandwiches" || cuisine == "3") {
            for (int i = 0; i < l3.size(); i++) {
                cout << i + 1 << ". " << l3[i] << endl;
            }
            cout << "Enter the number of items you want to order: ";
            int num_items;
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n <= l3.size()) {
                    n--;
                    num_items--;
                    cout << "Your chosen item is " << l3[n] << " with price " << d3[l3[n]] << endl;
                    orders.push_back(l3[n]);
                    total_sum += d3[l3[n]];
                }
                else {
                    cout << "Your input exceeds the number of items" << endl;
                }
            }
        }
        else if (cuisine == "Burgers" || cuisine == "burgers" || cuisine == "4") {
            for (int i = 0; i < l4.size(); i++) {
                cout << i + 1 << ". " << l4[i] << endl;
            }
            cout << "Enter the number of items you want to order: ";
            int num_items;
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n <= l4.size()) {
                    n--;
                    num_items--;
                    cout << "Your chosen item is " << l4[n] << " with price " << d4[l4[n]] << endl;
                    orders.push_back(l4[n]);
                    total_sum += d4[l4[n]];
                }
                else {
                    cout << "Your input exceeds the number of items" << endl;
                }
            }
        }
        else if (cuisine == "rice and pasta" || cuisine == "Rice and Pasta" || cuisine == "5") {
            for (int i = 0; i < l5.size(); i++) {
                cout << i + 1 << ". " << l5[i] << endl;
            }
            cout << "Enter the number of items you want to order: ";
            int num_items;
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n <= l5.size()) {
                    n--;
                    num_items--;
                    cout << "Your chosen item is " << l5[n] << " with price " << d5[l5[n]] << endl;
                    orders.push_back(l5[n]);
                    total_sum += d5[l5[n]];
                }
                else {
                    cout << "Your input exceeds the number of items" << endl;
                }
            }
        }
        else if (cuisine == "add-ons"|| cuisine == "Add-ons" || cuisine == "6") {
            for (int i = 0; i < l6.size(); i++) {
                cout << i + 1 << ". " << l6[i] << endl;
            }
            cout << "Enter the number of items you want to order: ";
            int num_items;
            cin >> num_items;
            while (num_items > 0) {
                int n;
                cout << "Enter the food index item you want: ";
                cin >> n;
                if (n <= l6.size()) {
                    n--;
                    num_items--;
                    cout << "Your chosen item is " << l6[n] << " with price " << d6[l6[n]] << endl;
                    orders.push_back(l6[n]);
                    total_sum += d6[l6[n]];
                }
                else {
                    cout << "Your input exceeds the number of items" << endl;
                }
            }
        }
        cout << "Your total bill is " << total_sum << " rupees." << endl;
        orders.push_back(to_string(total_sum));
        return orders;
    }

    void writeToFile(const vector<string>& orders, string& cuisine, string& name, int table_no, int token_no) {
        ofstream file;
        file.open("orders1.txt", ios::app);
        
        file << cuisine<< endl; // write("string")
        file << name <<endl;
        file<< "Table Number " << table_no << endl;
        file << "Token Number " << token_no<< endl;
        for (const auto& order : orders) {      //for order in orders: 
            file << order << endl;              //     fname.append(order)
        }
        file << endl;
        file.close();
    }
};

int main() {
    l1 = {"Sweet chilli chicken wrap", 
        "Salad wrap",
        "Chicken caesar wrap",
        "Chicken mayo wrap",
        "Chicken salad wrap",
        "Mexican wrap",
        "Chicken Wrap",
        "Veg Wrap",
        "Chicken barbeque wrap",
        "Veg Kebab",
        "Harabhara Kebab"};

    l2 = {"Salad bread roll",
          "Egg and lettuce roll",
          "Chicken and mayo bread roll",
          "Hot and spicy chicken schnitzel bread roll",
          "Hot chicken gravy bread roll"};

    l3 = {"Cheese and tomato sandwich",
        "Chicken and cheese",
        "Tuna sandwich",
        "Chicken lettuce and mayo sandwich",
        "Chicken caesar sandwich", 
        "Vegan sandwich",
        "Veg Club Sandwich"};

    l4 = {"Chicken Burger",
          "Veg Burger",
          "Fries",
          "Aloo Tikki Burger",
          "Spicy Chicken Burger",
          "Spicy Veg Burger"};

    l5 = {"Butter Chicken Rice",
          "Pasta Red Sauce",
          "Pasta White Sauce",
          "Roasted Veggies Pasta",
          "Fried Rice"};

    l6 = {"Fruit Bowl",
          "Muffins",
          "Pastry"};

    

    Canteen canteen;
    
    Seating sb(canteen.t2,canteen.t4,canteen.t6,canteen.t8);
    while(1)
    {

        string name;
        cout<<"Enter your name: ";
        cin>>name;
        
        
        int num_of_people;
        cout<<"Enter the number of customers: ";
        cin>> num_of_people; 
        int table_no = sb.assignTables(canteen.t2,canteen.t4,canteen.t6,canteen.t8, num_of_people);

        string cuisine;
        cout << "Enter the cuisine: \n1. Wraps\n2. Rolls\n3. Sandwiches\n4. Burgers\n5. Rice and Pasta\n6. Add-ons\n";
        cin >> cuisine;
        vector<string> orders = canteen.takeOrder(cuisine);

        

        int token = sb.get_token();
        cout << "Your token number is " << token << endl;

        canteen.writeToFile(orders, cuisine, name, table_no, sb.token_no);

        cout<<"\n----------------------------------------------------------------------------------------------------------------------------------\n"<<endl;
    }
    return 0;
}
