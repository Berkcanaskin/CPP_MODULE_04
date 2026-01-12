# CPP Module 04 - Subtype Polymorphism, Abstract Classes ve Interfaces

## 📚 Proje Açıklaması

CPP Module 04, C++'da polymorphism, abstract classes, pure virtual functions ve liskov substitution principle gibi ileri OOP konseptlerini detaylı şekilde kapsayan eğitim projesidir.

## 🎯 Modülde Bulunan Egzersizler

### Exercise 00: Polymorphism
**Amaç:** Subtype polymorphism'i pratik etmek

**Neler Öğrenildi:**
- Virtual functions ve dynamic dispatch
- Base class pointers/references ile derived class objelerine erişim
- Polymorphic behavior
- Type safety

**Örnek:**
```cpp
Animal *animal = new Dog();
animal->makeSound();  // Dog'un makeSound'ını çağırır
```

### Exercise 01: I don't want to set the world on fire
**Amaç:** Abstract base class ve pure virtual functions

**Neler Öğrenildi:**
- Pure virtual functions (`= 0`)
- Abstract classes (instantiate edilemez)
- Interface'leri tanımlama
- Derived classes'ta pure virtual fonksiyonları implement etme

**Yapı:**
```cpp
class Animal {
public:
    virtual void makeSound() = 0;    // Pure virtual
    virtual ~Animal() {}
};

// Animal sınıfından nesne oluşturamayız:
// Animal a; // HATA!

// Fakat derived classes'tan oluşturabiliriz:
class Dog : public Animal {
public:
    void makeSound() { std::cout << "Woof!" << std::endl; }
};
Dog d; // OK
```

### Exercise 02: Abstract Class
**Amaç:** Daha kompleks abstract class hiyerarşisi

**Neler Öğrenildi:**
- Multiple abstract levels
- Interface segregation
- Abstract class design patterns
- Real-world polymorphism examples

## 🛠️ Kullanım

```bash
cd CPP_MODULE_04/ex00
make
./polymorphism
```

## 📖 Temel C++ Kavramları

### Pure Virtual Functions

```cpp
class Shape {
public:
    virtual void draw() = 0;        // Pure virtual
    virtual double getArea() = 0;   // Pure virtual
    virtual ~Shape() {}
};
```

### Abstract Classes

Abstract class'ın özellikleri:
- En az bir pure virtual function içerir
- Nesne oluşturulamaz (instantiate edilemez)
- Derived classes'ta pure virtual fonksiyonlar implement edilmelidir
- Pointers ve references olarak kullanılabilir

```cpp
// Yanlış - hata:
Shape shape; // ERROR: cannot instantiate abstract class

// Doğru - derived class:
class Circle : public Shape {
public:
    void draw() override { /* ... */ }
    double getArea() override { /* ... */ }
};
Circle c; // OK
```

### Polymorphic Behavior

```cpp
std::vector<Shape*> shapes;
shapes.push_back(new Circle());
shapes.push_back(new Rectangle());
shapes.push_back(new Triangle());

for (auto shape : shapes) {
    shape->draw();      // Doğru derived class'ın draw'ı çağırır
}
```

### Liskov Substitution Principle (LSP)

Derived class, base class yerine kullanılabilir olmalıdır:

```cpp
void processShape(Shape *shape) {
    shape->draw();  // Shape'in herhangi bir derived class'ı olabilir
}

Circle c;
Rectangle r;
processShape(&c);   // OK
processShape(&r);   // OK
```

## 📚 Öğrenme Çıktıları

✅ Subtype polymorphism mastered  
✅ Pure virtual functions anlaşıldı  
✅ Abstract class design öğrenildi  
✅ Dynamic dispatch konsepti öğrenildi  
✅ Liskov Substitution Principle anlaşıldı  
✅ Real-world polymorphism örnekleri uygulandı  

## 🔧 Makefile

```bash
make         # Derleme
make clean   # Object dosyaları sil
make fclean  # Tüm dosyaları sil
make re      # Yeniden derleme
```

## 📝 Notlar

- Pure virtual functions kesinlikle implement edilmiştir
- Virtual destructors kullanılmıştır
- const correctness göz önüne alınmıştır
- Memory leaks mevcut değildir
- Override keyword kullanılmıştır

## Faydalı Linkler

- [Pure Virtual Functions](https://en.cppreference.com/w/cpp/language/abstract_class)
- [Polymorphism](https://en.cppreference.com/w/cpp/language/polymorphism)
- [Liskov Substitution Principle](https://en.wikipedia.org/wiki/Liskov_substitution_principle)
