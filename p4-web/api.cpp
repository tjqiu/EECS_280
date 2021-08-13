// Project UID c1f28c309e55405daf00c565d57ff9ad
#include <list>
#include "json.hpp"
#include <iostream>

void header200() {
    std::cout << "HTTP/1.1 200 OK" << std::endl << "Content-Type: "
    << "application/json; charset=utf-8" << std::endl << "Content-Length: ";
}

void error() {
    std::cout << "HTTP/1.1 400 Bad Request" << std::endl
    << "Content-Type: application/json; charset=utf-8"
    << std::endl << "Content-Length: 0" << std::endl << std::endl;
}

void getApi() {
    header200();
    std::cout << "160" << std::endl << std::endl;
    nlohmann::json j = {
        {"queue_head_url", "http://localhost/queue/head/"},
        {"queue_list_url", "http://localhost/queue/"},
        {"queue_tail_url", "http://localhost/queue/tail/"}
    };
    std::string out = j.dump(4) + "\n";
    std::cout << out;
}

void getQue() {
    header200();
    std::cout << "40" << std::endl << std::endl;
    nlohmann::json j ={
        {"count", 0},
        {"results", "null"}
    };
    std::string out = j.dump(4) + "\n";
    std::cout << out;
}

class OHQueue {
public:
    bool isEmpty() {
        return queue.empty();
    }
    
    int size() {
        return int(queue.size());
    }
    
    void post(nlohmann::json j) {
        Student t;
        t.uniqname = j["uniqname"];
        t.location = j["location"];
        t.position = int(queue.size()) + 1;
        queue.push_back(t);
    }
    
    void postCout() {
        std::cout << "HTTP/1.1 201 Created" << std::endl
        << "Content-Type: " << "application/json; charset=utf-8"
        << std::endl
        << "Content-Length: ";
        Student t = queue.back();
        nlohmann::json j = {
            {"location", t.location},
            {"position", t.position},
            {"uniqname", t.uniqname}
        };
        std::string out = j.dump(4) + "\n";
        std::cout << int(out.length()) << std::endl << std::endl << out;
    }
    
    void getHeadCout() {
        header200();
        Student t = queue.front();
        nlohmann::json j = {
            {"location", t.location},
            {"position", t.position},
            {"uniqname", t.uniqname}
        };
        std::string out = j.dump(4) + "\n";
        std::cout << int(out.length()) << std::endl << std::endl << out;
    }
    
    void getQueCout() {
        header200();
        nlohmann::json arr;
        std::list<Student> temp;
        temp = queue;
        for (int i = 0; i < int(queue.size()); i++) {
            Student t = temp.front();
            nlohmann::json tem = {
                {"location", t.location},
                {"position", t.position},
                {"uniqname", t.uniqname}
            };
            arr.push_back(tem);
            temp.pop_front();
        }
        nlohmann::json j = {
            {"count", int(queue.size())},
            {"results", arr}
        };
        std::string out = j.dump(4) + "\n";
        std::cout << int(out.length()) << std::endl << std::endl << out;
    }
    
    void deleteCout() {
        queue.pop_front();
        std::cout << "HTTP/1.1 204 No Content" << std::endl
        << "Content-Type: application/json; charset=utf-8"
        << std::endl << "Content-Length: 0" << std::endl << std::endl;
    }
    
    void errorPost() {
        std::string buffer;
        while (std::cin >> buffer) {
            if (buffer == "}" || buffer == "{}") {
                error();
                break;
            }
        }
    }
    
    void postMain(std::string status) {
        std::string path, buffer;
        int content_length;
        nlohmann::json j;
        if (status == "POST") {
            std::cin >> path;
            if (path != "/api/queue/tail/") {
                errorPost();
            }
            else {
                for (int i = 0; i < 7; i++) {
                    std::cin >> buffer;
                }
                std::cin >> content_length;
                std::cin >> j;
                post(j);
                postCout();
            }
        }
    }
    
    void getMain(std::string status) {
        std::string path, buffer;
        int content_length;
        nlohmann::json j;
        if (status == "GET") {
            std::cin >> path;
            for (int i = 0; i < 7; i++) {
                std::cin >> buffer;
            }
            std::cin >> content_length;
            if (path == "/api/") {
                getApi();
            }
            else if (path == "/api/queue/head/") {
                if (!isEmpty()) {
                    getHeadCout();
                }
                else {
                    error();
                }
            }
            else if (path == "/api/queue/") {
                if (!isEmpty()) {
                    getQueCout();
                }
                else {
                    getQue();
                }
            }
            else {
                error();
            }
        }
    }
    
    void deletePar() {
        std::string buffer;
        int content_length;
        for (int i = 0; i < 7; i++) {
            std::cin >> buffer;
        }
        std::cin >> content_length;
        if (isEmpty()) {
            error();
        }
        else {
            deleteCout();
        }
    }
    
    void errorDelete() {
        std::string buffer;
        while (std::cin >> buffer) {
            if (buffer == "0") {
                error();
                break;
            }
        }
    }
    
    void deleteMain(std::string status) {
        std::string path, buffer;
        if (status == "DELETE") {
            std::cin >> path;
            if (path != "/api/queue/head/") {
                errorDelete();
            }
            else {
                deletePar();
            }
        }
    }
    
private:
  struct Student {
      std::string uniqname;
      std::string location;
      int position;
  };
    std::list<Student> queue;
};



int main() {
    OHQueue OHQueue;
    nlohmann::json j;
    std::string status, path, buffer;
    while (std::cin >> status) {
        OHQueue.postMain(status);
        OHQueue.getMain(status);
        OHQueue.deleteMain(status);
    }
    return 0;
}
