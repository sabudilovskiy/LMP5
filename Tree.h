//
// Created by MRV on 26.12.2021.
//

#ifndef LMP5_TREE_H
#define LMP5_TREE_H
#include "Node.h"
#include <string>
class Tree{
    Node* root;
public:
    Tree(){
        root = new Node(0);
    }
    Node* get_root(){
        return root;
    }
    void add(const std::string& str){
        int i = 0;
        Node* cur_node = root;
        while (i < str.size()){
            char cur_ch = tolower(str[i]);
            int found = -1;
            std::list<Node*>& childs = cur_node->get_childs();
            auto cur_child = childs.begin();
            while (cur_child != childs.end() && found == -1){
                char temp = (*cur_child)->get_info();
                if ( temp == cur_ch){
                    found = 1;
                }
                else if (temp < cur_ch){
                    cur_child++;
                }
                else {
                    found = 0;
                }
            }
            if (found == -1){
                childs.push_back(new Node(cur_ch));
                cur_child = childs.begin();
                cur_node = *(cur_child);
            }
            else if (found == 1){
                cur_node = (*cur_child);
            }
            else{
                childs.insert(cur_child, new Node(cur_ch));
                cur_child--;
                cur_node = *(cur_child);
            }
            i++;
        }
        cur_node->up_end();
    }
};
#endif //LMP5_TREE_H
