#include <iostream>
#include <sstream>

int main() {

    std::string query = "SELECT * FROM TABALE WHERE ID = 5";
    std::stringstream ss;
    ss.str(query);
    std::string t;
    while (ss >> t) {
        std::cout << t << std::endl;
    }
    
}