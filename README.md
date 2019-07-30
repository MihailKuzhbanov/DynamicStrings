# DynamicStrings
Test task
Реализовать класс динамических строк, который:

1. Написан на C++11 без каких либо сторонних библиотек. Не использует в своей основе 
какую-либо другую реализацию динамических строк, контейнеров или умных указателей STL.

2. Имеет конструктор копирования, оператор присваивания и поддерживает move-семантику.
У класса есть "внешний" оператор сложения двух строк.

3. Поддерживает строки произвольного размера, используя базовые операции работы с 
динамическим хипом (функции malloc()/free() или операторы new/delete).


Написать пример с использованием этого класса строк и какого-либо контейнера STL. 
Программа должна принимать список строк, затем выдавать его в порядке, обратном
лексикографическому без учета регистра.

Программа-пример работает из командной строки.
