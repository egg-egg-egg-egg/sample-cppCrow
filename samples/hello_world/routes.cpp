#include "routes.h"
#include <fstream>
#include <sstream>

void setupRoutes(crow::SimpleApp& app) {
    // 根路径返回静态 HTML
    CROW_ROUTE(app, "/")([](){
        // 指定静态文件路径
        std::ifstream file("samples/hello_world/static/index.html");
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    });

    // 一个简单的 JSON API
    CROW_ROUTE(app, "/api/hello")([](){
        crow::json::wvalue x;
        x["message"] = "Hello from Crow!";
        return x;
    });
}
