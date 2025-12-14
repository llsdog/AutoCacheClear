#include <stdlib.h>
#include <iostream>
#include <string>
#include <unistd.h>

int main() {
    int clearLevel = 1, intervalTime = 1, clearCount = 0; // 配置初始化
    
    std::cout << "清除等级(1/2/3)选择:";
    // 获取并检查清除等级
    try
    {
        std::cin >> clearLevel;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "输入类型与预期不符!" << "\n";
    }
    if (clearLevel != 1 && clearLevel != 2 && clearLevel != 3)
    {
        std::cout << "输入范围与预期不符!" << "\n";
        return 0;
    }

    // 获取间隔时间
    std::cout << "间隔时间(h)输入:";
    try
    {
        std::cin >> intervalTime;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "输入类型与预期不符!" << "\n";
    }
    if (intervalTime < 1)
    {
        std::cout << "输入范围与预期不符!" << "\n";
        return 0;
    } 
    
    while (1)
    {
        system(("echo " + std::to_string(clearLevel) + " > /proc/sys/vm/drop_caches").c_str());
        clearCount++;
        std::cout << "清除成功,次数:" << clearCount << "\n";
        sleep(intervalTime*3600);
    }

    return 0;
}