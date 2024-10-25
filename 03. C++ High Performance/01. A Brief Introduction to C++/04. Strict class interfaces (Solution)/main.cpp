#include <iostream>

/* Classes should either behave as deep-copied or should fail to compile when
copied. Copying a class should not have side effects where the resulting copied
class can modify the original class. This may sound obvious, but there are many
circumstances when, for example, a class requires a heap-allocated object accessed
by a pointer member variable of some sort, for example std::shared_ptr, as
follows */
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

/* The programmer of the Boat class has left a rather loose interface without any
precautions regarding copy semantics */
class Boat
{
    public:
        Boat(std::shared_ptr<Engine> e, float l)
            : _engine(e),
            _length(l) { }
        auto set_length(float l)
        {
            _length = l;
        }
        auto& get_engine()
        {
            return _engine;
        }

    private:
        // Being a derivable class, _engine has to be heap allocated
        std::shared_ptr<Engine> _engine;
        float _length { };
};

/* Later, another programmer uses the Boat class and expects correct copy behavior */
void copy_boat_example()
{
    auto boat0 = Boat
    {
        std::make_shared<YamahaEngine>(),
        6.7f
    };

    auto boat1 = boat0;

    // Doesn't realize that the oil amount applies to both boats
    boat1.set_length(8.56f);
    boat1.get_engine()->set_oil_amount(3.4f);
}