#include <iostream>
using namespace std;

void print_rectangle(int x = 4, int y = 4){
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            cout << "X " ;
        }
        cout << endl;
    }
    cout << endl;
}


int main(int argc, char *argv[])
{
    std::cout << "x = 2, y = 5: " << std::endl;
    print_rectangle(2, 5);

    std::cout << "x = 3, y = 3: " << std::endl;
    print_rectangle(3, 3);

    std::cout << "x = 4: " << std::endl;
    print_rectangle(4);

    return 0;
};

