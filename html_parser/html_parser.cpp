﻿/*||======================================================||
  ||    GitHub: https://github.com/losif22/html_parser    ||
  ||    License: MIT                                      ||
  ||======================================================||*/
#include "html_parser.h"

std::string HTMLTagParser::parseTitle(const std::string& html_content) {
    std::smatch match;
    if (std::regex_search(html_content, match, title_regex)) {
        return match[1];
    }
    return "";
}

std::string getHTMLVersion(const std::string& html_content) {
    std::regex html5_regex("<!DOCTYPE\\s+html>", std::regex::icase);
    std::regex html4_regex("<!DOCTYPE\\s+HTML\\s+PUBLIC\\s+\"-//W3C//DTD\\s+HTML\\s+4\\.01//EN\"", std::regex::icase);
    std::regex xhtml_regex("<!DOCTYPE\\s+html\\s+PUBLIC\\s+\"-//W3C//DTD\\s+XHTML\\s+1\\.0\\s+Strict//EN\"", std::regex::icase);

    if (std::regex_search(html_content, html5_regex)) {
        return "HTML5";
    }
    else if (std::regex_search(html_content, html4_regex)) {
        return "HTML 4.01";
    }
    else if (std::regex_search(html_content, xhtml_regex)) {
        return "XHTML 1.0";
    }
    else {
        return "Unknown HTML Version";
    }
}

std::string HTMLTagParser::parseLang(const std::string& html_content) {
    std::smatch match;
    if (std::regex_search(html_content, match, lang_regex)) {
        return match[1];
    }
    return "";
}

std::string HTMLTagParser::parseEncoding(const std::string& html_content) {
    std::smatch match;
    if (std::regex_search(html_content, match, encoding_regex)) {
        return match[1];
    }
    return "";
}

HTMLParser::HTMLParser(const char* file_name) {
    html_file.open(file_name);
    if (!html_file) {
        std::cout << "Помилка при відкритті файлу: " << file_name << "\n";
        exit(0);
    }

    std::stringstream buffer{};
    buffer << html_file.rdbuf();
    html_content = buffer.str();
}

HTMLParser::~HTMLParser() {
    if (html_file.is_open()) {
        html_file.close();
    }
}

void HTMLParser::getHTMLData() {
    std::string version = getHTMLVersion(html_content);
    std::string title = html_tags.parseTitle(html_content);
    std::string lang = html_tags.parseLang(html_content);
    std::string encoding = html_tags.parseEncoding(html_content);

    std::cout << "Версія HTML: " << version << "\n";
    std::cout << "Мова сторінки: " << lang << "\n";
    std::cout << "Кодування сторінки: " << encoding << "\n";
    std::cout << "Назва сторінки: " << title << "\n";

}
