#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
    int value;
};

struct List 
{
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
        if (current->date.value == key)
        {
            return current;
        }
        current = current->pNext;
    }
    return 0;
}

void delete_and_replace(List** lst, List* address, int data)
{
    List* current = *lst;
    List* temporary = *lst;
    while (current)//���� �� ������ �� ���� �������, ���� �� �������� ����
    {
        if (current == address)
        {
            temporary = current->pNext->pNext;//��������� ����� ��������������� ��������
            break;//����� �� �����
        }
        current = current->pNext;
    }
    current->date.value = data;//�������� � ������� ������� ������ ��������������� ��������
    current->pNext->pNext = temporary->pNext;//�������� �������������� �������, ��� ����� ������� ��� � ��������� �������
}

int main(void)
{
    srand(time(NULL));
    int size_list;
    do {
        cout << "Enter the size of list(more than 0): ";
        cin >> size_list;
    } while (size_list <= 0);
    List* lst = NULL;
    for (int i = 0; i < size_list; i++)
    {
        push_back(&lst, rand() % 15);//��������� ������ ���������� �������
    }
    cout << "The list:\n";
    print(lst);// ������� ������ �� �����
    int key;
    do {
        cout << "Enter the key (0 - 15): ";
        cin >> key;
    } while (key < 0 || key > 15);
    //����� ����
    List* key_address = find_key_address(&lst, key);
    if (key_address != 0)
    {
        List* current = lst;
        while (current)
        {
            if (current == key_address)
            {
                if (current->pNext != NULL || current->pNext->pNext != NULL) //����� ����� ���� >= 2 ��������
                {
                    delete_and_replace(&lst, current, current->pNext->pNext->date.value);
                    cout << "The list after insert:\n";
                    print(lst);
                }
                else
                {
                    cout << "You cannot swap two elements following the key because there are less than 2 elements after the key!\n";
                    //������ �������� ������� ��� �������� ������ ����� ����� ������ ��� ����� ����� ������ 2 ���������
                }
            }
            current = current->pNext;
        }
    }
    return 0;
}
