#include <string>
#include <iostream>
using namespace std;

struct ListElement
{
    int id;
    ListElement* p_next;
};

ListElement* p_root = nullptr;

void add_new_head_element(int id)
{
    ListElement* p_new_element = new ListElement();
    p_new_element->id = id;
    p_new_element->p_next = p_root;
    p_root = p_new_element;
}

void add_new_tail_element(int id)
{
    // HIER programmieren:
    //Falls Liste leer:(in main erstes Element über tail Funktion)
    if(p_root == nullptr){
        add_new_head_element(id);
        return;
    }
    // Neues listenElement erzeugen.
    ListElement* p_new_tail = new ListElement();
    // Ans Ende der Liste navigieren und neues listenElement anhängen.
    ListElement* p_tmp = p_root;//tmp pointer für Iteration
    while (p_tmp->p_next != nullptr){
        p_tmp = p_tmp->p_next;
    }
    //Neues Element am Ende einfügen
    p_new_tail->id = id;
    p_tmp->p_next = p_new_tail;
}

void delete_element(int id)
{
    ListElement *p_tmp = p_root;
    ListElement *p_predecessor = nullptr;

    while (p_tmp != nullptr && p_tmp->id != id)
    {
        p_predecessor = p_tmp;
        p_tmp = p_tmp->p_next;
    }
    if (p_tmp != nullptr)
    {
        if (p_tmp == p_root)
        {
            p_root = p_tmp->p_next;
        }
        else
        {
            p_predecessor->p_next = p_tmp->p_next;
        }
    }
    delete p_tmp;
}

void print_list()
{
    ListElement* p_tmp = p_root;//temp pointer auf root setzen
    while(p_tmp != nullptr){//iterieren bis tmp = null
        cout <<p_tmp->id << endl;
        p_tmp = p_tmp->p_next;
    }
}

int main(int argc, char* argv[])
{
    add_new_tail_element(9);
    add_new_head_element(2);
    add_new_head_element(1);
    add_new_tail_element(10);
    print_list();
    delete_element(2);
    print_list();

    return 0;
};

