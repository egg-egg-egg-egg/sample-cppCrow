#include "crow.h"
// 这是一个最基础可运行的代码, 更多的示例与框架请查看samples文件夹
int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello, Crow!";
    });
    app.port(18080).multithreaded().run();
}