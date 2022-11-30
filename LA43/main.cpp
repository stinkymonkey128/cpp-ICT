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
int PRIME = 48889;

int main() {
    //Item** hashMap = new Item*[CAPACITY * 1.5];//(Item*)malloc(sizeof(Item) * CAPACITY * 1.5);
    Item* hashMap[600] = {};
    ifstream fr("file400.txt");
    int size = 0, unique = 0;
    fr >> size;
    
    for (int i = 0; i < size; i++) {
        int id, inv, hash = 0;
        fr >> id >> inv;

        string data = to_string(id);

        // Some hashing algo

        for (auto& cd : data)
            hash = cd + (PRIME * hash) - 13;
        hash = abs((hash + PRIME) % 600);

        // End some hashing algo

        Item* newItem = new Item(id, inv, hashMap[hash]);
        hashMap[hash] = newItem;

    }

    fr.close();

    int longest = 0;
    double averageLen = 0;


    for (int i = 0; i < 600; i++) {
        if (hashMap[i] == NULL)
            unique++;
        else
        {
            int length = 1;
            Item* current = hashMap[i];

            while (current != NULL) {
                current = current->next;
                length++;
            }

            averageLen += length;

            longest = max(longest, length);
        }
    }

    averageLen /= (600 - (double)unique);

    cout << "Null Percentage = " << ((double)unique / 600 * 100) << endl;
    cout << "Average length of linked lists = " << averageLen << endl;
    cout << "The longested linked list = " << longest;
}
