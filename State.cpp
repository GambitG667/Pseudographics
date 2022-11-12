#include <iostream>

using namespace std;

class Machine  // некоторая машина с двкмя состояниями
{
    class MachineState; // объявление класса машины состояний
    MachineState* current; //поле со ссылкой на состояние
public:
    Machine();       //объявление конструктора
    void setCurrent(MachineState* s) //сеттер состояния
    {
        current = s;
    }
    void on(); // метод включения
    void off(); // метод выключения
};

class MachineState //иницализация класса машины состояний
{
public:
    virtual void on(Machine* m)
    {
        cout << "   already ON\n";
    }
    virtual void off(Machine* m)
    {
        cout << "   already OFF\n";
    }
};

void Machine::on()  // метод класса машины отсылает к методу класса состояния.
{
    current->on(this);
}

void Machine::off()
{
    current->off(this);
}

class OnMachineState : public MachineState //класс состояния наследуемый от класса машины состояний
{
public:
    OnMachineState()
    {
        cout << "   ON-ctor ";
    };
    ~OnMachineState()
    {
        cout << "   dtor-ON\n";
    };
    void off(Machine* m);
};

class OffMachineState : public MachineState
{
public:
    OffMachineState()
    {
        cout << "   OFF-ctor ";
    };
    ~OffMachineState()
    {
        cout << "   dtor-OFF\n";
    };
    void on(Machine* m)
    {
        cout << "   going from OFF to ON";
        m->setCurrent(new OnMachineState());
        delete this;
    }
};

void OnMachineState::off(Machine* m)  // вынесенная реализация
{
    cout << "   going from ON to OFF";
    m->setCurrent(new OffMachineState());
    delete this;
}


Machine::Machine()
{
    current = new OffMachineState();
    cout << '\n';
}
