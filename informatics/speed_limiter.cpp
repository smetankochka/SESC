#include <iostream>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class FixedWindowRateLimiter {
private:
    int maxRequests; // Максимальное количество запросов в окне
    int windowSize; // Длина окна в миллисекундах
    unordered_map<string, queue<int>> requestMap; // Хранит время каждого запроса для каждого IP-адреса

public:
    FixedWindowRateLimiter(int maxRequests, int windowSize) {
        this->maxRequests = maxRequests;
        this->windowSize = windowSize;
    }

    string processRequest(int timestamp, string ip) {
        if (requestMap.find(ip) == requestMap.end()) {
            requestMap[ip] = queue<int>();
        }

        queue<int>& requests = requestMap[ip];
        while (!requests.empty() && requests.front() <= timestamp - windowSize) {
            requests.pop(); // Удаляем запросы, которые вышли за пределы окна
        }

        if (requests.size() < maxRequests) {
            requests.push(timestamp); // Добавляем время текущего запроса в очередь
            return "allow";
        } else {
            return "reject";
        }
    }
};

int main() {
    int maxRequests, maxRequestsInWindow, windowSize;
    cin >> maxRequests >> maxRequestsInWindow >> windowSize;
    cin.ignore();
    FixedWindowRateLimiter limiter(maxRequestsInWindow * 2 - 1, windowSize);
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int timestamp;
        string ip;
        iss >> timestamp >> ip;
        string result = limiter.processRequest(timestamp, ip);
        cout << result << endl;
    }
    return 0;
}