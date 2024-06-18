#ifndef PRODUCTINVENTORY_H
#define PRODUCTINVENTORY_H

#include <iostream>
#include <list>
using namespace std;

class Product {
    protected:
        list<string> Name;
        list<string> Brand;
        list<float> Price;
        list<int> Quantity;
        list<string> Description;
        list<string> Size;
        list<string> Color;
        list<string> Category;
        list<string> Model;
        list<float> Warranty;
        list<string> Tech_spec;
        list<string> Material;
    
    public:
        Product() {};

        void set_name(list<string> name) {
            this->Name = name;
        }

        void set_brand(list<string> brand)  {
            this->Brand = brand;
        }

        void set_price(list<float> price) {
            this->Price = price;
        }

        void set_quantity(list<int> quantity) {
            this->Quantity = quantity;
        }

        void set_description(list<string> description) {
            this->Description = description;
        }

        void set_size(list<string> size) {
            this->Size = size;
        }

        void set_color(list<string> color) {
            this->Color = color;
        }

        void set_category(list<string> category) {
            this->Category = category;
        }

        void set_model(list<string> model) {
            this->Model = model;
        }

        void set_warranty(list<float> warranty) {
            this->Warranty = warranty;
        }

        void set_tech_spec(list<string> tech_spec) {
            this->Tech_spec = tech_spec;
        }

        void set_material(list<string> material) {
            this->Material = material;
        }

        list<string> get_name() {
            return Name;
        }

        list<string> get_brand() {
            return Brand;
        }

        list<float> get_price() {
            return Price;
        }

        list<int> get_quantity() {
            return Quantity;
        }

        list<string> get_description() {
            return Description;
        }

        list<string> get_size() {
            return Size;
        }

        list<string> get_color() {
            return Color;
        }

        list<string> get_category() {
            return Category;
        }

        list<string> get_model() {
            return Model;
        }

        list<float> get_warranty() {
            return Warranty;
        }

        list<string> get_tech_spec() {
            return Tech_spec;
        }

        list<string> get_material() {
            return Material;
        }

        // Display product details
        void Display() {
            for (auto it = Name.begin(); it != Name.end(); ++it) {          // Loop through Name list and display product details accordingly
                cout << "============================================\n";
                cout << "\t   Product Details: " << endl;
                cout << "============================================\n";
                cout << "Name: " << *it << endl;
                cout << "Brand: " << *Brand.begin() << endl;
                cout << "Price: " << *Price.begin() << endl;
                cout << "Quantity: " << *Quantity.begin() << endl;
                cout << "Description: " << *Description.begin() << endl;
                cout << "Size: " << *Size.begin() << endl;
                cout << "Color: " << *Color.begin() << endl;
                cout << "Category: " << *Category.begin() << endl;
                cout << "Model: " << *Model.begin() << endl;
                cout << "Warranty (in months): " << *Warranty.begin() << " months" << endl;
                cout << "Technical Specs: " << *Tech_spec.begin() << endl;
                cout << "Material: " << *Material.begin() << endl;
                cout << "============================================\n";
            }
        }
};

// Inheritance
class Clothing: public Product {
    public:
        Clothing() {};
};

// Inheritance
class Electronic: public Product {
    public:
        Electronic() {};
};

#endif