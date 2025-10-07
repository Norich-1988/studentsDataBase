#include "students.h"

void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;
    
    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

void displayStudents(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных студентов пуста.\n";
        return;
    }
    
    std::cout << "--- Список студентов ---\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

void removeStudent(std::vector<Student>& database) {
    std::string nameToRemove;
    std::cout << "Введите имя студента для удаления: ";
    std::cin >> nameToRemove;

    // Сначала просто находим итератор на студента, не удаляя его
    auto it = std::find_if(database.begin(), database.end(),
        [&](const Student& student) {
            return student.name == nameToRemove;
        });

    // Проверяем, был ли студент вообще найден
    if (it == database.end()) {
        std::cout << "Студент с именем '" << nameToRemove << "' не найден.\n";
    } else {
        // Студент найден, теперь запрашиваем подтверждение
        std::cout << "Найден студент: " << it->name << ", Возраст: " << it->age
                  << ". Вы уверены, что хотите удалить? (y/n): ";
        char confirmation;
        std::cin >> confirmation;

        if (confirmation == 'y' || confirmation == 'Y') {
            database.erase(it); // Удаляем только если пользователь согласился
            std::cout << "Студент '" << nameToRemove << "' успешно удален.\n";
        } else {
            std::cout << "Удаление отменено.\n";
        }
    }
}