class Led
{
 public:
  Led(int pin): m_pin(pin) {}

  void init()
  {
    pinMode(m_pin, OUTPUT);
  }
  
  void on()
  {
    digitalWrite(m_pin, HIGH);    
  }

  void off()
  {
    digitalWrite(m_pin, LOW);
  }

 protected:
    int m_pin;
};
