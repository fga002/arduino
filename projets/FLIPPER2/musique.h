// Notes françaises
#define DO 65
#define DOd 69
#define RE 74
#define REb DOd
#define REd 78
#define MI 83
#define MIb REd
#define FA 87
#define FAd 93
#define SOL 98
#define SOLb FAd
#define SOLd 104
#define LA 110
#define LAb SOLd
#define LAd 117
#define SI 123
#define SIb LAd

// Notes anglaises
#define NC   DO
#define NCS  DOd
#define ND   RE
#define NDS  REd
#define NE   MI
#define NF   FA
#define NFS  FAd
#define NG   SOL
#define NGS  SOLd
#define NA   LA
#define NAS  LAd
#define NB   SI

// Tempo
#define LENTO 1200
#define ANDANTE 800
#define MODERATO 400
#define ALLEGRO 200
#define PRESTO 100
#define PRESTISSIMO 50

// liste des temps
#define NOIRE 1
#define BLANCHE (NOIRE*2.0)
#define BLANCHEPOINTEE (NOIRE+BLANCHE)
#define RONDE (BLANCHE*2.0)
#define CROCHE (NOIRE/2.0)
#define NOIREPOINTEE (NOIRE+CROCHE)
#define DOUBLECROCHE (CROCHE/2.0)
#define CROCHEPOINTEE (DOUBLECROCHE+CROCHE)
#define TRIPLECROCHE (DOUBLECROCHE/2.0)
#define QUADRUPLECROCHE (QUADRUPLECROCHE/2.0)
#define QUINTUPLECROCHE (QUINTUPLECROCHE/2.0)

// liste des rythmiques de silences
#define PAUSE 1
#define DEMIPAUSE (PAUSE/2.0)
#define SOUPIR (DEMIPAUSE/2.0)
#define DEMISOUPIR (SOUPIR/2.0)
#define QUARDESOUPIR (DEMISOUPIR/2.0)
#define HUITIEMEDESOUPIR (QUARDESOUPIR/2.0)
#define SEIZIEMEDESOUPIR (HUITIEMEDESOUPIR/2.0)
#define TRENTEDEUXIEMEDESOUPIR (SEIZIEMEDESOUPIR/2.0)


// Structure NOTE
struct NOTE {
  byte note;
  float temps;
  byte octave;
  float silence;
};

#define NOTE_FIN {0, 0, 0, 0}

/**********************************************************************************************
 * musique
 **********************************************************************************************/
 void playMusique(int device, const struct NOTE* p, int tempsBase=MODERATO)
 {
  while (p->note)
  {
    int frequence = p->note * pow(2, p->octave);
    int duree = p->temps * tempsBase;
    int pause = p->silence * tempsBase;

    tone(device, frequence);
    delay(duree);
    noTone(device);
    delay(pause);
    p++;
  }
 }

 class Musique
 {
  public:
    Musique(int device, const struct NOTE* p, int tempsBase=MODERATO)
      :m_tempsBase(tempsBase)
      ,m_device(device)
      ,m_notes(p)
      {}

    void init()
    {
      pinMode(m_device, OUTPUT);
    }
    
    void play()
    {
      playMusique(m_device, m_notes, m_tempsBase);
    }

  protected:
    int m_device;
    const struct NOTE* m_notes;
    int m_tempsBase;
 };
