#include <iostream>
#include <vector>


std::vector<int> tree;
std::vector<int> printer;
void    check_priority(int cur_i);
//std::vector<int>::iterator iter = tree.begin();

void    pop_root() {
    printer.push_back(*tree.begin());
    std::swap(*tree.begin(), *(tree.end() - 1));
    tree.pop_back();
    check_priority(0);
}

void    check_priority(int cur_i) {
    int left_i = 2 * cur_i + 1;
    int right_i = 2 * cur_i + 2;
    int small_i = cur_i;

    if (left_i < tree.size() && tree[left_i] < tree[small_i])
        small_i = left_i;
    if (right_i < tree.size() && tree[right_i] < tree[small_i])
        small_i = right_i;
    if (small_i != cur_i)
    {
        std::swap(tree[small_i],tree[cur_i]);
        check_priority(small_i);
    }
}

void    check_priority_bottom_up(int last_i) {
    if (last_i <= 0)
        return ;
    int parent_i = (last_i - 1) / 2;
    int largest_i = parent_i;
    if (tree[largest_i] > tree[last_i])
    {
        std::swap(tree[largest_i], tree[last_i]);
        check_priority_bottom_up(largest_i);
    }
}

void    push_val(int temp) {
    tree.push_back(temp);
    check_priority_bottom_up(tree.size() - 1);
}

void priority_queue(int temp) {
    if (temp == 0)
    {
        if (tree.size() == 0)
            printer.push_back(0);
        else
            pop_root();
    }
    else 
    {
        push_val(temp);
    }
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int count;
    std::cin >> count;
    for (int i = 0 ; i < count ; i ++)
    {
        int temp;
        std::cin >> temp;
        priority_queue(temp);
    }
    for (int i = 0 ; i < printer.size() ; i++)
        std::cout << printer[i] << std::endl;
}