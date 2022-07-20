#include <cstddef>

template <typename T>
class Array {
 private:
  size_t size_;
  T* data_;

 public:
  explicit Array(size_t size, const T& value = T()) : size_(size) {
    data_ = static_cast<T*>(operator new[](size_ * sizeof(T)));
    for (size_t i = 0; i != size_; i++) {
      new (data_ + i) T(value);
    }
  }

  Array() {
    size_ = 0;
    data_ = 0;
  }

  Array(const Array& other) : size_(other.size()) {
    data_ = static_cast<T*>(operator new[](size_ * sizeof(T)));
    for (size_t i = 0; i != size_; i++) {
      new (data_ + i) T(other.data_[i]);
    }
  }

  ~Array() {
    for (size_t i = 0; i != size_; i++) {
      data_[i].~T();
    }
    operator delete[](data_);
  }

  Array& operator=(const Array& other) {
    if (this != &other) {
      this->~Array();
      size_ = other.size();
      data_ = static_cast<T*>(operator new[](size_ * sizeof(T)));
      for (size_t i = 0; i != size_; i++) {
        new (data_ + i) T(other.data_[i]);
      }
    }
    return *this;
  }

  size_t size() const { return size_; }

  T& operator[](size_t i) { return data_[i]; }

  const T& operator[](size_t i) const { return data_[i]; }

  // Список операций:
  //
  // explicit Array(size_t size = 0, const T& value = T())
  //   конструктор класса, который создает
  //   Array размера size, заполненный значениями
  //   value типа T. Считайте что у типа T есть
  //   конструктор, который можно вызвать без
  //   без параметров, либо он ему не нужен.
  //
  // Array(const Array &)
  //   конструктор копирования, который создает
  //   копию параметра. Считайте, что для типа
  //   T определен оператор присваивания.
  //
  // ~Array()
  //   деструктор, если он вам необходим.
  //
  // Array& operator=(...)
  //   оператор присваивания.
  //
  // size_t size() const
  //   возвращает размер массива (количество
  //                              элементов).
  //
  // T& operator[](size_t)
  // const T& operator[](size_t) const
  //   две версии оператора доступа по индексу.
};