#include <iostream>
#include <fstream>

using namespace std;
class Product
{
public:
    int product_id;
    string product_category;
    string product_name;

    void get_product()
    {
        ifstream in_product("productIn.txt");
        in_product >> product_id;
        in_product.ignore();
        getline(in_product, product_category);

        getline(in_product, product_name);
    }
    void set_product()
    {
        ofstream out_product("productOut.txt");

        out_product << "Product ID: " << product_id << endl;
        out_product << "Product Category: " << product_category << endl;
        out_product << "Product Name: " << product_name << endl;
    }
};
class soldProduct : public Product
{
public:
    int customer_id;
    string price;

    void get_soldProduct()
    {
        ifstream in_soldProduct("customerIn.txt");

        in_soldProduct >> customer_id >> price;
        in_soldProduct.close();
    }
    void set_soldProduct()
    {

        ofstream out_soldProduct("customerOut.txt");
        

        out_soldProduct << "Product ID: " << product_id << endl;
        out_soldProduct << "Product Category: " << product_category << endl;
        out_soldProduct << "Product Name: " << product_name << endl;

        out_soldProduct << "Customer ID: " << customer_id << endl;
        out_soldProduct << "Price: " << price;
    }
};
class boughtProduct : public Product
{
public:
    int buyer_id;
    string price;
    string buyer_name;
    void get_boughtProduct()
    {
        ifstream in_boughtProduct("buyerIn.txt");
        in_boughtProduct >> buyer_id >> price;
        in_boughtProduct.ignore();
        getline(in_boughtProduct, buyer_name);
        in_boughtProduct.close();
    }
    void set_boughtProduct()
    {
        ofstream out_boughtProduct("buyerOut.txt");
        out_boughtProduct << "Product ID: " << product_id << endl;
        out_boughtProduct << "Product Category: " << product_category << endl;
        out_boughtProduct << "Product Name: " << product_name << endl;
        out_boughtProduct << "Buyer ID: " << buyer_id << endl;
        out_boughtProduct << "Price: " << price << endl;
        out_boughtProduct << "Buyer Name: " << buyer_name << endl;
    }
};
int main()
{
    Product obj1;
    obj1.get_product();
    obj1.set_product();

    soldProduct obj2;
    obj2.get_product();
    obj2.get_soldProduct();
    obj2.set_soldProduct();

    boughtProduct obj3;
    obj3.get_product();
    obj3.get_boughtProduct();
    obj3.set_boughtProduct();
}