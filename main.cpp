//main file
#include "Menu.h"
#include "LinkedList.h"

int main(){
    //LinkedList Tests
    LinkedList ll;
    ll.addFront(1);
    ll.addFront(4);
    ll.addFront(3);
    ll.addBack(7);

    //Print Linked List
    std::cout << "List Size: " << ll.size() << std::endl;
    for (int i = 0; i < ll.size(); i++){
        int num = ll.get(i);
        std::cout << num << ", ";
    }
    std::cout << std::endl;


    //Run Menu
    Menu* menu = new Menu();
    menu->mainMenu();


    return EXIT_SUCCESS;
}