# include <iostream>
# include <vector>
# include <windows.h>
# include <algorithm>
# include <fstream>
using namespace std;

struct Date_strc {
    int year, month, day;
    
    Date_strc() {
        year = 0;
        month = 0;
        day = 0;
    }

    void input_info() {
        while (true) {
            cout << "year: ";
            cin >> year;
            if (1000 <= year && year <= 9999) break;
            else cout << "Invalid year entered, please try again" << endl;
        }
        while (true) {
            cout << "month: ";
            cin >> month;
            if (1 <= month && month <= 12) break;
            else cout << "Invalid month entered, please try again" << endl;
        }
        while (true) {
            cout << "day: ";
            cin >> day; 
            if (1 <= day && day <= 30) break;
            else cout << "Invalid day entered, please try again" << endl;
        }
    }
    
    void show_info() {
        cout << year << '-' << month << '-' << day << endl;
    } 
};

struct product {
    string name;
    float price;
    Date_strc Date;
    int ID;
    
    product() {
        name = "";
        price = 0.0;
        ID = 0;
    }
    
    void show_info() {
        cout << endl << "- Product name: " << name << endl;
        cout << "  Product price: " << price << endl;
        cout << "  Product Date: ";
        Date.show_info();
        cout << "  Product ID: " << ID << endl;
    }
};

    
int main() {
    vector<product> product_list;
    
    ifstream file("C:\\project\\data.dat");
    if (file.is_open()) {
        cout << "File read successfully";
        Sleep(1500);
        string name;
        float price;
        int year, month, day, ID;
        char ch;

        while (getline(file, name, ',')) {
            file >> price >> ch;
            file >> year >> ch;
            file >> month >> ch;
            file >> day >> ch;
            file >> ID;
            file.ignore();

            product temp;
            temp.name = name;
            temp.price = price;
            temp.Date.year = year;
            temp.Date.month = month;
            temp.Date.day = day;
            temp.ID = ID;
            
            product_list.push_back(temp);
        }
        file.close();
        
    }
    else {
        cout << "File not found";
        Sleep(3000);
    }
 
    while (true) {
        system("cls");
        cout << "1. Add" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Sort" << endl;
        cout << "5. Print All" << endl;
        cout << "6. Exit" << endl;
        
        string order;
        cin >> order;

        if (order == "add" || order == "1") {
            product new_product;
            cout << "Please enter the required information" << endl;
            cout << "product name: ";
            cin.ignore();
            getline(cin, new_product.name);
            cout << "product price: ";
            cin >> new_product.price;
            cout << "product Date: " << endl;
            new_product.Date.input_info();
            cout << "product ID: ";
            cin >> new_product.ID;
            product_list.push_back(new_product);
            
            cout << endl << "The desired product has been added";
            Sleep(2000);
        }
        

        else if (order == "delete" || order == "2") {
            bool flag = true;
            cout << "Please enter the desired product code" << endl;
            cout << "code: ";
            int code;
            cin >> code;
            for (int i = 0; i < product_list.size(); i++) {
                if (code == product_list[i].ID) {
                    product_list.erase(product_list.begin() + i);
                    flag = false;
                    break;
                }
            }
            
            if (flag) cout << "There is no product with this code" << endl;   
            else cout << "The desired product was deleted" << endl; 
            
            Sleep(2000);
        }
        

        else if (order == "search" || order == "3") {
            bool flag = true;
            cout << "Please enter the desired product code" << endl;
            cout << "code: ";
            int code;
            cin >> code;
            for (int i = 0; i < product_list.size(); i++) {
                if (code == product_list[i].ID) {
                    product_list[i].show_info();
                    flag = false;
                    break;
                }
            }
            if (flag) cout << "There is no product with this code" << endl; 
        
            cin.ignore();
            cout << endl << "to return to the menu please press Enter";
            cin.get();
        }
        

        else if (order == "sort" || order == "4") {
        
            cout << "Please choose the sorting method" << endl;
            cout << "  1. Auto sort" << endl;
            cout << "  2. Manual sort" << endl;
            char answer;
            while (true) {
                cin >> answer;
                if (answer == '1' || answer == '2') break;
                else cout << "Invalid answer, please try again" << endl;
            }
            
            if (answer == '1') {
                if (product_list.size() > 0) {

                    cout << "How should the product list be sorted?" << endl;
                    cout << "  1. sort by Date" << endl;
                    cout << "  2. sort by price" << endl;
                    cout << "  3. sort by ID" << endl;
                    cout << "  4. reverse list" << endl;
                    
                    char answer2;
                    while (true) {
                        cin >> answer2;
                        if (answer2 == '1' || answer2 == '2' || answer2 == '3' || answer2 == '4') break;
                        else cout << "Invalid answer, please try again" << endl;
                    }
    
                    if (answer2 == '1') {
                        sort(product_list.begin(), product_list.end(), [](const product &a, const product &b) {
                            if (a.Date.year != b.Date.year) return a.Date.year < b.Date.year;
                            if (a.Date.month != b.Date.month) return a.Date.month < b.Date.month;
                            return a.Date.day < b.Date.day;
                        });
                    }
                
                    else if (answer2 == '2') {
                        sort(product_list.begin(), product_list.end(), [](const product &a, const product &b) {
                            return a.price < b.price;
                        });
                    }
    
                    else if (answer2 == '3') {
                        sort(product_list.begin(), product_list.end(), [](const product &a, const product &b) {
                            return a.ID < b.ID;
                        });
                    }
                
                    if (answer2 == '4') reverse(product_list.begin(), product_list.end());
                
                    cout << endl << "Changes applied" << endl;
                    Sleep(2000);
                }
                else {
                    cout << "There are not enough products to sort" << endl;
                    Sleep(2000);
                }
                
            }

            else {
                
                if (product_list.size() >= 2) {
                    product temp;
                    int code1, code2, index1, index2;
                    cout << "Please enter the products codes you want to move" << endl;
                    
                    while (true) {
                        bool flag = true;
                        cout << "-";
                        cin >> code1;
                        for (int i = 0; i < product_list.size(); i++) {
                            if (code1 == product_list[i].ID) {
                                index1 = i;
                                flag = false; 
                                break;
                            }
                        }
                        if (flag) cout << "There is no product with this code" << endl;
                        else break;
                    }
    
                    while (true) {
                        bool flag = true;
                        cout << "-";
                        cin >> code2;
                        for (int i = 0; i < product_list.size(); i++) {
                            if (code2 == product_list[i].ID) {
                                index2 = i;
                                flag = false; 
                                break;
                            }
                        }
                        if (flag) cout << "There is no product with this code" << endl;
                        else break;
                    }
    
                    temp = product_list[index1];
                    product_list[index1] = product_list[index2];
                    product_list[index2] = temp; 
                    
                    cout << endl << "Changes applied" << endl;
                    Sleep(2000);
                }
                
                else {
                    cout << "There are not enough products to move" << endl;
                    Sleep(2000);
                }    
            }   
        }
        
        
        else if (order == "print all" || order == "5") {
            if (product_list.size() > 0) {
                for (int i = 0; i < product_list.size(); i++) {
                    product_list[i].show_info();
                }
            }
            else cout << "There are no products to show" << endl;

            cin.ignore();
            cout << endl << "to return to the menu please press Enter";
            cin.get();
        }
        

        else if (order == "exit" || order == "6") {
            
            cout << "Do you want to save the changes? (yes/no)" << endl;
            string answer;
            while (true) {
                cin >> answer;
                if (answer == "yes" || answer == "no") break;
                else cout << "Invalid answer, please try again" << endl;
            }    
            
            if (answer == "yes") {
                ofstream file_out("C:\\project\\data.dat");
                for (int i = 0; i < product_list.size(); i++) {
                    file_out << product_list[i].name << ',' << 
                    product_list[i].price << ',' <<
                    product_list[i].Date.year << ',' <<
                    product_list[i].Date.month << ',' <<
                    product_list[i].Date.day << ',' <<
                    product_list[i].ID << "\n";
                }            
            }
            
            break;
        }
    

        else {
            cout << "Invalid order .." << endl;
            Sleep(2000);
        }     
    }
}