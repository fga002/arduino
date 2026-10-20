class Ctrl74HC595N
{
public:
  Ctrl74HC595N(const int dataPin, const int clockPin, const int latchPin)
  :m_dataPin(dataPin)
  ,m_clockPin(clockPin)
  ,m_latchPin(latchPin) {}

  void init()
  {
    pinMode( m_dataPin, OUTPUT );
    pinMode( m_clockPin, OUTPUT );
    pinMode( m_latchPin, OUTPUT );  
  }

  /**********************************************************************************************
   * Pilote les leds via le 74HC595N
   **********************************************************************************************/
  void write( int iValeur )
  {
    Serial.print("Ctrl74HC595N: write ");
    Serial.println(iValeur);
    
    // --- Bloque le latch ---
    // Le latch devient non passant. Il memorise la valeur actuelle 
    //    des entrée du latch (du registre à décalage) et maintient
    //   les valeurs des sorties Q0 à Q7.
    // Peut importe les modifications du registre a décalage, le 
    //   latch n'en tient pas compte.  
    digitalWrite( m_latchPin, LOW );
  
    // Cette instruction écrit chaque bit d'un byte/octet sur la 
    //   dataPin du registre à décalage. Après chaque bit écrit,
    //   la fonction fait osciller la clockPin pour que le registre
    //   a décalage enregistre la valeur et effectue un décalage
    //   du registre (vers la droite) pour recevoir la valeur suivante.
    // La constante MSBFIRST (Most Significant Bit First) indique que
    //   l'on commence l'écriture par le bit le plus important (de gauche
    //   a droite)  
    shiftOut( m_dataPin, m_clockPin, MSBFIRST, iValeur );
   
    // --- Active le latch ---
    // Devient passant et applique les valeurs du registre à décalage
    // sur les sorties
     digitalWrite( m_latchPin, HIGH ); 
  }

protected:
  const int m_dataPin;
  const int m_clockPin;
  const int m_latchPin;
};
