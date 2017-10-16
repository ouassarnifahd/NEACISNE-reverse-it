# Les + du C++

# Introduction

## 1. Surcharge de fonction (≠ #arg & type_arg soit signatures ≠)
``` c++
int add(int a, int b);
float add(float a, float b);
```
## 2. Namespace
``` c++
namespace SOMETHING {
    int function(int arg) {
        return arg + 1;
    }
}

int main(int argc, char const *argv[]) {
    int a = SOMETHING::function(1);
    return 0;
}
```

## 3. Setters & Getters: securité et maintenance (encapsulation en C)
``` c++
typedef struct {
    int num;
    int den;
} Rationnel;

// INLINE!!! with compiler (-o3 argument);
int getNum(Rationnel r);
int getDen(Rationnel r);

void setNum(Rationnel* r, int num);
void setDen(Rationnel* r, int den);

Rationnel make(int num, int den);
```
not too useful! so..
``` c++
typedef struct PrivateRationnel* Rationnel; // defined somewhere else!

Rationnel allocate(int num, int den) throw (char*);// secured? /!\ EXCEPTIONS

// Impementation
    #include <cstdlib>

    Rationnel allocate(int num, int den) {
        if (!den) throw "Denominateur nul";
        else {
            //DO WHAT WE WANT YOU TO DO!
        }
    }

    int main(int argc, char const *argv[]) {

        try {
            // what is normal!
        } catch (char* erreur) {
            // If dead then 500M$ lost!
        }
        return EXIT_SUCCESS; // EXIT_FAILURE
    }
    void deallocate(Rationnel r);
```
## 4. Allocation dynamic ? (new,delete)
``` c++
int *x = new int, *y = new int[5]; // have exceptions!! runtime_err
int *t = new(std::nothrow)int; // no exceptions
// Do SOMETHING!
delete x;
delete [] y; //??
```
## 5. input/output
### console
``` c++
#include <iostream>

std::cin >> /* variable */;;
std::cout << "/* message */" << '\n';
std::cerr << "/* error message */" << '\n';

int main(int argc, char const *argv[]) {
    if (argc == 1) {
        std::cout << "usage: " << argv[0] << "<int> <double> <char*>" << std::endl;
        return EXIT_SUCCESS;
    } else if (argc != 4) {
        std::cerr << "Nbre d'arguments incorrect" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS; // EXIT_FAILURE
}
```
### string
* lecture d'un entier
    ``` c++
    #include <sstream>

    int entier;
    std::istringstream connecteur(argv[1]);
    connecteur >> entier; // tentative!
    if(!connecteur || !connecteur.eof()) {
        std::cerr << "argument" << argv[1] << "est incorrect!" << endl;
        return EXIT_FAILURE;
    } else {
        // Do SOMETHING!
    }
    ```
* lecture d'un reel
    ``` c++
    #include <sstream>

    double reel;
    std::istringstream connecteur(argv[2]);
    connecteur >> reel; // tentative!
    if(!connecteur || !connecteur.eof()) {
        std::cerr << "argument" << argv[2] << "est incorrect!" << endl;
        return EXIT_FAILURE;
    } else {
        // Do SOMETHING!
    }
    ```
### fichier
    ``` c++
    #include <fstream>

    std::ifstream fichier(argv[3]); // std::ifstream fichier = argv[3];
    if (!fichier) {
        std::cerr << "impossible d'ouvrir le fichier " << argv[3] << std::endl;
        return EXIT_FAILURE;
    } else {
        int e1,e2;
        fichier >> e1 >> e2;
        if (!fichier) {
            std::cerr << "impossible de lire le fichier " << argv[3] << std::endl;
            return EXIT_FAILURE;
        }
        //Do SOMETHING!
        return EXIT_SUCCESS;
    }
    ```

# I. Object Oriented Aspect
## 1. The 23 design parterns! (GoF = Gang of Four)
#### a. Modelisation with Unified Modeling Langage (UML)
  * Language visuel
  * Description d'API
  * Independant du language de programmation
  * Packages: fr.ensicaen.package.souspackage

  Dans le .hpp

  ``` c++
    #ifndef POINT_H
    #define POINT_H
    namespace geom {
        namespace point {
            class point {
            private:
                int x;
            public:
                point();
                point(const point& p);
                ~point();
                const int& getx() const; //READ ONLY!!
            };
        };
    };
    #endif /* end of include guard: POINT_H */

  ```

  Dans le .cpp

  ``` c++
    #include "point.hpp"
    namespace geom {
        namespace point {
            point::point(const point& p) {
                x = p.getx();
            }

            const int& point::getx() {

            }
        };
    };

  ```

#### b. Hierarchy SIMPLE


``` c++
class point {
private:
    /* data */

public:
    point (arguments);
    virtual ~point ();
};

class pixel : public point {
private:
    /* data */

public:
    pixel (arguments);
    virtual ~pixel ();
};
```

#### c. Hierarchy MULTIPLE

``` c++
class point2D {
private:
    /* data */

public:
    point (arguments);
    virtual ~point ();
};

class point3D {
private:
    /* data */

public:
    point (arguments);
    virtual ~point ();
};

class pixel : public point2D, public point3D {
private:
    /* data */

public:
    pixel (arguments);
    virtual ~pixel ();
};
```

#### d. Methode redefinition (same signature! but ≠ core)

``` c++
class point {
private:
    int x;

public:
    point (arguments);
    virtual ~point (); // OK je vois!
    virtual void print() const; // vurtual autorise la redefinition
};

class pixel : public point {
private:
    int color;

public:
    pixel (arguments);
    virtual ~pixel ();
    void print() const override; // Confirmation de la redefinition
};
```

#### e. Methode abstraite (pas de corps)
* redefinition obligée
* class abstraite => utilisation pour de la derivation

### 2. Interfaces (des classes abstraites pour du code generique)

* type comportemental contrairement a une classe (type structural)

``` c++
class Operation {
public:
    virtual void initialisation(int& o) const;
    virtual void combiner(int& acc, const int& elt) const;
    ...
};

class Somme : public Operation {
public:
    void initialisation(int& o) const override;
    void combiner(int& acc, const int& elt) const override;
    ...
};

```
