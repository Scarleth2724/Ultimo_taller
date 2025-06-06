#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    int id;
    string marca, modelo;
    int velocidad;

public:
    Vehiculo(int i, string m, string mo, int v)
        : id(i), marca(m), modelo(mo), velocidad(v) {}

    virtual void ver() {
        cout << "Placa: " << id << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Velocidad: " << velocidad << " km/h" << endl;
    }
};

class Terrestre : virtual public Vehiculo {
protected:
    string tipo, ruedas;

public:
    Terrestre(string t, string r, int i, string m, string mo, int v)
        : Vehiculo(i, m, mo, v), tipo(t), ruedas(r) {}

    void verTerrestre() {
        ver();
        cout << "Tipo terrestre: " << tipo << endl;
        cout << "Ruedas: " << ruedas << endl;
    }
};

class Aereo : virtual public Vehiculo {
protected:
    int alto_Maximo;

public:
    Aereo(int a, int i, string m, string mo, int v)
        : Vehiculo(i, m, mo, v), alto_Maximo(a) {}

    void verAereo() {
        ver();
        cout << "Altura max: " << alto_Maximo << " m" << endl;
    }
};

class Maritimo : virtual public Vehiculo {
protected:
    float profundidad;

public:
    Maritimo(float p, int i, string m, string mo, int v)
        : Vehiculo(i, m, mo, v), profundidad(p) {}

    void verMaritimo() {
        ver();
        cout << "Profundidad max: " << profundidad << " m" << endl;
    }
};

class DronHibrido : public Terrestre, public Aereo, public Maritimo {
public:
    DronHibrido(string m, string mo, int i, int v,
         string t, string r, int a, float p)
        : Vehiculo(i, m, mo, v),
          Terrestre(t, r, i, m, mo, v),
          Aereo(a, i, m, mo, v),
          Maritimo(p, i, m, mo, v) {}

    void verDronHibrido() {
        ver();
        cout << "Tipo: " << tipo << endl;
        cout << "Ruedas: " << ruedas << endl;
        cout << "Altura: " << alto_Maximo << " m" << endl;
        cout << "Profundidad: " << profundidad << " m" << endl;
    }
};

int main() {
    DronHibrido d(
        "DJI", "Mavic AIR4K",
        1001, 45,
        "Multiterreno", "Rotor",
        120,
        10.5
    );

    Terrestre t(
        "Camioneta", "Todo terreno", 
        2002, "Toyota", "Hilux", 160
    );

    Aereo a(
        11000, 3003, "Boeing", "747", 900
    );

    Maritimo m(
        200.75, 4004, "Yamaha", "WaveRunner", 85
    );

    cout << "\n--- DronHibrido ---\n";
    d.verDronHibrido();

    cout << "\n--- Terrestre ---\n";
    t.verTerrestre();

    cout << "\n--- Aereo ---\n";
    a.verAereo();

    cout << "\n--- Maritimo ---\n";
    m.verMaritimo();

    return 0;
}