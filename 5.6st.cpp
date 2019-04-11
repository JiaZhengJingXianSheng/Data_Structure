/*实验五、六  二叉树的建立、插入、删除与遍历（4学时）
一、实验目的
了解二叉树的定义及基本运算，掌握二叉树的描述方法、特点、性质及存储结构；
掌握二叉树的基本操作算法（包括查找、插入、删除和遍历等操作）。
二、实验内容
根据用户通过键盘给定数据建立二叉树，并对此二叉树进行查找、
插入、删除和遍历等操作，遍历方式有前序、中序、后序遍历三种。
基本要求：
（1）用户可通过键盘任意选择各种操作；
（2）用户可由键盘给定数据建立二叉树；
（3）分别显示树型结构和存储地址；
（4）查找某结点的地址；
（5）插入或删除某结点；
（6）进行二叉树遍历，遍历方式可由用户选择；
（7）输出遍历结果；
（8）可由用户选择退出程序。
三、实验要点及说明
用链式存储结构存储一个二叉树，首先应建立根结点，
其他结点可根据用户选择插入到根结点的左右子树中。
二叉树的遍历是指按照某种顺序访问二叉树中的每个结点，
使每个结点被访问一次且只被访问一次。常用的二叉树遍历方法如下：
(1) 前序遍历：访问次序：根→左→右，
(2) 中序遍历：访问次序：左→根→右，
(3) 后序遍历：访问次序：左→右→根。
要求用户操作界面如图所示：

可按如下格式定义二叉树的链式存储结构：
typedef  struct  btreenode
{
	datatype  data;
	struct btreenode  *lchild;
	struct btreenode  *rchild;
}nodetype;
模块划分：
（1）int initiate(nodetype **bt)：初始化
（2）nodetype *create(nodetype *bt, elemtype x)：建立只有根结点的二叉树
（3）nodetype *insertl(elemtype x, nodetype *parent)：将结点x插入到结点parent的左孩子结点
（4）nodetype *insertr(elemtype x, nodetype *parent)：将结点x插入到结点parent的右孩子结点
（5）nodetype *insert(nodetype *bt)：
（6）nodetype *deleted(nodetype *bt)：删除
（7）void printtree(nodetype *bt, int n)：屏幕显示树（凹入表形式）
void printftree(nodetype *bt) ：  屏幕显示树的存储结构
（8）preorder(nodetype *bt)：前序遍历
（9）inorder(nodetype *bt)：中序遍历
（10）postorder(nodetype *bt)：后续遍历
这个实验作为设计性实验，参考程序中只给出模块函数，需自己编写主函数和遍历函数，并进行功能调试。*/