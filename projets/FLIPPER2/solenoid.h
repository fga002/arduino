// ********************************************************************************************
// ***** Gere un solenoid
// ********************************************************************************************
class Solenoid
{
public:
  Solenoid(int numeroBouton, int numeroMoteur)
    :m_numeroBouton(numeroBouton)
    ,m_numeroMoteur(numeroMoteur)
    ,m_etatPrecedentBoutton(HIGH)
    ,m_dateDebutBoutton(0)
    {}

  void init()
  {
    pinMode(m_numeroBouton, INPUT_PULLUP);
    pinMode(m_numeroMoteur,OUTPUT);
  }

  bool update()
  {
    bool ok = true;
    int nouveauEtat = digitalRead(m_numeroBouton);
  
    if (nouveauEtat != m_etatPrecedentBoutton)
    {
      m_etatPrecedentBoutton = nouveauEtat;
      if (nouveauEtat == LOW)
      {
        // Le joueur vient d'appuyer sur le bouton 1
        Serial.print("Bouton appuye ");
        on();
      }
      else
      {
        // Le joueur vient de relacher le bouton 1
        Serial.print("Bouton relache ");
        off();
      }
  
      Serial.println(m_numeroBouton);
    }
    else if (nouveauEtat == LOW)
    {
      // Le joueur reste appuyé sur le bouton 1
      int dureeAppui = millis() - m_dateDebutBoutton;
      if (dureeAppui > 1000)
      {
        Serial.print("Bouton bloque ");
        Serial.println(m_numeroBouton);
        off(); 
        ok = false;

        /*
        digitalWrite(ledOn, LOW);
        musique(buzzer, melodie_bloque);
        delay(500);
        digitalWrite(ledOn, HIGH);
        */
      }
    }

    return ok;
  }

  void on()
  {
    m_dateDebutBoutton = millis();
    //digitalWrite(m_numeroBouton, HIGH);
    analogWrite(m_numeroBouton, 100);
    delay(50);
    digitalWrite(m_numeroBouton, HIGH);
  }

  void off()
  {
    digitalWrite(m_numeroBouton, LOW);
  }

protected:
  int m_numeroBouton;
  int m_numeroMoteur;
  int m_etatPrecedentBoutton;
  unsigned long m_dateDebutBoutton;
};
