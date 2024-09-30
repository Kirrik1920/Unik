#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include <fstream>

using namespace std;

class Paragraph
{
    string text;
public:
    Paragraph(const string& t) : text(t) {}

    string getText() const
    {
        return text;
    }

    string toString() const
    {
        return "Paragraph: " + text;
    }

    void writeToFile(ofstream& file) const
    {
        file << text << "\n";
    }

    static Paragraph readFromFile(ifstream& file)
    {
        string line;
        getline(file, line);
        return Paragraph(line);
    }
};

class Section
{
    string title;
    vector<Paragraph> paragraphs;
public:
    Section(const string& t) : title(t) {}

    void addParagraph(const Paragraph& p)
    {
        paragraphs.push_back(p);
    }

    string getTitle() const
    {
        return title;
    }

    string toString() const
    {
        stringstream ss;
        ss << "Section: " << title << "\n";
        for (const auto& p : paragraphs)
        {
            ss << p.toString() << "\n";
        }
        return ss.str();
    }

    void writeToFile(ofstream& file) const
    {
        file << title << "\n";
        file << paragraphs.size() << "\n"; // Зберігаємо кількість абзаців
        for (const auto& p : paragraphs)
        {
            p.writeToFile(file);
        }
    }

    static Section readFromFile(ifstream& file)
    {
        string title;
        getline(file, title);
        Section section(title);
        size_t paragraphCount;
        file >> paragraphCount;
        file.ignore(); // Пропускаємо символ нового рядка після кількості абзаців
        for (size_t i = 0; i < paragraphCount; ++i)
        {
            section.addParagraph(Paragraph::readFromFile(file));
        }
        return section;
    }
};

class Document
{
    string titlePage;
    vector<Section> sections;
    vector<string> references;
public:
    Document(const string& title) : titlePage(title) {}

    void addSection(const Section& s)
    {
        sections.push_back(s);
    }

    void addReference(const string& ref)
    {
        references.push_back(ref);
    }

    string toString() const
    {
        stringstream ss;
        ss << "Title Page: " << titlePage << "\n\n";
        ss << "Sections:\n";
        for (const auto& s : sections)
        {
            ss << s.toString() << "\n";
        }
        ss << "References:\n";
        for (const auto& ref : references)
        {
            ss << ref << "\n";
        }
        return ss.str();
    }

    void writeToFile(const string& filename) const
    {
        ofstream file(filename);
        if (!file.is_open())
        {
            cerr << "Error opening file for writing.\n";
            return;
        }
        file << titlePage << "\n";
        file << sections.size() << "\n"; // Зберігаємо кількість секцій
        for (const auto& section : sections)
        {
            section.writeToFile(file);
        }
        file << references.size() << "\n"; // Зберігаємо кількість посилань
        for (const auto& ref : references)
        {
            file << ref << "\n";
        }
        file.close();
    }

    static Document readFromFile(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Error opening file for reading.\n";
            return Document("Error");
        }

        string titlePage;
        getline(file, titlePage);
        Document doc(titlePage);

        size_t sectionCount;
        file >> sectionCount;
        file.ignore(); // Пропускаємо символ нового рядка після кількості секцій

        for (size_t i = 0; i < sectionCount; ++i)
        {
            doc.addSection(Section::readFromFile(file));
        }

        size_t referenceCount;
        file >> referenceCount;
        file.ignore(); // Пропускаємо символ нового рядка після кількості посилань

        for (size_t i = 0; i < referenceCount; ++i)
        {
            string reference;
            getline(file, reference);
            doc.addReference(reference);
        }

        file.close();
        return doc;
    }
};

class RandomDataGenerator
{
public:
    static string generateRandomString(int length)
    {
        const string charset = "abcdefghijklmnopqrstuvwxyz ";
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> dist(0, charset.size() - 1);

        string result;
        for (int i = 0; i < length; ++i)
        {
            result += charset[dist(generator)];
        }
        return result;
    }

    static Document generateRandomDocument()
    {
        Document doc("Random Document Title");

        // Generate random sections
        for (int i = 0; i < 5; ++i)
        {
            Section section("Section " + to_string(i + 1));
            for (int j = 0; j < 3; ++j)
            {
                section.addParagraph(Paragraph(generateRandomString(100)));
            }
            doc.addSection(section);
        }

        // Generate random references
        for (int i = 0; i < 3; ++i)
        {
            doc.addReference("Reference " + to_string(i + 1));
        }

        return doc;
    }
};
// інкапсуляція для полей і методів класу
// додати елемент documemntElement, наслідувати параграф і секцію від цього елементу(поліморфізм)
// додати більше елементів для документи, наприклад елемент Title, header, footer
// зробити приватними методи, з якими на пряму не взаємодіє користувач(наприклад generateRandomString, etc)
// 
// прибрати усі коментарі, або написати їх самому, бо дуже палиться що це чат жпт
int main()
{
    Document doc = RandomDataGenerator::generateRandomDocument();
    string filename = "document.txt";

    // Записуємо документ у файл
    doc.writeToFile(filename);
    cout << "Document written to file: " << filename << "\n";

    // Зчитуємо документ з файлу
    Document loadedDoc = Document::readFromFile(filename);
    cout << "Document read from file: " << filename << "\n";
    cout << loadedDoc.toString();

    return 0;
}
