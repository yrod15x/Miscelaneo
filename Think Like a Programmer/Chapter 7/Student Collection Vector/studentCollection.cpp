#include "studentCollection.h"
#include "iostream"
#include <algorithm>

studentCollection::studentCollection()
{
    //ctor
    estudiantes.clear();
}

studentCollection::~studentCollection()
{
    //dtor
}

studentCollection::studentCollection(const studentCollection& other)
{
    //copy ctor
    estudiantes.clear();
    for(student rec:other.estudiantes)
    {
        estudiantes.push_back(rec);
    }
}

void studentCollection::showAllRecords()
{
    for(student &rec:estudiantes)
    {
        std::cout << rec.id << " - " << rec.name << " - " << rec.grade << '\n';
    }
}

void studentCollection::addRecord(int id, std::string name, int grade)
{
    record.grade = grade;
    record.id = id;
    record.name = name;

    estudiantes.push_back(record);
}

int studentCollection::buscarPos(int id, std::vector<student> items)
{
    int inicio = 0;
    int fin = items.size() - 1;
    int mid = 0;

    while(inicio <= fin)
    {
        mid = inicio + (fin - inicio) / 2;
        if(id == items[mid].id)
        {
            return mid;
        }
        if(id > items[mid].id)
        {
            inicio = mid + 1;
        }
        else
        {
            fin = mid - 1;
        }
    }
    return -1;

}

void studentCollection::removeRecord(int id)
{
    std::sort(estudiantes.begin(), estudiantes.end());
    int pos = buscarPos(id, estudiantes);

    if(pos != -1)
    {
        estudiantes.erase(estudiantes.begin() + pos);
    }

}

void studentCollection::showRecord(int id)
{
    int pos = buscarPos(id, estudiantes);
    if(pos >= 0)
    {
        std::cout << estudiantes[pos].name << '\n';
    }
    else
    {
        std::cout << "No record found\n";
    }
}

studentCollection& studentCollection::operator=(const studentCollection &rhs)
{
    if(this != &rhs)
    {
        estudiantes.clear();
        for(student rec:rhs.estudiantes)
        {
            estudiantes.push_back(rec);
        }
    }
}
