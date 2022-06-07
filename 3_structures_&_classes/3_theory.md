# Structures, Unions, and Enumerations

Перевод восьмого раздела "Structures, Unions, and Enumerations" из книги "The C++ Programming Language" автора Bjarne Stroustrup.

## Structures

+ Массив - это совокупность элементов одного и того же типа. В своей простейшей форме структура представляет собой совокупность элементов произвольных типов. Например:

```c++
struct Address {
    const char* name; // "Jim Dandy"
    int number; // 61
    const char* street; // "South St"
    const char* town; // "New Providence"
    char state[2]; // 'N' 'J'
    const char* zip; // "07974"
};
```

+ Переменные типа Address могут быть объявлены точно так же, как и другие переменные, а доступ к отдельным элементам можно получить с помощью оператора **. (точка)**. Например:

```c++
void f() {
    Address jd;
    jd.name = "Jim Dandy";
    jd.number = 61;
}
```

+ Переменные структурных типов могут быть инициализированы с использованием обозначения **{}**. Например:

```c++
Address jd = {
    "Jim Dandy",
    61, "South St",
    "New Providence",
    {'N','J'}, "07974"
};
```

+ Обратите внимание, что jd.state не может быть инициализирован строкой "NJ". Строки заканчиваются нулевым символом 
'\0', поэтому "NJ" состоит из трех символов – на один больше, чем поместится в jd.state. Я намеренно использую довольно 
низкоуровневые типы для членов, чтобы проиллюстрировать, как это можно сделать и какие проблемы это может вызвать.

+ Доступ к структурам часто осуществляется через указатели с использованием оператора **->** (разыменование указателя структуры). Например:

```c++
void print_addr(Address* p) {
    cout << p->name << '\n'
    << p->number << ' ' << p->street << '\n'
    << p->town << '\n'
    << p->state[0] << p->state[1] << ' ' << p->zip << '\n';
}
```

+ Когда p является указателем, p->m эквивалентно (*p).m.

+ Альтернативно, структура может быть передана по ссылке и доступна с помощью оператора **. (доступ к элементу структуры)**:

```c++
void print_addr2(const Address& r) {
    cout << r.name << '\n'
    << r.number << ' ' << r.street << '\n'
    << r.town << '\n'
    << r.state[0] << r.state[1] << ' ' << r.zip << '\n';
}
```

+ Объекты структурных типов могут быть назначены, переданы в качестве аргументов функции и возвращены в качестве результата функции. Например:

```c++
Address current;

Address set_current(Address next) {
    address prev = current;
    current = next;
    return prev;
}
```

+ Другие возможные операции, такие как сравнение **(== и !=)**, по умолчанию недоступны. Однако пользователь может определить такие операторы.

***

## Struct layout

+ Объект структуры содержит свои члены в том порядке, в котором они объявлены. Например, мы могли бы хранить примитивные показания оборудования в такой структуре, как эта:

```c++
struct Readout {
    char hour; // [0:23]
    int value;
    char seq; // sequence mark ['a':'z']
};
```

***

## Struct names

+ Имя типа становится доступным для использования сразу после его обнаружения, а не только после просмотра полного объявления. Например:

```c++
struct Link {
    Link* previous;
    Link* successor;
}
```

+ Однако невозможно объявить новые объекты структуры до тех пор, пока не будет просмотрено ее полное объявление. Например:

```c++
struct No_good {
    No_good member; // error : recursive definition
};
```

+ Это ошибка, поскольку компилятор не может определить размер No_good. Чтобы разрешить двум (или более) структурам ссылаться друг на друга, мы можем объявить имя именем структуры. Например:

```c++
struct Link {
    Link* previous;
    Link* successor;
}
```

+ Имя типа становится доступным для использования сразу после его обнаружения, а не только после просмотра полного объявления. Например:

```c++
struct List; // struct name declaration: List to be defined later

struct Link {
    Link* pre;
    Link* suc;
    List* member_of;
    int data;
};

struct List {
    Link* head;
};
```

+ Без первого объявления List использование типа указателя List* в объявлении Link было бы синтаксической ошибкой

+ Имя структуры может быть использовано до определения типа, если для этого использования не требуется
  знать имя элемента или размер структуры. Однако до завершения
  объявления структуры эта структура является неполным типом. Например:

```c++
struct S; // ‘‘S’’ is the name of some type

extern S a;
S f();
void g(S);
S* h(S*);
```

+ Однако многие такие объявления не могут быть использованы, если не определен тип S:

```c++
void k(S* p) {
S a; // error : S not defined; size needed to allocate
f(); // error : S not defined; size needed to return value
g(a); // error : S not defined; size needed to pass argument
p->m = 7; // error : S not defined; member name not known
S* q = h(p); // ok: pointers can be allocated and passed
q->m = 7; // error : S not defined; member name not known
}
```

+ По причинам, которые восходят к предыстории C, можно объявить структуру и "не структуру" (non-struct) с
  одинаковым именем в одной и той же области видимости. Например:

```c++
struct stat { /* ... */ };
int stat(char* name, struct stat* buf)
```

+ В этом случае простое имя (состояние) - это имя "не структуры" (non-struct), и на структуру необходимо ссылаться
  с префиксом struct. Однако лучше не перегружать имена.

***

## Structures and Classes

+ Структура - это просто класс, члены которого по умолчанию являются public. Таким образом, структура может иметь
  функции-члены. В частности, структура может иметь конструкторы. Например:

```c++
struct Points {
    vector<Point> elem;// must contain at least one Point
    Points(Point p0) { elem.push_back(p0);}
    Points(Point p0, Point p1) { elem.push_back(p0); elem.push_back(p1); }
    // ...
};

Points x0; // error : no default constructor
Points x1{ {100,200} }; // one Point
Points x1{ {100,200}, {300,400} }; // two Points
```

+ Вам не нужно определять конструктор просто для инициализации элементов по порядку. Например:

```c++
struct Point {
    int x, y;
};

Point p0; // danger : uninitialized if in local scope (§6.3.5.1)
Point p1 {}; // default construction: {{},{}}; that is {0.0}
Point p2 {1}; // the second member is default constructed: {1,{}}; that is {1,0}
Point p3 {1,2}; // {1,2}
```

+ Конструкторы необходимы, если вам нужно изменить порядок аргументов, проверить аргументы, изменить аргументы,
  установить инварианты и т.д. Например:

```c++
struct Address {
    string name; // "Jim Dandy"
    int number; // 61
    string street; // "South St"
    string town; // "New Providence"
    char state[2]; // ’N’ ’J’
    char zip[5]; // 07974
    Address(const string n, int nu, const string& s, const string& t, const string& st, int z);
};
```

+ Здесь я добавил конструктор, чтобы гарантировать, что каждый элемент был инициализирован, и чтобы я мог использовать
  строку и int для почтового индекса, а не возиться с отдельными символами. Например:

```c++
Address jd = {
    "Jim Dandy",
    61, "South St",
    "New Providence",
    "NJ", 7974 // (07974 would be octal; §6.2.4.1)
};
```

+ Конструктор адреса может быть определен следующим образом:

```c++
Address::Address(const string& n, int nu, const string& s, const string& t, const string& st, int z)
    // validate postal code
    :name{n},
    number{nu},
    street{s},
    town{t}
{
    if (st.size()!=2)
    error("State abbreviation should be two characters")
    state = {st[0],st[1]}; // store postal code as characters
    ostringstream ost; // an output string stream; see §38.4.2
    ost << z; // extract characters from int
    string zi {ost.str()};
    switch (zi.size()) {
    case 5:
    zip = {zi[0], zi[1], zi[2], zi[3], zi[4]};
    break;
    case 4: // star ts with ’0’
    zip = {'0', zi[0], zi[1], zi[2], zi[3]};
    break;
    default:
    error("unexpected ZIP code format");
    }
    // ... check that the code makes sense ...
}
```

***

## Structures and Arrays

+ Естественно, у нас могут быть массивы структур и структуры, содержащие массивы. Например:

```c++
struct Point {
    int x,y
};

Point points[3] {{1,2},{3,4},{5,6}};
int x2 = points[2].x;

struct Array {
    Point elem[3];
};

Array points2 {{1,2},{3,4},{5,6}};
int y2 = points2.elem[2].y;
```

+ Размещение встроенного массива в структуре позволяет нам рассматривать этот массив как объект: мы можем скопировать структуру, 
содержащую его, при инициализации (включая передачу аргументов и возврат функции) и присваивании. Например:

```c++
Array shift(Array a, Point p) {
    for (int i=0; i!=3; ++i) {
    a.elem[i].x += p.x;
    a.elem[i].y += p.y;
    }
    return a;
}

Array ax = shift(points2,{10,20});
```

+ Обозначение для массива немного примитивно: почему i != 3? Зачем все время повторять .elem[i]? Почему только элементы 
типа Point? Стандартная библиотека предоставляет std::array как более полное и элегантное развитие идеи массива 
фиксированного размера как структуры:

```c++
template<typename T, size_t N >
struct array {
    T elem[N];
    T* begin() noexcept { return elem; }
    const T* begin() const noexcept {return elem; }
    T* end() noexcept { return elem+N; }
    const T* end() const noexcept { return elem+N; }
    constexpr size_t size() noexcept;
    T& operator[](size_t n) { return elem[n]; }
    const T& operator[](size_type n) const { return elem[n]; }
    T * data() noexcept { return elem; }
    const T * data() const noexcept { return elem; }
    // ...
};
```

+ Этот массив является шаблоном, позволяющим использовать произвольное количество элементов произвольных типов. Он также
  непосредственно касается возможности исключений и объектов const. Используя массив,
  теперь мы можем написать:

```c++
struct Point {
    int x,y
};

using Array = array<Point,3>; // array of 3 Points
Array points {{1,2},{3,4},{5,6}};
int x2 = points[2].x;
int y2 = points[2].y;

Array shift(Array a, Point p) {
    for (int i=0; i!=a.size(); ++i) {
    a[i].x += p.x;
    a[i].y += p.y;
    }
    return a;
}

Array ax = shift(points,{10,20});
```

+ Основные преимущества std::array перед встроенным массивом заключаются в том, что он является правильным типом объекта
(имеет назначение и т.д.) И неявно преобразуется в указатель на отдельный элемент:

```c++
ostream& operator<<(ostream& os, Point p)
{
    cout << '{' << p[i].x << ',' << p[i].y << '}';
}

void print(Point a[],int s) // must specify number of elements
{
    for (int i=0; i!=s; ++i)
    cout << a[i] << '\n';
}

template<typename T, int N>
void print(array<T,N>& a)
{
    for (int i=0; i!=a.size(); ++i)
    cout << a[i] << '\n';
}

Point point1[] = {{1,2},{3,4},{5,6}}; // 3 elements
array<Point,3> point2 = {{1,2},{3,4},{5,6}}; // 3 elements

void f()
{
    print(point1,4); // 4 is a bad error
    print(point2);
}
```

+ Недостатком std::array по сравнению со встроенным массивом является то, что мы не можем вывести количество
  элементов из длины инициализатора:

```c++
Point point1[] = {{1,2},{3,4},{5,6}}; // 3 elements
array<Point,3> point2 = {{1,2},{3,4},{5,6}}; // 3 elements
array<Point> point3 = {{1,2},{3,4},{5,6}}; // error : number of elements not given
```