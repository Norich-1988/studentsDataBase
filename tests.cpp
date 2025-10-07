#include "gtest/gtest.h"
#include "students.h"

// Тест 1: Успешное удаление существующего студента
TEST(RemoveStudentTest, RemovesExistingStudent) {
    // Arrange (Подготовка)
    std::vector<Student> db = {{"Иван", 20, "ИТ", 4.5}, {"Петр", 21, "Физика", 4.0}};
    
    // Перенаправляем cin для автоматического ввода "Иван" и "y"
    std::streambuf* orig_cin = std::cin.rdbuf();
    std::istringstream input("Иван\ny\n");
    std::cin.rdbuf(input.rdbuf());

    // Act (Действие)
    removeStudent(db);

    // Assert (Проверка)
    std::cin.rdbuf(orig_cin); // Восстанавливаем cin
    ASSERT_EQ(db.size(), 1);
    ASSERT_EQ(db[0].name, "Петр");
}

// Тест 2: Попытка удаления несуществующего студента
TEST(RemoveStudentTest, HandlesNonExistingStudent) {
    std::vector<Student> db = {{"Иван", 20, "ИТ", 4.5}};
    std::streambuf* orig_cin = std::cin.rdbuf();
    std::istringstream input("Анна\n");
    std::cin.rdbuf(input.rdbuf());

    removeStudent(db);

    std::cin.rdbuf(orig_cin);
    ASSERT_EQ(db.size(), 1); // База не должна измениться
}

// Тест 3: Удаление из пустого списка
TEST(RemoveStudentTest, WorksWithEmptyList) {
    std::vector<Student> db;
    std::streambuf* orig_cin = std::cin.rdbuf();
    std::istringstream input("Иван\n");
    std::cin.rdbuf(input.rdbuf());

    removeStudent(db);

    std::cin.rdbuf(orig_cin);
    ASSERT_TRUE(db.empty());
}

// Тест 4: Отмена удаления студента
TEST(RemoveStudentTest, DeletionCancelled) {
    std::vector<Student> db = {{"Иван", 20, "ИТ", 4.5}};
    std::streambuf* orig_cin = std::cin.rdbuf();
    std::istringstream input("Иван\nn\n"); // Вводим 'n' для отмены
    std::cin.rdbuf(input.rdbuf());

    removeStudent(db);

    std::cin.rdbuf(orig_cin);
    ASSERT_EQ(db.size(), 1); // Студент должен остаться
    ASSERT_EQ(db[0].name, "Иван");
}

// Тест 5 (юнит-тест на другую функцию): Проверка добавления студента
TEST(AddStudentTest, AddsStudentCorrectly) {
    std::vector<Student> db;
    std::streambuf* orig_cin = std::cin.rdbuf();
    std::istringstream input("Мария\n22\nХимия\n5.0\n");
    std::cin.rdbuf(input.rdbuf());

    addStudent(db);

    std::cin.rdbuf(orig_cin);
    ASSERT_EQ(db.size(), 1);
    ASSERT_EQ(db[0].name, "Мария");
    ASSERT_EQ(db[0].age, 22);
}