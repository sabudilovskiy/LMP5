//
// Created by MRV on 26.12.2021.
//

#ifndef LMP5_NODE_H
#define LMP5_NODE_H
#include <list>
class Node{
    char info;
    int end = 0;
    std::list<Node*> childs;
public:
    Node(char info) : info(info) {}
    char get_info() const {
        return info;
    }
    int get_end() const {
        return end;
    }
    void up_end(){
        end++;
    }
    [[nodiscard]] std::list<Node *>& get_childs() {
        return childs;
    }
    void add_child(Node* node){
        childs.push_back(node);
    }

};
#endif //LMP5_NODE_H
