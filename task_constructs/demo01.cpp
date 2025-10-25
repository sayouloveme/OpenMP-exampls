#include <iostream>
#include <omp.h>

using namespace std;

/*
task将代码封装成独立的任务，可以让多个线程去执行，默认情况的变量是firstprivate，即变量是初始化后的私有副本
*/
//二叉数结构
struct node
{
    node *left,*right;
    int data;
    node(int value) : left(nullptr),right(nullptr),data(value){}

};

//处理函数
extern void process(node *p)
{
    cout << "process with data " << p->data << endl;
}

//遍历二叉数
void traverse(node *p)
{
    if(p->left)
    {
        #pragma omp task
        traverse(p->left);
    }
    if(p->right)
    {
        #pragma omp task
        traverse(p->right);
    }
    process(p);
}

//后序遍历
void postorder_traverse(node *p)
{
    if(p->left)
    {
        #pragma omp task//创建一个并行任务
        postorder_traverse(p->left);
    }
    if(p->right)
    {
        #pragma omp task
        postorder_traverse(p->right);
    }
    #pragma omp taskwait//类似于同步，等待前面完成才进行下一阶段
    process(p);
}

//链表节点结构
struct list_node
{
    int data;
    list_node *next;

    list_node(int value): data(value),next(nullptr){}
};

void process2(list_node *p)
{
    cout << "process with data" << p->data << endl;
}

//链表处理函数
void increment_list_items(list_node *head)
{
    #pragma omp parallel
    {
        #pragma omp single
        {
            for(list_node *p=head;p;p=p->next)
            {
                #pragma omp task
                process2(p);
            }
        }
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << "Traversing tree is" << endl;

    #pragma omp parallel
    {
        #pragma omp single
        {
            traverse(root);
        }
    }

    list_node *head = new list_node(1);
    head->next = new list_node(2);
    head->next->next = new list_node(3);

    cout << "increment_list_items" << endl;
    increment_list_items(head);

    return 0;
}