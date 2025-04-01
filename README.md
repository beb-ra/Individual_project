# Описание индивидуального проекта
## Выбранная предметная область: Библиотека.
### Цель работы: Разработка программного обеспечения для автоматизации и оптимизации процессов управления библиотекой, включая учет книг, читателей и операций.
### Задачи проекта:
1.	Реализовать программное обеспечение для учета библиотечного фонда, читателей, сотрудников и операций.
2.	Приложение должно обеспечивать возможность администратору быстро и легко выполнять функции:
-	Регистрировать / редактировать данные читателей
-	Вести учет выданных и возвращенных книг
-	Продлевать срок выдачи книг
-	Вести учет задолженностей читателей
-	Осуществлять комплектование фонда (прием новых книг, заказ книг)
-	Списывать устаревшие или поврежденные книги
 и др.

### Функциональные требования:
Приложение реализуется в виде windows-приложения с удобным навигационным меню, качественным отображением информации и простыми формами для заполнения данных.
Основные возможности, которые будут предусмотрены приложением:
1.	Приложение реализуется с авторизацией по логину/паролю.
2.	Основной режим работы приложения упрощает работу администратора, предоставляет все необходимые ему функции (учет библиотечного фонда, читателей, операций), однако ограничивает доступ к информации о сотрудниках.
3.	Доступ к особому режиму создания/изменения сотрудников, назначения им окладов, мониторингу их работы будет осуществляться по особому логину/паролю, которые будут выданы директору.
4.	Все данные будут храниться в csv-формате и подтягиваться при очередном запуске приложения. 
5.	При запуске приложения на основе текущей даты удаляется неактуальная информация.
![image](https://github.com/user-attachments/assets/5e5c008d-35e9-4672-bc4c-08a1289fad17)

### Класс TVector. Функциональные требования. 
Класс TVector обязан реализовывать следующие функциональные возможности: 
1. Возможность создания 
a) пустого вектора по умолчанию, 
b) вектора заданного размера, 
c) вектора, созданного на основе переданного массива данных, 
d) конструктор копирования + иные способы создания вектора; а также уничтожения. 
2. Функции: data(), size(), capacity(), front(), back() + функции begin(), end(). 
3. Функция проверки на пустоту is_empty(). 
4. Стандартные функции вставки: push_front(), push_back(), insert().
5. Стандартные функции удаления: pop_front(), pop_back(), erase(). 
6. Функция замены значения emplace(). 
7. Функция присваивания assign(), функция обращения по индексу at() с проверкой допустимости индекса, функция очистки вектора clear(). 
8. Функция shrink_to_fit() для возврата дополнительной памяти в систему. Функция резервирования памяти заданного размера reserve(); если меньше текущей памяти – ничего не происходит. Функция изменения размера массива resize() с заполнителем и без (работает как на расширение памяти, так и на сжатие). 
9. Должны быть перегружены операторы: присваивания =, сравнения !=, ==, оператор [].
