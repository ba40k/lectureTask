# lectureTask
Это проект Ткаченко Радомира из группы 4

Главное:

В диалогах можно нажимать на Enter для ввода

Реализованы адаптивные размеры таблицы при растягивании и сужении окна

Все ключевые функции покрыты тестами (21 тест в фреймворке Google Test)

Использованы все указанные виды умных указателей

Предусмотрены крайние случаи при удалении книг и пользователей 

Все диалоги пользовательские

Краткое описание:

Вот какое окно встречает пользователя при запуске программы
![img.png](img.png)
Мы видим пустую таблицу, и кнопки меню с доступными действиями

Если навести мышкой на действия, то выпадет следующий список
![img_1.png](img_1.png)

Добавим книгу
![img_2.png](img_2.png)
![img_3.png](img_3.png)
Теперь добавим пользователя, чтобы было понятнее
![img_4.png](img_4.png)
![img_6.png](img_6.png)
Заметим, что нам не надо вводить его id, программа сама сгенерирует уникальный номер.
Появился столбец с именем пользователя.
Пока что он занимает все пространство, так как он только один
На пересечении столбца с Именем пользователя и названием книги можно записать брал ли пользователь эту книгу.

Кроме имени пользователя в столбце написан его id

Теперь продемонстрируем, что будет если ввод неккоректный
![img_7.png](img_7.png)
![img_8.png](img_8.png)
Аналогично программа будет реагировать, если ввести в качестве года издания строку и тп.

Теперь попробуем найти пользователя
![img_9.png](img_9.png)
![img_10.png](img_10.png)
Аналогично с книгами.
Теперь удалим пользователя
![img_11.png](img_11.png)
![img_12.png](img_12.png)
С книгами аналогично.
