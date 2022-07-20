#include <cstddef>

template <typename T>
class Array {
 private:
  size_t size_;
  T* data_;

  void copy(const Array& other) {
    size_ = other.size_;
    data_ = new T[size_];
    for (size_t i = 0; i != size_; i++) {
      data_[i] = other[i];
    }
  }

 public:
  //   конструктор класса, который создает
  //   Array размера size, заполненный значениями
  //   value типа T. Считайте что у типа T есть
  //   конструктор, который можно вызвать без
  //   без параметров, либо он ему не нужен.
  explicit Array(size_t size = 0, const T& value = T())
      : size_(size), data_(size ? new T[size_] : 0) {
    for (size_t i = 0; i < size_; i++) {
      data_[i] = value;
    }
  }

  //   конструктор копирования, который создает
  //   копию параметра. Считайте, что для типа
  //   T определен оператор присваивания.
  Array(const Array& other) { copy(other); }

  //   деструктор, если он вам необходим.
  ~Array() { delete[] data_; }

  //   оператор присваивания.
  Array& operator=(const Array& other) {
    if (this != &other) {
      this->~Array();
      copy(other);
    }
    return *this;
  }

  // возвращает размер массива (количество элементов).
  size_t size() const { return size_; }

  //   две версии оператора доступа по индексу.
  T& operator[](size_t i) { return data_[i]; }
  const T& operator[](size_t i) const { return data_[i]; }
};