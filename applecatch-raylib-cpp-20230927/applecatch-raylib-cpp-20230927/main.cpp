#include <iostream>
#include <fstream>
#include "webview.h"

// async callback passing (I think) the webview instance
std::string hello(const std::string& arg, const std::string& arg2, void* data) {
    std::printf("%s\n", arg.c_str());
    return std::string("ok");
}

// common entry point for console apps.
int main() {
    std::string line;
    std::string html;
    std::ifstream html_file("website/index.html");
    while (std::getline(html_file, line)) {
        html += line;
    }
    unsigned int count = 0;
    webview::webview w(false, nullptr);
    w.set_title("Bind Example");
    w.set_size(640, 480, WEBVIEW_HINT_NONE);
    w.bind("hello", hello, &w);
    w.set_html(html);
    w.run();

    return 0;
}