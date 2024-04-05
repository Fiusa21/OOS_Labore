#include <iostream>
#include <string>

class Customer{
    static int _s_count;
    static int _s_id_generator;
    std::string _name;
    std::string _location;
    int _age;
    double _business_done;
    int _transaction_count;
    int _id;

public:
    Customer(std::string name, std::string location, int age){
    };
    ~Customer();

};


int main(int argc, char *argv[]) {
    Customer peter = Customer("Peter", 17, "Stuttgart");
    Customer simon = Customer("Simon", 23, "Heilbronn");
    peter.~Customer();
    Customer micheal = Customer("Michael", 21, "Karlsruhe");
    Customer claudia = Customer("Claudia", 30, "Nagold");
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
    simon.do_business(230);
    simon.do_business(400);
    claudia.do_business(1000);
    micheal.do_business(199);
    simon.do_business(3.99);
    simon.print();
    micheal.print();
    claudia.print();
    claudia.~Customer();
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
    return 0;
}

