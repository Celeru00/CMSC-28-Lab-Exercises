#include <iostream>
#include <list>
#include "ProductInventory.h"
using namespace std;

int main()
{
    // Declare variables and lists
    list<int> Quantity;
    list<string> Name, Brand, Description, Color, Category, Model, Tech_spec, Material, Size;
    list<float> Price, Warranty;
    // Declare variables for user input
    string productName, productBrand, productDescription, productColor, productCategory, productModel, productTech_spec, productMaterial, productSize;
    float productPrice, productWarranty;
    int choice, productQuantity;
    Product product;
    Clothing clothing;
    Electronic electronic;
    // Display menu
    do
    {
        cout << "\n================================" << endl;
        cout << "Product Inventory System" << endl;
        cout << "================================" << endl;
        cout << "Select Category/Action: " << endl; // Display menu for user to choose category
        cout << "[1] Electronics" << endl;
        cout << "[2] Clothing" << endl;
        cout << "[3] Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        // Electronics operation
        case 1:
            cout << endl;
            cout << "Enter Product Name: "; // Get product name and set it to Name list
            cin.ignore();
            getline(cin, productName);
            Name = {productName};
            electronic.set_name(Name);

            Category = {"Electronics"}; // Set category to Electronics
            electronic.set_category(Category);

            cout << "Enter Brand: "; // Get brand and set it to Brand list
            getline(cin, productBrand);
            Brand = {productBrand};
            electronic.set_brand(Brand);

            cout << "Enter Price: "; // Get price and set it to Price list
            cin >> productPrice;
            Price = {productPrice};
            electronic.set_price(Price);

            cout << "Enter Quantity: "; // Get quantity and set it to Quantity list
            cin >> productQuantity;
            Quantity = {productQuantity};
            electronic.set_quantity(Quantity);

            cout << "Enter Description: "; // Get description and set it to Description list
            cin.ignore();
            getline(cin, productDescription);
            Description = {productDescription};
            electronic.set_description(Description);

            cout << "Enter Size: "; // Get size and set it to Size list
            getline(cin, productSize);
            Size = {productSize};
            electronic.set_size(Size);

            cout << "Enter Color: "; // Get color and set it to Color list
            getline(cin, productColor);
            Color = {productColor};
            electronic.set_color(Color);

            cout << "Enter Model: "; // Get model and set it to Model list
            getline(cin, productModel);
            Model = {productModel};
            electronic.set_model(Model);

            cout << "Enter Warranty (in months): "; // Get warranty and set it to Warranty list
            cin >> productWarranty;
            Warranty = {productWarranty};
            electronic.set_warranty(Warranty);

            cout << "Enter Technical Specs: "; // Get tech spec and set it to Tech_spec list
            cin.ignore();
            getline(cin, productTech_spec);
            Tech_spec = {productTech_spec};
            electronic.set_tech_spec(Tech_spec);

            cout << "Enter Material: "; // Get material and set it to Material list
            getline(cin, productMaterial);
            Material = {productMaterial};
            electronic.set_material(Material);

            system("cls");        // Clear screen
            electronic.Display(); // Display product details
            break;
        case 2: // Clothing operations (functions similarly to Electronics operations)
            cout << endl;
            cout << "Enter Product Name: ";
            cin.ignore();
            getline(cin, productName);
            Name = {productName};
            clothing.set_name(Name);

            Category = {"Clothing"};
            clothing.set_category(Category);

            cout << "Enter Brand: ";
            cin.ignore();
            getline(cin, productBrand);
            Brand = {productBrand};
            clothing.set_brand(Brand);

            cout << "Enter Price: ";
            cin >> productPrice;
            Price = {productPrice};
            clothing.set_price(Price);

            cout << "Enter Quantity: ";
            cin >> productQuantity;
            Quantity = {productQuantity};
            clothing.set_quantity(Quantity);

            cout << "Enter Description: ";
            cin.ignore();
            getline(cin, productDescription);
            Description = {productDescription};
            clothing.set_description(Description);

            cout << "Enter Size: ";
            getline(cin, productSize);
            Size = {productSize};
            clothing.set_size(Size);

            cout << "Enter Color: ";
            getline(cin, productColor);
            Color = {productColor};
            clothing.set_color(Color);

            cout << "Enter Model: ";
            getline(cin, productModel);
            Model = {productModel};
            clothing.set_model(Model);

            cout << "Enter Warranty (in months): ";
            cin >> productWarranty;
            Warranty = {productWarranty};
            clothing.set_warranty(Warranty);

            cout << "Enter Technical Specs: N/A" << endl;
            Tech_spec = {"N/A"};
            clothing.set_tech_spec(Tech_spec);

            cout << "Enter Material: ";
            cin.ignore();
            getline(cin, productMaterial);
            Material = {productMaterial};
            clothing.set_material(Material);

            system("cls");
            clothing.Display();
            break;
        case 3:
            cout << "Exiting Program..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 3);
}