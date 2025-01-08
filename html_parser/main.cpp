/*||======================================================||
  ||    GitHub: https://github.com/losif22/html_parser    ||
  ||    License: MIT                                      ||
  ||======================================================||*/

#include <iostream>
#include "html_parser.h"

int main() {
    setlocale(LC_ALL, "uk_UA");
    HTMLParser parser("index.html");
    parser.getHTMLData();
    std::cout << "\nНатиснiть будь-яку клавішу щоб закрити програму\n";
    system("pause>nul");
    return 0;
}