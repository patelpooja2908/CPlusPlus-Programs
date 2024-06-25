#include<iostream>
#include<malloc.h>
using namespace std;

struct slink
{
    int id;
    struct slink *next;
}*head, *last, *temp, *node;

void createnode_begin()
{
    node = (struct slink*)malloc(sizeof(struct slink));
    cout << "Enter data for id: ";
    cin >> node->id;
    node->next = NULL;
   
    if(head == NULL)
    {
        head = last = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
}

void createnode_end()
{
    node = (struct slink*)malloc(sizeof(struct slink));
    cout << "Enter data for id: ";
    cin >> node->id;
    node->next = NULL;
   
    if(head == NULL)
    {
        head = last = node;
    }
    else
    {
        last->next = node;
        last = node;
    }
}

void delete_begin()
{
    temp = head;
    head = head->next;
    free(temp);
}

void delete_last()
{
    temp = head;
    while(temp->next != last)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(last);
    last = temp;    
}

void display()
{
    temp = head;
    while(temp != NULL)
    {
        cout << temp->id << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int count_nodes()
{
    int count = 0;
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    int ch;
    cout << "Enter choice: ";
    cin >> ch;
    switch(ch)
    {
        case 1:
            cout << "This choice is for createnode_begin:\n";
            createnode_begin();
            main();
            break;
        case 2:
            cout << "This choice is for createnode_end:\n";
            createnode_end();
            main();
            break;
        case 3:
            cout << "This choice is for delete_begin:\n";
            delete_begin();
            main();
            break;
        case 4:
            cout << "This choice is for delete_last:\n";
            delete_last();
            main();
            break;
        case 5:
            cout << "This choice is for display:\n";
            display();
            main();
            break;
        case 6:
            cout << "This choice is for count_nodes:\n";
            cout << "Number of nodes: " << count_nodes() << endl;
            main();
            break;
        default:
            return 0;
    }
    return 0;
}