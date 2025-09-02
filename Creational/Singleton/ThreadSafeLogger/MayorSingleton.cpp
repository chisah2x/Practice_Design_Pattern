
/*The** Mayor's Singleton** pattern is a design pattern used in C++ to ensure that a class has only one instance and provides a global point of access to that instance. Here’s a breakdown of its key features:

- **Lazy Instantiation * *: The instance of the class is created only when it is needed, specifically when a method(often called `instance()`) is called for the first time.This is efficient because it avoids unnecessary object creation.

- **Thread Safety * *: From C++11 onwards, the static initialization of the instance is thread - safe.This means that multiple threads can safely call the method to access the instance without causing issues.

- **Automatic Cleanup * *: The instance is not allocated on the heap, so there is no need to manually delete it.It is automatically destroyed when the program ends, which simplifies memory management.

### Example :
    Here’s a simple example of how the Mayor's Singleton might look in code:
    In this example:
-The constructor is private, so no other part of the code can create an instance of `MayorSingleton`.
- The `instance()` method returns the single instance of the class, creating it only when first called.

*/

class MayorSingleton {
public:
    static MayorSingleton& instance() {
        static MayorSingleton instance; // This is the single instance
        return instance;
    }

private:
    MayorSingleton() {} // Private constructor to prevent instantiation
    MayorSingleton(const MayorSingleton&) = delete; // Prevent copy
    MayorSingleton& operator=(const MayorSingleton&) = delete; // Prevent assignment
};


