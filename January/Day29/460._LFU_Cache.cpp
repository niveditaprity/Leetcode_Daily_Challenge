class Node
{
    public:
    int val,key,freq;
    Node*prev,*next;
    Node(int key,int val)
    {
        this->key = key;
        this->val = val;
        freq = 1;
    }
};

class List {
    public:
    int len;
    Node *head, *tail;

    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        len = 0;
}
void addNode(Node*newNode)
{
    Node*temp = head->next;
    head->next = newNode;
    newNode->prev = head;
    newNode->next = temp;
    temp->prev = newNode;
    len++;
}
 
 void deleteNode(Node*node)
 {
  Node*delPrev = node->prev;
  Node*delNext = node->next;
  delPrev->next = delNext;
  delNext->prev = delPrev;
  len--;
 }
};

class LFUCache {
public:
    unordered_map<int, Node*> addOfKey;
    unordered_map<int, List*> freqListMap;
    int minFreq, currSize;
    int cacheCapacity;
    LFUCache(int capacity) {
      cacheCapacity = capacity;
      minFreq = 0;
      currSize = 0;
    }
    
    int get(int key) {
       if (addOfKey.find(key) == addOfKey.end()) {       
            return -1;
        }
        Node *resNode = addOfKey[key];                     
        int res = resNode->val;                             
        updateFreq(resNode);                         
        return res;    
    }
    
    void put(int key, int value) {
      if(cacheCapacity == 0)
      {
          return;
      }
      if(addOfKey.find(key) != addOfKey.end())
       {
          Node*availNode = addOfKey[key];
          availNode->val = value;
          updateFreq(availNode);
       } 
       else
       {
           if (currSize == cacheCapacity) {                
                List *list = freqListMap[minFreq];          
                Node *prevNode = list->tail->prev;         
                int keyRemoved = prevNode->key;          
                addOfKey.erase(keyRemoved);             
                freqListMap[minFreq]->deleteNode(prevNode); 
                currSize--;                                 
            }
            currSize++;                                    
            minFreq = 1;                                  

            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];           
            }
            Node *newNode = new Node(key, value);          
            listFreq->addNode(newNode);                     
            addOfKey[key] = newNode;                       
            freqListMap[minFreq] = listFreq; 

       } 
    }

   void updateFreq(Node*node)
   {
    addOfKey.erase(node->key);
    freqListMap[node->freq]->deleteNode(node);
    if (node->freq == minFreq && freqListMap[node->freq]->len == 0) {
       minFreq++; 
    } 
    List *nextHigherFreqList = new List();
        if (freqListMap.find(node->freq + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->freq + 1]; 
        }
        node->freq += 1;                                     
        nextHigherFreqList->addNode(node);                  
        freqListMap[node->freq] = nextHigherFreqList;         
        addOfKey[node->key] = node;   
   }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
