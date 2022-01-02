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

void pushBack(List** lst, int input)
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

void printList(List* lst)
{
    List* current = lst;
    while (current)
    {
        cout << current->date.value << " -> ";
        current = current->pNext;
    }
    cout << "NULL\n";
}

List* findKeyAddress(List** lst, int key)
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

void deleteAndReplace(List** lst, List* address, int data)
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

List* findBiggerThanKeyAddress(List** lst, int key)
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

int findMax(List** lst)
{
    int max = 0;
    List* current = *lst;
    while (current)
    {
        if (current->date.value > max)
        {
            max = current->date.value;
        }
        current = current->pNext;
    }
    return max;
}

void insertMax(List** lst, List* address, int data)
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

void clearList(List** lst)
{
    if (*lst == 0)
    {
        return;
    }
    List* p = *lst;
    List* t;
    while (p)
    {
        t = p;
        p = p->pNext;
        delete t;
    }
    *lst = 0;
}

int main(void)
{
    srand(time(NULL));
    int sizeList;
    do {
        cout << "Enter the size of list(more than 0): ";
        cin >> sizeList;
    } while (sizeList <= 0);
    List* lst = NULL;
    for (int i = 0; i < sizeList; i++)
    {
        pushBack(&lst, rand() % 15);//��������� ������ ���������� �������
    }
    cout << "The list:\n";
    printList(lst);// ������� ������ �� �����
    int key;
    do {
        cout << "Enter the key (0 - 15): ";
        cin >> key;
    } while (key < 0 || key > 15);
    //����� ����
    List* keyAddress = findKeyAddress(&lst, key);
    List* biggerThanKeyAddress = findBiggerThanKeyAddress(&lst, key);
    if (keyAddress != 0)
    {
        List* current = lst;
        while (current)
        {
            if (current == keyAddress)
            {
                if (current->pNext != NULL || current->pNext->pNext != NULL) //����� ����� ���� >= 2 ��������
                {
                    deleteAndReplace(&lst, current, current->pNext->pNext->date.value);
                    cout << "The list after general task:\n";
                    printList(lst);
                }
                else
                {
                    cout << "You cannot swap two elements following the key because there are less than 2 elements after the key!\n";
                    //����� ����� ������ 2 ���������, ���������� ��������
                }
            }
            current = current->pNext;
        }
    }
    int max = findMax(&lst);
    cout << "Max: " << max << endl;
    if (biggerThanKeyAddress != 0)
    {
        List* current = lst;
        while (current)
        {
            if (current == biggerThanKeyAddress)
            {
                insertMax(&lst, current, max);
                cout << "The list after individual task:\n";
                printList(lst);
            }
            current = current->pNext;
        }
    }
    clearList(&lst);//������� ������
    return 0;
}
