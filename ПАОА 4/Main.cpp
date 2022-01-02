#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
    int value;
};

struct List
{
    Node date;//данные что будем хранить
    List* pNext;//указатель на следующий элемент
};

void pushBack(List** lst, int input)
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
    while (current)//идем по списку до того момента, пока не встретим ключ
    {
        if (current == address)
        {
            temporary = current->pNext->pNext;//сохранили адрес послеследующего элемента
            break;//выход из цыкла
        }
        current = current->pNext;
    }
    current->date.value = data;//записали в текущий элемент данные послеследующего элемента
    current->pNext->pNext = temporary->pNext;//вырезали послеследующий элемент, тем самым поменяв его и следующий местами
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
        pushBack(&lst, rand() % 15);//заполняем список рандомными числами
    }
    cout << "The list:\n";
    printList(lst);// выводим список на экран
    int key;
    do {
        cout << "Enter the key (0 - 15): ";
        cin >> key;
    } while (key < 0 || key > 15);
    //ввели ключ
    List* keyAddress = findKeyAddress(&lst, key);
    List* biggerThanKeyAddress = findBiggerThanKeyAddress(&lst, key);
    if (keyAddress != 0)
    {
        List* current = lst;
        while (current)
        {
            if (current == keyAddress)
            {
                if (current->pNext != NULL || current->pNext->pNext != NULL) //после ключа есть >= 2 элемента
                {
                    deleteAndReplace(&lst, current, current->pNext->pNext->date.value);
                    cout << "The list after general task:\n";
                    printList(lst);
                }
                else
                {
                    cout << "You cannot swap two elements following the key because there are less than 2 elements after the key!\n";
                    //после ключа меньше 2 элементов, невозможно поменять
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
    clearList(&lst);//удаляем список
    return 0;
}
