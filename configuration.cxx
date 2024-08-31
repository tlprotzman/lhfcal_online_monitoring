#include "configuration.h"

#include <iostream>
#include <fstream>
#include <string>

void load_configs(std::string config_file) {
    auto config = configuration::get_instance();
    std::ifstream file(config_file);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Process each line of the config file
            // Example: Split the line into key-value pairs
            std::string key, value;
            std::size_t delimiter_pos = line.find('=');
            if (delimiter_pos != std::string::npos) {
                key = line.substr(0, delimiter_pos);
                value = line.substr(delimiter_pos + 1);
                // Do something with the key-value pair
                std::cout << "Key: " << key << ", Value: " << value << std::endl;
                if (key == "NUM_LINES") {
                    config->NUM_LINES = std::stoi(value);
                } else if (key == "NUM_FPGA") {
                    config->NUM_FPGA = std::stoi(value);
                } else if (key == "NUM_CHANNELS") {
                    config->NUM_CHANNELS = std::stoi(value);
                } else if (key == "NUM_LINES") {
                    config->NUM_LINES = std::stoi(value);
                } else if (key == "MAX_SAMPLES") {
                    config->MAX_SAMPLES = std::stoi(value);
                } else if (key == "MACHINE_GUN_MAX_TIME") {
                    config->MACHINE_GUN_MAX_TIME = std::stoi(value);
                } else if (key == "PACKET_SIZE") {
                    config->PACKET_SIZE = std::stoi(value);
                } else {
                    std::cerr << "Unknown key: " << key << std::endl;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Failed to open config file: " << config_file << std::endl;
    }
    print_configs();
}

void print_configs() {
    auto config = configuration::get_instance();
    // Print the configuration values
    std::cout << "Configuration values:" << std::endl;
    std::cout << "NUM_LINES: " << config->NUM_LINES << std::endl;
    std::cout << "NUM_FPGA: " << config->NUM_FPGA << std::endl;
    std::cout << "NUM_CHANNELS: " << config->NUM_CHANNELS << std::endl;
    std::cout << "NUM_LINES: " << config->NUM_LINES << std::endl;
    std::cout << "MAX_SAMPLES: " << config->MAX_SAMPLES << std::endl;
    std::cout << "MACHINE_GUN_MAX_TIME: " << config->MACHINE_GUN_MAX_TIME << std::endl;
    

    std::cout << "PACKET_SIZE: " << config->PACKET_SIZE << std::endl;

}

configuration *configuration::instance = nullptr;