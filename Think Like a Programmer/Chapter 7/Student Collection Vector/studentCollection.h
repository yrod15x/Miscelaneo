#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H
#include <string>
#include <vector>

class studentCollection
{
    //Toca colocarla private antes de la declaraciones públicas
    private:
        struct student
        {
            int id;
            std::string name;
            int grade;
            //Permite poder comparar las estructuras por ID. Para poder usar sort() en el vector
            bool operator<(const student& rhs) const
            {
                return id < rhs.id;
            }
        };
    public:
        studentCollection();
        ~studentCollection();
        studentCollection(const studentCollection& other);
        void addRecord(int id, std::string name, int grade);
        void removeRecord(int id);
        void showRecord(int id);
        studentCollection& operator=(const studentCollection &rhs);
        void showAllRecords();

    private:
        std::vector<student> estudiantes;
        student record;
        int buscarPos(int id, std::vector<student> items);
};

#endif // STUDENTCOLLECTION_H
