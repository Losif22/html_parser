/*||======================================================||
  ||    GitHub: https://github.com/losif22/html_parser    ||
  ||    License: MIT                                      ||
  ||======================================================||*/
#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>

struct HTMLTagParser {
    std::regex title_regex{ "<title>(.*?)</title>" };
    std::regex lang_regex{ "<html.*?lang=\"([^\"]+)\"" };
    std::regex encoding_regex{ "<meta.*?charset=\"([^\"]+)\"" };


    std::string parseTitle(const std::string& html_content);
    std::string parseLang(const std::string& html_content);
    std::string parseEncoding(const std::string& html_content);
};

class HTMLParser {
public:
    HTMLParser(const char* file_name);
    ~HTMLParser();

    void getHTMLData();

private:
    std::ifstream html_file;
    std::string html_content;
    HTMLTagParser html_tags;
};
