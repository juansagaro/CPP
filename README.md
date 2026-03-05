# CPP Modules - 42 School

A comprehensive collection of **C++ projects** from the **42 school curriculum** (modules 00 through 09), covering the fundamentals of object-oriented programming up to advanced template metaprogramming and STL mastery. All projects are compiled under the **C++98 standard**.

---

## Table of Contents

- [Overview](#overview)
- [Module 00 - Basics](#module-00---basics)
- [Module 01 - Memory & References](#module-01---memory--references)
- [Module 02 - Ad-hoc Polymorphism & Fixed Point](#module-02---ad-hoc-polymorphism--fixed-point)
- [Module 03 - Inheritance](#module-03---inheritance)
- [Module 04 - Subtype Polymorphism & Abstract Classes](#module-04---subtype-polymorphism--abstract-classes)
- [Module 05 - Exceptions](#module-05---exceptions)
- [Module 06 - C++ Casts](#module-06---c-casts)
- [Module 07 - Templates](#module-07---templates)
- [Module 08 - Templated Containers, Iterators & Algorithms](#module-08---templated-containers-iterators--algorithms)
- [Module 09 - STL Containers in Practice](#module-09---stl-containers-in-practice)
- [Build](#build)
- [Author](#author)

---

## Overview

| Module | Topic | Exercises | Key Concepts |
|--------|-------|:---------:|--------------|
| **CPP00** | Basics | 3 | Namespaces, classes, member functions, I/O streams, static members |
| **CPP01** | Memory & References | 7 | Stack/heap allocation, references, pointers, file streams, function pointers |
| **CPP02** | Fixed-Point Arithmetic | 4 | Orthodox Canonical Form, operator overloading, ad-hoc polymorphism |
| **CPP03** | Inheritance | 4 | Single, multiple and diamond inheritance, virtual base classes |
| **CPP04** | Polymorphism | 4 | Virtual functions, abstract classes, pure virtual, interfaces, deep copy |
| **CPP05** | Exceptions | 4 | try/catch/throw, custom exception classes, bureaucratic forms |
| **CPP06** | C++ Casts | 3 | `static_cast`, `reinterpret_cast`, `dynamic_cast`, RTTI |
| **CPP07** | Templates | 3 | Function templates, class templates, template specialization |
| **CPP08** | STL | 3 | Containers, iterators, algorithms, container adapters |
| **CPP09** | STL in Practice | 3 | `std::map`, `std::stack`, `std::list`/`std::deque`, algorithm complexity |

---

## Module 00 - Basics

> Introduction to C++ fundamentals: namespaces, classes, member functions, I/O streams, initialization lists, and static members.

### ex00 - Megaphone

A simple program that converts its command-line arguments to uppercase and prints them. Demonstrates basic I/O with `std::cout` and string manipulation with `std::toupper`.

```
./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

### ex01 - My Awesome PhoneBook

An interactive phonebook application that supports up to 8 contacts, using the `ADD`, `SEARCH`, and `EXIT` commands. Implements two classes:

- **Contact** - Stores personal information (first name, last name, nickname, phone number, darkest secret) with getters/setters.
- **PhoneBook** - Manages an array of 8 contacts with circular overwriting, formatted column display (10-char truncation with `.`), and input validation.

### ex02 - Account

Recreation of a banking `Account` class from a provided header and expected output log. Demonstrates:

- Static member variables and functions (`_nbAccounts`, `_totalAmount`, `getNbAccounts()`, etc.)
- Instance tracking across all objects
- Timestamp-formatted logging with `std::localtime`
- Deposit, withdrawal, and balance management

---

## Module 01 - Memory & References

> Memory allocation, references vs. pointers, file I/O, and member function pointers.

### ex00 - BraiiiiiiinnnzzzZ

`Zombie` class instantiation on the **stack** (`randomChump`) vs. the **heap** (`newZombie`). Illustrates the difference in object lifetime and the need for explicit `delete` with heap-allocated objects.

### ex01 - Moar brainz!

`zombieHorde` function that allocates an array of `N` zombies with `new[]`, naming each one. Demonstrates array allocation on the heap and proper cleanup with `delete[]`.

### ex02 - HI THIS IS BRAIN

Prints the memory address and value of a string through a **pointer** and a **reference**, showing that both refer to the same underlying object.

### ex03 - Unnecessary violence

Two human classes wielding a `Weapon`:

- **HumanA** - Receives the weapon by **reference** in the constructor (always armed).
- **HumanB** - Receives the weapon by **pointer** via a setter (can be unarmed, `NULL`-safe).

Demonstrates when to use references (mandatory, non-null) vs. pointers (optional, nullable).

### ex04 - Sed is for losers

A file I/O program that reads a file and writes a copy with all occurrences of string `s1` replaced by `s2`. Uses `std::ifstream`, `std::ofstream`, and `std::string::find`/`substr` for replacement without using `std::string::replace`.

### ex05 - Harl 2.0

`Harl` class with four complaint levels (`DEBUG`, `INFO`, `WARNING`, `ERROR`). Uses an **array of member function pointers** to dispatch the correct complaint function based on a string input, avoiding if/else chains.

### ex06 - Harl filter

Extension of ex05 using a `switch` statement with **fall-through behavior** to filter and display complaints at or above a given severity level.

---

## Module 02 - Ad-hoc Polymorphism & Fixed Point

> Operator overloading, Orthodox Canonical Form (OCF), and fixed-point number representation.

### ex00 - My First Class in Orthodox Canonical Form

`Fixed` class implementing the **Orthodox Canonical Form**:
- Default constructor, copy constructor, copy assignment operator, destructor.
- Stores a fixed-point number as an integer with 8 fractional bits.

### ex01 - Towards a more useful fixed-point number class

Extends `Fixed` with:
- Constructors from `int` and `float` (using bit shifting and `roundf`).
- `toFloat()` and `toInt()` conversion methods.
- `operator<<` overload for stream insertion.

### ex02 - Now we're talking

Full operator overloading for the `Fixed` class:
- **Comparison**: `>`, `<`, `>=`, `<=`, `==`, `!=`
- **Arithmetic**: `+`, `-`, `*`, `/`
- **Increment/Decrement**: pre/post `++` and `--`
- **Static**: `min()` and `max()` (with const and non-const overloads)

### ex03 - BSP (Binary Space Partitioning)

`Point` class (using `Fixed` for coordinates) and a `bsp()` function that determines if a point lies inside a triangle using the **cross-product sign method**. Demonstrates practical use of the fixed-point class.

---

## Module 03 - Inheritance

> Class inheritance hierarchies, from simple to diamond inheritance.

### ex00 - ClapTrap

Base class `ClapTrap` with attributes (hit points, energy, attack damage) and actions (`attack`, `takeDamage`, `beRepaired`). Foundation for the entire inheritance chain.

### ex01 - ScavTrap

`ScavTrap` inherits from `ClapTrap` with modified default attributes (100 HP, 50 energy, 20 attack) and a special ability `guardGate()`. Demonstrates constructor/destructor chaining and method overriding.

### ex02 - FragTrap

`FragTrap` inherits from `ClapTrap` with its own defaults (100 HP, 100 energy, 30 attack) and a `highFivesGuys()` ability.

### ex03 - DiamondTrap

`DiamondTrap` inherits from **both** `ScavTrap` and `FragTrap`, creating a **diamond inheritance** problem. Solved with `virtual` inheritance from `ClapTrap`. Features:
- Its own `name` attribute (separate from `ClapTrap::_name`)
- `whoAmI()` method printing both names
- Uses `ScavTrap::attack` via `using` declaration
- Attributes: FragTrap HP, ScavTrap energy, FragTrap attack damage

---

## Module 04 - Subtype Polymorphism & Abstract Classes

> Virtual functions, abstract classes, interfaces, and deep copy semantics.

### ex00 - Polymorphism

`Animal` base class with `Dog` and `Cat` derived classes. `makeSound()` is declared `virtual` so that calling it through an `Animal*` invokes the correct derived version. `WrongAnimal`/`WrongCat` demonstrate what happens **without** `virtual` (no polymorphism).

### ex01 - I don't want to set the world on fire

Adds a `Brain` class (containing an array of 100 `std::string` ideas) to `Dog` and `Cat`. Demonstrates **deep copy**: each animal owns its own `Brain` on the heap, properly duplicated in copy constructors and assignment operators, and freed in destructors.

### ex02 - Abstract class

`Animal` becomes `AAnimal` with `makeSound() = 0` as a **pure virtual function**. The base class can no longer be instantiated directly, enforcing that only concrete derived classes (`Dog`, `Cat`) exist.

### ex03 - Interface & recap

Full implementation of the **Materia system** with interfaces:
- **ICharacter** - Interface for characters with `equip`, `unequip`, `use` methods and a 4-slot inventory.
- **IMateriaSource** - Interface for storing and creating materia templates.
- **AMateria** - Abstract base class for materia with `clone()` pure virtual (prototype pattern).
- **Ice / Cure** - Concrete materia types with distinct effects.
- **Character** - Implements `ICharacter` with deep copy, inventory management, and floor tracking for unequipped materia.
- **MateriaSource** - Implements `IMateriaSource` with template storage and `createMateria()` factory.

---

## Module 05 - Exceptions

> Exception handling, custom exception classes, and the bureaucratic form system.

### ex00 - Mommy, when I grow up, I want to be a bureaucrat!

`Bureaucrat` class with a name and grade (1 = highest, 150 = lowest). Grade modifications throw custom exceptions:
- `GradeTooHighException` - When grade goes below 1.
- `GradeTooLowException` - When grade goes above 150.

Includes `operator<<` for formatted output.

### ex01 - Form up, maggots!

Introduces the `Form` class with:
- Sign requirements (minimum grade to sign/execute).
- `beSigned()` method with grade validation.
- `Bureaucrat::signForm()` for interaction logging.

### ex02 - No, you need form 28B, not 28C...

`Form` becomes `AForm` (abstract). Three concrete form types:
- **ShrubberyCreationForm** (sign 145, exec 137) - Writes ASCII trees to a file.
- **RobotomyRequestForm** (sign 72, exec 45) - 50% success robotomy attempt.
- **PresidentialPardonForm** (sign 25, exec 5) - Pardon by Zaphod Beeblebrox.

Each validates signature status and executor grade before performing its action.

### ex03 - At least this beats coffee-making

`Intern` class with a `makeForm()` factory method. Takes a form name and target, returns a dynamically allocated form. Uses an **array of function pointers** mapped to form names for dispatch, avoiding if/else chains. Handles unknown form names with an error message.

---

## Module 06 - C++ Casts

> The three main C++ cast operators: `static_cast`, `reinterpret_cast`, and `dynamic_cast`.

### ex00 - Conversion of scalar types

`ScalarConverter` - A non-instantiable utility class (private canonical form) with a single static method `convert()`. Takes a string literal and displays its conversion to all four scalar types (`char`, `int`, `float`, `double`). Handles:
- Pseudo-literals: `nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`
- Non-displayable characters
- Overflow detection using `std::numeric_limits`
- Type detection via `strtod` with endptr analysis

**Key concept**: `static_cast` for explicit, safe scalar type conversions.

### ex01 - Serialization

`Serializer` - Non-instantiable utility class with two static methods:
- `serialize(Data* ptr)` -> `uintptr_t` via `reinterpret_cast`
- `deserialize(uintptr_t raw)` -> `Data*` via `reinterpret_cast`

Proves that serializing a pointer to an integer and back preserves the exact address (bit-level round-trip).

**Key concept**: `reinterpret_cast` for raw, bit-level type reinterpretation.

### ex02 - Identify real type

Polymorphic hierarchy (`Base` with virtual destructor, derived `A`, `B`, `C`) with two `identify` functions:
- **Pointer version**: `dynamic_cast<A*>(p)` returns `NULL` on failure.
- **Reference version**: `dynamic_cast<A&>(p)` throws `std::bad_cast` on failure.

Randomly generates objects and identifies their runtime type without using `typeid`.

**Key concept**: `dynamic_cast` for safe runtime type identification via RTTI.

---

## Module 07 - Templates

> Function templates and class templates: generic programming in C++98.

### ex00 - Start with a few functions

Three function templates in `whatever.hpp`:
- `swap(T&, T&)` - Swaps two values by reference.
- `min(const T&, const T&)` - Returns the smaller value (returns `b` if equal).
- `max(const T&, const T&)` - Returns the larger value (returns `b` if equal).

Works with any type supporting comparison operators.

### ex01 - Iter

`iter()` function template that applies a callback function to each element of an array. Three overloads handle:
- Mutable arrays with `void (*func)(T&)`
- Const arrays with `void (*func)(T const&)`
- Generic callable via `template <typename T, typename Func>` (solves template deduction ambiguity)

### ex02 - Array

`Array<T>` - A fully templated dynamic array class implementing:
- **Orthodox Canonical Form** with deep copy semantics
- Value initialization via `new T[n]()`
- Bounds-checked `operator[]` (const and non-const) throwing a custom `OutOfBoundsException`
- `size()` method
- Separation of declaration (`.hpp`) and definition (`.tpp`)

---

## Module 08 - Templated Containers, Iterators & Algorithms

> Deep dive into the STL: containers, iterators, and algorithms.

### ex00 - Easy find

`easyfind<T>()` - A function template that searches for an integer in any STL container using `std::find`. Throws a custom `NotFoundException` if the element is not found. Demonstrates container-agnostic programming with iterators.

### ex01 - Span

`Span` class that stores up to `N` integers and computes:
- **shortestSpan()** - Minimum difference between any two elements (sorts a copy, checks adjacent pairs).
- **longestSpan()** - Difference between min and max elements (`std::min_element`, `std::max_element`).
- **Range insertion** via a template member function `addNumber(Iterator begin, Iterator end)` for bulk insertion.

Custom exceptions: `SpanFullException`, `NotEnoughElementsException`.

### ex02 - MutantStack

`MutantStack<T>` - Inherits from `std::stack<T>` and exposes iterators by accessing the protected `c` member (the underlying container, `std::deque<T>` by default). Provides:
- `iterator`, `const_iterator`, `reverse_iterator`, `const_reverse_iterator`
- `begin()`, `end()`, `rbegin()`, `rend()` (const and non-const overloads)

Proves behavioral equivalence with `std::list` through parallel tests producing identical output.

---

## Module 09 - STL Containers in Practice

> Practical applications of STL containers with emphasis on choosing the right container for each problem and algorithm efficiency.

### ex00 - Bitcoin Exchange

`BitcoinExchange` - Loads a historical Bitcoin price database (CSV, ~1600 entries from 2009 to 2022) into a `std::map<std::string, float>` and processes user input files. For each `date | value` entry:
- Finds the exchange rate on that date or the closest **earlier** date using `std::map::lower_bound()` (O(log n) lookup).
- Validates dates with `mktime()` calendar normalization.
- Validates values (positive, <= 1000).
- Prints `date => value = result`.

**Key concept**: `std::map` for ordered key-value storage with efficient range queries.

### ex01 - RPN (Reverse Polish Notation)

`RPN` - Evaluates mathematical expressions written in **Reverse Polish Notation** (postfix notation) using a `std::stack`. The program:
- Reads tokens from a single string argument.
- Pushes operands onto the stack.
- On encountering an operator (`+`, `-`, `*`, `/`), pops two operands, applies the operation, and pushes the result.
- Handles error cases: insufficient operands, division by zero, invalid tokens, leftover operands.

```
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
```

**Key concept**: `std::stack` as the natural data structure for postfix expression evaluation.

### ex02 - PmergeMe

`PmergeMe` - Implements the **Ford-Johnson merge-insertion sort algorithm** using two different containers (`std::vector` and `std::deque`) to compare their performance. The program:
- Takes a sequence of positive integers as arguments.
- Sorts them using the merge-insertion sort algorithm with both containers.
- Displays the unsorted and sorted sequences.
- Measures and displays the execution time for each container.

```
./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process with std::vector: 0.00031 us
Time to process with std::deque:  0.00042 us
```

**Key concept**: Comparing `std::vector` (contiguous memory, cache-friendly) vs. `std::deque` (segmented memory) performance characteristics. The Ford-Johnson algorithm minimizes the number of comparisons, approaching the theoretical lower bound.

---

## Build

Each exercise has its own `Makefile` with the following targets:

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

All projects compile with:
```
c++ -Wall -Wextra -Werror -std=c++98
```

---

## Author

**jsagaro-** | 42 Madrid
