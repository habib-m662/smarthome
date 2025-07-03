#include "securitycamera.h"
#include <iostream>

void secuirtycamera::perform_operation(std::string& op) {
    if (op == "ON" || op == "RECORD") {
        isrecording = true;
    } else if (op == "OFF") {
        isrecording = false;
    } else {
        std::cout << "[SecurityCamera] Unknown command.\n";
    }
}


std::string secuirtycamera::get_status() {
    return "[SecurityCamera] Recording: " + std::string(isrecording ? "Yes" : "No");
}