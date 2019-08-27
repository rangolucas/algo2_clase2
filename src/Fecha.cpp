//////////////
// PRELUDIO //
//////////////

// Typedef
typedef int Anio;
typedef int Mes;
typedef int Dia;

// MESES
const Mes ENERO = 1;
const Mes FEBRERO = 2;
const Mes MARZO = 3;
const Mes ABRIL = 4;
const Mes MAYO = 5;
const Mes JUNIO = 6;
const Mes JULIO = 7;
const Mes AGOSTO = 8;
const Mes SEPTIEMBRE = 9;
const Mes OCTUBRE = 10;
const Mes NOVIEMBRE = 11;
const Mes DICIEMBRE = 12;

// Ejercicio 1: esBisiesto
bool esBisiesto(Anio anio) {
  if(anio % 100 == 0) return anio % 400 == 0;
  return anio % 4 == 0;
}

// Ejercicio 2: diasEnMes
//
//
int diasEnMes(Anio anio, Mes mes) {
  switch(mes) {
    case ENERO:
    return 31;
    case FEBRERO:
      if(esBisiesto(anio))
        return 28;
      return 29;
    case MARZO:
      return 31;
    case ABRIL:
      return 30;
    case MAYO:
      return 31;
    case JUNIO:
      return 30;
    case JULIO:
      return 31;
    case AGOSTO:
      return 31;
    case SEPTIEMBRE:
      return 30;
    case OCTUBRE:
      return 31;
    case NOVIEMBRE:
      return 30;
    case DICIEMBRE:
      return 31;
  }
}

// Para ejercicio 6
class Periodo;

class Fecha {
 public:
  // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
  Fecha(Anio anio, Mes mes, Dia dia);

  Anio anio() const;
  Mes mes() const;
  Dia dia() const;

  bool operator==(Fecha o) const;
  bool operator<(Fecha o) const;

  // Ejercicio 7: sumar período a fecha

 private:
  Anio _anio;
  Mes _mes;
  Dia _dia;

  // Ejercicio 7: sumar a fecha
  void sumar_anios(int anios);
  void sumar_meses(int meses);
  void sumar_dias(int dias);
};

// Ejercicio 3: Constructor y métodos de Fecha
Fecha::Fecha(Anio anio, Mes mes, Dia dia) : _anio(anio), _mes(mes), _dia(dia) {
}

Anio Fecha::anio() const {
  return _anio;
}

// Fecha::mes()
Mes Fecha::mes() const {
  return _mes;
}
// dia
Dia Fecha::dia() const {
  return _dia;
}

// Ejercicio 4: comparadores
bool Fecha::operator==(Fecha o) const {
  return _anio == o.anio() && _mes == o.mes() && _dia == o.dia();
}

// Fecha::operator<
bool Fecha::operator<(Fecha o) const {
  if(_anio < o.anio()) return true;
  if(_anio > o.anio()) return false;
  if(_mes < o.mes()) return true;
  if(_mes > o.mes()) return false;
  return _dia < o.dia();
}


// Ejercicio 5: comparador distinto
bool operator!=(Fecha f1, Fecha f2) {
  return !(f1 == f2);
}

// Ejercicio 6: clase período
class Periodo {
public:
 Periodo(Anio anio, Mes mes, Dia dia);

 Anio anio() const;
 Mes mes() const;
 Dia dia() const;

private:
 Anio _anio;
 Mes _mes;
 Dia _dia;
};


// Ejercicio 8: clase Intervalo
