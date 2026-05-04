#include <iostream>
#include <string>

class AudioFile
{
public:
    //hier fehlt virtual damit die Funktion in den abgeleiteten Klassen überschrieben werden kann
    virtual void play() const
    {
        std::cout << "Playing generic audio file\n";
    }

    virtual void print_info() const
    {
        std::cout << "Generic audio file\n";
    }

    //Hier fehlt virtual damit der Destruktor der abgeleiteten Klassen aufgerufen wird
    virtual ~AudioFile()
    {
        std::cout << "AudioFile destroyed\n";
    }
};

class MP3File : public AudioFile
{
private:
    std::string artist;

public:
    MP3File(const std::string& artist_name) //Zuerst Konstruktor der Basisklasse aufrufen 
        : artist(artist_name)
    {
    }

    //Wenn hier die funktion Überschrieben werden soll muss sie in der Basisklasse virtual sein und hier muss const hinzugefügt werden
    virtual void play() const override
    {
        std::cout << "Playing MP3 by " << artist << "\n";
    }

    //Wenn hier die funktion Überschrieben werden soll  muss hier  const hinzugefügt werden
    virtual void print_info() const override
    {
        std::cout << "MP3 file by " << artist << "\n";
    }

    //Hier fehlt virtual damit der Destruktor der Basisklasse aufgerufen wird
    virtual ~MP3File()
    {
        std::cout << "MP3File destroyed\n";
    }
};

class WAVFile : public AudioFile
{
public:
    virtual void play() const
    {
        std::cout << "Playing WAV file\n";
    }

    virtual void print_info() const
    {
        std::cout << "Uncompressed WAV file\n";
    }

     ~WAVFile()
    {
        std::cout << "WAVFile destroyed\n";
    }
};

int main()
{
    AudioFile* playlist[2];

    playlist[0] = new MP3File("Daft Punk");
    playlist[1] = new WAVFile();

    for (int index = 0; index < 2; index++)
    {
        playlist[index]->print_info();
        playlist[index]->play();
    }

    for (int index = 0; index < 2; index++)
    {
        delete playlist[index];
    }

    return 0;
}