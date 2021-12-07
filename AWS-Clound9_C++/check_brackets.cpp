#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int pos_unmatched = -1;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket *b = new Bracket(next, position + 1);
            opening_brackets_stack.push(*b);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.size() == 0) {
                pos_unmatched = position + 1;
                break;
            }
            else if (opening_brackets_stack.top().Matchc(next)) {
                opening_brackets_stack.pop();
            }
            else {
                pos_unmatched = position + 1;
                break;
            }
        }
    }

    // Printing answer, write your code here
    if (opening_brackets_stack.size() == 0 && pos_unmatched == -1) {
        std::cout << "Success" << std::endl;
    }
    else {
        if (opening_brackets_stack.size() > 0 && pos_unmatched == -1) {
            pos_unmatched = opening_brackets_stack.top().position;
        }
        std::cout << pos_unmatched << std::endl;
    }

    return 0;
}
