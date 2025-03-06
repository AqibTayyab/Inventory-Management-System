#include <iostream>
#include <vector>
#include <iomanip>  // For formatting output

using namespace std;

// Structure to define a product
struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

// Class to manage inventory
class Inventory {
private:
    vector<Product> products;
    double totalSales; // Track total revenue

public:
    // Constructor to initialize total sales
    Inventory() {
        totalSales = 0.0;
    }

    // Function to add a new product
    void addProduct(int id, string name, double price, int quantity) {
        Product newProduct = {id, name, price, quantity};
        products.push_back(newProduct);
        cout << "Product added successfully!\n";
    }

    // Function to remove a product by ID
    void removeProduct(int id) {
        for (size_t i = 0; i < products.size(); i++) {
            if (products[i].id == id) {
                products.erase(products.begin() + i);
                cout << "Product removed successfully!\n";
                return;
            }
        }
        cout << "Product not found!\n";
    }

    // Function to update stock and track sales
    void sellProduct(int id, int quantity) {
        for (size_t i = 0; i < products.size(); i++) {
            if (products[i].id == id) {
                if (products[i].quantity >= quantity) {
                    products[i].quantity -= quantity;
                    double saleAmount = quantity * products[i].price;
                    totalSales += saleAmount;
                    cout << "Sold " << quantity << " of " << products[i].name << ".\n";
                    cout << "Total Sales: $" << fixed << setprecision(2) << totalSales << "\n";
                } else {
                    cout << "Not enough stock available!\n";
                }
                return;
            }
        }
        cout << "Product not found!\n";
    }

    // Function to display all products in the inventory
    void displayInventory() {
        if (products.empty()) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "\n---- Inventory List ----\n";
        cout << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Stock\n";
        cout << "-------------------------------------------\n";
        for (const auto &product : products) {
            cout << setw(5) << product.id << setw(20) << product.name << setw(10) << product.price << setw(10) << product.quantity << "\n";
        }
        cout << "-------------------------------------------\n";
    }

    // Function to show total sales revenue
    void showTotalSales() {
        cout << "Total Sales Revenue: $" << fixed << setprecision(2) << totalSales << "\n";
    }
};

// Main function
int main() {
    Inventory inventory;
    int choice, id, quantity;
    string name;
    double price;

    do {
        // Display menu options
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Sell Product\n";
        cout << "4. Display Inventory\n";
        cout << "5. Show Total Sales\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Product Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Product Price: ";
                cin >> price;
                cout << "Enter Product Quantity: ";
                cin >> quantity;
                inventory.addProduct(id, name, price, quantity);
                break;
            case 2:
                cout << "Enter Product ID to remove: ";
                cin >> id;
                inventory.removeProduct(id);
                break;
            case 3:
                cout << "Enter Product ID to sell: ";
                cin >> id;
                cout << "Enter Quantity to sell: ";
                cin >> quantity;
                inventory.sellProduct(id, quantity);
                break;
            case 4:
                inventory.displayInventory();
                break;
            case 5:
                inventory.showTotalSales();
                break;
            case 6:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
