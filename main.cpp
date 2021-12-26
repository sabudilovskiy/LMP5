#include <iostream>
#include "Tree.h"
#include <stack>
#include <Windows.h>
std::string stack_to_string(const std::stack<char>& s){
    std::string temp;
    temp.resize(s.size());
    std::stack<char> copy = s;
    int i = temp.size() - 1;
    while (i > -1){
        temp [i--]= copy.top();
        copy.pop();
    }
    return temp;
}
bool is_vowel(char ch){
    static std::string base = "אמףû‎‏ÿ";
    return base.find(ch) != -1;
}
bool is_corsonant(char ch){
    static std::string base = "בגדהזחךכלםןנסעפץצקרש";
    return base.find(ch) != -1;
}
void DPS(Node* cur_node, std::stack<char>& stack, bool vowel){
    if (vowel &&is_vowel(cur_node->get_info()) || !vowel && is_corsonant(cur_node->get_info())){
        stack.push(cur_node->get_info());
        if (cur_node->get_end() > 0) {
            std::string temp = stack_to_string(stack);
            for (int i = 0; i < cur_node->get_end(); i++) {
                std::cout << temp << '\n';
            }
        }
        std::list<Node*>& childs = cur_node->get_childs();
        auto iterator = childs.begin();
        while (iterator != childs.end()){
            DPS(*iterator, stack, !vowel);
            iterator++;
        }
        stack.pop();
    }
}
void task(Tree& tree){
    Node*cur_node = tree.get_root();
    std::stack<char> stack;
    auto iterator = cur_node->get_childs().begin();
    const auto& end = cur_node->get_childs().end();
    while (iterator != end) {
        cur_node = *iterator;
        char cur_ch = cur_node->get_info();
        if (is_vowel(cur_ch)){
            DPS(cur_node, stack, true);
        }
        else if (is_corsonant(cur_ch)){
            DPS(cur_node, stack, false);
        }
        iterator++;
    }
}

int main() {
    Tree tree;
    tree.add("לאלא");
    tree.add("לאךאךא");
    task(tree);
    return 0;
}
