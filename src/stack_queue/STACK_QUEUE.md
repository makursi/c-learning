队列（Queue）数据结构详解与 C 语言实现

队列是一种先进先出（FIFO - First In First Out） 的线性数据结构，就像排队买票一样：先来的人先被服务，后来的人排在队尾。

📌 队列的基本概念

核心特点：

- 队头（Front）：删除元素的一端
- 队尾（Rear/Rear）：插入元素的一端
- FIFO 原则：最早进入的元素最先被删除

基本操作：

- enqueue() - 入队（在队尾添加元素）
- dequeue() - 出队（从队头删除元素）
- peek() - 查看队头元素（不删除）
- isEmpty() - 判断队列是否为空
- isFull() - 判断队列是否已满（仅限固定大小队列）

🧱 队列的两种实现方式

1. 顺序队列（数组实现）

- 使用数组存储元素
- 需要两个指针：front 和 rear
- 缺点：会出现"假溢出"问题（前面有空位但无法使用）

2. 循环队列（推荐）

- 将数组看作首尾相连的环形结构
- 解决了假溢出问题，空间利用率高

3. 链式队列（链表实现）

- 使用链表存储元素
- 动态分配内存，无容量限制
- 需要维护头指针和尾指针

✅ 推荐实现：循环队列（C 语言）

下面我将为你实现一个完整的循环队列，包含所有你需要的功能。

步骤 1：定义数据结构

include
include
include

define MAX_SIZE 100 // 队列最大容量

// 元素类型定义（可根据需要修改）
typedef int ElemType;

// 循环队列结构体
typedef struct {
ElemType data[MAX_SIZE]; // 存储队列元素的数组
int front; // 队头指针（指向第一个元素）
int rear; // 队尾指针（指向最后一个元素的下一个位置）
int size; // 当前队列中元素个数（可选，便于实现）
} CircularQueue;

💡 关键设计说明：

- front 指向队头元素的位置
- rear 指向队尾元素的下一个位置（这样设计便于判断空/满）
- 使用 size 字段简化空/满判断（也可以不用，通过 (rear + 1) % MAX_SIZE == front 判断满）

步骤 2：初始化队列

// 初始化队列
CircularQueue* initQueue() {
CircularQueue* q = (CircularQueue\*)malloc(sizeof(CircularQueue));
if (q == NULL) {
printf("内存分配失败！n");
return NULL;
}

    q->front = 0;
    q->rear = 0;
    q->size = 0;

    return q;

}

步骤 3：判断队列状态

// 判断队列是否为空
bool isEmpty(CircularQueue\* q) {
return q->size == 0;
}

// 判断队列是否已满
bool isFull(CircularQueue\* q) {
return q->size == MAX_SIZE;
}

// 获取队列当前大小
int getSize(CircularQueue\* q) {
return q->size;
}

步骤 4：入队操作（enqueue）

// 入队：在队尾添加元素
bool enqueue(CircularQueue\* q, ElemType value) {
if (q == NULL) return false;

    if (isFull(q)) {
        printf("队列已满，无法入队！n");
        return false;
    }

    q->data[q->rear] = value;           // 在队尾位置存入元素
    q->rear = (q->rear + 1) % MAX_SIZE; // rear 指针循环移动
    q->size++;                          // 元素个数加1

    return true;

}

步骤 5：出队操作（dequeue）

// 出队：从队头删除元素，并通过指针返回被删除的值
bool dequeue(CircularQueue* q, ElemType* value) {
if (q == NULL || value == NULL) return false;

    if (isEmpty(q)) {
        printf("队列为空，无法出队！n");
        return false;
    }

    *value = q->data[q->front];         // 获取队头元素
    q->front = (q->front + 1) % MAX_SIZE; // front 指针循环移动
    q->size--;                          // 元素个数减1

    return true;

}

步骤 6：查看指定索引的元素（你的需求）

// 根据索引获取队列中的元素值（索引从0开始，0表示队头）
// 返回 true 表示成功，false 表示索引无效
bool getAtIndex(CircularQueue* q, int index, ElemType* value) {
if (q == NULL || value == NULL) return false;

    if (index = q->size) {
        printf("索引越界！有效范围：0 ~ %dn", q->size - 1);
        return false;
    }

    // 计算实际数组中的位置
    int actualIndex = (q->front + index) % MAX_SIZE;
    *value = q->data[actualIndex];

    return true;

}

步骤 7：查看队头元素（不删除）

// 查看队头元素（不删除）
bool peek(CircularQueue* q, ElemType* value) {
if (q == NULL || value == NULL) return false;

    if (isEmpty(q)) {
        printf("队列为空！n");
        return false;
    }

    *value = q->data[q->front];
    return true;

}

步骤 8：销毁队列

// 销毁队列，释放内存
void destroyQueue(CircularQueue\* q) {
if (q != NULL) {
free(q);
}
}

步骤 9：打印队列（调试用）

// 打印队列所有元素（从队头到队尾）
void printQueue(CircularQueue\* q) {
if (q == NULL) {
printf("队列不存在！n");
return;
}

    if (isEmpty(q)) {
        printf("队列为空n");
        return;
    }

    printf("队列内容（从队头到队尾）: ");
    for (int i = 0; i size; i++) {
        int index = (q->front + i) % MAX_SIZE;
        printf("%d ", q->data[index]);
    }
    printf("n");

}

🧪 完整测试示例

int main() {
// 创建队列
CircularQueue\* queue = initQueue();
if (queue == NULL) {
return -1;
}

    printf("=== 队列测试开始 ===n");

    // 测试入队
    printf("n1. 测试入队操作:n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printQueue(queue);

    // 测试获取指定索引元素
    printf("n2. 测试获取指定索引元素:n");
    ElemType val;
    if (getAtIndex(queue, 0, &val)) {
        printf("索引0的元素: %dn", val); // 应该是10（队头）
    }
    if (getAtIndex(queue, 1, &val)) {
        printf("索引1的元素: %dn", val); // 应该是20
    }
    if (getAtIndex(queue, 2, &val)) {
        printf("索引2的元素: %dn", val); // 应该是30（队尾）
    }

    // 测试出队
    printf("n3. 测试出队操作:n");
    if (dequeue(queue, &val)) {
        printf("出队元素: %dn", val); // 应该是10
    }
    printQueue(queue);

    // 再次测试索引访问
    printf("n4. 出队后再次测试索引访问:n");
    if (getAtIndex(queue, 0, &val)) {
        printf("索引0的元素: %dn", val); // 应该是20（新的队头）
    }
    if (getAtIndex(queue, 1, &val)) {
        printf("索引1的元素: %dn", val); // 应该是30
    }

    // 测试边界情况
    printf("n5. 测试边界情况:n");
    getAtIndex(queue, 5, &val); // 索引越界

    // 清空队列
    printf("n6. 清空队列:n");
    while (!isEmpty(queue)) {
        dequeue(queue, &val);
        printf("出队: %dn", val);
    }
    printQueue(queue);

    // 销毁队列
    destroyQueue(queue);
    printf("n=== 队列测试结束 ===n");

    return 0;

}

🔍 关键知识点解析

1. 循环队列的索引计算
   // 从逻辑索引到物理索引的转换
   int actualIndex = (front + logicalIndex) % MAX_SIZE;

- 逻辑索引：0（队头）、1、2...（队尾）
- 物理索引：数组中的实际位置

2. 为什么 rear 指向"下一个位置"？

- 这样设计使得：
  - 空队列：front == rear
  - 满队列：(rear + 1) % MAX_SIZE == front
- 但会浪费一个数组位置

3. 使用 size 字段的优势

- 简化空/满判断：size == 0 和 size == MAX_SIZE
- 避免复杂的模运算判断
- 便于实现 getSize() 函数

4. 错误处理策略

- 所有函数都返回 bool 表示操作是否成功
- 通过指针参数返回数据（C 语言特性）
- 提供详细的错误信息

⚠️ 注意事项

1. 内存管理：记得调用 destroyQueue() 释放内存
2. 空指针检查：所有函数都要检查输入参数是否为 NULL
3. 索引边界：getAtIndex 要验证索引有效性
4. 类型灵活性：可以通过修改 ElemType 支持不同数据类型

📊 时间复杂度分析
操作 时间复杂度
enqueue O(1)

dequeue O(1)

getAtIndex O(1)

isEmpty/isFull O(1)
