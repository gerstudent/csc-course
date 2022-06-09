/*
    Created by gerstudent

    Определен следующий класс (он также приведен в комментарии в шаблоне кода):

    struct Cls {
        Cls(char c, double d, int i);
    private:
        char c;
        double d;
        int i;
    };

    Как видно, все поля этого класса закрытые, ваша задача реализовать несколько функций,
    которые дают полный доступ к этим полям (см. шаблон кода), несмотря на то, что они закрытые.

*/


struct Cls2 {
    Cls2(char _c, double _d, int _i);
public:
    char c{};
    double d{};
    int i{};
};

Cls2::Cls2(char _c, double _d, int _i) {

}

char &get_c(Cls &cls) {
    void* voidptr = static_cast<void*>(&cls);
    auto* p = static_cast<Cls2*>(voidptr);
    return p->c;
}

double &get_d(Cls &cls) {
    void* voidptr = static_cast<void*>(&cls);
    auto* p = static_cast<Cls2*>(voidptr);
    return p->d;
}

int &get_i(Cls &cls) {
    void* voidptr = static_cast<void*>(&cls);
    auto* p = static_cast<Cls2*>(voidptr);
    return p->i;
}