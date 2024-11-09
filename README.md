# JSMN-based-JSON-Data-Extractor
JSMN JSON Data Extractor is a lightweight and efficient tool designed to parse JSON strings and extract key-value pairs using the JSMN (Jansson Minimal) parser. This tool supports both string and numeric (integer or hexadecimal) values, making it ideal for embedded systems, IoT applications, and other environments where memory and processing power are limited.

## Features
- Efficient Parsing: Uses the JSMN (Jansson Minimal) parser for fast, memory-efficient JSON parsing.
- String & Numeric Support: Supports parsing of both string and numeric (decimal and hexadecimal) values.
- Customizable Key Extraction: Allows you to specify which keys to extract from a given JSON string.
- Lightweight: Designed for environments with limited resources, such as embedded systems.
## Requirements
- C Compiler: GCC or Clang (for compiling the C code).
- JSMN Library: This tool uses the JSMN parser, which is lightweight and minimalistic, find more about jasmine library for embedded devices [here](https://zserge.com/jsmn/)

## Installation
To use the JSMN JSON Data Extractor, follow these steps:

- Install the JSMN Parser
First, you need to download the JSMN library. You can either clone the repository or download the files directly.
```
git clone https://github.com/zserge/jsmn.git
```
- Clone or Download the Project
Clone the project repository to your local machine (if you haven't done so already):
```
git clone <repository_url>
```
## Compile the Project
Once you have the project and dependencies set up, navigate to the project directory and compile the C files:
```
gcc -o json_extractor main.c jsmn_json_extractor.c -I/path/to/jsmn -lm
```
Replace /path/to/jsmn with the path to where the jsmn library is located. This command compiles the source code and links it to the JSMN library.

## Usage
After successfully compiling the program, you can run it to extract key-value pairs from a JSON string.

- Prepare Your JSON String
The JSON string is defined in your C program (or passed as input) and should be formatted as follows:
```
const char *json_string = "{\"1\":123,\"2\":\"0x1\",\"3\":23,\"5\":\"device\",\"6\":\"example_string\",\"7\":456,\"8\":\"0x2A\",\"9\":789,\"10\":\"another_device\"}";
```
## Specify Keys for Extraction
In your program, specify the keys you want to extract. For example:
```
const char *keys[] = {"1",  "6", "7", "8", "10"};
int key_count = 5;
```
## Run the Program
```
./json_extractor
```
## Output Example
After running the program, you should see the output in the terminal:
```
Key: 1, Value: 123
Key: 6, Value: example_string
Key: 7, Value: 456
Key: 8, Value: 42
Key: 10, Value: another_device
```
## Modify Keys as Needed

You can easily modify the keys[] array to extract different values based on your specific needs.

## Code Example
Here is an example of how the program extracts key-value pairs from a JSON string:
```
int main() {
    const char *json_string = "{\"1\":123,\"2\":\"0x1\",\"3\":23,\"5\":\"device\",\"6\":\"example_string\",\"7\":456,\"8\":\"0x2A\",\"9\":789,\"10\":\"another_device\"}";
    const char *keys[] = {"1", "2", "3", "5", "6", "7", "8", "9", "10"};
    int key_count = 9;

    VariableHolderType variables[key_count];
    int result = extract_json_data(json_string, keys, key_count, variables);

    if (result == 0) {
        for (int i = 0; i < key_count; i++) {
            printf("Key: %s, Value: ", keys[i]);
            if (variables[i].is_int) {
                printf("%d\n", variables[i].int_val);
            } else {
                printf("%s\n", variables[i].string_val);
            }
        }
    } else {
        printf("Error extracting JSON data\n");
    }
    
    return 0;
}
```
## Contributing
Feel free to contribute to this project! You can:

- Report bugs or issues.
- Suggest features or improvements.
- Fork the project and submit pull requests with enhancements.

Please make sure to follow the existing coding style and add tests for any new features.

