#include <iostream>
#include <string>

using namespace std; 

struct Image
{
    virtual void draw() = 0;
};

struct Bitmap : Image
{
    string m_filename;

    Bitmap(const string& filename) : m_filename(filename) {
        cout << "Loading image from " << m_filename << endl;
    }
    void draw() { cout << "Drawing image " << m_filename << endl; }
};

int main() {
    Bitmap img_1{ "image_1.png" };
    Bitmap img_2{ "image_2.png" };

    img_1.draw();
    img_2.draw();

    return EXIT_SUCCESS;
}