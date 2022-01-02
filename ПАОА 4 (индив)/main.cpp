#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
    int value;
};

struct List {

    Node date;//данные что будем хранить
    List* pNext;//указатель на следующий элемент
};

void push_back(List** lst, int input)
{
    if (*lst == 0) // исходный список пуст - вставка в начало
    {
        List* temp = new List;
        temp->date.value = input;
        temp->pNext = NULL;
        *lst = temp;
    }
    else //если список не пуст - добавляем в конец списка
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
    while (current)//идем по списку до того момента, пока не встретим ключ
    {
        if (current == address)
        {
            temporary = current->pNext;//сохранили адрес следующего элемента
            break;
        }
        current = current->pNext;
    }
    List* temp = new List;// создали новый элемент
    temp->date.value = data;//записали в новый элемент данные
    current->pNext = temp;//поставили новый элемент после ключа
    temp->pNext = temporary;//поставили после нового элемента тот элемент, что стоял после ключа раньше
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
        push_back(&lst, *(a + i));//заполняем список рандомными числами
    }
    cout << "The list:\n";
    print(lst);// выводим список на экран
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
