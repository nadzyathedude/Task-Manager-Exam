
#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

#include <locale>
using namespace std;

struct task {
    string name;
    string  priority;
    string description;
    string  day;
    string month;
};

void print(task* array, int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << array[i].name << " " << array[i].priority << " " << array[i].description << " " << array[i].day << " " << array[i].month << " " << endl;
    }
}




void create(task* array, int k)
{

    for (int i = 0; i < k; i++)
    {
        cout << "Введите название дела" << endl;
        cin >> array[i].name;
        cout << " Введите приритет дела, где 1 - очень важно , 2 - важно, 3 - умеренной важности " << endl;
        cin >> array[i].priority;
        cout << "Введите описание дела " << endl;
        cin >> array[i].description;
        cout << "Введите дату исполнения " << endl;
        cout << "Если это число от первого до девятого включительно, то просто цифра (первое число, вводим 1, месяц аналогично) " << endl;
        cout << "День - " << "  ";
        cin >> array[i].day;
        cout << endl;
        cout << "Месяц - " << "  " << endl;
        cin >> array[i].month;
    }
}

void addNewTask(task* array, int k, task* array1, int todo)
{
    string name, priority, description, day, month;

    int index = todo;
    cout << "Введите название дела" << endl;
    cin >> name;
    cout << " Введите приритет дела, где 1 - очень важно , 2 - важно, 3 - умеренной важности " << endl;
    cin >> priority;
    cout << "Введите описание дела " << endl;
    cin >> description;
    cout << "Введите дату исполнения " << endl;
    cout << "Если это число от первого до девятого включительно, то просто цифра (первое число, вводим 1, месяц аналогично) " << endl;
    cout << "День - " << "  ";
    cin >> day;
    cout << endl;
    cout << "Месяц - " << "  " << endl;
    cin >> month;

    for (int i = 0; i < todo; i++)
    {
        array1[i] = array[i];
    }
    array1[todo + 1].name = name;
    array1[todo + 1].priority = priority;
    array1[todo + 1].description = description;
    array1[todo + 1].day = day;
    array1[todo + 1].month = month;
    for (int i = 0; i < k; i++)
    {
        array[i] = array1[i];
    }


    for (int i = 0; i < k; i++)
    {

        cout << array[i].name << " " << array[i].priority << " " << array[i].description << " " << array[i].day << " " << array[i].month << " " << endl;

    }
}


void Delete(task* array, int k, task* array1, int todo, string b)
{

    int index = 0;
    for (int i = 0; i < k; i++)
    {
        if (array[i].name == b)
        {
            index = i; break;
        }

    }
    cout << index << "-индекс" << endl;
    for (int i = 0; i < index; i++)
    {
        array1[i] = array[i];
    }
    for (int i = index + 1; i < k; i++)
        array1[i] = array[i];
    for (int i = 0; i < k; i++)
        array[i] = array1[i];


    for (int i = 0; i < todo; i++)
    {

        cout << array[i].name << " " << array[i].priority << " " << array[i].description << " " << array[i].day << " " << array[i].month << " " << endl;

    }

}




void addSmth(task* array, int k, string addIndex)
{
    string a;
    int choice;
    int index = -1;



    cout << "Если вы хотите добавить что-то в название дела, нажмите  1 " << endl;
    cout << "Если вы хотите добавить что-то в описание дела, нажмите  2 " << endl;
    cin >> choice;
    cout << "Что вы хотите добавить?" << endl;
    cin >> a;
    int size;
    switch (choice)
    {
    case 1:
        for (int i = 0; i < k; i++)
        {
            index++;
            if (array[i].name == addIndex)
            {
                break;
            }
        }
        size = array[index].name.size();
        array[index].name.insert(size, " ");
        size = array[index].name.size();

        array[index].name.insert(size, a);

        cout << array[index].name << " " << array[index].priority << " " << array[index].description << " " << array[index].day << "  " << array[index].month << endl;


        break;

    case 2:
        for (int i = 0; i < k; i++)
        {
            index++;
            if (array[i].name == addIndex)
            {
                break;
            }
        }
        size = array[index].description.size();
        array[index].description.insert(size, " ");
        size = array[index].description.size();

        array[index].description.insert(size, a);

        cout << array[index].name << " " << array[index].priority << " " << array[index].description << " " << array[index].day << "  " << array[index].month << endl;



        break;
    }


}

void replaceSmth(task* array, int k, int ch)
{

    string a, b;
    if (ch == 1)
    {
        cout << "Какое название  вы хотите удалить? " << endl;
        cin >> a;
        cout << "На какое название вы хотите его заменить?";
        cin >> b;

        int num;
        for (int i = 0; i < k; i++)
        {
            if (array[i].name == a)
            {
                num = i;
                array[num].name = b;
            }
        }



        cout << array[num].name << " " << array[num].priority << " " << array[num].description << " " << array[num].day << "  " << array[num].month << endl;


    }

    else if (ch == 2)
    {
        cout << "Какой приоритет   вы хотите удалить? " << endl;
        cin >> a;

        cout << "На какое приоритет вы хотите его заменить?";
        cin >> b;

        int num;
        for (int i = 0; i < k; i++)
        {
            if (array[i].priority == a)
            {
                num = i;
                array[num].priority = b;
            }
        }


        cout << array[num].name << " " << array[num].priority << " " << array[num].description << " " << array[num].day << "  " << array[num].month << endl;

    }

    else if (ch == 3)
    {
        cout << "Какое описание  вы хотите удалить? " << endl;
        cin >> a;

        cout << "На какое описание  вы хотите его заменить?" << endl;
        cin >> b;

        int num;
        for (int i = 0; i < k; i++)
        {
            if (array[i].description == a)
            {
                num = i;
                array[num].description = b;
            }
        }


        cout << array[num].name << " " << array[num].priority << " " << array[num].description << " " << array[num].day << "  " << array[num].month << endl;

    }

    else if (ch == 4)
    {
        string aa, bb;
        cout << "Какую дату  вы хотите удалить? " << endl;
        cout << "Введите день " << endl;
        cin >> aa;
        cout << "Введите месяц " << endl;
        cin >> a;

        cout << "На какую дату  вы хотите заменить? " << endl;
        cout << "Введите день " << endl;
        cin >> bb;
        cout << "Введите месяц " << endl;
        cin >> b;


        int numm; int num;
        for (int i = 0; i < k; i++)
        {
            if (array[i].month == a)
            {
                numm = i;
                array[numm].month = b;
            }

            if (array[i].day == aa)
            {
                num = i;
                array[num].day = bb;
            }
        }


        cout << array[num].name << " " << array[num].priority << " " << array[num].description << " " << array[num].day << "  " << array[numm].month << endl;

    }

}


void searchByName(task* array, int k, string a)
{
    bool b = 0;
    int num;
    for (int i = 0; i < k; i++)
    {
        if (array[i].name == a)

        {
            b = 1; num = i;
        }
    }
    if (b == 1)
    {
        cout << array[num].name << endl;
        cout << array[num].priority << endl;
        cout << array[num].description << endl;
        cout << array[num].day << " " << array[num].month << endl;
    }
    else cout << "Нет такого дела" << endl;

}

void searhByPriority(task* array, int k, string a)
{

    bool b = 0;
    int num;
    for (int i = 0; i < k; i++)
    {
        if (array[i].priority == a)

        {
            b = 1; num = i;
        }
    }
    if (b == 1)
    {
        cout << array[num].name << endl;
        cout << array[num].priority << endl;
        cout << array[num].description << endl;
        cout << array[num].day << " " << array[num].month << endl;
    }
    else cout << "Нет такого дела" << endl;
}

void searchByDescription(task* array, int k, string a)
{
    bool b = 0;
    int num;
    for (int i = 0; i < k; i++)
    {
        if (array[i].description == a)

        {
            b = 1; num = i;
        }
    }
    if (b == 1)
    {
        cout << array[num].name << endl;
        cout << array[num].priority << endl;
        cout << array[num].description << endl;
        cout << array[num].day << " " << array[num].month << endl;
    }
    else cout << "Нет такого дела" << endl;
}

void searchByDate(task* array, int k, string a, string b)
{
    bool bb = 0;
    int num;
    for (int i = 0; i < k; i++)
    {
        if (array[i].month == a && array[i].day == b)

        {
            bb = 1; num = i;
        }
    }
    if (bb == 1)
    {
        cout << array[num].name << endl;
        cout << array[num].priority << endl;
        cout << array[num].description << endl;
        cout << array[num].day << " " << array[num].month << endl;
    }
    else cout << "Нет такого дела" << endl;
}

void printDay(task* array, int k, string Currentday, string Currentmonth)
{

    int count = 0;
    for (int i = 0; i < k; i++)
    {
        if (array[i].day == Currentday && array[i].month == Currentmonth)
            count++;

    }
    task* temp = new task[count];
    for (int i = 0; i < count; i++)
    {
        if (array[i].day == Currentday && array[i].month == Currentmonth)
            temp[i] = array[i];
        else cout << "Таких дел нет!" << endl;

    }

    print(temp, count);

}
void printWeek(task* array, int k)
{
    int  count=0;
  
    string first, last;
    cout << "Введите начальную дату недели" << endl;
    cin >> first;
    cout << "Введите конечную дату недели" << endl;
    cin >> last;
    
    for (int i = 0; i < k; i++)
    {
        if (array[i].day >= first && array[i].day <= last)

        count++;
    }

        task* temp = new task[count];

        for (int i = 0; i < count; i++)
        {
            if (array[i].day >= first || array[i].day <= last)
            temp[i] = array[i];
            else cout << "Таких дел нет!" << endl;

        }
        print(temp, count);
    
            

}

void printMonth(task* array, int k, string Currentmonth)
{
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        if (array[i].month == Currentmonth)
            count++;

    }
    task* temp = new task[count];
    for (int i = 0; i < count; i++)
    {
        if (array[i].month == Currentmonth)
            temp[i] = array[i];
        else cout << "Таких дел нет!" << endl;

    }


}

void sortByPriority(task* array, int k)
{
    task  tmp;
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            if (array[j + 1].priority < array[j].priority)  
            {
                tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void sortByDate(task* array, int k)
{
    task  tmp;
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            if (array[j + 1].day > array[j].day && array[j + 1].month > array[j].month)  //по убыванию
            {
                tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int n = 20, todo;
    cout << "В вашей записной книжке помещается 20 дел" << endl;
    cout << "Введите кол-во дел  ";
    cin >> todo;

    task* array1 = new task[20];
    task* array2 = new task[20];
    task* array = new task[20];
    create(array, todo);
  
    print(array, todo);

    int choice;
    while (1)
    {
        cout << "Выберите действие:" << endl;
        cout << "Удалить дело -> 1" << endl;
        cout << "Редактировать дело -> 2" << endl;
        cout << "Поиск дела -> 3" << endl;
        cout << "Отобразить дела -> 4" << endl;
        cout << "Сортировать дела -> 5" << endl;
        cout << "Добавить еще одно дело -> 6" << endl;
        cout << "Выход -> 7" << endl;
        cin >> choice;
        string a;
        int b;
        string Currentday;
        string Currentmonth;
        int chooseSort;

        switch (choice)
        {

        case 1:
            cout << "Вы выбрали удалить дело. Чтобы удалить дело, введите его имя" << endl;
            cin >> a;
            Delete(array, n, array1, todo, a);




            break;

        case 2:

            cout << "Вы выбрали редактировать дело " << endl;

            cout << "Введите название дела" << endl;
            cin >> a;
            cout << "Если хотите что-то добавить, нажмите 1. Если убрать, нажмите 2" << endl;
            cin >> b;
            if (b == 1)
            {

                addSmth(array, n, a);


            }

            else if (b == 2)
            {
                cout << "Что хотите заменить " << endl;
                cout << "Заменить  название -1 " << endl;
                cout << "Заменить приоритет - 2" << endl;
                cout << "Заменить  описание  - 3" << endl;
                cout << "Заменить  дату - 4" << endl;
                int ch;
                cin >> ch;

                replaceSmth(array, n, ch);

            }
            break;

        case 3:
            cout << "Вы выбрали поиск дела" << endl;
            cout << "Для поиска по названию нажмите 1" << endl;
            cout << "Для поиска по приоритету нажмите 2" << endl;
            cout << "Для поиска по описанию нажмите 3" << endl;
            cout << "Для поиска по дате исполнения нажмите 4" << endl;
            cin >> b;

            if (b == 1)
            {
                cout << "Вы выбрали поиск по названию. Введите название дела" << endl;
                cin >> a;
                searchByName(array, n, a);
            }
            if (b == 2)
            {
                cout << "Вы выбрали поиск по приоритету. Введите введите приоритет дела дела" << endl;
                cin >> a;
                searchByDescription(array, n, a);
            }
            if (b == 3)
            {
                cout << "Вы выбрали поиск по описанию. Введите описание  дела" << endl;
                cin >> a;
                searchByDescription(array, n, a);

            }
            if (b == 4)
            {
                string d;
                cout << "Вы выбрали поиск по дате. Введите дату исполнения  дела - день" << endl;
                cin >> d;
                cout << "Вы выбрали поиск по дате. Введите дату исполнения  дела - месяц" << endl;
                cin >> a;
                searchByDate(array, n, a, d);

            }

            break;


        case 4:
            cout << "Вы выбрали отображение дел" << endl;
            cout << "Если хотите отобразить дела на день, нажмите 1" << endl;
            cout << "Если хотите отобразить дела на неделю, нажмите 2" << endl;
            cout << "Если хотите отобразить дела на месяц, нажмите 3" << endl;
            cin >> b;


            if (b == 1)
            {
                cout << "Введите текущую дату - день" << endl;
                cin >> Currentday;
                cout << "Введите текущую дату - месяц" << endl;
                cin >> Currentmonth;
                printDay(array, todo, Currentday, Currentmonth);

            }

            if (b == 2)
            {

                printWeek(array, todo);

            }

            if (b == 3)
            {
                cout << "Введите текущую дату - день" << endl;
                cin >> Currentday;
                cout << "Введите текущую дату - месяц" << endl;
                cin >> Currentmonth;
                printMonth(array, todo, Currentmonth);

            }
            break;

        case 5:
            cout << "Вы выбрали сортировать дела" << endl;
            cout << "Для сортировки по приоритету нажмите 1" << endl;
            cout << "Для сортировки по дате исполнения нажмите 2" << endl;
            cin >> b;
            if (b == 1)
            {
                sortByPriority(array, todo);
                print(array, todo);
            }
            if (b == 2)
            {
                sortByDate(array, n);
                cout << "Будет отсортированно по убыванию" << endl;
                print(array, todo);
            }

            break;
        case 6:

            cout << "Вы выбрали добавить дело" << endl;

            addNewTask(array, n, array2, todo);
            break;
        }
        if (choice == 7) break;
    }
}



