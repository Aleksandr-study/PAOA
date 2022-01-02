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
        push_back(&lst, rand() % 15);//заполняем список рандомными числами
    }
    cout << "The list:\n";
    print(lst);// выводим список на экран
    int key;
    do {
        cout << "Enter the key (0 - 15): ";
        cin >> key;
    } while (key < 0 || key > 15);
    //ввели ключ
    List* key_address = find_key_address(&lst, key);
    if (key_address != 0)
    {
        List* current = lst;
        while (current)
        {
            if (current == key_address)
            {
                if (current->pNext != NULL || current->pNext->pNext != NULL) //после ключа есть >= 2 элемента
                {
                    delete_and_replace(&lst, current, current->pNext->pNext->date.value);
                    cout << "The list after insert:\n";
                    print(lst);
                }
                else
                {
                    cout << "You cannot swap two elements following the key because there are less than 2 elements after the key!\n";
                    //Нельзя поменять местами два элемента идущих после ключа потому что после ключа меньше 2 элементов
                }
            }
            current = current->pNext;
        }
    }
    return 0;
}
