#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

#define MAX    100

class itemEntry {
public:
       float unit_price;
       int item;
       char name[30];
       char company[30];
};

class Store {
public:
       int numItem;
       itemEntry database[MAX];

       Store() {
              numItem = 0;
       }
       void insertItem(char itemName[], char company[], int c, float p);
       void deleteItem(char itemName[]);
       itemEntry *search(char itemName[]);
       void updateItem(char itemName[], int total, float price);
};

void Store::insertItem(char itemName[], char company[], int c, float p) {
       strcpy(database[numItem].name, itemName);
       strcpy(database[numItem].company, company);
       database[numItem].item = c;
       database[numItem].unit_price = p;
       cout << "Item Inserted Successfully.\n";
       ++numItem;
}

void Store::deleteItem(char itemName[]) {
       int i;
       for (i = 0; i < numItem; i++) {
              if (strcmp(itemName, database[i].name) == 0) {
                     database[i].item--;
                     cout << "Item Deleted Successfully.\n";
                     return;
              }
       }
       cout << "Item not found.\n";
}

itemEntry *Store::search(char itemName[]) {
       int i;
       for (i = 0; i < numItem; i++) {
              if (strcmp(itemName, database[i].name) == 0)
                     return &database[i];
       }
       return NULL;
}

void Store::updateItem(char itemName[], int total, float price)
{
       itemEntry *item = search(itemName);
       if (item == NULL)
       {
              cout << "Item not found.\n";
              return;
       }
       item->item += total;
       item->unit_price = price;
}

int main() {
       Store sto;
       system("cls");
       char option='f', name[30], company[30], item[10], unit_price[30];
       while (option != 'e') {
              cout << "\n----------->Enter your choice:<------------\n";
              cout << "I for insert\n";
              cout << "D for delete\n";
              cout << "S for search\n";
              cout << "U for update\n";
              cout << "E for exit\n";

              cin.getline(name, 80);
              option = name[0];

              switch (option) {

              case 'i':
                     cout << "Enter Name of Item"<<endl;
                     cin.getline(name, 80);
                     cout<<"Enter Company Name"<<endl;
                     cin.getline(company, 80);
                     cout<<"EnterNo. of Items"<<endl;
                     cin.getline(item, 80);
                     cout<<"Enter Price"<<endl;
                     cin.getline(unit_price, 80);
                     sto.insertItem(name, company, atoi(item), atof(unit_price));
                     break;
              case 'd':
                     cout << "Enter Name of Item:\n";
                     cin.getline(name, 80);
                     sto.deleteItem(name);
                     break;
              case 's':
                     cout << "Enter Name of Item:\n";
                     cin.getline(name, 80);
                     itemEntry *test;
                     test = sto.search(name);
                     if (test != NULL) {
                           cout << "---------------->Searching Result<---------------------" << endl;
                           cout << "Item found\n" << "Name of the Item:" << test->name << endl << "Company name:" << test->company << endl << "Number of item available:" << test->item << endl << "Unit price:" << test->unit_price << endl;
                     }
                     else
                           cout << "Item not found\n";
                     break;
              case 'u':
                     cout << "Enter details for update...\n";
                     cout << "Enter name: "; cin.getline(name, 80);
                     cout << "Enter total new entry: "; cin.getline(item, 80);
                     cout << "Enter new price: "; cin.getline(unit_price, 80);
                     sto.updateItem(name, atoi(item), atof(unit_price));
                     break;
                     /*        case 'e':
                     exit(0);
                     break;*/
              }
       }
       return 0;

}
