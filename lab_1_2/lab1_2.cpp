#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include <fstream>

using namespace std;


class DocumentElement
{
public:
    virtual string toString() const = 0;
    virtual void saveToFile(ofstream& out) const = 0;
    virtual void loadFromFile(ifstream& in) = 0;
    virtual ~DocumentElement() = default;
};


class Paragraph : public DocumentElement
{
    string text;
public:
    Paragraph() = default;
    Paragraph(const string& t) : text(t) {}

    string getText() const
    {
        return text;
    }

    void setText(const string& t)
    {
        text = t;
    }

    string toString() const override
    {
        return "Paragraph: " + text;
    }

    void saveToFile(ofstream& out) const override
    {
        size_t length = text.size();
        out.write((char*)&length, sizeof(length));
        out.write(text.c_str(), length);
    }

    void loadFromFile(ifstream& in) override
    {
        size_t length;
        in.read((char*)&length, sizeof(length));
        char* buffer = new char[length + 1];
        in.read(buffer, length);
        buffer[length] = '\0';
        text = string(buffer);
        delete[] buffer;
    }
};


class Section : public DocumentElement
{
    string title;
    vector<Paragraph> paragraphs;
public:
    Section() = default;
    Section(const string& t) : title(t) {}

    string getTitle() const
    {
        return title;
    }

    void setTitle(const string& t)
    {
        title = t;
    }

    void addParagraph(const Paragraph& p)
    {
        paragraphs.push_back(p);
    }

    string toString() const override
    {
        stringstream ss;
        ss << "Section: " << title << "\n";
        for (const auto& p : paragraphs)
        {
            ss << p.toString() << "\n";
        }
        return ss.str();
    }

    void saveToFile(ofstream& out) const override
    {
        size_t titleLength = title.size();
        out.write((char*)&titleLength, sizeof(titleLength));
        out.write(title.c_str(), titleLength);

        size_t paraCount = paragraphs.size();
        out.write((char*)&paraCount, sizeof(paraCount));
        for (const auto& p : paragraphs)
        {
            p.saveToFile(out);
        }
    }

    void loadFromFile(ifstream& in) override
    {
        size_t titleLength;
        in.read((char*)&titleLength, sizeof(titleLength));
        char* buffer = new char[titleLength + 1];
        in.read(buffer, titleLength);
        buffer[titleLength] = '\0';
        title = string(buffer);
        delete[] buffer;

        size_t paraCount;
        in.read((char*)&paraCount, sizeof(paraCount));
        paragraphs.resize(paraCount);
        for (size_t i = 0; i < paraCount; ++i)
        {
            paragraphs[i].loadFromFile(in);
        }
    }
};


class Title : public DocumentElement
{
    string title;
public:
    Title() = default;
    Title(const string& t) : title(t) {}

    string getTitle() const
    {
        return title;
    }

    void setTitle(const string& t)
    {
        title = t;
    }

    string toString() const override
    {
        return "Title: " + title;
    }

    void saveToFile(ofstream& out) const override
    {
        size_t titleLength = title.size();
        out.write((char*)&titleLength, sizeof(titleLength));
        out.write(title.c_str(), titleLength);
    }

    void loadFromFile(ifstream& in) override
    {
        size_t titleLength;
        in.read((char*)&titleLength, sizeof(titleLength));
        char* buffer = new char[titleLength + 1];
        in.read(buffer, titleLength);
        buffer[titleLength] = '\0';
        title = string(buffer);
        delete[] buffer;
    }
};

class Header : public DocumentElement
{
    string content;
public:
    Header() = default;
    Header(const string& c) : content(c) {}

    string getContent() const
    {
        return content;
    }

    void setContent(const string& c)
    {
        content = c;
    }

    string toString() const override
    {
        return "Header: " + content;
    }

    void saveToFile(ofstream& out) const override
    {
        size_t length = content.size();
        out.write((char*)&length, sizeof(length));
        out.write(content.c_str(), length);
    }

    void loadFromFile(ifstream& in) override
    {
        size_t length;
        in.read((char*)&length, sizeof(length));
        char* buffer = new char[length + 1];
        in.read(buffer, length);
        buffer[length] = '\0';
        content = string(buffer);
        delete[] buffer;
    }
};


class Footer : public DocumentElement
{
    string content;
public:
    Footer() = default;
    Footer(const string& c) : content(c) {}

    string getContent() const
    {
        return content;
    }

    void setContent(const string& c)
    {
        content = c;
    }

    string toString() const override
    {
        return "Footer: " + content;
    }

    void saveToFile(ofstream& out) const override
    {
        size_t length = content.size();
        out.write((char*)&length, sizeof(length));
        out.write(content.c_str(), length);
    }

    void loadFromFile(ifstream& in) override
    {
        size_t length;
        in.read((char*)&length, sizeof(length));
        char* buffer = new char[length + 1];
        in.read(buffer, length);
        buffer[length] = '\0';
        content = string(buffer);
        delete[] buffer;
    }
};


class Document
{
    Title titlePage;
    Header header;
    Footer footer;
    vector<Section> sections;
    vector<string> references;
public:
    Document(const Title& t, const Header& h, const Footer& f) : titlePage(t), header(h), footer(f) {}

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
        ss << titlePage.toString() << "\n";
        ss << header.toString() << "\n";
        for (const auto& s : sections)
        {
            ss << s.toString() << "\n";
        }
        ss << footer.toString() << "\n";
        ss << "References:\n";
        for (const auto& ref : references)
        {
            ss << ref << "\n";
        }
        return ss.str();
    }

    void saveToFile(const string& filename) const
    {
        ofstream out(filename, ios::binary);
        if (!out)
        {
            cerr << "Cannot open file for writing: " << filename << endl;
            return;
        }

        titlePage.saveToFile(out);
        header.saveToFile(out);
        footer.saveToFile(out);

        size_t sectionCount = sections.size();
        out.write((char*)&sectionCount, sizeof(sectionCount));
        for (const auto& s : sections)
        {
            s.saveToFile(out);
        }

        size_t refCount = references.size();
        out.write((char*)&refCount, sizeof(refCount));
        for (const auto& ref : references)
        {
            size_t refLength = ref.size();
            out.write((char*)&refLength, sizeof(refLength));
            out.write(ref.c_str(), refLength);
        }

        out.close();
    }

    void loadFromFile(const string& filename)
    {
        ifstream in(filename, ios::binary);
        if (!in)
        {
            cerr << "Cannot open file for reading: " << filename << endl;
            return;
        }

        titlePage.loadFromFile(in);
        header.loadFromFile(in);
        footer.loadFromFile(in);

        size_t sectionCount;
        in.read((char*)&sectionCount, sizeof(sectionCount));
        sections.resize(sectionCount);
        for (size_t i = 0; i < sectionCount; ++i)
        {
            sections[i].loadFromFile(in);
        }

        size_t refCount;
        in.read((char*)&refCount, sizeof(refCount));
        references.resize(refCount);
        for (size_t i = 0; i < refCount; ++i)
        {
            size_t refLength;
            in.read((char*)&refLength, sizeof(refLength));
            char* refBuffer = new char[refLength + 1];
            in.read(refBuffer, refLength);
            refBuffer[refLength] = '\0';
            references[i] = string(refBuffer);
            delete[] refBuffer;
        }

        in.close();
    }
};


class RandomDataGenerator
{
private:
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

public:
    static Document generateRandomDocument()
    {
        Title title("Random Document Title");
        Header header("Document Header");
        Footer footer("Document Footer");

        Document doc(title, header, footer);


        for (int i = 0; i < 5; ++i)
        {
            Section section("Section " + to_string(i + 1));
            for (int j = 0; j < 3; ++j)
            {
                section.addParagraph(Paragraph(generateRandomString(100)));
            }
            doc.addSection(section);
        }


        for (int i = 0; i < 3; ++i)
        {
            doc.addReference("Reference " + to_string(i + 1));
        }

        return doc;
    }
};

int main()
{

    Document doc = RandomDataGenerator::generateRandomDocument();


    string filename = "document.dat";
    doc.saveToFile(filename);
    cout << "Document saved to " << filename << endl << endl;


    Document loadedDoc{ Title(), Header(), Footer() };
    loadedDoc.loadFromFile(filename);
    cout << "Document loaded from " << filename << ":\n\n";
    cout << loadedDoc.toString();

    return 0;
}

