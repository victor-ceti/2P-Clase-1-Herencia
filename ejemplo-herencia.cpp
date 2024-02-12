#include <iostream>
#include <string>

using namespace std;

// Interfaz
class Transporte {
protected:
  string nombre;
  string color;

public:
  int contador = 0;
  Transporte(string nombre, string color) {
    this->nombre = nombre;
    this->color = color;
  }
  virtual void transportar(int distancia) = 0;
};

class Terrestre : public Transporte {
public:
  void transportar(int distancia);
  Terrestre(string nombre, string color) : Transporte(nombre, color) {}
};

void Terrestre::transportar(int distancia) {
  cout << "Transportando " << distancia << "km en " << nombre << " de color "
       << color << endl;
}

class Maritimo : public Transporte {
public:
  void transportar(int distancia);
  Maritimo(string nombre, string color) : Transporte(nombre, color) {}
};

void Maritimo::transportar(int distancia) {
  cout << "Navegando " << distancia << "km en " << nombre << " de color "
       << color << endl;
}

class Aereo : public Transporte {
public:
  void transportar(int distancia);
  Aereo(string nombre, string color) : Transporte(nombre, color) {}
};

void Aereo::transportar(int distancia) {
  cout << "Volando " << distancia << "km en " << nombre << " de color " << color
       << endl;
}

void viajar(Transporte *transporte, const int distancia) {
  transporte->contador++;
  transporte->transportar(distancia);
}

int main() {
  Terrestre terrestre = Terrestre("Coche", "Azul");
  Maritimo maritimo = Maritimo("Barco", "Blanco");
  Aereo aereo = Aereo("Avion", "Gris");

  int distancia = 200;
  viajar(&terrestre, distancia);

  cout << terrestre.contador << endl;
  cout << distancia << endl;
  return 0;
}
