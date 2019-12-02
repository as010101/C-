
//非指针型结构体
struct Seqlist{//C++标准定义结构体方法
    int elem[MAX];//数组
    int len;//数组长
};

typedef struct SS{
    int elem[MAX];//数组
    int len;//数组长
}Seqlist;//为结构体SS起一个别名Seqlist

typedef struct{
    int elem[MAX];//数组
    int len;//数组长
}Seqlist;//定义匿名结构体，别名为Seqlist


//指针型结构体

struct BinTNode{ //定义结点
    char data;
    struct BinTNode *lchild, *rchild;//经测试，在vc6.0中去掉struct也行
};
typedef BinTNode *BinTree; //定义二叉树，本质是结构体指针或节点指针

typedef struct node{ //定义结点
    char data;
    struct node *lchild, *rchild;
}BinTNode,*BinTree; //定义二叉树
