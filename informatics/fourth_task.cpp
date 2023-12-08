#include <iostream>
#include <string>

void xorstring(std::string &msg, std::string key) {
    std::string result;
    for (int i = 0; i < msg.size(); i++) {
        result.push_back(msg[i] ^ key[i % key.size()]);
    }
    for (char c : result) {
        std::cout << int(c) << " ";
    }
}

int main() {
    std::string msg, key;
    std::cin >> msg >> key;
    xorstring(key, "sesc");
    xorstring(msg, key);
}