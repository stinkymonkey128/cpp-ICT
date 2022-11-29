#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item {
   int id, inv;
   Item* next;

   Item(int, int, Item*);
};

Item::Item(int _id, int _inv, Item* _next) : 
   id(_id), inv(_inv), next(_next) {}

int CAPACITY = 400;

int main() {
   Item* hashMap = (Item*) malloc(sizeof(Item) * CAPPACITY * 1.5);
   ifstream fr("file400.txt");
   int size = 0, unique = 0;
   fr >> size;

   for (int i = 0; i < size; i++) {
      int id, inv, hash = 0;
      fr >> id >> inv;

      string data = to_string(id);

      // Some hashing algo

      // End some hashing algo

      hashMap[hash] = new Item(id, inv, hashMap[hash]); // prob pointer error
   }

   fr.close();

   for (int i = 0; i < CAPACITY * 1.5; i++)
      if (hashMap[i]->next == NULL)
         unique++;

   cout << "Unique rate = " << (unique / 400) << endl;
}
