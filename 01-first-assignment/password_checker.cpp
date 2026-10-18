//长度判断：原代码第16行原来用 <= 10, 导致短密码通过，长密码被拒绝，与原意不符。应为 >= 10。
//范围边界：原代码第六行<将原边界排除了，所以要加上=号。
//数字判断：0与9不是字符，而是整数。所以要加单引号。
//自己设计的测试输入与预期输出：Lao Da Cc112345678 ; VALID
#include <iostream>
#include <string>

bool contains_between(const std::string& text, char lower, char upper) {
    for (char ch : text) {
        if (lower <= ch && ch <= upper) {
            return true;
        }
    }
    return false;
}

bool check_password(const std::string& first_name,
                    const std::string& last_name,
                    const std::string& password) {
    bool length_ok = password.size() >= 10;
    bool upper_ok = contains_between(password, 'A', 'Z');
    bool lower_ok = contains_between(password, 'a', 'z');
    bool digit_ok = contains_between(password, '0', '9');
    bool name_ok = password.find(first_name) == std::string::npos &&
                   password.find(last_name) == std::string::npos;
    return length_ok && upper_ok && lower_ok && digit_ok && name_ok;
}

int main() {
    std::string first_name, last_name, password;
    if (!(std::cin >> first_name >> last_name >> password)) {
        std::cerr << "请输入：名 姓 密码\n";
        return 1;
    }
    std::cout << (check_password(first_name, last_name, password)
                      ? "VALID" : "INVALID") << '\n';
    return 0;
}
