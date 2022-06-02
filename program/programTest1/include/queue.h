typedef int QElemType;
#define MAXSIZE 20

typedef struct {
  QElemType data[MAXSIZE];
  int rear;
  int front;
} SqQueue;
bool visit(QElemType c);
bool initQueue(SqQueue* Q);
bool clearQueue(SqQueue* Q);
bool isEmptyQueue(SqQueue* Q);
bool isFullQueue(SqQueue* Q);
int queueLength(SqQueue* Q);
bool getHead(SqQueue* Q, QElemType* e);
bool enQueue(SqQueue* Q, QElemType e);
bool deQueue(SqQueue* Q, QElemType* e);
bool traverseQueue(SqQueue* Q);
