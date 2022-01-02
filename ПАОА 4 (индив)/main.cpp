#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
    int value;
};

struct List {

    Node date;//������ ��� ����� �������
    List* pNext;//��������� �� ��������� �������
};

void push_back(List** lst, int input)
{
    if (*lst == 0) // �������� ������ ���� - ������� � ������
    {
        List* temp = new List;
        temp->date.value = input;
        temp->pNext = NULL;
        *lst = temp;
    }
    else //���� ������ �� ���� - ��������� � ����� ������
    {
        List* current = *lst;
        while (current->pNext)
        {
            current = current->pNext;
        }
        current->pNext = new List;
        current->pNext->date.value = input;
        current->pNext->pNext = NULL;
    }

}

void print(List* lst)
{
    List* current = lst;
    while (current)
    {
        cout << current->date.value << " -> ";
        current = current->pNext;
    }
    cout << "NULL\n";
}

List* find_key_address(List** lst, int key)
{
    List* current = *lst;
    while (current)
    {
        if (current->date.value > key)
        {
            return current;
        }
        current = current->pNext;
    }
    return 0;
}

void insert_max(List** lst, List* address, int data)
{
    List* current = *lst;
    List* temporary = *lst;
    while (current)//���� �� ������ �� ���� �������, ���� �� �������� ����
    {
        if (current == address)
        {
            temporary = current->pNext;//��������� ����� ���������� ��������
            break;
        }
        current = current->pNext;
    }
    List* temp = new List;// ������� ����� �������
    temp->date.value = data;//�������� � ����� ������� ������
    current->pNext = temp;//��������� ����� ������� ����� �����
    temp->pNext = temporary;//��������� ����� ������ �������� ��� �������, ��� ����� ����� ����� ������
}

int main(void)
{
    srand(time(NULL));
    int sizeOfList;
    int max = 0;
    do {
        cout << "Enter the size of list (> 0): ";
        cin >> sizeOfList;
    } while (sizeOfList <= 0);
    List* lst = NULL;
    int* a = new int[sizeOfList];
    for (int i = 0; i < sizeOfList; i++)
    {
        *(a + i) = rand() % 15;
        if (max < *(a + i))
        {
            max = *(a + i);
        }
        push_back(&lst, *(a + i));//��������� ������ ���������� �������
    }
    cout << "The list:\n";
    print(lst);// ������� ������ �� �����
    int key;
    do {
        cout << "Enter the key (0 - 15): ";
        cin >> key;
    } while (key < 0 || key > 15);
    cout << "Max: " << max << endl;
    List* key_address = find_key_address(&lst, key);
    if (key_address != 0)
    {
        List* current = lst;
        while (current)
        {
            if (current == key_address)
            {
                insert_max(&lst, current, max);
                cout << "The list after insert (individual task):\n";
                print(lst);
            }
            current = current->pNext;
        }
    }
    return 0;
}
