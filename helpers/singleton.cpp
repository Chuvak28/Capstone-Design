#include <string>

using namespace std;

class Singleton
{
private:
    Singleton() {}

    Singleton(Singleton const &);
    void operator=(Singleton const &);

public:
    Singleton(Singleton const &) = delete;
    void operator=(Singleton const &) = delete;

    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
    }
};