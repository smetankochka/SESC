#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>


std::string processRequest(int timestamp, const std::string& ip, int maxRequests, int windowSize, std::unordered_map<std::string, std::queue<int>>& requestMap) {
    if (requestMap.find(ip) == requestMap.end()) {
        requestMap[ip] = std::queue<int>();
    }

    std::queue<int>& requests = requestMap[ip];
    while (!requests.empty() && requests.front() <= timestamp - windowSize) {
        requests.pop();
    }

    if (requests.size() < maxRequests) {
        requests.push(timestamp);
        return "allow";
    } else {
        return "reject";
    }
}

int main() {
    int maxRequests, maxRequestsInWindow, windowSize, timestamp;
    std::string ip;
    std::unordered_map<std::string, std::queue<int>> requestMap;

    std::cin >> maxRequests >> maxRequestsInWindow >> windowSize;

    while (std::cin >> timestamp >> ip) {
        std::cout << processRequest(timestamp, ip, maxRequestsInWindow * 2 - 1, windowSize, requestMap) << std::endl;
    }

    return 0;
}
