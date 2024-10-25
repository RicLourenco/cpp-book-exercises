#include <iostream>

class Engine
{
    public:
        auto set_oil_amount(float v)
        {
            _oil = v;
        }
        auto get_oil_amount() const
        {
            return _oil;
        }

    private:
        float _oil {};
};

class YamahaEngine : public Engine
{
    // ...
};

/* This could have been prevented if the Boat class interface were made stricter
by preventing copying. Now, the second programmer will have to rethink the design
of the algorithm handling boats, but she won't accidentally introduce any subtle
bugs */
class Boat
{
    public:
        Boat(std::shared_ptr<Engine> e, float l)
            : _engine{e},
            _length{l} { }
        auto set_length(float l)
        {
            _length = l;
        }
        auto& get_engine()
        {
            return _engine;
        }
    
    private:
        Boat(const Boat& b) = delete; // Noncopyable
        auto operator = (const Boat& b) -> Boat& = delete; // Noncopyable
        float _length { };
        std::shared_ptr<Engine> _engine;
};

// When the other programmer tries to copy a Boat object...
auto boat0 = Boat
{
    std::make_shared<YamahaEngine>(),
    6.7f
};

/* Won't compile, the second programmer will have to find another solution
compliant with the limitations of the Boat */
auto boat1 = boat0;