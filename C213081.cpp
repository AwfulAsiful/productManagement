#include <iostream>
#include <fstream>

using namespace std;
class Product
{
public:
    int product_id;
    string product_category;
    string product_name;

    void get_product(){
        ifstream in("productIn.txt");
        in>>product_id;
        in.ignore();
        getline(in,product_category);
        
        getline(in,product_name);

        
        in.close();
    }
    void set_product(){
        ofstream out("productOut.txt");
        out<<"Product ID: "<<product_id<<endl;
        out<<"Product Category: "<<product_category<<endl;
        out<<"Product Name: "<<product_name<<endl;
    }

};
class soldProduct:public Product{
   public:
    int customer_id;
    string price;
    void get_soldProduct(){
        ifstream in("customerIn.txt");
        in>>customer_id>>price;
        in.close();
    }
    void set_soldProduct(){
        ofstream out("customerOut.txt");
        out<<"Customer ID: "<<customer_id<<endl;
        out<<"Price: "<<price;
    }
};
class boughtProduct:public Product{
    public:
    int buyer_id;
    string price;
    string buyer_name;
    void get_boughtProduct(){
        ifstream in("buyerIn.txt");
        in>>buyer_id>>price;
        in.ignore();
        getline(in,buyer_name);
        in.close();
    }
    void set_boughtProduct(){
        ofstream out("buyerOut.txt");
        out<<"Buyer ID: "<<buyer_id<<endl;
        out<<"Price: "<<price<<endl;
        out<<"Buyer Name: "<<buyer_name<<endl;
    }
};
int main()
{
    Product obj1;
    obj1.get_product();
    obj1.set_product();


    soldProduct obj2;
    obj2.get_soldProduct();
    obj2.set_soldProduct();


    boughtProduct obj3;
    obj3.get_boughtProduct();
    obj3.set_boughtProduct();
}