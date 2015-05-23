void atras1(int vel)
{

  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  analogWrite(3, vel);

}

void adelante1(int vel)
{

  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  analogWrite(3, vel);

}

void alto1()
{

  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);

}

void atras2(int vel)
{

  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  analogWrite(6, vel);

}

void adelante2(int vel)
{

  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  analogWrite(6, vel);

}

void alto2()
{

  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);

}

void adelante3(int vel)
{

  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(9, vel);

}

void atras3(int vel)
{

  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(9, vel);

}

void alto3()
{

  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);

}

void adelante4(int vel)
{

  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  analogWrite(11, vel);

}

void atras4(int vel)
{

  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  analogWrite(11, vel);

}

void alto4()
{

  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);

}

void alto()
{

  alto1();
  alto2();
  alto3();
  alto4();

}

void adelante(int vel)
{

  adelante1(vel);
  adelante2(vel);
  adelante3(vel);
  adelante4(vel);

}

void atras(int vel)
{

  atras1(vel);
  atras2(vel);
  atras3(vel);
  atras4(vel);

}

void izquierda(int vel)
{

  atras1(vel);
  adelante2(vel);
  atras3(vel);
  adelante4(vel);

}

void derecha(int vel)
{

  adelante1(vel);
  atras2(vel);
  adelante3(vel);
  atras4(vel);

}

void adelder(int vel)
{

  alto1();
  adelante2(vel);
  adelante4(vel);
  alto4();

}

void atrasder(int vel)
{

  atras1(vel);
  alto2();
  atras3(vel);
  alto4();

}

void adelizq(int vel)
{

  adelante1(vel);
  alto2();
  adelante3(vel);
  alto4();

}

void atrasizq(int vel)
{

  alto1();
  atras2(vel);
  atras4(vel);
  alto4();

}

void giroder(int vel)
{

  adelante1(vel);
  adelante2(vel);
  atras3(vel);
  atras4(vel);

}

void giroizq(int vel)
{

  atras1(vel);
  atras2(vel);
  adelante3(vel);
  adelante4(vel);

}

void setup()
{

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
}

void loop()
{

  adelante(250);

}
