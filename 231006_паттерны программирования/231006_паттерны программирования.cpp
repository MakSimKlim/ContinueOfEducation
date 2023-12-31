﻿// 231006_паттерны программирования
//
//сложности при разработке ПО:
/*
Высокая сложность создаваемых систем:
-большие размеры
-большая функциональность
-требования пользователей часто меняются
-высокие требования к опыту пользователя

ООП - парадигма программирования.
Парадигма - это подход к концептуализации проекта, который определяет, как проводятся вычисления 
и как должна быть структурирована работа компьютера.

Декомпозиция -  процесс разбиения задачи на отдельные, структурно связанные части.
Процедурная д. - в задаче  выделяется алгоритмами и структурами данных.
Логическая д. - правила, связывающие определенные понятия.
ОО д. - в задаче выденляются классы объектов и их взаимодействие.

Абстрагирование - способность отделить логический смысл фрагмента программы от его реализации.

Модульность - метод создания и управления совокупности имён и связанными с ними значениями.
Суть модуля в разбиении пространства имён на открытую и закрытую чать (public, private)

Иерархия - упорядоченная система абстракций.


================================  Парадигмы  ================================


       1. Процедурно-ориентированная парадигма
Мысль, что любую задачу можно записать, как последовательность простых действий, 
которую выполняет компьютер. Исходным понятием является алгоритм.
Алгоритм - последовательность действий направленная на достижение поставленной цели.
Блок-схемы. 
Процедура - алгоритм, применительный к решению задач на компьютере.
Разработка больших программ потребовала разбиения их на небольшие последовательности инструкций. 
Основой для их разбиения и стала процедурная декомпозиция.
ПРограмма разбивается на отдельные части - модули.
Особенность процедурного программирования состоит в выделении моментов начала и конца.
Для выполнения текущей процедуры требуется завершение выполнения инструкций предыдущей.
Изменение этого порядка действий потребовало включения специального синтаксиса:
if -else и goto.
Спагетти код - сложный и запутанный код с применением goto.
Хорошим стилем программирования считается отказ от goto
Методология структурного программирования - процедурная декомпозиция программной системы 
и организация отдельных модулей в виде совокупностивыполняемых процедур
В рамккахэтой методологии получило развитие нисходящее проектирование, 
оно же программирование сверху-вниз


       2. Объектно-ориентированное программирование
Фундаментальные понятия ООП - объект и класс.
Класс- это совокупность объектов, которые имеют одинаковые свойства и поведение. 
Объект - это экземпляр соответствующего класса.
Три основных принципа ООП - инкапсуляция, полиморфизм, наследование.
     - Инкапсуляция - сокрытие деталей внутреннего устройства класса от внешних 
по отношению к нему объектов или пользователей. Происходит от деления модуля на две части:
интерфейс (*.h) и реализацию (*.cpp).
     - Наследование- это принцип в соответствии с которым знание
о более общей котегории можно применить к более узкой категории.
     - Полиморфизм - способность некоторых объекутов применять различные 
внешние формы. В ООП это значит, что действия выполняемые одноименными методвами иогут
отличаться в зависимости от того, кому принадлежит метод.
Объектно-ориентированная декомпозиция - отдельными структурнными единицами кода
являются не процедуры и функции, а классы и объекты, с их атрибутами и методами.
программа перестала быть последовательностью предопределенных действий.
Вместо программирования сверху-вниз программы стали событийно - ориентированными.
Это значит, что программа представляет собой бесконечный цикл ожидания
некоторых заранее определенных событий, исходящих от других программ или пользователей.

     
     3.Методология объектно-ориентированного анализа и проектирования (ООАП).
ООАП.
Процесс выделения компонентов предметной области называется концептуализацией.
Компонент - это некоторая абстрактная единица, обладающая функциональностью.
Аналитик (архитектор) - участвует в построении концептуальной схемы вместе
с разработчиками, которая в дальнейшем преобразуется в код.
 При посроении схемы выделяются компоненты, которые затем можно удобно 
 представить в виде классов и объектов.
 Такое разделение проецесса разработки привело к появлению
 концепции жизненного цикла программы.
 Это совокупность этапов разработки программы от разработки требований 
 до отказа от использования.
  - анализ предметной области и формулировка требований к программе
  - проектирование струкутуры программы.
  - реализация программного кода (программирование)
      1. тестирование (сливается с реализацией))
  - внедрение программы
  - сопровождение программы (выпуск патчей, обновлений и улучшений программы),
  это самый длительный процесс.
  - отказ от использования (стоимость сопровождения слишком высокая, устарела
  программа, изменилась платформа и т.д.)
Методология ООАП тесно связана с концепцией автоматизированной
разработки ПО (Computer Aided Software Engineering - CASE)


      4. Методология системного анализа и системного моделирования 
Система- совокупность объектов, компонентов или элементов произвольной природы, 
образующих некую целостность.
Предпосылка выделения некоей совокупности, как системы - это появление у неё 
свойств, неприсущих её элементам.
Структура и процесс функционирования.
Структура - устойчивая по времени совокупность внутренних взаимосвязей системы.
Структура может отражать вложенность элементов одной системы в другую.
В этом случае, вложенную малую систему называют подсистемой, 
а более крупную - метасистемой.
Важная характеристика системы - это состояние, то есть совокупность признаков
и свойств системы, котрые отражают её наиболее существенные особенности поведения
Процесс функционирования системы - последовательное изменение состояний этой системы.
Соввокупность признаков при изменении состояния и условий его изменения
называется переходом.
Системно-ориентированная декомпозиция.
Важным является построение модели системы.
Процесс построения и применения моделей для получения информации о системе 
называется моделирование.
Наиболее общей моделью является модель - "черный ящик". В этой модели
система почти изолирована от окружающей среды, кроме существующих у неё входных 
воздействий. Также система оказывает воздействие нра другие системы через их входные воздействия.
Для этого она использует свои выходные воздействия.
Сложность системы можно описать как 
   - сложность структуры, то есть количество элементов и количество их взаимосвязей
   - сложность процессаа функционирования - как часто и при насколько предсказуемых
   и простых условиях меняются состояния

========================     Классы и объекты       ==========================

Объект - понятие, абстракция, или конкретная вещь с чётко очерченными границами,
которая имеет смысл в контексте рассматриваемой прикладной задаче,
Ведение объектов имеет две цели:
 - понимание прикладной задачи
 - ведение основы для реализации на компьютере.
Объект обладает состоянием, поведением и индивидуальностью.
Объекты существуют во времени, изменяются, имеют внутреннее состояние, могут быть 
созданы, разрушены, разделены - то есть преходящи.
Структура и поведение схожих объектов определяет для них общий класс.
 
Состояние объекта - это перечень всех возможных свойств данного объекта 
и текущие значения этих свойств. Обычно свойства статичны, а значение динамичны
 
Поведение - последовательность совершаемых над объектом действий. Это то
как объект воздействует на другие объекты, изменяя их состояние, и как другие объекты
воздействуют на него, изменяя его состояние.

Объединение в классы позволяет ввести абстракцию. 
У класса есть имя. Кроме того класс описывает имена атрибутов.

Атрибут - некое значение, которое характеризует объект в классе.
(например фамилии у студентов). 
Среди атрибутов различают константные и переменные.
Константные характеризуют объект в классе. Переменные описывают текущее состояние объектов.
(имя, фамилия у студентов - константные, средняя оценка - переменные атрибуты)
Изменяя атрибуты, изменяем состояние объекта.

                         Операции над объектом 

Операция -функция, которую можно применять к объектам некоего класса
Все объекты класса используют один и тот же экземпляр операции. 
Объект, из которого вызвана операция, передается внутри неё, как this
(в Python'е - Self). 
Полиморфные операции - операции, которые могут быть применены к объектам
разных классов (например сложение).
Внутри класса, операции соответствуют методы - это реализация операций для объектов классов.
Операция определяется сигнатурой (интерфейсом), включает в себя: имя операции,
типы аргументов, типы результата.
Все методы реализующие операцию должны иметь такую же сигнатуру.
Состояние объекта - это значения его атрибутов (они характеризуют состояние объекта).
При моделировании систем различают 2 вида операций:
 - Операции, которые изменяют состояние объекта (имеют побочные эффекты)
 - Операции, которые только возвращают нужные значения, не изменяя состояния объекта - 
их называют запросы.

Значение некоторых атрибутов можно узнать только через запросы.
Запросы без аргументов рассматривают, как производные атрибуты (например length).
length - считается производным атрибутом.

                         Распространенные операции
1. Конструктор
2. Деструктор
3. Итератор - организует доступ к полям объекта в некоей последовательности (например по индексу внутри массива)
4. Модификатор - изменяет состояние объекта путем записи.
5. Селектор - дает доступ к элементам, определяющим состояние системы без  его изменения.

                        Отношения между объектами

Отношения можно определять по тому, что объекты знают друг о друге, 
а также о доступных в отношении операциях и об ожидаемом поведении.
2 типа отношений:
- связи
- агрегации

В отношении "связи" объекты выполняют определенные роли:
- Актёр (Actor - активный объект) - объект, который может действовать, но не подвержен воздействию
- Сервер (исполнитель) - объект, который управляется другими объектами, но никогда сам не активен
- Агент (посредник или брокер) - выполняет роль и актера и сервера, как правило 
вспомогательный для "актёра".

Агрегация - это отношение типа часть-целое. Целое - это агрегат, его части - атрибуты. 
Может быть реализована, как физическое вхождение одного лобъекта в другой, 
но может быть иметь и другую семантику, например, принадлежность (например Журнал - агрегат, студенты - его атрибуты).
(Филиал - сотрудники с указателем на филиал, поэтому филиал - агрегат для сотрудников)

                        Формальное определение класса

Класс - множество объектов, связанных общностью структуры и поведения.
Выделяют интерфейс и реализацию класса.,

Интерфейс (сигнатура) - виден всем, это внешний облик и сигнатура методов.

Реализация (код) - защищенное от других внутреннее устройство.

Класс задается указанием имени класса и последующим перечислением его атрибутов и методов.
Объект - структура данных, тип которой соответствует классу объекта.
Разные классы могут состоять в отношении наследования. Класс, который расширяет
или специализирует, это подкласс. Класс, который расширяется или более общий - это суперкласс, или
родительский класс.

Иногда в подклассе переопределяют операции из его суперкласса. Для этого операция суперкласса
может быть получена из этого суперкласса, а её определение в подклассе заслоняет
определение из суперкласса, так что в подклассе применяется новая операция.
(например в подклассе переопределяется какой-то из методов его родителя, то создается новый
набор инструкций, в который мы потом и переходим, а не в инструкции суперкласса,
при этом набор инструкций суперкласса никуда не девается и их можно применят в дальнейшем)

Переопределение преследует следующие цели:
- расширение: расширить унаследованную операцию с учетом атрибутов наследника
- ограничение: из-за специфики подкласса, может требоваться выполнение лишь части действий
- оптимизация: специфика подкласса позволяет реализовать какие-то вещи быстрее
- удобство чтения или определения

При реализации ОТНОШЕНИЙ между классами, на практике ОНИ получаются следующего вида:
- ассоциация - смысловая связь между классами, отношения один-к-одному, один-к-многим, многие-к-многим 
- аналогии - они выявляются через обобщение и наследование, формируя многоуровневую классификацию. Есть 
ещё способ реализации - делегирование. Объекты рассматриваются в качестве образцов, 
которые делегируют поведение другим объектам. Позволяет не создавать новые классы
- агрегация - когда одни объекты являются частями другого.
- отношение разницы и отношение общности (классификации)
- полиморфизм
- использование
- наполнение или сборный класс. Однородные и неоднородные классы.
- метаклассы (класс классов) - (например механизм интерфейсов в с# где полностью абстрактные классы)
в которых классы трактуются как объекты


                         Отношения между классами и объектами

Классификация - это упорядочивание знаний
Методы классификации:
- классический - распределение по категориям
- концептуальный - сначала сформировать концептуальное описание, а затем распределить по категориям
- теория прототипов


================================ Диаграммы ================================

Структурный системный анализ - метод иссследования системы от общего описания к последующей детализации
Общая модель системы строится в виде некой структуры, которая отражает различные уровни абстракции 
с ограниченным числом компонентов на каждом уровне.
На каждом уровне выделяются наиболее существенные компоненты
Для визуального отображения принято рассматривать три графические нотации:
- диаграммы сущность-связь (Entity-Relationship Diagrams, EDR)
- диаграммы функционального моделирования (Structured Analysis and Design Technique,SADT)
- диаграммы потоков данных (Data Flow Diagrams, DFD)


                            Диаграммы сущность-связь

Предназначены для графического представления моделей данных
Основные понятия: сущность и связь
Сущность (Entity) - произвольное множество объектов, каждый из которых имеет 
схожее свойство и характеристики.
Каждый объект системы может являться экземпляром только одной сущности,
должен иметь уникальное имя (идентификатор) и отличаться от других экземпляров той же сущности.
(Банк, клиент банка, автомобиль, его водитель, много преподаввателей, один факультет и т.д.)

Графическая модель отображает не только сами связи, но и их аспекты - обязательность связи, 
а также кратность участвующих в отношении сущностей

В одном филиале - более одного сотрудника. Каждый сотрудник работает только в одном филиале

Каждый сотрудник может работать более чем над одним проектом, 
над одним проектом работают более одного сотрудника.


                       Диаграммы функционального моделирования

SADT 
Integrated Computer Aided Manufacturing, ICAM
IDEF0 - нотация, для документирования процессов производства и отображении информации
об использованнии ресурсов
IDEF1 - нотация, для документирования информации об окружении систем (в 1985 расширена до IDEFIX)
IDEF2 - нотация, для документирования поведения системы во времени (не была реализована полностью)
IDEF3 - нотация, для моделирования бизнес процессов

в 1991 г  появилась группа пользователей IDEF User Group для стандартизации нотаций.
в 1993 г был создан стандарт FIPS , который используется и сейчас в коммерческих 
и правительственных организациях, он в том числе применялся в CASE -средствах

                   Основные понятия, связанные с методологией
Деятельность - некоторые действия или набор действий, которые приводят к некоему конечному результату
Иногда также называют процессом (отображается в виде блоков)
Отображаются в  виде прямоугольника, называемого блоком. Стрелки вокруг блокаиспользуют для обозначения взаимодействия











*/

